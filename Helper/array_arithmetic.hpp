/**
 * @file array_arithmetic.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once

#ifndef ARRAY_ARITHMETIC_HPP
#define ARRAY_ARITHMETIC_HPP

namespace helper
{
namespace array_arithmetic
{

// clang-format off
template<typename T, std::size_t N>
#if _HAS_CXX23
    requires requires (T t) {
        {
            std::cout << t
        } -> std::convertible_to<std::ostream&>;
    }
#endif // _HAS_CXX23
// clang-format on
inline std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr)
{
    os << "[";
    for (typename std::array<T, N>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        os << *it;
        if (it != arr.end() - 1) [[unlikely]]
        {
            os << ", ";
        }
        else [[likely]]
        {
            continue;
        }
    }
    os << "]";
    return os;
}

// clang-format off
template<typename T, std::size_t N>
#if _HAS_CXX23
    requires requires (T t) {
        {
            +t
        } -> std::convertible_to<T>;
    }
#endif // _HAS_CXX23
// clang-format on
inline constexpr std::array<T, N> operator+(const std::array<T, N>& rhs)
{
    /* NRVO variable */
    /// @brief Named Return Value Optimization
    std::array<T, N> ans = std::array<T, N>();
    for (std::size_t i = 0; i < N; ++i)
    {
        ans[i] = +rhs[i];
    }
    return ans;
}

// clang-format off
template<typename T, std::size_t N>
#if _HAS_CXX23
    requires requires (T t) {
        {
            -t
        } -> std::convertible_to<T>;
    }
#endif // _HAS_CXX23
// clang-format on
inline constexpr std::array<T, N> operator-(const std::array<T, N>& rhs)
{
    std::array<T, N> ans = std::array<T, N>();
    for (std::size_t i = 0; i < N; ++i)
    {
        ans[i] = -rhs[i];
    }
    return ans;
}

} // namespace array_arithmetic
} // namespace helper

#endif // !ARRAY_ARITHMETIC_HPP
