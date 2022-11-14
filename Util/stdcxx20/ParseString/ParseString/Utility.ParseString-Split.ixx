export module Utility.ParseString:Split;

#include <iostream>
#include <vector>
#include <sstream>

export template<typename T>
const std::vector<T> split_str(const std::string& str, char delimiter = ',')
{
    std::vector<T> result;

    if (str.length() < 8E5) {
        std::stringstream ss(str);
        while (ss.good()) {
            std::string substr;
            getline(ss, substr, delimiter);
            result.push_back(stoi(substr));
        }
    }

    return result;
}
