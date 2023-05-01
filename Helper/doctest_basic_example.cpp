// cl .\doctest_basic_example.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// .\doctest_basic_example.exe

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include <iostream>
#include <vector>

consteval int factorial(int number)
{
    static_assert(std::is_constant_evaluated());
    return number <= 1 ? number : factorial(number - 1) * number;
}

