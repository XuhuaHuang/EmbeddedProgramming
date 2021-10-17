/*****************************************************************//**
 * \file   demo_parse_str.cpp
 * \brief  Demonstration of function to parse a comma-separated string
 * into integers and store them in a std::vector<int>.
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "Util/parse.h"

int main() {

	/* Split a comma-separated string to an array of integers. */
	std::string str;
	// std::cin >> str;
	str = "1,23,456,789";						// demo with a comma as delimiter
	std::string cell_phone = "541-952-1655";	// demo with a dash as delimiter
	std::vector<int> integers = util::parse::parse_str<int>(cell_phone, '-');
	for (int i = 0; i < integers.size(); i++) {
		std::cout << integers[i] << "\n";
	}

	/* Split a comma-separated string to an array of characters. */
	const std::string name = "Huang,Xuhua";
	std::vector<char> spell_name = util::parse::parse_str<char>(name);
	for (int j = 0; j < spell_name.size(); ++j) {
		std::cout << spell_name[j] << "\n";
	}

	system("pause");
	return 0;
}