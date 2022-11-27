/*****************************************************************//**
 * \file   is_something.cpp
 * \brief  Use cases of is_ functions in the type_traits library.
 * 
 * $ g++ -c ./is_something.cpp -o ./is_something.exe -std=c++2a
 * $ ./is_something.exe
 * 
 * \author Xuhua Huang
 * \date   November 25, 2022
 *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <type_traits>

// variable template
// to provide shorter access to value
template<char c>
constexpr bool is_digit = (c >='0' && c <= '9');

auto main(void) -> int {
    // compile-time assertions
    static_assert(std::is_integral<int>::value);
    static_assert(!std::is_integral<float>::value);
    static_assert(std::is_floating_point<double>::value);
    static_assert(std::is_class<struct Point>::value);
    static_assert(!std::is_same<int, long>::value);

    static_assert(!is_digit<'x'>);
    static_assert(is_digit<'0'>);

    static_assert(std::is_same_v<typename std::remove_const<const int>::type, int>);
    static_assert(std::is_same_v<typename std::remove_const<int>::type, int>);
    static_assert(std::is_same_v<typename std::add_const<int>::type, const int>);
    static_assert(std::is_same_v<typename std::add_pointer<int**>::type, int***>);
    static_assert(std::is_same_v<typename std::decay<int[3][4]>::type, int(*)[4]>);

    return EXIT_SUCCESS;
}
