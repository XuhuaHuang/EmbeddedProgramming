/*****************************************************************//**
 * \file   fibonacci_series.cpp
 * \brief  Fibonacci Series - first 25 term
 * The i-th item of the series equals to the sum of previous two
 * print a new line every five numbers in console
 *
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
    int current; // currentTerm = previous + SecondPrevious
    int previous;
    int secondPrevious;

    current = previous = secondPrevious = 1;
    std::cout << previous << " " << current << " ";

    for (int i = 3; i <= 25; i++)
    {
        current = previous + secondPrevious;
        std::cout << current << " ";

        if (i % 5 == 0)
            std::cout << "\n";

        secondPrevious = previous; // refresh the value in the series
        previous = current;
    }

    return 0;
}
