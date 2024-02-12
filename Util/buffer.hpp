/**
 * @file buffer.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-02-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string_view>

namespace util
{
namespace data_structure
{

template<auto N>
struct buffer
{
    constexpr buffer() {}
    constexpr char const* begin() const { return data; }
    constexpr char const* end() const { return data + N; }
    constexpr operator std::basic_string_view<char>() const { return std::basic_string_view<char>(begin(), end()); }

    char      data[N]{};
};

constexpr buffer<42> b;
static_assert(42 == std::string_view{b}.size());
static_assert(&b.data[0] == std::string_view{b}.begin());
static_assert(&b.data[42] == std::string_view{b}.end());

} // namespace data_structure
} // namespace util

#endif // !BUFFER_HPP
