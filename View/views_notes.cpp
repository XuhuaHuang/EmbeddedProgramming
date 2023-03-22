/**
 * @file views_notes.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-14
 *
 * @copyright ueg (c) 2023
 *
 */

#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    // generate a view of values from 1 to 5 (inclusive)
    std::ranges::iota_view<int, int> values = std::views::iota(1, 6);

    std::cout << typeid(values).name() << "\n"; // class std::ranges::iota_view<int,int>

    // iterate over the values and print them
    for (auto value : values)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";

    // generate a view of even numbers from 2 to 10 (inclusive)
    auto even_numbers = std::views::iota(2, 11) | std::views::filter([](int x) { return x % 2 == 0; });

    // iterate over the even numbers and print them
    for (auto even_number : even_numbers)
    {
        std::cout << even_number << " ";
    }
    std::cout << "\n";

    return 0;
}
