/**
 * @file print_range_exec.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-30
 *
 * cl .\print_range_exec.cpp /std:c++latest /EHsc
 * .\print_range_exec.exe
 *
 * @copyright ueg (c) 2023
 *
 */

#include "print_range.inl"
#include <vector>

auto main() -> int
{
    std::vector<std::vector<int>> v{
        {1, 2, 3},
        {2, 4, 6},
        {3, 6, 9}
    };
    // [[1,2,3],[2,4,6],[3,6,9]]
    util::range::print_range(v);
    return 0;
}
