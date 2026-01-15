/**
 * @file println.inl
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-09-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PRINTLN_HPP
#define PRINTLN_HPP

#include <iostream>
#include <vector>

namespace util {

template <typename T>
concept printable = requires (std::ostream& os, T v) { v.print(os); };

template <typename T>
std::ostream& print_ln(std::ostream& os, const T& v) {
  if constexpr (printable<T>) {
    v.print(os);
  } else {
    os << v;
  }
  os << "\n";
  return os;
}

template <printable T>
using vector_of_printable = std::vector<T>;

} // namespace util

#endif //! PRINTLN_HPP
