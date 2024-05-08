/*****************************************************************//**
 * \file   TimeConversion.cpp
 * \brief  Test question on HackerRank platform.
 * https://www.hackerrank.com/challenges/time-conversion/problem
 * Given a time in 12-hour AM/PM format, convert it to 24-hour time.
 * Passes all test cases and the code is submitted.
 * 
 * Command used to compile:
 * $ g++ -o time.exe .\TimeConversion.cpp -std=c++11
 * $ .\time.exe
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
std::string timeConversion(std::string s) {
    std::string result = "";

    if (s.find("AM") != std::string::npos && stoi(s.substr(0, 2)) == 12) {
        result = s.erase(8, 2);
        result = s.replace(0, 2, "00");
    }
    else if (s.find("PM") != std::string::npos && stoi(s.substr(0, 2)) == 12) {
        result = s.erase(8, 2);
    }
    else if (s.find("AM") != std::string::npos) {
        result = s.erase(8, 2);
    }
    else if (s.find("PM") != std::string::npos) {
        result = s.erase(8, 2);
        result = s.replace(0, 2, std::to_string((stoi(s.substr(0, 2)) + 12)));
    }

    return result;
}

int main()
{
    std::string s;
    std::getline(std::cin, s); // get the 12-hour format time from the user

    std::string result = timeConversion(s);

    std::cout << result << "\n";

    return 0;
}
