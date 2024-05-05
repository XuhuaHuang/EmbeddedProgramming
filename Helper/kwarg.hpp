/**
 * @file kwarg.hpp
 * @author Xuhua Huang
 * @brief Use user-defined-literal with compile-time strings to implement Python-like keyword argument.
 * @version 0.1
 * @date 2024-03-30
 *
 * $ g++ -c kwarg_unittest.cpp -o kwarg_unittest.exe -std=c++2b -Wall -Wextra
 * $ .\kwarg_unittest
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#ifndef KWARG_HPP
#define KWARG_HPP

#include <array>
#include <string_view>

namespace helper
{
namespace mlcxx
{

struct kwarg
{
    kwarg() = delete;
    explicit((true)) consteval inline kwarg(const char* rhs) { kw = rhs; }
    explicit((true)) consteval inline kwarg(const std::string_view& rhs) { kw = rhs; }
    explicit((true)) consteval inline kwarg(std::string_view&& rhs) { kw = std::move(rhs); }

    consteval inline decltype(auto) operator=(const auto rhs) { return rhs; }

    consteval inline bool           operator==(const kwarg& rhs) const = default;
    constexpr inline decltype(auto) operator<=>(const kwarg& rhs)      = delete;

private:
    std::string_view kw;
};

} // namespace mlcxx
} // namespace helper

#endif //! KWARG_HPP
