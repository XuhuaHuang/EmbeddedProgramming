/**
 * @file square_table.c
 * @author Xuhua Huang
 * @brief Lookup table example using arrays.
 * @version 0.1
 * @date 2025-06-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdint.h>
#include <stdio.h>

#define TABLE_SIZE 16

// Precomputed square values for 0 to 15
// clang-format off
static const uint32_t square_table[TABLE_SIZE] = {
    0 * 0, 1 * 1, 2 * 2, 3 * 3, 4 * 4, 5 * 5, 6 * 6, 7 * 7,
    8 * 8, 9 * 9, 10 * 10, 11 * 11, 12 * 12, 13 * 13, 14 * 14, 15 * 15
};
// clang-format on

uint32_t get_square(uint8_t value) {
    if (value < TABLE_SIZE) {
        return square_table[value];
    } else {
        // Handle out-of-bound index appropriately
        return UINT32_MAX;
    }
}

int main(void) {
    for (uint8_t i = 0; i < TABLE_SIZE; ++i) {
        printf("Square of %u is %u\n", i, get_square(i));
    }
    return 0;
}
