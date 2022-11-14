/*****************************************************************//**
 * \file   ternary_operator.cpp
 * \brief  Legacy ternary operator demonstration.
 *
 * g++ -c .\ternary_operator.cpp -o ternary_operator.exe
 * ./ternary_operator.exe
 *
 * \author Xuhua Huang
 * \date   March 06, 2021
 *********************************************************************/

#include <iostream>
#include <cmath>

int determineSign(int num);

int main(void)
{
    std::cout << "\nConditional Operation" << "\n";
    int x = 1, y = 3;
    int result = (y - x) > 0 ? y - x : x - y;
    std::cout << result << "\n";

    //if (y - x > 0)
    //    result = y - x;
    //else
    //    result = x - y;

    // nested conditional operation
    std::cout << "\nNested conditional operation" << "\n";
    int signX = determineSign(x);
    std::cout << signX << "\n";

    return 0;
}

int determineSign(int num)
{
    return (num > 0 ? 1 : (num < 0 ? -1 : 1)); // return +1 if positive, -1 if negative, 0 if zero
}
