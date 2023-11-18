/**
 * @file matrix_determinant.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * Recall that for any matrix A, det(A Transposed) == det(A)
 * the determinant of A is equal to the determinant of its transpose.
 *
 * For any matrices A and B that can multiplied, det(AB) == det(A)det(B).
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_DETERMINANT_HPP
#define MATRIX_DETERMINANT_HPP

#include <array>
#include <concepts>
#include <type_traits>

template<typename T>
[[nodiscard]]
inline constexpr T det(const matrix_t<T, 1, 1>& M) noexcept
{
    return M[0][0];
}

#endif // !MATRIX_DETERMINANT_HPP
