/**
 * @file ref.cpp
 * @author Xuhua Huang
 * @brief `std::ref` and `std::cref`
 *
 * @details `std::ref` and `std::cref` are utility functions in
 * the C++ Standard Library that create reference wrappers
 * for objects. They are defined in the `<functional>` header.
 * std::reference_wrapper<Type>
 * std::reference_wrapper<const Type>
 * These wrappers allow you to store references in
 * standard containers (like `std::vector`, `std::list`, etc.)
 * and pass them to algorithms that expect copyable objects.
 *
 * echo $?
 * Returns: 15\
 * Explanation: The accumulator lambda captures the sum by value,
 * but since it's mutable, it can modify its internal state.
 * However, when passed to `std::for_each`, a copy of the lambda is made,
 * so the original accumulator outside the loop remains unchanged.
 *
 * @version 0.1
 * @date 2026-01-05
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <vector>

struct stats_tracker {
  int count = 0;
  int total = 0;

  void operator()(int x) {
    count++;
    total += x;
  }
};

int main() {
  const std::array<int, 5> data{1, 2, 3, 4, 5};
  auto accumulator = [sum = 0](int value) mutable -> int {
    sum += value;
    return sum;
  };

  std::for_each(data.begin(), data.end(), std::ref(accumulator));
  std::cout << accumulator(0) << "\n"; // Outputs: 15

  std::vector<int> items = {10, 20, 30};
  stats_tracker tracker;

  // without std::ref
  // std::for_each makes a copy of 'tracker'. The copy updates its count to 3.
  // The copy is destroyed after the loop. 'tracker' remains empty.
  std::for_each(items.begin(), items.end(), tracker);
  std::cout << "Without ref: " << tracker.count << "\n"; // Output: 0

  // with std::ref
  // The loop operates on the actual 'tracker' object via reference.
  std::for_each(items.begin(), items.end(), std::ref(tracker));
  std::cout << "With ref: " << tracker.count << "\n"; // Output: 3

  return 0;
}
