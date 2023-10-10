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

/**
 * @brief A container of type C is a type that can be iterated with range-based for loop if:
 * std::begin(C&) returns begin iterator
 * std::end(C&) return tail iterator
 * begin iterator and tail iterator are comparable with !=
 * std::next can be used on a begin iterator
 * begin iterator has * operator and isn't void
 * begin iterator and tail iterator are copy constructible and destructible
 */

template<typename C>
using TBegin = decltype(std::begin(std::declval<C&>()));

template<typename C>
using TEnd = decltype(std::end(std::declval<C&>()));

template<typename BeginIter, typename EndIter>
using TNotEqual = decltype(std::declval<BeginIter>() != std::declval<EndIter>());

template<typename BeginIter>
using TInc = decltype(std::next(std::declval<BeginIter>()));

template<typename BeginIter>
using TDeref = decltype(*std::declval<BeginIter>());

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
