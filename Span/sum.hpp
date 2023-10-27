/**
 * @file sum.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-07-23
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef SUM_HPP
#define SUM_HPP

#include <numeric>

namespace util
{
namespace span
{

// clang-format off
constexpr auto sum = []([[maybe_unused]] auto s) -> auto {
    return std::accumulate(std::cbegin(s), std::cend(s), 0);
};
// clang-format on

} // namespace span
} // namespace util

#endif // !SUM_HPP
