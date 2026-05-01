// clang-format off
/*****************************************************************//**
 * \file   Fibonacci.hpp
 * \brief  Struct definition for Fibonacci series.
 * 
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/
// clang-format on

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <cstddef>

template <std::size_t N>
struct Fibonacci {
  static constexpr std::size_t value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
  static constexpr std::size_t value = 0;
};

template <>
struct Fibonacci<1> {
  static constexpr std::size_t value = 1;
};

#endif
