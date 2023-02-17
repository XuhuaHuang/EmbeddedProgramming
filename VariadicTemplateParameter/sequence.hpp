/*****************************************************************//**
 * \file   sequence.hpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   February 8, 2023
 *********************************************************************/

#include <array>
#include <iostream>

template <typename T, T... Numbers>
class sequence
{
public:
    static constexpr std::array<T, sizeof...(Numbers)> values = {Numbers...};
};

template <typename T, T... Numbers>
constexpr std::array<T, sizeof...(Numbers)> sequence<T, Numbers...>::values;
