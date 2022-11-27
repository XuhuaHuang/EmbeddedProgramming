/*****************************************************************//**
 * \file   SupportsComparison.hpp
 * \brief  Concept that requires a generic type T to support <=>
 * 
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#ifndef SUPPORTCOMPARISON_HPP
#define SUPPORTCOMPARISON_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <concepts>

template<typename T>
concept SupportsComparison = requires (T t) { t <=> t; };

#endif
