/**
 * @file fibonacci.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-12-31
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <generator> // C++23 header, standard in C++26
#include <iostream>
#include <ranges>

/**
 * @brief Generates a sequence of Fibonacci numbers up to a given limit.
 *
 * @param limit The upper bound for the generated Fibonacci numbers.
 * @return std::generator<int> A generator yielding Fibonacci numbers.
 */
std::generator<int> fibonacci_sequence(const int limit) {
  int a = 0;
  int b = 1;

  while (a < limit) {
    // co_yield suspends execution and returns a value
    co_yield a;

    int next = a + b;
    a = b;
    b = next;
  }
  // Coroutine ends automatically when function exits
}

int main() {
  std::cout << "Fibonacci numbers less than 20:\n";

  // Use the generator in a range-based for loop
  for (int num : fibonacci_sequence(20)) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  // Compatible with C++20 Ranges
  // Create a new generator since the previous one is exhausted
  std::cout << "Squared values:\n";
  auto square = [](int n) { return n * n; };

  for (int num :
       fibonacci_sequence(20) | std::ranges::views::transform(square)) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}