/*****************************************************************//**
 * \file   trimstr.hpp
 * \brief  Demonstration of handy constant expressions that trim
 *         `std::string` at compile time with `std::ranges`
 *
 * $ g++ trimstr.hpp -o trimstr.o -std=c++23 -Wall -Wextra -Wpedantic
 *
 * \author Xuhua Huang
 * \date   March 2022
 *********************************************************************/

#if defined __has_include
#if __has_include(<ranges>) && __has_include(<string>)
#include <ranges>
#include <string>
#else
#error "Require std::ranges and std::string library!"
#endif
#endif

inline constexpr auto trim_front = std::views::drop_while(::isspace);
inline constexpr auto trim_back = std::views::reverse
    | std::views::drop_while(::isspace)
    | std::views::reverse;

inline constexpr auto trim_spaces = trim_front | trim_back;

std::string trim_str(const std::string& str) {
    // std::rangesnext::to in C++23 proposal
    // that converts ranges to a container
    return str | trim_spaces | std::rangesnext::to<std::string>;
}
