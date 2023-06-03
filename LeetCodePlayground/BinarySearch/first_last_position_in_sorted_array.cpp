#include "first_last_position_in_sorted_array.hpp"
#include <iostream>
#include <vector>

auto main(void) -> int
{
    Solution         solution;
    std::vector<int> nums{5, 7, 7, 8, 8, 10};

    std::vector<int> res = solution.searchRange(nums, 6);
    std::cout << "[" << res[0] << ", " << res[1] << "]"
              << "\n";

    return EXIT_SUCCESS;
};