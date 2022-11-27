/*****************************************************************//**
 * \file   array.c
 * \brief  gcc -c array.c -o array.exe -Wall
 *
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return;
}

// the displayArray function defined above
// is the same as the one defined below
// int arr[] will decade to int* arr
// void displayArray(int* arr, const int size) {
//    for (int i = 0; i < size; i++) {
//        printf("%d, ", *(arr+i));
//    }
//    printf("\n");
//    return;
// }

int main(void) {
    int vector[5] = { 1, 2, 3, 4, 5 };
    displayArray(vector, 5);

    printf("With dynamic array size determination:\n");
    displayArray(vector, sizeof(vector)/sizeof(vector[0]));

    system("pause");
    return EXIT_SUCCESS;
}
