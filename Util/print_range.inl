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

auto print_range(const std::ranges::range auto& range, bool newline) -> void
{
    const auto begin = std::ranges::cbegin(range);
    const auto end   = std::ranges::cend(range);

    std::cout << '[';

    for (auto&& i : std::ranges::subrange(begin, end - 1))
    {
        // std::cout << i << ",";
        detail::print(i);
        std::cout << ',';
    }

    // std::cout << *(end - 1) << ']';
    detail::print(*(end - 1));
    std::cout << ']';

    if (newline)
    {
        std::cout << '\n';
    }
}

} // namespace range
} // namespace util

#endif
