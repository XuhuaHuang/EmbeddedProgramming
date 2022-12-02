/*****************************************************************//**
 * \file   Fibonacci.hpp
 * \brief  Struct definition for Fibonacci series.
 * 
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

template<size_t N>
struct Fibonacci {
    constexpr static size_t value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0> {
    constexpr static size_t value = 0;
};

template<>
struct Fibonacci<1> {
    constexpr static size_t value = 1;
};

#endif
