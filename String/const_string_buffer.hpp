/**
 * @file const_string_buffer.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#ifndef CONST_STRING_BUFFER_HPP
#define CONST_STRING_BUFFER_HPP

#include <string_view>

namespace util
{

template<std::size_t N>
struct buffer
{
    constexpr buffer() = default;

    constexpr char const* begin() const { return data; }
    constexpr char const* end() const { return data + N; }

    constexpr operator std::basic_string_view<char>() const { return std::basic_string_view<char>(begin(), end()); }

    char data[N]{};
};

constexpr buffer<42> b;
static_assert(42 == std::string_view{b}.size());
static_assert(&b.data[0] == std::string_view{b}.begin());
static_assert(&b.data[42] == std::string_view{b}.end());

} // namespace util

#endif // !CONST_STRING_BUFFER_HPP
