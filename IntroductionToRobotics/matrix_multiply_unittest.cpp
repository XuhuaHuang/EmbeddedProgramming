// g++ matrix_multiply_unittest.cpp  -std=c++2b -o matrix_multiply_unittest -Wall -Wextra -O3
// -Wno-pragma-once-outside-header
// ./matrix_multiply_unittest
// rm matrix_multiply_unittest

// cl .\matrix_multiply_unittest.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// ./matrix_multiply_unittest
// rm matrix_multiply_unittest

#include <array>
#include <iostream>

#include "matrix_multiply.hpp"

int main()
{
    // A is a matrix of 3 by 2
    constexpr std::array<std::array<int, 2>, 3> A = {
        {{1, 2}, {3, 4}, {5, 6}}
    };
    std::cout << A << "\n";


    // B is a matrix of 2 by 3
    constexpr std::array<std::array<int, 3>, 2> B = {
        {{7, 8, 9}, {10, 11, 12}}
    };
    std::cout << B << "\n";

    // std::array<std::array<int, 3Ui64>, 3Ui64>
    // The size of the result matrix is:
    // number of row of the first matrix
    // by
    // number of column of the second matrix
    auto result = matrix_multiply(A, B);
    std::cout << result << "\n";

    // std::cout << matmul{}(A, B) << "\n";
    // std::cout << dotprod{}(A, B) << "\n";
    // std::cout << A * B << "\n";

    std::cout << typeid(result).name() << "\n";

    return 0;
}
