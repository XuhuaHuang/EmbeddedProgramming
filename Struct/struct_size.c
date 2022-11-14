/**
 * @file struct_size.c
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Exploring the size of a customized struct in C.
 * 
 * Command to compile and run on Windows:
 * $ gcc -o structSize.exe .\struct_size.c
 * $ .\structSize
 * 
 * @version 0.1
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#pragma pack(1)
/* Explicitly tell the compiler NOT to insert padding into structs. */

#define NAME_LENGTH 60

typedef struct {                /* Memory allocation example */
    uint8_t age;                /* FDD0; start of the struct */
    uint16_t height_in_cm;      /* FDD1; age occupied 8 bits (1 byte) */
    char name[NAME_LENGTH];     /* FDD3; height_in_cm occupied 16 bits (2 bytes) */
    uint16_t chess_score;       /* FE0F; FE0F - FDD3 = 3C (60) -> length of name */
    uint8_t weight;             /* FE11; chess_score occupied 16 bits (2 bytes)  */

} person_t;

int main(void) {
    printf("The size of the defined struct person_t is %llu bytes.\n", sizeof(person_t));
    /* Expecting 66 bytes; but the compiler adds extra padding to make the code run faster. */

    /* Print the address of the attributes with %p format specifier. */
    person_t p;
    printf("&age: %p\n", &(p.age));
    printf("&height_in_cm: %p\n", &(p.height_in_cm));
    printf("&name: %p\n", &(p.name));
    printf("&chess_score: %p\n", &(p.chess_score));
    printf("&weight: %p\n", &(p.weight));

    system("pause");
    return 0;
}