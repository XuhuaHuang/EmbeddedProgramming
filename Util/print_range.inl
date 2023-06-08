/**
 * @file print_range.inl
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-30
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef PRINT_RANGE_INL
#define PRINT_RANGE_INL

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _RANGES_
#include <ranges>
#endif

namespace util
{
namespace range
{

auto print_range(const std::ranges::range auto& range, bool newline = false) -> void;

namespace detail
{

auto print(const std::ranges::range auto& value) -> void
{
    print_range(value, false);
}

auto print(const auto& value) -> void
{
    std::cout << value;
}

} // namespace detail

} // namespace range
} // namespace util

#endif
