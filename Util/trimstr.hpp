// clang-format off
/*****************************************************************//**
 * \file   trimstr.hpp
 * \brief  Demonstration of handy constant expressions that trim
 *         `std::string` at compile time with `std::ranges`
 *
 * $ g++ trimstr.hpp -std=c++23 -Wall -Wextra -Wpedantic
 *
 * \author Xuhua Huang
 * \date   March 2022
 *********************************************************************/
// clang-format on

#pragma once
#ifndef UTIL_TRIMSTR_HPP
#define UTIL_TRIMSTR_HPP

#include <algorithm>
#include <cctype>
#include <ranges>
#include <string>
#include <string_view>

namespace util {

/**
 * @brief Helper lambda to check if a character is a whitespace
 * std::isspace is not constexpr and has undefined behavior with negative chars.
 */
constexpr inline auto is_space = [](char c) {
  return std::isspace(static_cast<unsigned char>(c));
};

// Define the views.
// Use string_view for the argument to ensure we aren't copying strings
// unnecessarily.
constexpr auto trim_front = std::views::drop_while(is_space);
constexpr auto trim_back = std::views::reverse |
                           std::views::drop_while(is_space) |
                           std::views::reverse;

/**
 * @brief Trims whitespace from both ends of a string_view
 *
 * @note Uses C++23 `std::ranges::to` to convert the view back to a string
 * @param str The string_view to trim
 * @return constexpr std::string The trimmed string
 */
constexpr inline std::string trim_str(std::string_view str) {
  auto trimmed_view = str | trim_front | trim_back;
  // Convert the view back to a std::string
  return trimmed_view | std::ranges::to<std::string>();
}

} // namespace util

constexpr inline auto trim_front = std::views::drop_while(::isspace);
constexpr inline auto trim_back = std::views::reverse |
                                  std::views::drop_while(::isspace) |
                                  std::views::reverse;

constexpr inline auto trim_spaces = trim_front | trim_back;

std::string trim_str(const std::string &str) {
  // std::rangesnext::to in C++23 proposal
  // that converts ranges to a container
  // return str | trim_spaces | std::rangesnext::to<std::string>;
  return std::ranges::to<std::string>(str | trim_spaces);
}

#endif // UTIL_TRIMSTR_HPP
