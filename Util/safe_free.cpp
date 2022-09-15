/*****************************************************************//**
 * \file   safe_free.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <Util\safe_free.hpp>

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
    return (EXIT_SUCCESS);
}
