/*****************************************************************//**
 * \file   learn_move.cpp
 * \brief  Move semantics in C++
 * Demonstrated using std::vector
 *
 * std::move()
 * std::move_if_noexcept()
 *
 * Command used to compile this file:
 * g++ -o learn_move.exe learn_move.cpp -std=c++11
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "../Util/print_vec.hpp"
#include "../Util/is_instance_of.hpp"

int main(void)
{
    /* Initialize 2 strings, 1 of which to move. */
    std::string hello_str = "hello";
    std::string world_str = "world";

    std::vector<std::string> str_vec;
    str_vec.push_back(hello_str);

    // uses the rvalue reference push_back(T&&) overload, 
    // which means no strings will be copied; instead, the contents
    // of world_str will be moved into the vector. 
    // This is less expensive, but also means world_str might now be empty.
    str_vec.push_back(std::move(world_str));
    // still able to access hello_str, but not world_str

    /* Verify element via printing. */
    std::cout << "The vector contains: " << "\n";
    for (const std::string& str : str_vec)
        std::cout << str << "\t";
    std::cout << "\nEnd of the vector" << "\n";

    std::cout << "Attempting to access hello_str: " << hello_str << "\n"
        << "Attempting to access world_str: " << world_str << "\n";

    /* Test functions in the ../Util headers. */
    std::cout << "Testing Util functions: " << "\n";
    if (util::type::is_instance_of<std::vector<std::string>>(str_vec)) {
        util::vector::print_vec(str_vec);
    }

    system("pause");
    return 0;
}
