/* clang-format off */
/*****************************************************************//**
 * \file   basics.hpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 21, 2022
 *********************************************************************/
/* clang-format on */

#ifndef MATH_BASICS_HPP
#define MATH_BASICS_HPP

#include <algorithm>
#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>

namespace util
{
namespace math
{

/* requires std::forward_iterator<decltype(data)> */
template<typename T>
[[nodiscard]] inline T mean(const auto& data)
    requires std::ranges::range<decltype(data)>
{
    return std::accumulate(std::begin(data), std::end(data), static_cast<T>(0)) / data.size();
}

template<typename T>
[[nodiscard]] inline T std_deviation(const auto& data)
{
    T mean    = std::accumulate(std::begin(data), std::end(data), static_cast<T>(0)) / data.size();
    T sq_sum  = std::inner_product(data.begin(), data.end(), data.begin(), static_cast<T>(0));
    T std_dev = std::sqrt(sq_sum / data.size() - static_cast<T>(mean * mean));
    return std_dev;
}

template<typename Iterable>
bool any(Iterable&& iterable)
{
    return std::any_of(std::begin(iterable), std::end(iterable), [](const auto& x) { return static_cast<bool>(x); });
}

template<typename InputIt, typename UnaryPredicate>
bool any(InputIt first, InputIt last, UnaryPredicate pred)
{
    for (; first != last; ++first)
    {
        if (pred(*first))
        {
            return true;
        }
    }
    return false;
}

bool all(const auto& data)
{
    bool true_so_far = true;
    for (const auto& d : data)
    {
        true_so_far = d && true;
        if (!true_so_far) [[likely]]
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true_so_far;
}

} // namespace math
} // namespace util

#endif // MATH_BASICS_HPP
