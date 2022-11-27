/*****************************************************************//**
 * \file   test_safe_free.cpp
 * \brief  Demonstration of library code in ".\util\safe_free.hpp"
 * 
 * To compile and run this file on Windows:
 * $ g++ -o test_safe_free.exe .\test_safe_free.cpp -std=c++11
 * $ .\test_safe_free.exe
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "safe_free.hpp"

int main(void)
{
    int* pi;
    pi = (int*)malloc(sizeof(int));
    *pi = 5;
    printf("Before: %p.\n", pi);
    util::pointer::safe_free((void**)&(pi));

    printf("After: %p.\n", pi);
    util::pointer::safe_free((void**)&(pi));

    system("pause");
    return EXIT_SUCCESS;
}
