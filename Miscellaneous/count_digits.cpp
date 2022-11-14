/*****************************************************************//**
 * \file   fun_count_digits.cpp
 * \brief  contains function definition and calling
 *		   to count the number of digits in an integer
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <iostream>
using namespace std;

size_t numDigits(int number);

int main(void)
{
    for (int i = 0; i <= 100; ++i) {
        std::cout << "The number of digit of number " << i << " is: " << numDigits(i) << "\n";
    }

    std::cout << "\nSingle calling.\nThe number of digit of number 20 is: " << numDigits(20) << "\n";
    return 0;
}

size_t numDigits(int number)
{
    std::size_t digitsCount = 1;
    while ((number /= 10) != 0) { ++digitsCount; }

    return digitsCount;
}
