/*****************************************************************//**
 * \file   find_digit.cpp
 * \brief  Test question on HackerRank platform.
 * https://www.hackerrank.com/challenges/find-digits/problem
 * Using the integer's digits as divisors, count the number of them.
 * Passes all test cases and the code is submitted.
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

std::string ltrim(const std::string&);
std::string rtrim(const std::string&);

/*
 * Complete the 'findDigits' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
void splitNumber(std::vector<int>& digits, int number) {
    /**
     * Split a number into digits and store them in an integer array.
     */
    if (0 == number) {
        digits.push_back(0);
    }
    else {
        while (number != 0) {
            int last = number % 10;
            digits.insert(digits.begin(), 1, last);
            number = (number - last) / 10;
        }
    }
}

int findDigits(int n) {
    int count = 0;
    std::vector<int> temp;
    splitNumber(temp, n);

    for (int i = 0; i < temp.size(); ++i) {
        if ((temp[i] != 0) && (n % temp[i] == 0)) {
            count++;
        }
    }

    return count;
}

int main()
{
    std::string t_temp;
    std::getline(std::cin, t_temp);

    int t = std::stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        std::string n_temp;
        std::getline(std::cin, n_temp);

        int n = std::stoi(ltrim(rtrim(n_temp)));

        int result = findDigits(n);

        std::cout << result << "\n";
    }

    return 0;
}

/**
 * ltrim and rtrim function dependencies:
 * library <algorithm> and <functional>.
 */
std::string ltrim(const std::string& str) {
    std::string s(str);

    s.erase(
        s.begin(),
        find_if(
            s.begin(), s.end(), // specify an iterator-based range to search
            std::not1(std::ptr_fun<int, int> (isspace)) // lambda parsed to determine
        )
    );

    return s;
}

std::string rtrim(const std::string& str) {
    std::string s{ str };

    s.erase(
        std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
