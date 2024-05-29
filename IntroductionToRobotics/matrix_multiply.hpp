/**
 * @file matrix_multiply.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-08-26
 *
 * The inner dimensions of the 2 matrices being multiplied together must match
 * The resulting matric has the shape of the outer dimensions
 *
 * Special clang-format option: BreakAfterAttributes: Always
 *
 * @copyright ueg (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_MULTIPLY_HPP
#define MATRIX_MULTIPLY_HPP

#include <array>
#include <concepts>
#include <numeric>
#include <type_traits>

#include "matrix_constraint.hpp"

#if defined(_MSC_VER)
// Microsoft Visual C++
#define INLINE inline __forceinline
#elif defined(__GNUC__) || defined(__clang__)
// GCC or Clang
#define INLINE __attribute__((always_inline)) inline
#else
// Default fallback
#define INLINE inline
#endif

/// @brief Using declaration to represent a row vector
/// @tparam T Individual element type
/// @tparam N Number of columns in the only row
template<typename T, std::size_t N>
    requires std::is_arithmetic_v<T>
using row_vector_t = std::array<std::array<T, N>, 1U>;

/// @brief Using declaration to represent a column vector
/// @tparam T Individual element type
/// @tparam N Number of rows, each row has 1 element
template<typename T, std::size_t N>
    requires std::is_arithmetic_v<T>
using col_vector_t = std::array<std::array<T, 1U>, N>;

template<typename T>
concept is_matrix_multiplicable_type = requires (T lhs, T rhs) {
    { (lhs * rhs) } -> std::convertible_to<T>;
} and std::is_arithmetic_v<T>;

/// @brief Function to multiply 2 matrices
/// @details Requires std::array of arithmetic type
///
/// @param [in] A LHS matrix of size M by N
/// @param [in] B RHS matrix of size N by P
/// @return Result matrix of size M by P
template<typename T, std::size_t M, std::size_t N, std::size_t P>
    requires is_matrix_multiplicable_type<T>
[[nodiscard]]
INLINE constexpr
    auto matrix_multiply(const std::array<std::array<T, N>, M>& A, const std::array<std::array<T, P>, N>& B)
        -> std::array<std::array<T, P>, M>;

/// @brief Function to multiply a matrix with a scalar
/// @tparam T Individual element type
/// @tparam M Number of rows
/// @tparam N Number of columns
/// @param A matrix of size M by N
/// @param scalar scalar to be multiplied with matrix A
/// @return matrix of size M by N
template<typename T, std::size_t M, std::size_t N>
    requires is_matrix_multiplicable_type<T>
[[nodiscard]]
INLINE constexpr auto matrix_multiply(const matrix_t<T, M, N>& A, const T& scalar) -> matrix_t<T, M, N>
{
    matrix_t<T, M, N> result{};
    for (std::size_t row = 0; row < M; ++row)
    {
        for (std::size_t col = 0; col < N; ++col)
        {
            result[row][col] = A[row][col] * scalar;
        }
    }
    return result;
}

/// @brief Operator * overload to multiply 2 matrices
/// @tparam T Individual element type
/// @tparam M Number of rows of the first matrix
/// @tparam N Number of columns of the first matrix, number of rows of the second matrix
/// @tparam P Number of columns of the second matrix
/// @param A LHS matrix of size M by N
/// @param B RHS matrix of size N by P
/// @return Result matrix of size M by P
template<typename T, size_t M, size_t N, size_t P>
    requires is_matrix_multiplicable_type<T>
[[nodiscard]]
inline __attribute__((always_inline)) constexpr // function attributes
    auto
    operator*(const std::array<std::array<T, N>, M>& A, const std::array<std::array<T, P>, N>& B)
        -> std::array<std::array<T, P>, M>
{
    return matrix_multiply(A, B);
}

/// @brief Alias struct to function matrix_multiply
struct matmul
{
    template<typename T, std::size_t M, std::size_t N, std::size_t P>
    [[nodiscard]]
    inline __attribute__((always_inline)) constexpr auto
    operator()(const std::array<std::array<T, N>, M>& A, const std::array<std::array<T, P>, N>& B)
        -> std::array<std::array<T, P>, M>
    {
        return matrix_multiply(A, B);
    }
};

/// @brief Using declaration alias to struct matmul
using dotprod = matmul;

/// @brief Operator << overload to print a std::array
/// @tparam T Individual element type
/// @tparam N Number of elements
/// @param os Mutable reference of output stream object
/// @param A Constant reference of a std::array object
/// @return Modified output stream object with contents concatenated
template<typename T, std::size_t N>
    requires std::is_arithmetic<T>::value
inline std::ostream& operator<<(std::ostream& os, const std::array<T, N>& A);

/// @brief Operator << overload to print a matrix to output stream
/// @tparam T Individual element type
/// @tparam M Number of rows
/// @tparam N Number of columns
/// @param os Mutable reference of output stream object
/// @param A Constant reference of an array of arrays
/// @return Modified output stream object with contents concatenated
template<typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic<T>::value
inline std::ostream& operator<<(std::ostream& os, const std::array<std::array<T, N>, M>& A);

#include "matrix_multiply.inl"

#endif // !MATRIX_MULTIPLY_HPP
