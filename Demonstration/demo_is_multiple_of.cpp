/*****************************************************************//**
 * \file   demo_is_multiple_of.cpp
 * \brief  Asked question in test for the company Kinaxis.
 * 
 * Command used to compile:
 * $ g++ -o demo_is_multiple.exe .\demo_is_multiple_of.cpp -std=c++11
 * $ .\demo_is_multiple.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>

#include "Util/print_vec.h"
#include "Util/log.h"

using namespace util::vector;

#ifndef DEBUG
#define DEBUG(str) std::cout << str << std::endl;
#endif

/**
 * Given a std::vector<int> of any size n,
 * For a, b in such provided vector, count the times the following conditions are met:
 * 1) the sum of a and b is multiple of 60,
 * 2) any of a and b is multiple of 60.
 */

bool is_multiple_of_60(const int num) {
	return num%60 == 0;
}

int main(int argc, char** argv)
{
	std::vector<int> input = { 30, 60, 90, 120 };
	print_vec(input);
	// equivalence of: util::vector::print_vec(input);

	int count = 0;
	std::vector<int> result;

	for (int i = 0; i < 4; ++i) {
		if (is_multiple_of_60(input[i])) {
			count++;
			result.push_back(input[i]);
		}
		else {
			for (int j = 1; j <= input.size(); ++j) {
				if (is_multiple_of_60(input[i] + input[j]) == true) {
					count++;
					result.push_back(input[i] + input[j]);
				}
			}
		}
	}

	printf_s("Count: %d\n", count);
	print_vec(result);

	system("pause");
	return 0;
}