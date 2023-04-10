/*****************************************************************//**
 * \file   main.cpp
 * \brief  https://en.cppreference.com/w/cpp/language/parameter_pack
 * 
 * \author Xuhua Huang
 * \date   February 7, 2023
 *********************************************************************/

#include <iostream>
#include "sequence.hpp"

using fibonacci = sequence<int, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34>;

auto main(void) -> int
{
    for (const int i : fibonacci::values)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return EXIT_SUCCESS;
}
