/*****************************************************************//**
 * \file   main.cpp
 * \brief  Scratch program using refactoring approach.
 *
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

#ifndef DEBUG
#define DEBUG 1
	#if DEBUG
		#define DEBUG(str) std::cout << str << std::endl;
	#endif
#endif

class Person
{
public:
	Person() : _name(""), _tell(""), _email(""), _addr("") {
		DEBUG("Default constructor for class Person");
	}
	virtual ~Person() {}
	
	/**
	 * Provide mutator and accessors for private members.
	 */
	string name() const { return _name; }
	string tell() const { return _tell; }
	string email() const { return _email; }
	string addr() const { return _addr; }

private:
	Person(const Person&) = delete;

	/* Private attributes associated with individuals. */
	string _name;
	string _tell;
	string _email;
	string _addr;
};

int main(int argc, char* argv)
{
	Person demoPersonToAdd;


	cout << "Hello World!" << endl;

	system("pause");
	return 0;
}