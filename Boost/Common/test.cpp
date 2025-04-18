/*****************************************************************//**
 * \file   test.cpp
 * \brief  Test installation of the Boost library.
 * 
 * $ g++ -o test.exe -IC:\\boost\\boost_1_82_0 .\test.cpp -std=c++11
 * $ .\test.exe
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

#include <boost/config.hpp>
#include <boost/version.hpp>
#include <iostream>

int main(void) {
    /* boost/version.hpp */
    std::cout << BOOST_VERSION << "\n" << BOOST_LIB_VERSION << "\n";

    /* boost/config.hpp */
    std::cout << BOOST_PLATFORM << "\n" << BOOST_COMPILER << "\n" << BOOST_STDLIB << "\n";

    /*std::cin.get();*/
    system("pause");
    return EXIT_SUCCESS;
}
