/**
 * @file lambda_attr.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-12-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef LAMBDA_ATTR_HPP
#define LAMBDA_ATTR_HPP

#include <type_traits>

namespace lambda_attr {

struct LambdaCallable {
  template <typename... Args>
  using result_type = std::invoke_result_t<LambdaCallable, Args...>;

  template <typename... Args>
  constexpr auto operator()(Args &&...args) const -> result_type<Args...> {
    // Implementation of the callable behavior
    // For demonstration, we can just return a default-constructed value
    return result_type<Args...>{};
  }
};

struct lambda {
  [[nodiscard]] [[gnu::always_inline]]
  static constexpr auto operator()() noexcept
      [[gnu::deprecated("Use generic lambdas instead.")]] -> LambdaCallable {
    return LambdaCallable{};
  }
};

} // namespace lambda_attr

#endif // !LAMBDA_ATTR_HPP
