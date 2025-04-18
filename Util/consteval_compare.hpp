#pragma once

namespace util {

template <auto LHS, auto RHS>
constexpr inline bool equal = LHS == RHS;
template <auto LHS, auto RHS>
constexpr inline bool not_equal = LHS != RHS;

template <auto LHS, auto RHS>
constexpr inline bool less = LHS < RHS;
template <auto LHS, auto RHS>
constexpr inline bool less_or_equal = LHS <= RHS;

template <auto LHS, auto RHS>
constexpr inline bool greater = LHS > RHS;
template <auto LHS, auto RHS>
constexpr inline bool greater_or_equal = LHS >= RHS;

} // namespace util
