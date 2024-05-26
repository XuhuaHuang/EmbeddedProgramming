/*****************************************************************//**
 * \file   notes_user.cpp
 * \brief  brief notes on structure
 *         By convention is to use smaller thing in structure
 *         more complex things in class
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

struct User
{
public:
    // by default, variables inside a struture are public
    // if changed to private, need to create accessor and mutator functions
    // in-line assignment is reserved for standard C++11

    std::string firstName;
    std::string lastName;
    std::string status;
};

int main(void)
{
    User user;
    user.firstName = "Xuhua";
    user.lastName = "Huang";

    std::cout << "The user's name is " << user.firstName << user.lastName << "\n";

    return 0;
}
