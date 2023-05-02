// clang-format off
/*****************************************************************//**
 * \file   fibonacci_series.cpp
 * \brief  Fibonacci Series - first 25 term
 * The i-th item of the series equals to the sum of previous two
 * print a new line every five numbers in console
 *
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/
// clang-format on

#include <iostream>
#include <math.h>

int main(void)
{
    int current{1}; // current = previous + secondPrevious
    int previous{1};
    int secondPrevious{1};

    std::cout << previous << " " << current << " ";

    for (int i = 3; i <= 25; i++)
    {
        current = previous + secondPrevious;
        std::cout << current << " ";

        if (i % 5 == 0)
        {
            std::cout << "\n";
        }

        secondPrevious = previous; // refresh the value in the series
        previous       = current;
    }

    return 0;
}
