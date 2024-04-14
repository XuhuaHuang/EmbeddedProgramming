/**
 * @file as_const.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-04-14
 *
 * https://en.cppreference.com/w/cpp/utility/as_const
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AS_CONST_HPP
#define AS_CONST_HPP

namespace util
{
namespace type_safety
{

template<typename T>
constexpr inline const T& as_const(const T& t) noexcept
{
    return t;
}

} // namespace type_safety
} // namespace util

#endif // !AS_CONST_HPP
