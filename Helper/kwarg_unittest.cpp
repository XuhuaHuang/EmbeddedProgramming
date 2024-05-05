/**
 * @file kwarg_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-05-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "kwarg.hpp"

consteval inline int add(const int a, const int b) noexcept
{
    return a + b > INTMAX_MAX ? INTMAX_MAX : a + b;
}

int main(void)
{
    using namespace helper::mlcxx;
    static_assert(add(kwarg{"a"} = 1, kwarg{"b"} = 2) == 3);
    return 0;
}
