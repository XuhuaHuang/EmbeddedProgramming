/**
 * @file constexpr_for.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright ueg (c) 2023
 *
 */

#include <iostream>

constexpr int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

constexpr int f = factorial(5);

int main()
{
    static_assert(f == 120, "Factorial of 5 should be 120");
    return 0;
}
