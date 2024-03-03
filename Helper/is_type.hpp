/**
 * @file is_type.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-02-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#ifndef IS_TYPE_HPP
#define IS_TYPE_HPP

namespace helper
{

template<typename C, typename X>
auto is(X const&) -> std::false_type
{
    return {};
}

template<typename C, std::same_as<C> X>
constexpr auto is(X const&) -> std::true_type
{
    return {};
}

// template<typename C, inherited_from<C> X>
// constexpr auto is(X const&) -> std::true_type
// {
//     return {};
// }

// template<polymorphic C, polymorphic X>
//     requires std::same_as<C, X>
// constexpr auto is(X const&) -> std::true_type
// {
//     return {};
// }

template<typename C, typename X>
    requires (!std::same_as<C, X> && !std::is_base_of<C, X> && !(std::is_polymorphic_v<C> && std::is_polymorphic_v<X>))
auto is(X const&) -> std::false_type
{
    return {};
}
template<typename C, typename X>
    requires (std::is_base_of<C, X>)
auto is(X const&) -> std::true_type
{
    return {};
}

} // namespace helper

#endif // !IS_TYPE_HPP
