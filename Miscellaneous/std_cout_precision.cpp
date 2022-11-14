/*****************************************************************//**
 * \file   std_cout_precision.cpp
 * \brief  Set the precision of number output to std::cout with std::fixed
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>

int main(void)
{
    int numPrecision = 2;

    std::cout.precision(numPrecision);

    double a = 0;
    int b = 1;

    std::cout << "Value for \"double a\" is: " << std::fixed << a << "\n";
    std::cout << "Value for \"int b\" is: " /* << std::fixed */ << b << "\n";

    return 0;
}
