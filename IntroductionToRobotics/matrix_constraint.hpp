/**
 * @file matrix_constraint.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-08-27
 *
 * $ g++ matrix_constraint.hpp -std=c++2b -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_CONSTRAINT_HPP
#define MATRIX_CONSTRAINT_HPP

#include <array>
#include <concepts>

template<typename T, std::size_t M, std::size_t N>
concept matrix = requires (std::array<std::array<T, N>, M> matrix) {
    {
        matrix.size()
    } -> std::convertible_to<size_t>;
    {
        matrix[0].size()
    } -> std::convertible_to<size_t>;
};

#endif // !MATRIX_CONSTRAINT_HPP
