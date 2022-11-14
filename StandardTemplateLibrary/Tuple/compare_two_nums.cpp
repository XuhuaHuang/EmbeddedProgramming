/*****************************************************************//**
 * \file   compare_two_nums.cpp
 * \brief  example to compare two numbers using a tuple.
 * 
 * * Member function:
 *   operator =              - assign content
 *   swap                    - swap content
 * 
 * Non-member function:
 *   std::make_tuple              - create a tuple object
 *   tie                     - unpack a tuple into individual objects
 *   forward_as_tuple        - creates a tuple of forwarding references
 *   tuple_cat               - creates a tuple by coinvatening tuples
 *   std::get                - tuple accesses specified element
 * 
 * Operator:
 *   ==
 *   !=  <   <=  >   >=      removed in C++ 20
 *   <=> added in C++ 20
 * 
 * Helper classes:
 *   tuple_size              - obtains the size of a tuble
 *   tuple_element           - obtains the type of specified element
 *   ignore                  - placeholder to skip an element when unpacking a tuple using tie
 * 
 * \author Xuhua Huang
 * \date   Nov 13, 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, int> findGreaterSmaller(int num1, int num2)
{
    if (num1 < num2)
        return std::make_tuple(num1, num2);
    else if (num1 > num2)
        return std::make_tuple(num2, num1);
    else
        return std::make_tuple(0, 0);
}

int main(void)
{
    int num1, num2;
    std::cout << "Enter the first number of two to compare: ";
    std::cin >> num1;
    std::cout << "Enter the second number of two to compare: ";
    std::cin >> num2;

    int min, max;
    std::tie(min, max) = findGreaterSmaller(num1, num2);

    /**
     * 'findGreaterSmaller' is the name of the function
     * function argument: int, int
     * 
     * return type: tuple<int, int>
     * tie() function groups int min and max together to be a tuple
     * to receive result of the function
     * 
     * after variables in tuples are assigned value
     * variables can be accessed individually 
     */

    std::cout << "The greater number is: " << max << "\n"
         << "The smaller number is: " << min << "\n";

    return 0;
}
