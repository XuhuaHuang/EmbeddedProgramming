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
	std::string str;
	// std::cin >> str;
	str = "1,23,456,789";
	std::vector<int> integers = util::parse::parse_str<int>(str);
	for (int i = 0; i < integers.size(); i++) {
		std::cout << integers[i] << "\n";
	}

	system("pause");
	return 0;
}