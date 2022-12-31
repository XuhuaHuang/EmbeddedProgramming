/*****************************************************************//**
 * \file   two_dims_array.cpp
 * \brief  example on how to work with 2D array/vector
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <array>
#include <vector>
#include <iostream>

int main(void)
{
    std::cout << "\nCreating a multidimentional array" << "\n"
        << "which groups 1-12 in groups of 3" << "\n"
        << "printint the 2D array with nested for loops.\n" << "\n";

    int data1[][4] = // [][4] is required to specify 4 grouped elements
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << data1[row][col] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\nCreating a multidimentional vector" << "\n"
        << "it will also be printed wirh nested for loops." << "\n";

    std::vector<std::vector<int>> data2 =
    {
        {13, 14, 15},
        {16, 17, 18},
        {19, 20, 21},
        {22, 23, 24}
    };

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << data2[row][col] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
