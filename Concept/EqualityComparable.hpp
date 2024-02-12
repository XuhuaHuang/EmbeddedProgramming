/*****************************************************************//**
 * \file   EqualityComparable.hpp
 * \brief  Concept that requires a generic type T to support == and !=
 * 
 * \author Xuhua Huang
 * \date   January 19, 2023
 *********************************************************************/

#ifndef EQUALITYCOMPARABLE_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <concepts>

template<typename T>
concept EqualityComparable = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

#endif // !EQUALITYCOMPARABLE_HPP
