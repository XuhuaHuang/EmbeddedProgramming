/*****************************************************************//**
 * \file   main.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#include <iostream>
#include <complex>
#include <string>
#include "Stack.hpp"

auto main(void) -> int {
    Stack<int> intStack;
    intStack.push(7);

    Stack<std::string> strStack;
    strStack.push("hello");
    strStack.push("world");
    std::cout << strStack.top() << ", ";
    strStack.pop();
    std::cout << strStack.top() << "! ";

    /**
     * Your compiler may not recognize the sequential >> operator
     * at the trailling template instanciation.
     * This is a known issue; change to the following instead:
     * Stack<std::complex<double> > cpxStack;
     * \return
     */
    Stack<std::complex<double>> cpxStack;

    Stack<std::pair<int, double>> pairStack;
    pairStack.push(std::pair<int, double>(1, 2.0));
    pairStack.push({ 3, 4.00 });
    std::cout << pairStack.top().first << "\n";

    //pairStack.print(); // compile-time error; std::pair does not overload operator <<

    return EXIT_SUCCESS;
}
