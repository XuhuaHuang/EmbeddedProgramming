/*****************************************************************//**
 * \file   main.cpp
 * \brief  Scratch program using refactoring approach.
 * 
 * TODO: write overloaded cin(>>) and cout(<<) operator
 * and test Person class
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
		#define DEBUG(output) std::cout << output << std::endl;
	#endif
#endif

enum Sex {
	female = 0,
	male = 1
};

class Person
{
public:
	/* Public default and overloaded constructor. */
	/* Default constructor */
	Person() : _name(""), _sex(Sex::female), _tell(""), _email(""), _addr("") {
		DEBUG("Default constructor for class Person");
	}
	/* Overloaded constructor */
	Person(
		const string name, const int sex,
		const string tell, const string email, const string addr = "")
	{	
		DEBUG("Overloaded constructor for class Person")
		this->setName(name);
		this->setSex(sex);
		this->setTell(tell);
		this->setEmail(email);
		this->setAddr(addr);
	}
	virtual ~Person() {}

	/**
	 * Provide mutator and accessors for private members.
	 */
	void setName(const string name) {
		if (name != "\n")
			_name = name;
		else
			DEBUG("Error occurred while setting name! Empty argument.");
	}

	void setSex(const int sex) {
		if (sex)
			_sex = Sex::male;
		else if (!sex)
			_sex = Sex::female;
		else
			DEBUG("Error occurred while setting sex! Non-binary argument.")
	}

	void setTell(const string tell) {
		if (tell != "\n")
			_tell = tell;
		else
			DEBUG("Error occurred while setting phone number! Empty argument.");
	}

	void setEmail(const string email) {
		if (email != "\n")
			_email = email;
		else
			DEBUG("Error occurred while setting phone number! Empty argument.");
	}

	void setAddr(const string addr) {
		_addr = addr; // with provided default argument in overloaded constructor
	}

	string name() const { return _name; }
	string sex() const { return _sex ? "Male": "Female"; }
	string tell() const { return _tell; }
	string email() const { return _email; }
	string addr() const { return _addr; }

private:
	Person(const Person&) = delete;

	/* Private attributes associated with individuals. */
	string _name;
	int _sex;
	string _tell;
	string _email;
	string _addr;
};

int main(int argc, char* argv)
{
	Person demoPersonToAdd;
	
	demoPersonToAdd.setName("Xuhua Huang");
	demoPersonToAdd.setSex(Sex::male);
	demoPersonToAdd.setTell("+1(514)-952-1655");
	demoPersonToAdd.setEmail("xuhuahuang0412@gmail.com");
	demoPersonToAdd.setAddr("1460 Boul Provencher");

	DEBUG(demoPersonToAdd.name());
	DEBUG(demoPersonToAdd.sex());
	DEBUG(demoPersonToAdd.tell());
	DEBUG(demoPersonToAdd.email());
	DEBUG(demoPersonToAdd.addr());

	cout << "Hello World!" << endl;

	system("pause");
	return 0;
}