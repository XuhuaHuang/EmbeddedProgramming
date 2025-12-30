/**
 * @file views_notes.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-14
 *
 * @copyright ueg (c) 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

std::vector<int> generate_values(int start, int end) {
  std::vector<int> values;
  for (int i = start; i <= end; ++i) {
    values.push_back(i);
  }
  return values;
}

[[nodiscard]] [[gnu::always_inline]] auto get_data() -> std::vector<int> {
  return generate_values(2, 13);
}

bool test_data() {
  bool result = std::ranges::all_of(get_data() | std::ranges::views::drop(1) |
                                        std::ranges::views::take(2),
                                    [](int x) { return x < 5; });
  return result;
}

void iterate_data() {
  // Note: get_data() returns a temporary, but ranges handle lifetime extension
  // in loops mostly fine in C++20. std::ranges::views::drop(1) skips the first
  // element.
  for (const auto &elem : get_data() | std::ranges::views::drop(1)) {
    std::print("{}\n", elem);
  }
}

/**
 * @brief Iterate with index using a stateful generic lambda
 */
void iterate_with_index() {
  // A stateful generic lambda that maintains an index counter
  auto make_index = [idx = std::size_t{0}]<typename T>(const T &elem) mutable {
    return std::pair<std::size_t, const T &>{idx++, elem};
  };

  for (const auto &[index, elem] :
       get_data() | std::ranges::views::transform(make_index)) {
    std::print("{}: {}\n", index, elem);
  }
}

/**
 * @brief Iterate with index for first n elements
 *
 * @param n Number of elements to iterate over
 */
void iterate_with_index_first_n_elems(std::size_t n) {
  auto make_index = [idx = std::size_t{0}]<typename T>(const T &elem) mutable {
    return std::pair<std::size_t, const T &>{idx++, elem};
  };

  for (const auto &[index, elem] :
       get_data() | std::ranges::views::take(n) |
           std::ranges::views::transform(make_index)) {
    std::print("{}: {}\n", index, elem);
  }
}

int main() {
  // generate a view of values from 1 to 5 (inclusive)
  std::ranges::iota_view<int, int> values = std::views::iota(1, 6);

  std::cout << typeid(values).name()
            << "\n"; // class std::ranges::iota_view<int,int>

  // iterate over the values and print them
  for (auto value : values) {
    std::cout << value << ", ";
  }
  std::cout << "\n";

  // generate a view of even numbers from 2 to 10 (inclusive)
  auto even_numbers = std::views::iota(2, 11) |
                      std::views::filter([](int x) { return x % 2 == 0; });

  // iterate over the even numbers and print them
  for (auto even_number : even_numbers) {
    std::cout << even_number << ", ";
  }
  std::cout << "\n";

  test_data();
  iterate_data();
  iterate_with_index();
  iterate_with_index_first_n_elems(5);

  return 0;
}
