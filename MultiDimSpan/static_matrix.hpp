/**
 * @file static_matrix.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-07
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#ifndef STATIC_MATRIX_HPP
#define STATIC_MATRIX_HPP

#include <array>

template <typename T, std::size_t M, std::size_t N>
struct static_matrix {

    /// @brief Underlying data storage
    std::array<T, M * N> data;

    /// @brief Access element at (i, j)
    constexpr T& operator()(std::size_t i, std::size_t j) {
        return data[i * N + j];
    }

    /// @brief Access element at (i, j) (const version)
    constexpr const T& operator()(std::size_t i, std::size_t j) const {
        return data[i * N + j];
    }

    /// @brief Get number of rows
    constexpr std::size_t rows() const {
        return M;
    }

    /// @brief Get number of columns
    constexpr std::size_t cols() const {
        return N;
    }
};

#endif // !STATIC_MATRIX_HPP
