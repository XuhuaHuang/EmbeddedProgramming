/*****************************************************************//**
 * \file   spilt_three_digits.cpp
 * \brief  g++ spilt_three_digits.cpp -o spilt_three_digits.exe
 * ./spilt_three_digits.exe
 *
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/

#include <iostream>
#include <cmath>

int main(void)
{
    int threeDigit;
    std::cout << "Please enter a three digit number: ";
    std::cin >> threeDigit;

    std::cout << "The most significant digit is: " << threeDigit / 100 << "\n";
    std::cout << "The digit at the middle is: " << (threeDigit % 100) / 10 << "\n";
    std::cout << "THe least significant digit is: " << threeDigit % 10 << "\n";

    return 0;
}
