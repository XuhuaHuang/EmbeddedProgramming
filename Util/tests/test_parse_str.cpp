/*****************************************************************//**
 * \file   test_parse_str.cpp
 * \brief  Demonstration of function to parse a comma-separated string
 * into integers and store them in a std::vector<int>.
 * 
 * To compile and run this file on Windows:
 * $ g++ -o test_parse_str.exe .\test_parse_str.cpp -std=c++11
 * $ .\test_parse_str.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

// Customized utility library
#include "parse.hpp"
#include "print_vec.hpp"

int main() {
    /* Split a comma-separated string to an array of integers. */
    std::string str;
    // std::cin >> str;

    str = "1,23,456,789";                       // test with a comma as delimiter
    std::vector<int> integers = util::parse::parse_str<int>(str);
    util::vector::print_vec<int>(integers);

    std::string cell_phone = "541-952-1655";    // test with a dash as delimiter
    std::vector<int> cell_to_ints = util::parse::parse_str<int>(cell_phone, '-');
    util::vector::print_vec<int>(cell_to_ints);

    /* Split a comma-separated string to an array of characters. */
    const std::string name = "Huang,Xuhua";
    std::vector<std::string> spell_name = util::parse::parse_str<std::string>(name);
    util::vector::print_vec<std::string>(spell_name);

    system("pause");
    return EXIT_SUCCESS;
}
