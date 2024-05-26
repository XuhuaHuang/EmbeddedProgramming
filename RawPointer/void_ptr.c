/*****************************************************************//**
 * \file   void_ptr.c
 * \brief  Let's look into the void!
 * 
 * (void*) are strictly pointers, but without type information.
 * They are simply 8-byte pointers on a 64-bit machine pointing to memory addresses.
 * It's the same type that malloc(), calloc(), realloc() and reallocarray() returns.
 * Without type information, pointer arithmetic are undefined.
 * 
 * \author Xuhua Huang
 * \date   December 08, 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    void* vp;
    int* ip;

    /* print out the size of pointers */
    printf("sizeof(void*) -> %zu\n", sizeof(vp));
    printf("sizeof(int*) -> %zu\n", sizeof(ip));

    int x = 0xFEEDBEEF;
    ip = &x;
    vp = ip;

    /* print out the address of both p and ip */
    printf("vp -> %p\n", vp);
    printf("ip -> %p\n", ip);

    /* dereference the int* and assign it a new value */
    *ip = 0x00C0FFEE;
    //*p = 0xDEADBEEF; // void is not assignable. no type information
    *(int*)vp = 0xDEADBEEF; // this assignment will overwrite the 0xCOFFEE assignment
    // because both *p and *ip point to the same address
    // therefore, they both read the latest assignment

    /* print out hexadecimal value */
    printf("vp -> %p, with value of %x\n", vp, *(int*)vp);
    printf("ip -> %p with value of %x\n", ip, *ip);

    /* c and cpp differ with the following lines */
    // int* ip2 = malloc(sizeof(int)); // error in cpp, requires explicit conversion
    // prefer the explicit conversion for portability and readability
    int *ip2 = (int*)malloc(sizeof(int));
    free(ip2);

    system("pause");
    return EXIT_SUCCESS;
}
