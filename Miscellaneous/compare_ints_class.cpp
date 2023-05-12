// clang-format off
/*****************************************************************//**
 * \file   compare_ints_class.cpp
 * \brief  Modified program using class - C++ only
 *
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/
// clang-format on

#include <iostream>

class GreaterSmaller
{
public:
    int greater, smaller;
};

// function takes two integers value and returns an object of class "GreaterSmaller"
GreaterSmaller findGreaterSmaller(int a, int b)
{
    GreaterSmaller result{};
    if (a > b)
    {
        result.greater = a;
        result.smaller = b;
    }
    else
    {
        result.greater = b;
        result.smaller = a;
    }

    return result;
}

// Driver code
int main()
{
    int num1, num2;

    std::cout << "Enter the first number of two to compare: ";
    std::cin >> num1;
    std::cout << "Enter the second number of two to compare: ";
    std::cin >> num2;

    // calling function
    // arguments: int, int
    // return type: GreaterSmaller
    GreaterSmaller result = findGreaterSmaller(num1, num2);

    // 'greater' and 'smaller' are public variable inside of class 'GreaterSmaller'
    std::cout << "\nThe greater number is: " << result.greater << "\n"
              << "The smaller number is: " << result.smaller << "\n";

    return 0;
}
