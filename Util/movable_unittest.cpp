/**
 * @file movable_unittest.cpp
 * @author Xuhua Huang
 * @brief
 *
 * g++ -c movable_unittest.cpp -o movable_unittest.exe -std=c++2b -Wall -Wextra
 *
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "movable.hpp"
#include <concepts>

int main()
{
    using namespace util::type_safety;

    static_assert(not std::movable<not_movable>);
    static_assert(std::movable<movable>);

    static_assert(not std::copyable<not_copyable>);
    static_assert(std::copyable<copyable>);

    static_assert(not std::semiregular<not_semiregular>);
    static_assert(std::semiregular<semiregular>);

    static_assert(not std::regular<not_regular>);
    static_assert(std::regular<regular>);

    return 0;
}
