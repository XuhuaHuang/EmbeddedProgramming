/**
 * @file multi_array.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <boost/multi_array.hpp>
#include <iostream>

int main()
{
    // define the shape of the tensor (3D)
    const int d1   = 2;
    const int d2   = 3;
    const int d3   = 4;

    // create the tensor
    // 3 dimensional array
    // constructs of multiple two-dimensional array
    // in this case, 2 (d1) of 2D array of 3 (d2) rows by 4 (d3) columns
    using tensor_t = boost::multi_array<double, 3>;
    tensor_t tensor(boost::extents[d1][d2][d3]);

    // fill the tensor with some values
    for (int i = 0; i < d1; ++i)
    {
        for (int j = 0; j < d2; ++j)
        {
            for (int k = 0; k < d3; ++k)
            {
                tensor[i][j][k] = i * j * k;
            }
        }
    }

    // print the tensor
    for (int i = 0; i < d1; ++i)
    {
        for (int j = 0; j < d2; ++j)
        {
            for (int k = 0; k < d3; ++k)
            {
                std::cout << tensor[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
