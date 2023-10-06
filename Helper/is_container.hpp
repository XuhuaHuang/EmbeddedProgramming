/**
 * @file is_container.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-09-29
 *
 * A naive implementation to detect a container in modern C++
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once

#ifndef IS_CONTAINER_HPP
#define IS_CONTAINER_HPP

namespace helper
{
namespace generic_container
{

template<typename T>
struct is_container {
    template<typename S>
    static std::byte f(...);

    template<typename S>
    static std::size_t f(typename S::iterator*);

    static const bool value = (sizeof(f<T>(0)) == sizeof(std::size_t));
};

} // namespace generic_container
} // namespace helper

#endif // !IS_CONTAINER_HPP
