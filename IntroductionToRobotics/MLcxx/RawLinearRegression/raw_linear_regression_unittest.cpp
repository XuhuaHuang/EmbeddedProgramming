/**
 * @file raw_linear_regression_unittest.cpp
 * @brief Dependency-free regression, validation, and callable lifetime checks.
 */
// Include the public header first to verify that it supplies its dependencies.
#include "raw_linear_regression.hpp"

#include <array>
#include <cmath>
#include <concepts>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>
#include <valarray>
#include <vector>

namespace robotics::mlcxx::test {

void check(bool condition, std::string_view message) {
  if (!condition) {
    throw std::runtime_error(std::string(message));
  }
}

void check_near(long double actual, long double expected, long double tolerance, std::string_view message) {
  if (!std::isfinite(actual) || std::abs(actual - expected) > tolerance) {
    throw std::runtime_error(
      std::string(message) + ": expected " + std::to_string(expected) + ", got " + std::to_string(actual)
    );
  }
}

template <typename callable_t>
void expect_domain_error(callable_t&& callable, std::string_view message) {
  try {
    callable();
  } catch (const std::domain_error&) {
    return;
  }
  throw std::runtime_error(std::string(message) + ": expected std::domain_error");
}

void basic_regression() {
  const std::vector<double> x{1.0, 2.0, 3.0, 4.0, 5.0};
  const std::vector<double> y{2.0, 4.0, 5.0, 4.0, 5.0};
  check_near(mean(x), 3.0, 0.0, "x mean");
  check_near(mean(y), 4.0, 0.0, "y mean");
  // Sxy = 6 and Sxx = 10; both covariance calculations divide by n = 5.
  check_near(covariance(x, y, mean(x), mean(y)), 1.2, 1e-12, "population covariance");
  check_near(covariance(x, x, mean(x), mean(x)), 2.0, 0.0, "population variance");
  const auto slope = calculate_slope(x, y, mean(x), mean(y));
  check_near(slope, 0.6, 1e-12, "slope");
  check_near(calculate_intercept(slope, mean(x), mean(y)), 2.2, 1e-12, "intercept");
  const auto model                     = simple_ordinary_least_squares(x, y);
  const auto [intercept, fitted_slope] = model;
  check_near(intercept, 2.2, 1e-12, "structured binding intercept");
  check_near(fitted_slope, 0.6, 1e-12, "structured binding slope");
  check_near(model(2.0), 3.4, 1e-12, "prediction");
  check_near(get<2>(model)(2.0), 3.4, 1e-12, "extracted callable prediction");
}

void double_precision_with_large_offsets() {
  const std::vector<double> x{100000000.0, 100000001.0, 100000002.0};
  const std::vector<double> y{0.0, 1.0, 2.0};
  static_assert(sizeof(decltype(mean(x))) >= sizeof(double));
  check_near(mean(x), 100000001.0, 0.0, "large-offset x mean");
  check_near(covariance(x, x, mean(x), mean(x)), 2.0 / 3.0, 1e-12, "large-offset variance");
  check_near(calculate_slope(x, y, mean(x), mean(y)), 1.0, 1e-12, "large-offset slope");
  const auto model = simple_ordinary_least_squares(x, y);
  check_near(get<0>(model), -100000000.0, 0.0, "large-offset intercept");
  check_near(get<1>(model), 1.0, 0.0, "stored large-offset slope");
  check_near(model(100000001.0), 1.0, 0.0, "large-offset prediction");
}

void stored_slope_with_large_intercept() {
  const std::array<double, 3> x{0.0, 4.0, 8.0};
  const std::array<double, 3> y{1e16, 1e16 + 2.0, 1e16 + 4.0};
  const auto                  model = simple_ordinary_least_squares(x, y);
  check_near(get<0>(model), 1e16, 0.0, "large intercept");
  check_near(get<1>(model), 0.5, 0.0, "stored slope");
  // Predictions round together here, so their difference cannot recover the slope.
  check_near(model(1.0) - model(0.0), 0.0, 0.0, "rounded predictions");
}

void covariance_with_explicit_centers() {
  const std::array<double, 2> x{1.0, 3.0};
  const std::array<double, 2> y{2.0, 4.0};
  check_near(covariance(x, y, 0.0, 0.0), 7.0, 0.0, "covariance honors supplied centers");
  check_near(covariance(x, y, mean(x), mean(y)), 1.0, 0.0, "covariance with sample means");
}

void adjacent_offset_intercept() {
  const std::array<double, 2> x{1e16, 1e16 + 2.0};
  const std::array<double, 2> y{1.0, 2.0};
  check_near(calculate_slope(x, y, mean(x), mean(y)), 0.5, 0.0, "slope with rounded absolute mean");
  const auto model = simple_ordinary_least_squares(x, y);
  check_near(get<1>(model), 0.5, 0.0, "adjacent-offset slope");
  check_near(get<0>(model), -4999999999999999.0, 0.0, "adjacent-offset intercept");
  check_near(model(x[0]), 1.0, 0.0, "adjacent-offset first prediction");
  check_near(model(x[1]), 2.0, 0.0, "adjacent-offset second prediction");
}

void decimal_constant_independent_variable() {
  const std::array<double, 3> x{0.1, 0.1, 0.1};
  const std::array<double, 3> y{2.0, 3.0, 4.0};
  const auto x_mean = mean(x);
  const auto y_mean = mean(y);
  check_near(x_mean, 0.1, 0.0, "constant decimal mean");
  check_near(covariance(x, x, x_mean, x_mean), 0.0, 0.0, "constant decimal variance");
  check_near(covariance(x, y, x_mean, y_mean), 0.0, 0.0, "constant decimal covariance");
  expect_domain_error([&] { (void)calculate_slope(x, y, x_mean, y_mean); }, "constant decimal slope");
  expect_domain_error(
    [&] { (void)calculate_slope(x, y, 0.10000000000000002, y_mean); }, "constant decimal slope with rounded mean"
  );
  expect_domain_error([&] { (void)simple_ordinary_least_squares(x, y); }, "constant decimal fit");
}

void shifted_offset_and_sample_order() {
  const std::array<double, 3> x{1e16 + 2.0, 1e16 + 4.0, 1e16 + 6.0};
  const std::array<double, 3> y{0.0, 1.0, 2.0};
  const auto x_mean = mean(x);
  const auto y_mean = mean(y);
  check_near(x_mean, 1e16 + 4.0, 0.0, "shifted-offset mean");
  check_near(covariance(x, x, x_mean, x_mean), 8.0 / 3.0, 1e-12, "shifted-offset variance");
  check_near(covariance(x, y, x_mean, y_mean), 4.0 / 3.0, 1e-12, "shifted-offset covariance");
  check_near(calculate_slope(x, y, x_mean, y_mean), 0.5, 1e-14, "shifted-offset helper slope");
  const auto model = simple_ordinary_least_squares(x, y);
  check_near(get<1>(model), 0.5, 1e-14, "shifted-offset fit slope");
  check_near(get<0>(model), -5000000000000001.0, 0.0, "shifted-offset intercept");
  check_near(model(x[0]), 0.0, 1e-12, "shifted-offset first prediction");

  const std::array<double, 3> reversed_x{x[2], x[1], x[0]};
  const std::array<double, 3> reversed_y{y[2], y[1], y[0]};
  const auto reversed_model = simple_ordinary_least_squares(reversed_x, reversed_y);
  check_near(get<1>(reversed_model), get<1>(model), 1e-14, "sample-order invariant slope");
  check_near(get<0>(reversed_model), get<0>(model), 0.0, "sample-order invariant intercept");
}

void scaled_tiny_independent_values() {
  const std::array<double, 3> x{0.0, 1e-200, 2e-200};
  const std::array<double, 3> y{0.0, 1.0, 2.0};
  // The variance underflows double, but the ratio Sxy/Sxx has a finite slope.
  check_near(calculate_slope(x, y, mean(x), mean(y)), 1e200, 1e188, "tiny-scale helper slope");
  const auto model = simple_ordinary_least_squares(x, y);
  check_near(get<1>(model), 1e200, 1e188, "tiny-scale fit slope");
  check_near(get<0>(model), 0.0, 1e-12, "tiny-scale intercept");
  check_near(model(1e-200), 1.0, 1e-12, "tiny-scale middle prediction");
  check_near(model(2e-200), 2.0, 1e-12, "tiny-scale last prediction");
}

void mixed_precision_and_range_types() {
  const std::vector<double> x{1e16, 1e16 + 2.0};
  const std::valarray<long double> y{0.0L, 1.0L};
  const auto model = simple_ordinary_least_squares(x, y);
  static_assert(std::same_as<decltype(get<1>(model)), long double>);
  check_near(get<1>(model), 0.5L, 0.0, "mixed-precision slope");
  check_near(get<0>(model), -5000000000000000.0L, 0.0, "mixed-precision intercept");
  check_near(model(x[0]), 0.0L, 0.0, "mixed-precision first prediction");
  check_near(model(x[1]), 1.0L, 0.0, "mixed-precision second prediction");
}

void finite_mean_without_sum_overflow() {
  const auto maximum = std::numeric_limits<double>::max();
  check_near(mean(std::array<double, 2>{maximum, maximum}), maximum, 0.0, "finite maximum mean");
  check_near(mean(std::array<double, 2>{maximum, -maximum}), 0.0, 0.0, "balanced extreme mean");
}

void cancelling_mean_and_sample_order() {
  const std::array<std::array<double, 3>, 3> permutations{{
    {1e16, 1.0, -1e16},
    {-1e16, 1.0, 1e16},
    {1e16, -1e16, 1.0},
  }};
  for (const auto& samples : permutations) {
    check_near(mean(samples), 1.0 / 3.0, 1e-15, "cancelling mean independent of sample order");
  }
}

void four_observation_example() {
  const std::array<double, 4> x{1.0, 3.0, 7.0, 12.0};
  const std::array<double, 4> y{8.0, 13.0, 26.0, 35.0};
  const auto                  model = simple_ordinary_least_squares(x, y);
  check_near(mean(x), 5.75, 0.0, "four-point x mean");
  check_near(mean(y), 20.5, 0.0, "four-point y mean");
  check_near(covariance(x, x, mean(x), mean(x)), 70.75 / 4.0, 0.0, "four-point variance");
  check_near(covariance(x, y, mean(x), mean(y)), 177.5 / 4.0, 0.0, "four-point covariance");
  check_near(get<1>(model), 710.0 / 283.0, 1e-12, "four-point slope");
  check_near(get<0>(model), 1719.0 / 283.0, 1e-12, "four-point intercept");
  check_near(model(2.0), 3139.0 / 283.0, 1e-12, "four-point prediction");
}

void integer_valarray_means() {
  const std::valarray<int> positive{1, 2};
  const std::valarray<int> negative{-1, -2};
  static_assert(std::floating_point<decltype(mean(positive))>);
  check_near(mean(positive), 1.5, 0.0, "positive integer mean");
  check_near(mean(negative), -1.5, 0.0, "negative integer mean");
}

void valarray_regression() {
  const std::valarray<double> x{1.0, 2.0, 3.0};
  const std::valarray<double> y{3.0, 5.0, 7.0};
  const auto                  model = simple_ordinary_least_squares(x, y);
  check_near(get<0>(model), 1.0, 0.0, "valarray intercept");
  check_near(get<1>(model), 2.0, 0.0, "valarray slope");
  check_near(model(4.0), 9.0, 0.0, "valarray prediction");
}

void float_observations() {
  const std::array<float, 5> x{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
  const std::array<float, 5> y{2.0f, 4.0f, 5.0f, 4.0f, 5.0f};
  const auto                 model = simple_ordinary_least_squares(x, y);
  check_near(get<0>(model), 2.2, 1e-6, "float intercept");
  check_near(get<1>(model), 0.6, 1e-6, "float slope");
  check_near(model(2.0f), 3.4, 1e-6, "float prediction");
}

void insufficient_observations() {
  const std::vector<double>   empty;
  const std::vector<double>   single{1.0};
  const std::array<double, 0> empty_array{};
  const std::valarray<int>    single_valarray{1};
  expect_domain_error([&] { (void)mean(empty); }, "empty vector mean");
  expect_domain_error([&] { (void)mean(single); }, "single vector mean");
  expect_domain_error([&] { (void)mean(empty_array); }, "empty array mean");
  expect_domain_error([&] { (void)mean(single_valarray); }, "single valarray mean");
  expect_domain_error([&] { (void)covariance(empty, empty, 0.0, 0.0); }, "empty covariance");
  expect_domain_error([&] { (void)covariance(single, single, 1.0, 1.0); }, "single covariance");
  expect_domain_error([&] { (void)simple_ordinary_least_squares(empty, empty); }, "empty fit");
  expect_domain_error([&] { (void)simple_ordinary_least_squares(single, single); }, "single fit");
}

void mismatched_observation_counts() {
  const std::vector<double> x{1.0, 2.0};
  const std::vector<double> y{3.0, 4.0, 5.0};
  expect_domain_error([&] { (void)covariance(x, y, 1.5, 4.0); }, "mismatched covariance");
  expect_domain_error([&] { (void)calculate_slope(x, y, 1.5, 4.0); }, "mismatched slope");
  expect_domain_error([&] { (void)simple_ordinary_least_squares(x, y); }, "mismatched fit");
}

void constant_independent_variable() {
  const std::array<double, 3> x{1.0, 1.0, 1.0};
  const std::array<double, 3> y{2.0, 3.0, 4.0};
  expect_domain_error([&] { (void)calculate_slope(x, y, 1.0, 3.0); }, "constant-x slope");
  expect_domain_error([&] { (void)simple_ordinary_least_squares(x, y); }, "constant-x fit");
}

void nonfinite_observations() {
  const std::vector<double> finite{1.0, 2.0};
  for (const auto invalid :
       {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::infinity(),
        -std::numeric_limits<double>::infinity()}) {
    const std::vector<double> invalid_values{1.0, invalid};
    expect_domain_error([&] { (void)mean(invalid_values); }, "nonfinite mean");
    expect_domain_error([&] { (void)covariance(finite, invalid_values, 1.5, 1.5); }, "nonfinite dependent covariance");
    expect_domain_error(
      [&] { (void)calculate_slope(invalid_values, finite, 1.5, 1.5); }, "nonfinite independent slope"
    );
    expect_domain_error(
      [&] { (void)simple_ordinary_least_squares(finite, invalid_values); }, "nonfinite dependent fit"
    );
  }
}

void double_array_evaluation() {
  const lambda_linreg_t       model{[](double x) { return x + 0.125; }};
  const std::array<double, 3> indexes{100000000.0, 100000001.0, 100000002.0};
  const auto                  values = model.at(indexes);
  static_assert(sizeof(typename decltype(values)::value_type) >= sizeof(double));
  check_near(values[0], 100000000.125, 0.0, "first double array prediction");
  check_near(values[1], 100000001.125, 0.0, "second double array prediction");
  check_near(values[2], 100000002.125, 0.0, "third double array prediction");
}

void temporary_callable_lifetime() {
  const auto make_transform = [] { return lambda_linreg_t{[offset = -2.0](double x) { return x + offset; }}.abs(); };
  const auto absolute_model = make_transform();
  check_near(absolute_model(1.0), 1.0, 0.0, "temporary absolute prediction");
  check_near(absolute_model(5.0), 3.0, 0.0, "temporary second prediction");
}

void chained_transformations() {
  const auto model = lambda_linreg_t{[](double x) { return x - 3.0; }}.abs().square().sqrt().pow(2.0);
  check_near(model(1.0), 4.0, 0.0, "chained prediction at one");
  check_near(model(6.0), 9.0, 0.0, "chained prediction at six");
  const auto root_model = lambda_linreg_t{[](double x) { return x; }}.pow(0.5);
  check_near(root_model(9.0), 3.0, 0.0, "fractional power");
}

void fitted_model_equality() {
  const std::array<double, 3> x{1.0, 2.0, 3.0};
  const std::array<double, 3> y{3.0, 5.0, 7.0};
  const std::array<double, 3> shifted_y{4.0, 6.0, 8.0};
  const auto                  first     = simple_ordinary_least_squares(x, y);
  const auto                  same      = simple_ordinary_least_squares(x, y);
  const auto                  different = simple_ordinary_least_squares(x, shifted_y);
  check(first == same, "equal fitted coefficients");
  check(!(first == different), "different fitted coefficients");
  check(first < different, "fitted-model ordering compares coefficients");
  check(!(different < first), "fitted-model ordering is asymmetric");
}

struct comparable_callable_t {
  double                offset;
  constexpr double      operator()(double x) const noexcept { return x + offset; }
  friend constexpr bool operator==(const comparable_callable_t&, const comparable_callable_t&) = default;
};

void callable_state_equality_and_noexcept() {
  const lambda_linreg_t first{comparable_callable_t{1.0}};
  const lambda_linreg_t same{comparable_callable_t{1.0}};
  const lambda_linreg_t different{comparable_callable_t{2.0}};
  static_assert(noexcept(first(1.0)));
  check(first == same, "equal callable state");
  check(!(first == different), "different callable state");
}

void mixed_valarray_indexing() {
  using namespace indexing;
  linreg_t data{
    std::valarray<int>{1,   2  },
    std::valarray<double>{3.5, 4.5}
  };
  check(data[0_x] == 1, "integer x indexing");
  check_near(data[1_y], 4.5, 0.0, "double y indexing");
  data[1_x]                  = 7;
  data[0_y]                  = 8.5;
  const auto& read_only_data = data;
  check(read_only_data[1_x] == 7, "mutable x indexing");
  check_near(read_only_data[0_y], 8.5, 0.0, "mutable y indexing");
#if defined(__cpp_multidimensional_subscript) && __cpp_multidimensional_subscript >= 202110L
  check_near(read_only_data[internal_index_type_t::x_index, 1U], 7.0, 0.0, "mixed x multidimensional indexing");
  check_near(read_only_data[internal_index_type_t::y_index, 0U], 8.5, 0.0, "mixed y multidimensional indexing");
#endif
}

struct test_case_t {
  std::string_view name;
  void (*run)();
};

} // namespace robotics::mlcxx::test

int main() {
  using namespace robotics::mlcxx::test;
  const test_case_t cases[]{
    {"basic regression and population covariance", basic_regression                    },
    {"double precision with large offsets",        double_precision_with_large_offsets },
    {"stored slope with large intercept",          stored_slope_with_large_intercept   },
    {"covariance with explicit centers",           covariance_with_explicit_centers    },
    {"adjacent offset intercept",                  adjacent_offset_intercept           },
    {"constant decimal independent variable",     decimal_constant_independent_variable},
    {"shifted offset and sample order",            shifted_offset_and_sample_order     },
    {"scaled tiny independent values",             scaled_tiny_independent_values      },
    {"mixed precision and range types",            mixed_precision_and_range_types     },
    {"finite mean without sum overflow",           finite_mean_without_sum_overflow    },
    {"cancelling mean and sample order",            cancelling_mean_and_sample_order    },
    {"four observation example",                   four_observation_example            },
    {"integer and negative valarray means",        integer_valarray_means              },
    {"valarray regression",                        valarray_regression                 },
    {"float observations",                         float_observations                  },
    {"insufficient observations",                  insufficient_observations           },
    {"mismatched observation counts",              mismatched_observation_counts       },
    {"constant independent variable",              constant_independent_variable       },
    {"nonfinite observations",                     nonfinite_observations              },
    {"double array evaluation",                    double_array_evaluation             },
    {"temporary callable lifetime",                temporary_callable_lifetime         },
    {"chained transformations",                    chained_transformations             },
    {"fitted model equality",                      fitted_model_equality               },
    {"callable state equality and noexcept",       callable_state_equality_and_noexcept},
    {"mixed valarray indexing",                    mixed_valarray_indexing             },
  };
  std::size_t failures = 0;
  for (const auto& test : cases) {
    try {
      test.run();
    } catch (const std::exception& error) {
      ++failures;
      std::cerr << "FAIL: " << test.name << ": " << error.what() << '\n';
    } catch (...) {
      ++failures;
      std::cerr << "FAIL: " << test.name << ": unknown exception\n";
    }
  }
  std::cout << std::size(cases) - failures << "/" << std::size(cases) << " test cases passed\n";
  return failures == 0 ? 0 : 1;
}