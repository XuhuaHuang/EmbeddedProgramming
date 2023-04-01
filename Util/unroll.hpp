/**
 * @file unroll.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef UNROLL_HPP
#define UNROLL_HPP

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif // !_TYPE_TRAITS_

namespace util
{
// immediately-invoked function expression
namespace iife
{

// clang-format off
template<auto N>
constexpr auto unroll = [](auto expr) {
    [expr]<auto... Is>(std::index_sequence<Is...>) {
        ((expr(), void(Is)), ...);
    } (std::make_index_sequence<N>{});
};

template<auto N>
constexpr auto unroll_ = [](auto expr) {
    auto [... Is] = std::make_index_sequence<N>{};
    ((expr(), void(Is)), ...);
};
// clang-format on

} // namespace iife
} // namespace util

#endif
