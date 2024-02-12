/**
 * @file nth_element.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

#include "Helper/generic_container.hpp"

int main()
{
    using helper::generic_container::operator<<;

    std::vector<int> v{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};
    std::cout << v << "\n";

    auto m = v.begin() + v.size() / 2;
    std::nth_element(v.begin(), m, v.end());
    std::cout << "The median is " << v[v.size() / 2] << "\n";

    // the consequence of the inequality of elements before/after the Nth one:
    assert(std::accumulate(v.begin(), m, 0) < std::accumulate(m, v.end(), 0));
    std::cout << v << "\n";

    // comparattor changed
    std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater{});
    std::cout << "The second largest element is " << v[1] << "\n";
    std::cout << "The largest element is " << v[0] << "\n";
    std::cout << v << "\n";
    
    return 0;
}
