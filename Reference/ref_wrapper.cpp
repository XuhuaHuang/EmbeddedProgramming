/**
 * @file ref_wrapper.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <concepts>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <ranges>
#include <vector>

void println(const auto rem, const std::ranges::range auto& v) {
  for (std::cout << rem; const auto& e : v)
    std::cout << e << ' ';
  std::cout << '\n';
}

int main() {
  std::list<int> l(10);
  std::iota(l.begin(), l.end(), -4);

  // can't use shuffle on a list (requires random access), but can use it on a vector
  std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());

  // std::ranges::shuffle(v, std::mt19937{std::random_device{}()});
  std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
  println("Contents of the list: ", l);
  println("Contents of the list, as seen through a shuffled vector: ", v);

  std::cout << "Doubling the values in the initial list...\n";
  // std::ranges::for_each(l, [](int& i) { i *= 2; });
  std::for_each(l.begin(), l.end(), [](int& i) -> void { i *= 2; });

  println("Contents of the list, as seen through a shuffled vector: ", v);

  return 0;
}