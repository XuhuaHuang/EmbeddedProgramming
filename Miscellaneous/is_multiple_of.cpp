// clang-format off
/*****************************************************************//**
 * \file   is_multiple_of.cpp
 * \brief  Asked question in test for the company Kinaxis.
 * 
 * Command used to compile:
 * $ g++ -o is_multiple.exe .\is_multiple_of.cpp -std=c++11
 * $ .\is_multiple.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/
// clang-format on

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "../Util/log.h"
#include "../Util/print_vec.hpp"

#ifndef DEBUG
#define DEBUG(str) std::cout << str << "\n";
#endif

/**
 * Given a std::vector<int> of any size n,
 * For a, b in such provided vector, count the times the following conditions are met:
 * 1) the sum of a and b is multiple of 60,
 * 2) any of a and b is multiple of 60.
 */

bool is_multiple_of_60(const int num)
{
    return num % 60 == 0;
}

int main(int argc, char** argv)
{
    using namespace util::vector;

    std::vector<int> input = {30, 60, 90, 120};
    print_vec(input);
    // equivalence of: util::vector::print_vec(input);

    int              count = 0;
    std::vector<int> result;

    for (int i = 0; i < 4; ++i)
    {
        if (is_multiple_of_60(input[i]))
        {
            count++;
            result.push_back(input[i]);
        }
        else
        {
            for (int j = 1; j <= input.size(); ++j)
            {
                if (is_multiple_of_60(input[i] + input[j]) == true)
                {
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
