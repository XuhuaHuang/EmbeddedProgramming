/**
 * @file matrix_transpose.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-08-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_TRANSPOSE_HPP
#define MATRIX_TRANSPOSE_HPP

#include <array>
#include <concepts>

/// @brief Function to transpose 1 matrix
/// @tparam T Individual element type
/// @tparam M Number of rows of the input matrix
/// @tparam N Number of columns of the input matrix
/// @param A Input matrix of size M by N
/// @return Result matrix of size N by M
template<typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic_v<T> && std::is_copy_assignable_v<T>
[[nodiscard]]
inline __attribute__((always_inline)) constexpr // function attributes
    auto matrix_transpose(const std::array<std::array<T, N>, M>& matrix) -> std::array<std::array<T, M>, N>;

#include "matrix_transpose.inl"

#endif // !MATRIX_TRANSPOSE_HPP
