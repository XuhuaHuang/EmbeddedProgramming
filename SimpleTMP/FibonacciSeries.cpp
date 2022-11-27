/*****************************************************************//**
 * \file   FibonacciSeries.cpp
 * \brief  Using variadic template to implement a series generator.
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <iostream>
#include <limits>

/**
 * Generic template and first 2 element specialization.
 * Compile-time calculation with constexpr.
 */
template<size_t N>
constexpr size_t fibonacci = fibonacci<N-1> + fibonacci<N-2>;

// create template specialization for the first and second element
template<>
constexpr size_t fibonacci<0> = 0;

template<>
constexpr size_t fibonacci<1> = 1;

/**
 * Determine the ratio of 2 sequential element in the series.
 * First 3 element are excluded
 */
template<size_t N>
constexpr double golden_ratio = fibonacci<N+1> * 1.0 / fibonacci<N>;

auto main(void) -> int {
    std::cout << "fibonacci<10>: " << fibonacci<10> << "\n";

    std::cout.precision(std::numeric_limits<double>::max_digits10);
    std::cout << "golden_ratio<20>: " << golden_ratio<20> << "\n";
    std::cout << "golden_ratio<50>: " << golden_ratio<50> << "\n";

    return EXIT_SUCCESS;
}
