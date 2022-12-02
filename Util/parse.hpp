/*****************************************************************//**
 * \file   parse.hpp
 * \brief  contains a template function to parse
 * comma-separated strings and store them in std::vector<T>.
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#ifndef PARSE_STR_HPP
#define PARSE_STR_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _SSTREAM_
#include <sstream>
#endif

namespace util {
    namespace parse {

        template<char c>
        constexpr bool is_digit = (c >= '0' && c <= '9');

        /**
         * Template to parse a delimiter-separated string.
         * The default delimiter is a comma ','
         * Ideal use case: convert such string to an integer array.
         */
        template<typename T>
        static const std::vector<T> parse_str(const std::string& str, char delimiter = ',') {
            std::vector<T> result;

            if (str.length() < 8E5) {
                std::stringstream ss(str);
                while (ss.good()) {
                    std::string substr;
                    getline(ss, substr, delimiter);
                    if constexpr (std::is_same_v<T, std::string>) {
                        result.push_back(substr);
                    }
                    else if constexpr (std::is_same_v<T, char>) {
                        result.push_back(static_cast<char>(substr));
                    }
                    else if constexpr (std::is_same_v<T, int>) {
                        result.push_back(stoi(substr));
                    }
                }
            }

            return result;
        }

        /* Read digits from an integer and store in an array. */
        static const std::vector<int> num_to_digits(int number) {
            std::vector<int> digits;

            if (number == 0) {
                digits.push_back(0);
            }
            else {
                while (number != 0) {
                    int last = number % 10;
                    digits.insert(digits.begin(), 1, last);
                    number = (number - last) / 10;
                }
            }

            return digits;
        }

    } // end util::parse
} // end util

#endif
