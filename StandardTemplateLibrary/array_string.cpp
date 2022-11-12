/*****************************************************************//**
 * \file   STL_array_string.cpp
 * \brief  array and vector contains strings
 * 
 * \author Xuhua Huang
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <array>
#include <string>
#include <vector>

int main(void)
{
	// initialize String Array
	std::string colour[4] = { "Blue", "Red", "Orange", "Yellow" };

	// print strings array
	for (int i = 0; i < 4; i++)
		std::cout << colour[i] << "\n";

	// declaring vector of string type
	// values can be added here using initializer-list syntax
	std::vector<std::string> colourVec{ "Blue", "Red", "Orange" };

	// strings can be added at any time with push_back
	colourVec.push_back("Yellow");

	// print Strings stored in vector
	for (int i = 0; i < colourVec.size(); i++)
		std::cout << colourVec[i] << "\n";


	// initialize templtized array
	std::array<std::string, 4> colourArr{ "Blue", "Red", "Orange", "Yellow" };

	// print Strings stored in a templtized array
	for (int i = 0; i < 4; i++)
		std::cout << colourArr[i] << "\n";

	return 0;
}
