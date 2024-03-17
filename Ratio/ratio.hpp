/**
 * @file ratio.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-03-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <ratio>

template<std::intmax_t Num1, std::intmax_t Den1, std::intmax_t Num2, std::intmax_t Den2>
consteval auto operator*(const std::ratio<Num1, Den1> r, const std::ratio<Num2, Den2> r2)
{
    return std::ratio_multiply<decltype(r), decltype(r2)>{};
}

template<std::intmax_t Num1, std::intmax_t Den1, std::intmax_t Num2, std::intmax_t Den2>
consteval bool operator==(const std::ratio<Num1, Den1> r, const std::ratio<Num2, Den2> r2)
{
    return std::ratio_equal_v<decltype(r), decltype(r2)>;
}

static_assert(std::femto{} * std::exa{} == std::kilo{});
