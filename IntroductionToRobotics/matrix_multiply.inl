/**
 * @file matrix_multiply.inl
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-06-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#ifndef MATRIX_MULTIPLY_INL
#define MATRIX_MULTIPLY_INL

namespace robotics {

template <typename T, size_t M, size_t N, size_t P>
    requires is_matrix_multipliable_type<T>
constexpr inline auto
matrix_multiply(const std::array<std::array<T, N>, M>& A, const std::array<std::array<T, P>, N>& B)
    -> std::array<std::array<T, P>, M> {
    std::array<std::array<T, P>, M> result{};

    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < P; ++j) {
            result[i][j] = 0;
            for (size_t k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

/// @brief Overloaded stream insertion operator for std::array.
/// @tparam T The type of the elements in the std::array.
/// @tparam N The size of the std::array.
/// @param os The output stream to write to.
/// @param A The std::array to be printed.
/// @return std::ostream& The output stream after writing the std::array.
/// @note This function allows the elements of a std::array to be printed to an output stream.
/// The elements are enclosed in square brackets and separated by commas.
template <typename T, std::size_t N>
    requires std::is_arithmetic_v<T>
inline std::ostream& operator<<(std::ostream& os, const std::array<T, N>& A) {
    os << "[";
    if constexpr (N > 1) {
        for (std::size_t i = 0; i < N - 1; i++) {
            os << A[i] << ", ";
        }
    }
    os << A[N - 1] << "]";
    return os;
}

/// @brief Overloaded stream insertion operator for printing a 2D array (matrix) to an output stream.
/// @tparam T The type of the elements in the matrix. Must be an arithmetic type.
/// @tparam M The number of rows in the matrix.
/// @tparam N The number of columns in the matrix.
/// @param os The output stream to write the matrix to.
/// @param A The 2D array (matrix) to be printed.
/// @return The output stream after writing the matrix.
/// @note This function prints the elements of a 2D array in a matrix format, enclosed in square brackets.
/// Each row of the matrix is printed on a new line, separated by commas.
template <typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic_v<T>
inline std::ostream& operator<<(std::ostream& os, const std::array<std::array<T, N>, M>& A) {
    os << "[";
    if constexpr (M > 1) {
        for (std::size_t i = 0; i < M - 1; ++i) {
            os << A[i] << ",\n ";
        }
    }
    os << A[M - 1] << "]";
    return os;
}

} // namespace robotics

#endif // !MATRIX_MULTIPLY_INL
