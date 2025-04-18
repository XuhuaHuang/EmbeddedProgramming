/**
 * @file with_array.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-06-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <array>
#include <iostream>

int main() {
    std::array arr{1, 2, 3};

    const auto [a, b, c] = arr;

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";

    for (auto& [index, value] : {
             std::pair{0, arr[0]},
             std::pair{1, arr[1]},
             std::pair{2, arr[2]}
    }) {
        std::cout << "Index: " << index << ", Value: " << value << "\n";
    }

    return 0;
}
