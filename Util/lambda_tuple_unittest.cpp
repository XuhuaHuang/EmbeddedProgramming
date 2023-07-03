/**
 * @file lambda_tuple_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-06-18
 *
 * g++ -c lambda_tuple_unittest.cpp -o lambda_tuple_unittest.exe -std=c++2b -Wall -Wextra
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lambda_tuple.hpp"
#include <iostream>

int main()
{
    using util::type::get;
    using util::type::tuple;

    static_assert(1 == get<0>(tuple(1, 2, 3)));
    static_assert(2 == get<1>(tuple(1, 2, 3)));
    static_assert(3 == get<2>(tuple(1, 2, 3)));

    static_assert('a' == get<0>(tuple('a', 42, 77.)));
    static_assert(42 == get<1>(tuple('a', 42, 77.)));
    static_assert(77. == get<2>(tuple('a', 42, 77.)));

    static_assert(42 == get<int>(tuple('a', 42, 77.)));
    static_assert(77. == get<double>(tuple('a', 42, 77.)));
    static_assert('a' == get<char>(tuple('a', 42, 77.)));

    return 0;
}
