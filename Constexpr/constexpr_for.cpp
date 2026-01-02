/**
 * @file constexpr_for.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright ueg (c) 2023
 *
 */

#include <iostream>

constexpr int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

constexpr int f = factorial(5);

int main() {
  static_assert(f == 120, "Factorial of 5 should be 120");
  return 0;
}
