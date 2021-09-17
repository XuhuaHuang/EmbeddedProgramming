/*****************************************************************//**
 * \file   main.cpp
 * \brief  Scratch program using refactoring approach.
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/

#include <stdlib.h>
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
	explicit Person() : _name(""), _sex(Sex::female), _tell(""), _email(""), _addr("") {
		DEBUG("Default constructor for class Person");
	}
	/* Overloaded constructor */
	explicit Person(
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

	/* Add support for use case like "std::cout << person;" */
	friend istream& operator>> (istream& input, Person& argPerson);
	friend ostream& operator<< (ostream&, const Person&);
	
private:
	Person(const Person&) = delete;

	/* Private attributes associated with individuals. */
	string _name;
	int _sex;
	string _tell;
	string _email;
	string _addr;
};

/* UI namespace contains all required function for View. */
namespace UI {

	namespace interact {
		/* Print instruction in terminal and store answer in reference variable. */
		void input(const string instruction, string& answer) {
			if (instruction != "\n") {
				cout << instruction;
				std::getline(std::cin, answer);
			}
			else
				DEBUG("Error occurred while asking for input! Invalid instruction.");
		}
	}

	namespace display {

		void printAsterisks(const int numToPrint = 43, const string arg = "") {
			for (int i = 0; i < numToPrint; ++i) {
				cout << "*";
			}
			cout << "\n";
		}

		void printInstructions(const string arg = "") {
			printAsterisks();
			cout << "*** Press 0 to print all saved contacts ***" << endl
				<< "*** Press 1 to add a new contact to App ***" << endl
				<< "*** Press 2 to look up saved individual ***" << endl
				<< "*** Press 3 to delete a contact by name ***" << endl
				<< "*** Press 4 to remove all saved contact ***" << endl;
			printAsterisks();
		}

		void clearScreen() {
			system("CLS");
		}
	}
}

istream& operator>> (istream& input, Person& argPerson)
{
	string name, sex, tell, email, address;

	UI::interact::input("Name: ", name);
	UI::interact::input("Sex: ", sex);
	UI::interact::input("Tell: ", tell);
	UI::interact::input("Email: ", email);
	UI::interact::input("Address: ", address);

	/* Call mutators to write to object. */
	argPerson.setName(name);

	if (sex == "Male" || sex == "male" || sex == "1")
		argPerson.setSex(Sex::male);
	else if (sex == "Female" || sex == "female" || sex == "0")
		argPerson.setSex(Sex::female);

	argPerson.setTell(tell);
	argPerson.setEmail(email);
	argPerson.setAddr(address);

	return input;
}

ostream& operator<< (ostream& output, const Person& argPerson)
{
	output << "\nPerson: " << argPerson.name() << ", "
		<< argPerson.sex() << endl
		<< "Tell: " << argPerson.tell() << endl
		<< "Email: " << argPerson.email() << endl
		<< "Address: " << argPerson.addr() << endl;

	return output;
}

int main(int argc, char* argv)
{
	Person demoPersonToAdd;
	cin >> demoPersonToAdd;
	cout << demoPersonToAdd;

	UI::display::printAsterisks();
	UI::display::printInstructions();
	
	system("pause");
	return 0;
}