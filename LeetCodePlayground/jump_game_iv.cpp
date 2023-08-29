#include "jump_game_iv.hpp"

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int main(int argc, const char** argv)
{
    std::vector<int> arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    // std::vector<int> arr{7, 6, 9, 6, 9, 6, 9, 7};
    Solution  solution;
    const int result = solution.minJumps(arr);

    arr              = {7, 6, 9, 6, 9, 6, 9, 7};
    result           = solution.minJumps(arr);

    std::cout << result << "\n";
    return EXIT_SUCCESS;
}
