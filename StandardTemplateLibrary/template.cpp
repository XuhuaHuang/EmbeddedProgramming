/*****************************************************************//**
 * \file   template.cpp
 * \brief  Introduction on template in C++
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>

// overload functions
int sum(int num1, int num2) { return num1 + num2; }
double sum(double num1, double num2) { return num1 + num2; }

// function templates
template<class Custom> // class type is a variable // equivalent to : template<typename Custom>
Custom sum(Custom num1, Custom num2) // when calling: sum<Custom>(num1, num2)
{
    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
    return num1 + num2;
}

template<class Custom, int N>
Custom fixedMultiply(Custom val) // when calling: fixedMultiply<Custom, N>(val)
{
    std::cout << val << " is being multiplied with " << N << "\n";
    return val * N;
}

int main(void)
{
    std::cout << "\nWith overloading functions" << "\n";
    std::cout << sum(10, 20) << "\n"; // 30
    std::cout << sum(10.01, 20.02) << "\n"; // 30.03

    /**
     * syntax of C++ template
     *
     * template <class sometype>
     * sometype sum(sometype a, sometype b) { return a + b; }
     *
     * In this way, the type of the parameters become variables
     */

    std::cout << "\nWith function template" << "\n";
    std::cout << sum<int>(10, 20) << "\n";
    std::cout << sum<double>(10.01, 20.02) << "\n";

    std::cout << "\nWith function template \"fixedMultiply\"" << "\n";
    std::cout.precision(2); // set double digits precision
    std::cout << std::fixed << fixedMultiply<double, 4>(20.00) << "\n";

    return 0;
}
