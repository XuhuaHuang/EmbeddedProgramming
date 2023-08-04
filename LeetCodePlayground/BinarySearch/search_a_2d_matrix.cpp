/* clang-format off */
/*****************************************************************//**
 * \file   search_a_2d_matrix_exec.cpp
 * \brief  Xuhua Huang
 * 
 * \author Xuhua Huang
 * \date   March 07, 2023
 *********************************************************************/
/* clang-format on */

#include <iostream>
#include <vector>

#include "search_a_2d_matrix.hpp"

auto main(void) -> int
{
    std::vector<std::vector<int>> matrix = {
        {1,  3,  5,  7 },
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target  = 3;

    bool result = Solution::searchMatrix(matrix, target);
    std::cout << std::boolalpha << result << "\n";

    target = 13;
    result = Solution::searchMatrix(matrix, target);
    std::cout << std::boolalpha << result << "\n";

    return EXIT_SUCCESS;
}
