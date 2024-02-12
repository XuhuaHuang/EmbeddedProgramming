/*****************************************************************//**
 * \file   test_any_all.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 31, 2022
 *********************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>

#include "../basics.hpp"

auto main(void) -> int {
    std::vector<bool> test{ true, true, true, false };

    std::cout << std::boolalpha << util::math::any(test) << "\n";
    std::cout << std::boolalpha << util::math::all(test) << "\n";

    test.back() = true;

    std::cout << std::boolalpha << util::math::any(test) << "\n";
    std::cout << std::boolalpha << util::math::all(test) << "\n";

    system("pause");
    return EXIT_SUCCESS;
}
