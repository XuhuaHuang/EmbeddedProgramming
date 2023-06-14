/**
 * @file raw_ranges_to_vector.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <ranges>
#include <vector>

namespace test::ranges
{

[[nodiscard]] constexpr auto to_vector(std::ranges::range auto range)
{
    return range | ::std::ranges::to<std::vector>();
}

} // namespace test::ranges

namespace test::stl
{

[[nodiscard]] constexpr auto to_vector(std::ranges::range auto range)
{
    using value_type = std::remove_cvref_t<decltype(*std::ranges::begin(range))>;
    std::vector<value_type> output{};
    if constexpr (requires { std::size(range); })
    {
        output.reserve(std::size(range));
    }
    std::ranges::copy(std::ranges::begin(range), std::ranges::end(range), std::back_inserter(output));
    return output;
}

} // namespace test::stl
