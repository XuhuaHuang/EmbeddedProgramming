/*****************************************************************//**
 * \file   matrix.c
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int matrix[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 5; col++) {
            printf("matrix[%d][%d] Address: %p Value: %d\n",
            row, col,
            &matrix[row][col],
            matrix[row][col]);
        }
    }
    return EXIT_SUCCESS;
}
