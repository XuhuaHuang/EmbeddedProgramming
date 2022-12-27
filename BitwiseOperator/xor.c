/*****************************************************************//**
 * \file   xor.c
 * \brief  Exclusive or operator in C.
 * 
 * If 2 bits are the same, the output is 0;
 * if 2 bits are different, the output is 1.
 * 
 * \author Xuhua Huang
 * \date   December 08, 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int x = 888;
    int y = 234;

    printf("Before swapping with xor operator, x = %d, y = %d\n", x, y);

    /* use xor operator to swap 2 numbers without introducing a temperary variable */
    x ^= y;
    y ^= x;
    x ^= y;

    printf("Done swapping with xor operator, x = %d, y = %d\n", x, y);

    int a = 0b101110;
    int b = 0b110000;
    // a^b: 0b011110
    a ^= b; // a = a ^ b; a = 0b011110;
    b ^= a; // b = b ^ a; b = 0b110000 ^ 0b011110 = 0b101110
    a ^= b; // a = a ^ b; a = 0b011110 ^ 0b101110 = 0b110000

    system("pause");
    return EXIT_SUCCESS;
}
