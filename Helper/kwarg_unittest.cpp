/**
 * @file kwarg_unittest.cpp
 * @author Xuhua Huang
 * @brief g++ -std=c++2b -Wall -Wextra kwarg_unittest.cpp
 * @version 0.1
 * @date 2024-05-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "kwarg.hpp"

#include <climits>
#include <iostream>

consteval inline int add(const int a, const int b) noexcept {
  return a + b > INT_MAX ? INT_MAX : a + b;
}

int main(void) {
  using namespace helper::mlcxx;
  static_assert(add(kwarg{"a"} = 1, kwarg{"b"} = 2) == 3);

  {
    using namespace helper::mlcxx::literals;
    constexpr auto axis = "axis"_kw = 1;
    constexpr auto dtype = "dtype"_kw = "float32";
    constexpr auto keep = "keepdims"_kw = true;

    std::cout << "axis: " << axis << "\n";
    std::cout << "dtype: " << dtype << "\n";
    std::cout << "keepdims: " << keep << "\n";

    static_assert((axis == "axis"_kw) && (dtype == "dtype"_kw) && (keep == "keepdims"_kw));
  }

  return 0;
}
