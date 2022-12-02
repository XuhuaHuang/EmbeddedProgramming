/*****************************************************************//**
 * \file   SupportsHashFunction.hpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 02, 2022
 *********************************************************************/

#ifndef SUPPORTHASHFUNCTION_HPP
#define SUPPORTHASHFUNCTION_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <concepts>

/* Templated concept to determine whether can call hash function on an object. */
template<typename T>
concept SupportsHashFunction = requires(T t) {
    { std::hash<T>{}(t) } -> std::convertible_to<std::size_t>;
};

#endif
