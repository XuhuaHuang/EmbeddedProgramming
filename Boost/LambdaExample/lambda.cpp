/*****************************************************************//**
 * \file   lambda.cpp
 * \brief  Demonstration of using lambda with boost library.
 * Enter any integer, the program will multiply them by 3 and print them
 * out to the terminal.
 * To exit the program:
 *     1. hold down Ctrl, press Z.
 *     2. release Ctrl, press Enter.
 * 
 * Reference: https://www.boost.org/doc/libs/1_80_0/more/getting_started/windows.html
 * 
 * To compile this file with g++ in PowerShell or bash:
 * $ g++ -o lambda_example.exe -IC:\\boost\\boost_1_82_0 .\LambdaExample.cpp -std=c++17
 * $ echo 1 2 3 | .\lambda_example.exe
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

auto main(void) -> int {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " "
    );

    return EXIT_SUCCESS;
}
