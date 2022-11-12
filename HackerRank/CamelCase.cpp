/*****************************************************************//**
 * \file   CamelCase.cpp
 * \brief  Test question on HackerRank platform.
 * https://www.hackerrank.com/challenges/camelcase/problem
 * Count the total number of words in a camelCase formatted string.
 * Passes all test cases and the code is submitted.
 * 
 * Command used to compile:
 * $ g++ -o camelCase.exe .\CamelCase.cpp -std=c++11
 * $ .\camelCase.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <string>

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int camelcase(const std::string s) {
    int word_count = 1;

    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s.at(i))) {
            // equivalent to: isupper(s[i])
            // check if the letter is upper case
            // if it is, we consider as the start of a word
            word_count++;
        }
    }

    return word_count;
}

int main()
{
    std::cout << "Please type one or more camel case words: ";
    std::string s;
    std::getline(std::cin, s); // get a camelCase formatted string from user

    int result = camelcase(s);

    std::cout << "Camel casing count: " << result << "\n";

    return 0;
}