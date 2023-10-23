/// @file matrix_transpose_unittest.cpp
// g++ matrix_transpose_unittest.cpp -std=c++2b -o matrix_transpose_unittest -Wall -Wextra -O3
// -Wno-pragma-once-outside-header
// ./matrix_transpose_unittest
// rm matrix_transpose_unittest

#include <array>
#include <iostream>
#include <type_traits>

#include "matrix_multiply.hpp"
#include "matrix_transpose.hpp"

int main()
{
    constexpr std::array<std::array<float, 3U>, 3U> A = {
        {{1.0F, 2.0F, 3.0F}, {4.0F, 5.0F, 6.0F}, {7.0F, 8.0F, 9.0F}}
    };
    constexpr auto A_T = matrix_transpose(A);

    std::cout << A_T << "\n";
    // std::cout << typeid(A_T).name() << "\n";

    constexpr std::array<std::array<float, 4>, 3> B = {
        {{1.0F, 4.0F, 7.0F, 10.0F}, {2.0F, 5.0F, 8.0F, 11.0F}, {3.0F, 6.0F, 9.0F, 12.0F}}
    };
    constexpr auto B_T = matrix_transpose(B);
    std::cout << __LINE__ << std::boolalpha << " "
              << std::is_same<decltype(B_T), std::array<std::array<float, 3>, 4>>::value << "\n";

    std::cout << B_T << "\n";
    // std::cout << typeid(B_T).name() << "\n";

    return 0;
}
