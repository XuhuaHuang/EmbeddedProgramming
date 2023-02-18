/*****************************************************************//**
 * \file   ranges_notes.cpp
 * \brief  Demonstration of ranges and views in C++ 20.
 * 
 * $ g++ ranges_notes.cpp -o exec -std=c++20 -Wall -Wextra -Wpedantic
 * $ ./exec
 * 
 * $ cl .\ranges_notes.cpp /EHsc /std:c++20
 * $ .\ranges_notes.exe
 * 
 * \author Xuhua Huang
 * \date   March 2022
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <ranges>

// #include "Util/print_range.hpp"
// util::range::print_range()

int main()
{
    std::vector<std::int16_t> vec { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    constexpr auto is_even = [&](int elem) -> bool { return elem % 2 == 0; };
    constexpr auto square = [&](int elem) -> int { return elem * elem; };

    /* with std::views::filter */
    auto even_nums = vec | std::views::filter(is_even);
    // view on stack with adapter
    for (const int16_t& i : even_nums) {
       std::cout << i << " ";
    }
    std::cout << "\n"
       << "End execution with " << std::quoted("std::views::filter(is_even)") << "\n";

    /* with std::ranges::filter_view */
    for (const int16_t& i : std::ranges::filter_view(vec, is_even)) {
       std::cout << i << " ";
    }
    std::cout << "\n"
       << "End execution with " << std::quoted("std::ranges::filter_view(vec, is_even)") << "\n";

    /* with std::views::transform */
    auto even_nums_squared = even_nums | std::views::transform(square);
    // view on range-for loop
    for (const int16_t& i : even_nums_squared) {
       std::cout << i << " ";
    }
    std::cout << "\n"
       << "End execution with " << std::quoted("std::views::transform(square)") << "\n";

    /* pipelining syntax */
    auto output = vec
       | std::views::filter(is_even)
       | std::views::transform(square);
    // view on range-for loop
    for (const int16_t& i : output) {
       std::cout << i << " ";
    }
    std::cout << "\n"
       << "End execution with pipeline syntax" << "\n";

    return 0;
}
