/**
 * @file merge.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-11-27
 *
 * cl .\merge.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * /I"${EmbeddedProgrammingRoot}"
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>

#include "Helper/generic_container.hpp"

int main()
{
    std::array<int, 5U> v1{
        {1, 3, 5, 7, -5}
    };
    std::array<int, 4U> v2{
        {2, -4, 6, -8}
    };

    using helper::generic_container::operator<<;
    std::cout << v1 << "\n";
    std::cout << v2 << "\n";
    if (not std::is_sorted(v1.begin(), v1.end()))
    {
        std::sort(std::begin(v1), std::end(v1), std::less<int>());
    }
    std::cout << v1 << "\n";

    std::vector<decltype(v1)::value_type> result{};
    // std::merge(...) requires decltype(result)::push_back() member function
    // therefore, result has to be the type of std::vector
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));

    std::cout << result << "\n";
    assert(result.size() == 9U);
    assert(not std::is_sorted(result.begin(), result.end()));

    // partial sort
    // sort the first 5 elements in the result vector
    std::partial_sort(std::begin(result), std::begin(result) + 4, std::end(result));
    std::cout << result << "\n";

    return 0;
}
