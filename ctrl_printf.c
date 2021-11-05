/**
 * @file ctrl_printf.c
 * @author Xuhua Huang (xuhuahuang0412@gmail.com)
 * @brief Demonstration of conversion specification with printf() function in C.
 * @version 0.1
 * @date 2021-11-02
 * Command used to compile:
 * $ gcc -o ctrlPrint.exe .\ctrl_printf.c
 * $ .\ctrlPrint.exe
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    unsigned width;
    int number = 256;
    /* ask user for field width. */
    printf("Please enter fileld width: ");
    scanf("%d", &width);
    printf("The number is: %*d", width, number);

    unsigned precision;
    double weight = 242.66;
    /* number of digits before and after the decimal points. */
    printf("\nNow please enter a width and precision: ");
    scanf("%d %d", &width, &precision);
    printf("Weight = %*.*f\n", width, precision, weight);

    printf("Done\n");

    system("pause");
    return 0;
}