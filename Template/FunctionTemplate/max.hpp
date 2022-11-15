/*****************************************************************//**
 * \file   main.hpp
 * \brief  Usually the definition of a templated function is provided
 * in the same header file, instead of a separate translation unit.
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#ifndef MAX_HPP
#define MAX_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <concepts>

/**
* This function definition has 2 implicit requirements of genric type T:
* 1. it has the comparison operator overloaded
* 2. it is copiable, since we are passing and returning by value
*/
// template<typename T>
// T max(T a, T b) {
//     return b < a ? a : b;
// }

template<typename T>
concept SupportsLessThan = requires (T t) { t < t; };

/* Adding explicit constraint for T */
template<typename T>
requires std::copyable<T> && SupportsLessThan<T>
T max(T a, T b) {
    return b < a ? a : b;
}

#endif
