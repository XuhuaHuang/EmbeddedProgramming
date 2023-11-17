/**
 * @file distance_unittest.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "distance.hpp"

int main()
{
    // Must have a decimal point to bind to the operator we defined!
    Distance d{402.0_km};                                           // construct using kilometers
    std::cout << "Kilometers in d: " << d.get_kilometers() << "\n"; // 402

    Distance d2{402.0_mi};                                            // construct using miles
    std::cout << "Kilometers in d2: " << d2.get_kilometers() << "\n"; // 646.956

    // add distances constructed with different units
    Distance d3 = 36.0_mi + 42.0_km;
    std::cout << "d3 value = " << d3.get_kilometers() << "\n"; // 99.9364

    // Distance d4(90.0); // error constructor not accessible

    return 0;
}
