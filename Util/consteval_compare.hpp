#pragma once

namespace util
{

template<auto LHS, auto RHS>
inline constexpr bool equal = LHS == RHS;
template<auto LHS, auto RHS>
inline constexpr bool not_equal = LHS != RHS;

template<auto LHS, auto RHS>
inline constexpr bool less = LHS < RHS;
template<auto LHS, auto RHS>
inline constexpr bool less_or_equal = LHS <= RHS;

template<auto LHS, auto RHS>
inline constexpr bool greater = LHS > RHS;
template<auto LHS, auto RHS>
inline constexpr bool greater_or_equal = LHS >= RHS;

} // namespace util
