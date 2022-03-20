/*****************************************************************//**
 * \file   struct_notes_User.cpp
 * \brief  brief notes on structure
 *		   By convention is to use smaller thing in structure
 *		   more complex things in class
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
using namespace std;

struct User
{
public: 
	// by default, variables inside a struture are public
	// if changed to private, need to create accessor and mutator functions
	// in-line assignment is reserved for standard C++11
	
	string firstName;
	string lastName;
	string status;
};

int main(void)
{
	User user;
	user.firstName = "Xuhua";
	user.lastName = "Huang";

	cout << "The user's name is " << user.firstName << user.lastName << endl;

	return 0;
}
