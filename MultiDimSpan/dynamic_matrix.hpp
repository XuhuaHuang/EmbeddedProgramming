/**
 * @file dynamic_matrix.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-07
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef DYNAMIC_MATRIX_HPP
#define DYNAMIC_MATRIX_HPP

#include <vector>

template <typename T>
struct dynamic_matrix {
    std::vector<T> data;
    std::size_t    rows, cols;

    dynamic_matrix(std::size_t r, std::size_t c)
        : data(r * c)
        , rows(r)
        , cols(c) {}

    T& operator()(std::size_t i, std::size_t j) { return data[i * cols + j]; }

    const T& operator()(std::size_t i, std::size_t j) const { return data[i * cols + j]; }

    std::size_t num_rows() const { return rows; }

    std::size_t num_cols() const { return cols; }
};

#endif // !DYNAMIC_MATRIX_HPP
