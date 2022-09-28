/*****************************************************************//**
 * \file   raw_string_literal.cpp
 * \brief  Demonstration of raw string literal introduced in C++11.
 * 
 * $ g++ -o raw_string_literal.exe -c .\raw_string_literal.cpp -std=c++17
 * \author Xuhua Huang
 * \date   September 27, 2022
 *********************************************************************/

#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);

    // the R indicated it's a raw string literal
    // \n will not be interpreted as new line character
    // and the empty spaces at line 19 will be printed
    std::cout << R"(Hello,\n
        world)" << "\n";

    std::cout << R"(This is a Python style
multi-line string literal,
which acts like doc strings)" << "\n";

    return 0;
}
