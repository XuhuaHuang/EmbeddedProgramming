/*****************************************************************//**
 * \file   Pointer_compare.cpp
 * \brief  Modified program using References in C++
 *
 * \author Xuhua Huang
 * \date   July 2021
 *********************************************************************/
#include <iostream>

void compare(int a, int b, int& addr_greater, int& addr_smaller)
{
    if (a > b)
    {
        addr_greater = a;
        addr_smaller = b;
    }
    else
    {
        addr_greater = b;
        addr_smaller = a;
    }

    return;
}

// Driver code 
int main(void)
{
    int greaterNum, smallerNum, num1, num2;

    std::cout << "Enter the first number of two to compare: ";
    std::cin >> num1;
    std::cout << "Enter the second number of two to compare: ";
    std::cin >> num2;

    // The last two arguments are passed
    // by giving addresses of memory locations
    compare(num1, num2, greaterNum, smallerNum);

    std::cout << "\nThe greater number is: " << greaterNum << "\n"
        << "The smaller number is: " << smallerNum << "\n";

    return 0;
}
