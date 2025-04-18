/**
 * @file matrix_size.hpp
 * @author Xuhua Huang
 * @brief
 *
 * g++ matrix_size.hpp -std=c++2b -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 *
 * @version 0.1
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_SIZE_HPP
#define MATRIX_SIZE_HPP

#include <array>
#include <concepts>
#include <tuple>

namespace robotics {

/// @brief Alias struct to std::tuple of std::size_t
using size = std::tuple<std::size_t, std::size_t>;

/// @brief Function to return the size of matrix
/// @tparam T Individual element type
/// @tparam M Number of rows of the input matrix
/// @tparam N Number of columns of the input matrix
/// @param matrix Input matrix of size M by N
/// @return Object of size
template <typename T, std::size_t M, std::size_t N>
    requires std::is_arithmetic_v<T> && std::is_copy_assignable_v<T>
[[nodiscard]]
constexpr auto matrix_size(const std::array<std::array<T, N>, M>&) -> size {
    return std::make_tuple{M, N};
}

/// @brief Operator << overload to print a matrix size object to output stream
/// @param os Mutable reference of output stream object
/// @param s Constant reference of size object
/// @return Modified output stream object with contents concatenated
inline std::ostream& operator<<(std::ostream& os, const size& s) {
    os << "size [";
    os << std::get<0>(s) << ", " << std::get<1>(s);
    os << "]";
    return os;
}

} // namespace robotics

#endif
