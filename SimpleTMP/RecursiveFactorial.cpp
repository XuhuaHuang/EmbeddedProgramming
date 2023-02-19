/**
 * @file RecursiveFactorial.cpp
 * @author Xuhua Huang
 * @brief TMP stands for "Template Metaprogramming"
 * Basic "Hello, world" program to the world of TMP
 *
 * To compile and run this file:
 * $ cd .\SimpleTMP
 * $ g++ -c RecursiveFactorial.cpp -o RecursiveFactorial.exe
 * $ .\RecursiveFactorial.exe
 *
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

// general case: the value of Factorial<n> is
// n times the value of Factorial<n-1>
template<unsigned int n>
struct Factorial {
    enum {
        value = n * Factorial<n-1>::value
    };
};

// special case: the value of Factorial<0> is 1
template<>
struct Factorial<0> {
    enum {
        value = 1
    };
};

int main(void) {
    std::cout << "Factorial of 5: " << Factorial<5>::value << "\n";
    std::cout << "Factorial of 10: " << Factorial<10>::value << "\n";

    return 0;
}
