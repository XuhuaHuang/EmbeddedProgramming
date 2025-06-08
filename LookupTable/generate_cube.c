/**
 * @file generate_cube.c
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t (*lut_fn_t)(uint32_t);

/**
 * @brief Generate a lookup table (LUT) for a given function.
 *
 * @param size Size of the LUT.
 * @param func Function to compute LUT values.
 * @return uint32_t* Pointer to the generated LUT or NULL on failure.
 */
uint32_t* generate_lut(size_t size, lut_fn_t func) {
    uint32_t* table = malloc(size * sizeof(uint32_t));
    if (table == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        table[i] = func(i);
    }
    return table;
}

/**
 * @brief Compute the cube of a number.
 *
 * @param x Input number.
 * @return uint32_t Cube of the input number.
 */
uint32_t cube(uint32_t x) {
    return x * x * x;
}

int main(void) {
    size_t    size       = 10;
    uint32_t* cube_table = generate_lut(size, cube);

    if (cube_table) {
        for (size_t i = 0; i < size; ++i) {
            printf("Cube of %zu is %u\n", i, cube_table[i]);
        }
        free(cube_table);
    }

    return 0;
}
