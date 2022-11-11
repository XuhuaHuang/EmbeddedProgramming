/*****************************************************************//**
 * \file   test.cpp
 * \brief  Test installation of the Boost library.
 * 
 * $ g++ -o test.exe -IC:\\boost\\boost_1_80_0 .\test.cpp -std=c++11
 * $ .\test.exe
 * 
 * \author Xuhua Huang (xuhua.huang.io@outlook.com)
 * \date   September 2022
 *********************************************************************/

#include <iostream>
#include <boost/version.hpp>
#include <boost/config.hpp>

int main(void) {
    /* boost/version.hpp */
    std::cout << BOOST_VERSION << "\n"
        << BOOST_LIB_VERSION << "\n";

    /* boost/config.hpp */
    std::cout << BOOST_PLATFORM << "\n"
        << BOOST_COMPILER << "\n"
        << BOOST_STDLIB << "\n";

    /*std::cin.get();*/
    system("pause");
    return 0;
}
