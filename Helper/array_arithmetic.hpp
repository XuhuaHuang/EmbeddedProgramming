/**
 * @file array_arithmetic.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-04-03
 *
 * cmake -Bbuild -Wno-dev
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once

#ifndef ARRAY_ARITHMETIC_HPP
#define ARRAY_ARITHMETIC_HPP

#ifndef _ARRAY_
#include <array>
#endif

#ifndef _IOSTREAM_
#include <iostream>
#endif

namespace helper
{
namespace array_arithmetic
{

template<typename T, std::size_t rows, std::size_t cols>
using mdarray = std::array<std::array<T, cols>, rows>;

template<typename T, std::size_t N>
    requires requires (T t) {
        {
            std::cout << t
        } -> std::convertible_to<std::ostream&>;
    }
inline std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr)
{
    os << "[";
    for (typename std::array<T, N>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        os << *it;
        if (it != arr.end() - 1) [[likely]]
        {
            os << ", ";
        }
        else [[unlikely]]
        {
            continue;
        }
    }
    os << "]";
    return os;
}

template<typename T, std::size_t N>
    requires requires (T t) {
        {
            +t
        } -> std::convertible_to<T>;
    }
[[nodiscard]] constexpr std::array<T, N> operator+(const std::array<T, N>& rhs)
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

template<typename T, std::size_t N>
    requires requires (T t) {
        {
            -t
        } -> std::convertible_to<T>;
    }
[[nodiscard]] constexpr std::array<T, N> operator-(const std::array<T, N>& rhs)
{
    std::array<T, N> ans = std::array<T, N>();
    for (std::size_t i = 0; i < N; ++i)
    {
        ans[i] = -rhs[i];
    }
    return ans;
}

template<typename T, std::size_t N>
    requires requires (T t) {
        {
            ~t
        } -> std::convertible_to<T>;
    }
[[nodiscard]] constexpr std::array<T, N> operator~(const std::array<T, N>& rhs)
{
    std::array<T, N> ans = std::array<T, N>();
    for (std::size_t i = 0; i < N; ++i)
    {
        ans[i] = ~rhs[i];
    }
    return ans;
}

template<typename T, std::size_t N>
    requires requires (T t) {
        {
            !t
        } -> std::convertible_to<bool>;
    }
[[nodiscard]] constexpr std::array<bool, N> operator!(const std::array<T, N>& lhs)
{
    std::array<bool, N> ans = std::array<T, N>();
    for (std::size_t i = 0; i < N; ++i)
    {
        ans[i] = !lhs[i];
    }
    return ans;
}

template<typename T, std::size_t N>
    requires requires (T lhs, T rhs) {
        {
            lhs += rhs
        } -> std::convertible_to<T>;
    }
inline std::array<T, N>& operator+=(std::array<T, N>& lhs, const T& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        lhs[i] += rhs;
    }
    return lhs;
}

template<typename T, std::size_t N>
    requires requires (T lhs, T rhs) {
        {
            lhs += rhs
        } -> std::convertible_to<T>;
    }
inline std::array<T, N>& operator+=(std::array<T, N>& lhs, const std::array<T, N>& rhs)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        lhs[i] += rhs[i];
    }
    return lhs;
}

} // namespace array_arithmetic
} // namespace helper

#endif // !ARRAY_ARITHMETIC_HPP
