/*****************************************************************//**
 * \file   reverse_digits.cpp
 * \brief  g++ reverse_digits.cpp -o reverse_digits.exe
 * ./reverse_digits.exe
 *
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/

#include <cmath>
#include <iostream>

int main(void)
{
    int value = 0;
    std::cout << "Reversing a four digit number..."
              << "\n";
    std::cout << "Please enter a four digits number: ";
    std::cin >> value;

    /* reading original digits
     * int thousands = (value / 1000 % 10);
     * int hundreds = (value / 100 % 10);
     * int tens = (value / 10 % 10);
     * int ones = (value % 10);
     */

    int reverseValue =
        (value % 10) * 1000 + (value / 10 % 10) * 100 + (value / 100 % 10) * 10 + (value / 1000 % 10) * 1;
    std::cout << "The reversed value is now: " << reverseValue << "\n";

    return 0;
}
