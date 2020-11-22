/*****************************************************************//**
 * \file   class_notes_User.cpp
 * \brief  brief notes on class
 *		   By convention is to use smaller thing in structure
 *		   more complex things in class
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
using namespace std;

class User
{
public:
	User();
	~User();

	void setFirstName(string userFirstName) { firstName = userFirstName; }
	string getFirstName(void) { return firstName; }
	
	void setLastName(string userLastName) { lastName = userLastName; }
	string getLastName(void) { return lastName; }
	
	void setStatus(string userStatus) { status = userStatus; }
	string getStatus(void) { return status; }

	void printInfo(void);

private:
	string firstName;
	string lastName;
	string status;
};

User::User() // default constructor
{
}

User::~User() // destructor
{
}

void User::printInfo(void)
{
	cout << "User " << firstName << " " << lastName
		 << " is of status " << status << endl;
}

int main(void)
{
	User user;
	user.setFirstName("Xuhua");
	user.setLastName("Huang");
	user.setStatus("Student");
	
	user.printInfo();

	return 0;
}
