/*****************************************************************//**
 * \file   test_print_range.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "print_range.hpp"

auto main(void) -> int {

    // std::vector<std::vector<int>> x{
    //     std::vector<int> {3, 1, 1, 4},
    //     std::vector<int> {5, -3, 2, 1},
    //     std::vector<int> {6, 2, -9, 5},
    // };
    std::vector<int> x{ 6, 2, -9, 5 };
    util::range::print_range(x, true);
    std::cout << "\n";

    std::string_view s{ "hello" };
    util::range::print_range(s, true);
    std::cout << "\n";

    util::range::print_range(std::string_view { "world" }, true);
    std::cout << "\n";

    system("pause");
    return EXIT_SUCCESS;
}
