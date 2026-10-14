/**
 * @file raw_linear_regression.hpp
 * @author Xuhua Huang
 * @brief Closed-form linear regression and value-owning callable helpers.
 */

#ifndef RAW_LINEAR_REGRESSION_HPP
#define RAW_LINEAR_REGRESSION_HPP

#include <algorithm>
#include <array>
#include <cmath>
#include <compare>
#include <concepts>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <limits>
#include <ostream>
#include <ranges>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <valarray>

namespace robotics::mlcxx {

using float32_t = std::float_t;

// Accumulate integers and floats in at least double precision.
template <typename... value_types_t>
using regression_real_t = std::common_type_t<double, value_types_t...>;

template <typename range_t>
concept arithmetic_range = std::ranges::sized_range<const range_t> && std::ranges::forward_range<const range_t>
                           && std::is_arithmetic_v<std::ranges::range_value_t<const range_t>>;

namespace regression_detail {

template <std::floating_point real_t>
struct compensated_sum_t {
  real_t sum{};
  real_t correction{};

  void add(real_t value) noexcept {
    const auto next = sum + value;
    correction += std::abs(sum) >= std::abs(value)
                    ? (sum - next) + value
                    : (value - next) + sum;
    sum = next;
  }

  [[nodiscard]] real_t value() const noexcept { return sum + correction; }
};

template <std::floating_point real_t>
struct axis_scale_t {
  real_t minimum;
  real_t maximum;
  int exponent;
};

// Power-of-two scaling preserves nearby representable values without overflowing.
template <std::floating_point real_t, arithmetic_range range_t>
[[nodiscard]] auto sample_scale(const range_t& data, real_t extra_value = real_t{0}) {
  if (std::ranges::size(data) < 2) {
    throw std::domain_error("At least 2 samples are required to perform a linear regression.");
  }
  if (!std::isfinite(extra_value)) {
    throw std::domain_error("Regression means must be finite.");
  }
  auto minimum = std::numeric_limits<real_t>::max();
  auto maximum = std::numeric_limits<real_t>::lowest();
  auto magnitude = std::abs(extra_value);
  for (const auto value : data) {
    const auto sample = static_cast<real_t>(value);
    if (!std::isfinite(sample)) {
      throw std::domain_error("Regression samples must be finite.");
    }
    minimum = std::min(minimum, sample);
    maximum = std::max(maximum, sample);
    magnitude = std::max(magnitude, std::abs(sample));
  }
  int exponent{};
  (void)std::frexp(magnitude, &exponent);
  return axis_scale_t<real_t>{minimum, maximum, exponent};
}

template <std::floating_point real_t>
[[nodiscard]] real_t checked_scale(real_t value, int exponent, const char* message) {
  const auto result = std::scalbn(value, exponent);
  if (!std::isfinite(result)) {
    throw std::domain_error(message);
  }
  return result;
}

template <std::floating_point real_t>
struct axis_statistics_t {
  int exponent;
  bool constant;
  real_t origin;
  real_t deviation_mean;
};

template <std::floating_point real_t, arithmetic_range range_t>
[[nodiscard]] auto centered_axis(const range_t& data, real_t origin) {
  const auto scale = sample_scale<real_t>(data);
  if (!std::isfinite(origin)) {
    throw std::domain_error("Regression means must be finite.");
  }
  // Supplied means are centering hints. Keep the origin in the sample range.
  origin = std::clamp(origin, scale.minimum, scale.maximum);
  const auto normalized_origin = std::scalbn(origin, -scale.exponent);
  compensated_sum_t<real_t> deviations;
  for (const auto value : data) {
    deviations.add(std::scalbn(static_cast<real_t>(value), -scale.exponent) - normalized_origin);
  }
  return axis_statistics_t<real_t>{
    scale.exponent, scale.minimum == scale.maximum, normalized_origin,
    deviations.value() / static_cast<real_t>(std::ranges::size(data))};
}

template <std::floating_point real_t>
struct fit_statistics_t {
  axis_statistics_t<real_t> x;
  axis_statistics_t<real_t> y;
  real_t normalized_slope;
};

template <std::floating_point real_t, arithmetic_range x_range_t, arithmetic_range y_range_t>
[[nodiscard]] auto centered_fit(
  const x_range_t& x, const y_range_t& y, real_t x_origin, real_t y_origin
) {
  if (std::ranges::size(x) != std::ranges::size(y)) {
    throw std::domain_error("The independent and dependent variables must have the same number of samples.");
  }
  const auto x_statistics = centered_axis<real_t>(x, x_origin);
  const auto y_statistics = centered_axis<real_t>(y, y_origin);
  if (x_statistics.constant) {
    throw std::domain_error("Cannot fit a line when all independent samples are equal.");
  }

  compensated_sum_t<real_t> sxx;
  compensated_sum_t<real_t> sxy;
  auto y_iterator = std::ranges::begin(y);
  for (const auto x_value : x) {
    const auto x_deviation =
      (std::scalbn(static_cast<real_t>(x_value), -x_statistics.exponent) - x_statistics.origin)
      - x_statistics.deviation_mean;
    const auto y_deviation =
      (std::scalbn(static_cast<real_t>(*y_iterator++), -y_statistics.exponent) - y_statistics.origin)
      - y_statistics.deviation_mean;
    sxx.add(x_deviation * x_deviation);
    sxy.add(x_deviation * y_deviation);
  }
  if (sxx.value() == real_t{0}) {
    throw std::domain_error("The independent sample variation cannot be represented.");
  }
  return fit_statistics_t<real_t>{x_statistics, y_statistics, sxy.value() / sxx.value()};
}

} // namespace regression_detail

template <arithmetic_range range_t>
[[nodiscard]]
inline auto mean(const range_t& data) {
  using real_t = regression_real_t<std::ranges::range_value_t<const range_t>>;
  const auto scale = regression_detail::sample_scale<real_t>(data);
  regression_detail::compensated_sum_t<real_t> sum;
  for (const auto value : data) {
    sum.add(std::scalbn(static_cast<real_t>(value), -scale.exponent));
  }
  auto normalized_mean = sum.value() / static_cast<real_t>(std::ranges::size(data));
  // Rounding must not move a finite mean beyond the observed sample bounds.
  normalized_mean = std::clamp(
    normalized_mean, std::scalbn(scale.minimum, -scale.exponent),
    std::scalbn(scale.maximum, -scale.exponent));
  return regression_detail::checked_scale(normalized_mean, scale.exponent, "The sample mean is not finite.");
}

template <arithmetic_range x_range_t, arithmetic_range y_range_t, typename x_mean_t, typename y_mean_t>
  requires std::is_arithmetic_v<x_mean_t> && std::is_arithmetic_v<y_mean_t>
[[nodiscard]]
inline auto covariance(const x_range_t& x, const y_range_t& y, x_mean_t x_mean, y_mean_t y_mean) {
  using real_t = regression_real_t<
    std::ranges::range_value_t<const x_range_t>, std::ranges::range_value_t<const y_range_t>,
    x_mean_t, y_mean_t>;
  if (std::ranges::size(x) != std::ranges::size(y)) {
    throw std::domain_error("The independent and dependent variables must have the same number of samples.");
  }
  const auto x_scale = regression_detail::sample_scale<real_t>(x, static_cast<real_t>(x_mean));
  const auto y_scale = regression_detail::sample_scale<real_t>(y, static_cast<real_t>(y_mean));
  const auto x_center = std::scalbn(static_cast<real_t>(x_mean), -x_scale.exponent);
  const auto y_center = std::scalbn(static_cast<real_t>(y_mean), -y_scale.exponent);
  regression_detail::compensated_sum_t<real_t> sum;
  auto y_iterator = std::ranges::begin(y);
  for (const auto x_value : x) {
    const auto x_deviation = std::scalbn(static_cast<real_t>(x_value), -x_scale.exponent) - x_center;
    const auto y_deviation = std::scalbn(static_cast<real_t>(*y_iterator++), -y_scale.exponent) - y_center;
    sum.add(x_deviation * y_deviation);
  }
  // Population covariance around the explicitly supplied centers.
  return regression_detail::checked_scale(
    sum.value() / static_cast<real_t>(std::ranges::size(x)), x_scale.exponent + y_scale.exponent,
    "The sample covariance is not finite.");
}

template <arithmetic_range x_range_t, arithmetic_range y_range_t, typename x_mean_t, typename y_mean_t>
  requires std::is_arithmetic_v<x_mean_t> && std::is_arithmetic_v<y_mean_t>
[[nodiscard]]
inline auto calculate_slope(const x_range_t& x, const y_range_t& y, x_mean_t x_mean, y_mean_t y_mean) {
  using real_t = regression_real_t<
    std::ranges::range_value_t<const x_range_t>, std::ranges::range_value_t<const y_range_t>,
    x_mean_t, y_mean_t>;
  // Recenter residuals so a rounded supplied mean cannot bias Sxx or Sxy.
  const auto statistics = regression_detail::centered_fit<real_t>(
    x, y, static_cast<real_t>(x_mean), static_cast<real_t>(y_mean));
  return regression_detail::checked_scale(
    statistics.normalized_slope, statistics.y.exponent - statistics.x.exponent,
    "The regression slope is not finite.");
}

template <typename slope_value_t, typename x_mean_t, typename y_mean_t>
  requires std::is_arithmetic_v<slope_value_t> && std::is_arithmetic_v<x_mean_t> && std::is_arithmetic_v<y_mean_t>
[[nodiscard]]
inline auto calculate_intercept(slope_value_t slope, x_mean_t x_mean, y_mean_t y_mean) {
  using real_t = regression_real_t<slope_value_t, x_mean_t, y_mean_t>;
  if (!std::isfinite(static_cast<real_t>(slope)) || !std::isfinite(static_cast<real_t>(x_mean))
      || !std::isfinite(static_cast<real_t>(y_mean))) {
    throw std::domain_error("Regression coefficients and means must be finite.");
  }
  const auto result = std::fma(-static_cast<real_t>(slope), static_cast<real_t>(x_mean), static_cast<real_t>(y_mean));
  if (!std::isfinite(result)) {
    throw std::domain_error("The regression intercept is not finite.");
  }
  return result;
}

namespace indexing {

enum class internal_index_type_t {
  x_index = 0,
  y_index = 1,
  XIndex  = x_index, // Compatibility with the original indexing API.
  YIndex  = y_index
};

template <internal_index_type_t index_type>
struct internal_index_t {
  std::size_t index{};

  constexpr internal_index_t() = default;
  constexpr internal_index_t(std::size_t value) noexcept
    : index{value} {}
  constexpr operator std::size_t() const noexcept { return index; }
};

[[nodiscard]]
constexpr auto operator""_x(unsigned long long value) {
  if (value > std::numeric_limits<std::size_t>::max()) {
    throw std::out_of_range("The sample index does not fit in size_t.");
  }
  return internal_index_t<internal_index_type_t::x_index>{static_cast<std::size_t>(value)};
}

[[nodiscard]]
constexpr auto operator""_y(unsigned long long value) {
  if (value > std::numeric_limits<std::size_t>::max()) {
    throw std::out_of_range("The sample index does not fit in size_t.");
  }
  return internal_index_t<internal_index_type_t::y_index>{static_cast<std::size_t>(value)};
}

using InternalIndexType = internal_index_type_t;
template <internal_index_type_t index_type>
using InternalIndex = internal_index_t<index_type>;

} // namespace indexing

template <typename container_t>
concept random_access_container = arithmetic_range<container_t> && std::ranges::random_access_range<const container_t>
                                  && requires (container_t& data, const container_t& const_data, std::size_t index) {
                                       data[index];
                                       {
                                         const_data[index]
                                       } -> std::convertible_to<std::ranges::range_value_t<const container_t>>;
                                     };

template <random_access_container x_container_t, random_access_container y_container_t>
struct linreg_t {
  using x_value_t = std::ranges::range_value_t<const x_container_t>;
  using y_value_t = std::ranges::range_value_t<const y_container_t>;
  using value_t   = std::common_type_t<x_value_t, y_value_t>;
  using X = x_container_t; // Legacy container aliases.
  using Y = y_container_t;

  using internal_index_type_t = indexing::internal_index_type_t;
  using InternalIndexType     = internal_index_type_t;
  template <internal_index_type_t index_type>
  using InternalIndex = indexing::internal_index_t<index_type>;

  x_container_t x;
  y_container_t y;

  linreg_t() = delete;
  constexpr linreg_t(x_container_t x_values, y_container_t y_values)
    : x{std::move(x_values)}
    , y{std::move(y_values)} {}

  constexpr decltype(auto) operator[](indexing::internal_index_t<internal_index_type_t::x_index> index) const {
    return x[index.index];
  }

  constexpr decltype(auto) operator[](indexing::internal_index_t<internal_index_type_t::x_index> index) {
    return x[index.index];
  }

  constexpr decltype(auto) operator[](indexing::internal_index_t<internal_index_type_t::y_index> index) const {
    return y[index.index];
  }

  constexpr decltype(auto) operator[](indexing::internal_index_t<internal_index_type_t::y_index> index) {
    return y[index.index];
  }

#if defined(__cpp_multidimensional_subscript) && __cpp_multidimensional_subscript >= 202110L
  constexpr value_t operator[](std::size_t variable, std::size_t index) const {
    if (variable == 0) {
      return static_cast<value_t>(x[index]);
    }
    if (variable == 1) {
      return static_cast<value_t>(y[index]);
    }
    throw std::out_of_range("A regression variable index must be 0 or 1.");
  }

  constexpr value_t operator[](internal_index_type_t variable, std::size_t index) const {
    return (*this)[static_cast<std::size_t>(variable), index];
  }
#endif

  template <internal_index_type_t index_type>
  constexpr decltype(auto) operator[](std::size_t index) const {
    if constexpr (index_type == internal_index_type_t::x_index) {
      return x[index];
    } else {
      static_assert(index_type == internal_index_type_t::y_index);
      return y[index];
    }
  }
};

template <typename x_container_t, typename y_container_t>
linreg_t(x_container_t, y_container_t) -> linreg_t<x_container_t, y_container_t>;

// Preserve existing source compatibility while exposing snake_case type names.
template <typename x_container_t, typename y_container_t>
using linreg    = linreg_t<x_container_t, y_container_t>;
using IndexType = indexing::internal_index_type_t;

template <typename function_t, typename value_t>
concept arithmetic_invocable = requires (function_t&& function, value_t value) {
  { std::invoke(std::forward<function_t>(function), value) } -> std::convertible_to<value_t>;
};

template <std::floating_point real_t>
struct affine_function_t {
  real_t slope;
  real_t intercept;

  [[nodiscard]]
  constexpr real_t operator()(real_t value) const noexcept {
    return std::fma(slope, value, intercept);
  }

  constexpr bool operator==(const affine_function_t&) const  = default;
  constexpr auto operator<=>(const affine_function_t&) const = default;
};

template <
  typename function_t,
  typename real_value_t = regression_real_t<std::invoke_result_t<const function_t&, double>>>
  requires std::floating_point<real_value_t> && arithmetic_invocable<const function_t&, real_value_t>
struct lambda_linreg_t final {
  using real_t              = real_value_t;
  using lambda_type_t       = function_t;
  using const_lambda_type_t = const function_t;
  using lambda_type         = function_t;
  using const_lambda_type   = const function_t;

  function_t f;

  lambda_linreg_t() = delete;
  explicit constexpr lambda_linreg_t(const function_t& function
  ) noexcept(std::is_nothrow_copy_constructible_v<function_t>)
    : f{function} {}
  explicit constexpr lambda_linreg_t(function_t&& function) noexcept(std::is_nothrow_move_constructible_v<function_t>)
    : f{std::move(function)} {}

  constexpr lambda_linreg_t(const lambda_linreg_t&)            = default;
  constexpr lambda_linreg_t(lambda_linreg_t&&)                 = default;
  constexpr lambda_linreg_t& operator=(const lambda_linreg_t&) = default;
  constexpr lambda_linreg_t& operator=(lambda_linreg_t&&)      = default;

  template <typename other_function_t, typename other_real_t>
    requires requires (const function_t& lhs, const other_function_t& rhs) {
      { lhs == rhs } -> std::convertible_to<bool>;
    }
  constexpr bool operator==(const lambda_linreg_t<other_function_t, other_real_t>& other) const
    noexcept(noexcept(f == other.f)) {
    return f == other.f;
  }

  constexpr auto operator<=>(const lambda_linreg_t& other) const
    requires std::three_way_comparable<function_t>
  {
    return f <=> other.f;
  }

  [[nodiscard]]
  constexpr real_t operator()(real_t value) const
    noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) {
    return static_cast<real_t>(std::invoke(f, value));
  }

  [[nodiscard]]
  constexpr real_t operator[](real_t value) const
    noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) {
    return (*this)(value);
  }

  [[nodiscard]]
  constexpr real_t at(real_t value) const noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) {
    return (*this)(value);
  }

  template <std::floating_point index_t, std::size_t count>
  [[nodiscard]]
  constexpr std::array<real_t, count> at(const std::array<index_t, count>& indexes) const
    noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) {
    std::array<real_t, count> result{};
    for (std::size_t index = 0; index < count; ++index) {
      result[index] = (*this)(static_cast<real_t>(indexes[index]));
    }
    return result;
  }

  template <std::floating_point value_t, std::size_t count>
  constexpr operator std::array<value_t, count>() const
    noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) {
    std::array<value_t, count> result{};
    for (std::size_t index = 0; index < count; ++index) {
      result[index] = static_cast<value_t>((*this)(static_cast<real_t>(index)));
    }
    return result;
  }

  template <typename other_function_t, typename other_real_t>
    requires requires (const lambda_linreg_t& lhs, const lambda_linreg_t<other_function_t, other_real_t>& rhs) {
      { lhs == rhs } -> std::convertible_to<bool>;
    }
  constexpr bool equal_to(const lambda_linreg_t<other_function_t, other_real_t>& other) const {
    return *this == other;
  }

  template <typename other_function_t>
    requires requires (const function_t& lhs, const other_function_t& rhs) {
      { lhs == rhs } -> std::convertible_to<bool>;
    }
  constexpr bool equal_to(const other_function_t& other) const {
    return f == other;
  }

  template <typename other_t>
    requires requires (const lambda_linreg_t& lhs, const other_t& rhs) {
      { lhs.equal_to(rhs) } -> std::convertible_to<bool>;
    }
  constexpr bool not_equal_to(const other_t& other) const {
    return !equal_to(other);
  }

  [[nodiscard]]
  auto abs() const {
    auto transformed = [function = f](real_t value
                       ) noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) -> real_t {
      return std::abs(static_cast<real_t>(std::invoke(function, value)));
    };
    return lambda_linreg_t<decltype(transformed), real_t>{std::move(transformed)};
  }

  [[nodiscard]]
  auto square() const {
    auto transformed = [function = f](real_t value
                       ) noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) -> real_t {
      const auto result = static_cast<real_t>(std::invoke(function, value));
      return result * result;
    };
    return lambda_linreg_t<decltype(transformed), real_t>{std::move(transformed)};
  }

  [[nodiscard]]
  auto sqrt() const {
    auto transformed = [function = f](real_t value
                       ) noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) -> real_t {
      return std::sqrt(static_cast<real_t>(std::invoke(function, value)));
    };
    return lambda_linreg_t<decltype(transformed), real_t>{std::move(transformed)};
  }

  [[nodiscard]]
  auto pow(real_t exponent) const {
    auto transformed = [function = f, exponent](real_t value
                       ) noexcept(std::is_nothrow_invocable_r_v<real_t, const function_t&, real_t>) -> real_t {
      return std::pow(static_cast<real_t>(std::invoke(function, value)), exponent);
    };
    return lambda_linreg_t<decltype(transformed), real_t>{std::move(transformed)};
  }
};

template <typename function_t>
lambda_linreg_t(function_t) -> lambda_linreg_t<function_t>;

template <typename function_t, typename real_t = regression_real_t<std::invoke_result_t<const function_t&, double>>>
using lambda_linreg = lambda_linreg_t<function_t, real_t>;

template <typename function_t, typename real_t>
std::ostream& operator<<(std::ostream& output, const lambda_linreg_t<function_t, real_t>& function) {
  const auto previous_flags     = output.flags();
  const auto previous_precision = output.precision();
  output << '[' << std::fixed << std::setprecision(2);
  for (int value = -5; value <= 5; ++value) {
    if (value != -5) {
      output << ", ";
    }
    output << function(static_cast<real_t>(value));
  }
  output << ']';
  output.flags(previous_flags);
  output.precision(previous_precision);
  return output;
}

template <arithmetic_range x_range_t, arithmetic_range y_range_t>
[[nodiscard]]
inline auto simple_ordinary_least_squares(const x_range_t& x, const y_range_t& y) {
  if (std::ranges::size(x) != std::ranges::size(y)) {
    throw std::domain_error("The independent and dependent variables must have the same number of samples.");
  }
  if (std::ranges::size(x) < 2) {
    throw std::domain_error("At least 2 samples are required to perform a linear regression.");
  }
  using real_t = regression_real_t<
    std::ranges::range_value_t<const x_range_t>, std::ranges::range_value_t<const y_range_t>>;
  const auto statistics = regression_detail::centered_fit<real_t>(
    x, y, static_cast<real_t>(*std::ranges::begin(x)), static_cast<real_t>(*std::ranges::begin(y)));
  const auto slope = regression_detail::checked_scale(
    statistics.normalized_slope, statistics.y.exponent - statistics.x.exponent,
    "The regression slope is not finite.");
  // Derive the intercept from the same centered coordinates, not rounded absolute means.
  const auto normalized_intercept =
    std::fma(-statistics.normalized_slope, statistics.x.origin, statistics.y.origin)
    + std::fma(-statistics.normalized_slope, statistics.x.deviation_mean, statistics.y.deviation_mean);
  const auto intercept = regression_detail::checked_scale(
    normalized_intercept, statistics.y.exponent, "The regression intercept is not finite.");
  return lambda_linreg_t<affine_function_t<real_t>, real_t>{affine_function_t<real_t>{slope, intercept}};
}

template <typename function_t>
constexpr inline bool is_affine_function_v = false;
template <std::floating_point real_t>
constexpr inline bool is_affine_function_v<affine_function_t<real_t>> = true;

template <std::size_t index, typename function_t, typename real_t>
  requires (index <= 2)
[[nodiscard]]
constexpr auto get(const lambda_linreg_t<function_t, real_t>& function) {
  if constexpr (index == 0) {
    if constexpr (is_affine_function_v<function_t>) {
      return function.f.intercept;
    } else {
      return function(real_t{0});
    }
  } else if constexpr (index == 1) {
    if constexpr (is_affine_function_v<function_t>) {
      return function.f.slope;
    } else {
      return function(real_t{1}) - function(real_t{0});
    }
  } else {
    return function.f;
  }
}

} // namespace robotics::mlcxx

namespace std {

template <typename function_t, typename real_t>
struct tuple_size<robotics::mlcxx::lambda_linreg_t<function_t, real_t>> : integral_constant<size_t, 2> {};

template <size_t index, typename function_t, typename real_t>
  requires (index < 2)
struct tuple_element<index, robotics::mlcxx::lambda_linreg_t<function_t, real_t>> {
  using type = real_t;
};

} // namespace std

#endif // RAW_LINEAR_REGRESSION_HPP
