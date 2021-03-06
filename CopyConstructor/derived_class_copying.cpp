/*****************************************************************//**
 * \file   derived_class_copying.cpp
 * \brief  properly copying derived class objects by invoking:
 *		     base class copy constructor
 *		     base class copy assignment operator
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <string>

// make a log entry to keep track of function call
void logCall(const std::string& functionName)
{
	// make log entry
	std::cout << "\nLog entry invoked on function called: " 
			      << functionName << std::endl;
}

class Date
{
private:
	int year = 2021;
	int month = 3;
	int day = 1;

public:
	// default, overloaded constructor and destructor
	Date() : year(), month(), day() {}
	Date(int argYear, int argMonth, int argDay)
		: year(argYear), month(argMonth), day(argDay) {}
	~Date() {}
	
	// function to print information
	void printDate() {
		std::cout << "\n[fn][Date::printDate()]\n"
				      << "Year: " << this->year << std::endl
				      << "Month: " << this->month << std::endl
				      << "Day: " << this->day << std::endl;
	}
};

class Customer
{
public:
	// ...
	// default and overloaded constructor
	Customer() : name("unknown"), ID("unknown") {}
	Customer(std::string argName, std::string argID)
		: name(argName), ID(argID) {}
	
	// copy constructor
	Customer(const Customer&);
	
	// copy assignment operator
	Customer& operator=(const Customer&);
	// ...

	void printCustomer(int priority = 0)
	{
		std::cout << "\n[fn][Customer::printCustomer]\n"
				      << "Name: " << name << std::endl
				      << "ID: " << ID << std::endl
              << "Priority: " << priority << std::endl;
	}

private:
	std::string name;
	std::string ID;

	// extra member contains a 'Date' object
	// when you add something in the member list
	// remember to change the copy constructor and copy assignment operator
	Date lastTransaction;
};

Customer::Customer(const Customer& rhs)
	: name(rhs.name),						// member initialization list
	  ID(rhs.ID), 
	  lastTransaction(rhs.lastTransaction)  // added for copy constructor to behave as required
{
	logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
	logCall("Customer copy assignment operator");
	this->name = rhs.name;
	this->ID = rhs.ID;
	this->lastTransaction = rhs.lastTransaction;
	
	// return convention
	// assignment operators return a reference to *this
	return *this;
}

// MOST of the issue arise through inheritance
class priorityCustomer : public Customer
{
private:
	int priority;

public:
	// overloaded constructor
	priorityCustomer(std::string argName, std::string argID, int argPriority)
		: Customer(argName, argID), // invoke base class overloaded constructor
		  priority(argPriority) {}
	
	// copy constructor
	priorityCustomer(const priorityCustomer&);
	
	// copy assignment operator
	priorityCustomer& operator= (const priorityCustomer&);
};

// dereived class copy constructor
// invoking parent class copy constructor
priorityCustomer::priorityCustomer(const priorityCustomer& rhs)
	: Customer(rhs),
	  priority(rhs.priority)
{
	logCall("PriorityCustomer copy constructor");
}

priorityCustomer& priorityCustomer::operator= (const priorityCustomer& rhs)
{
	logCall("PriorityCustomer copy assignment operator");
	
	// invoke base class copy assignment operator
	Customer::operator=(rhs);
	priority = rhs.priority;

	// assignment operators return a reference to *this
	return *this;
}

int main(void)
{
	// test base class overloaded constructor
	Customer customer1("Xuhua Huang", "1879700");
	customer1.printCustomer();

	// test copy constructor
	Customer customer2(customer1);
	customer2.printCustomer();

	// test copy assignment operator
	Customer customer3; // unknown, unknown
	
	std::cout << "\nBefore copying: ";
	customer3.printCustomer();
	
	customer3 = customer2; // copied
	
	std::cout << "\nAfter invoking copy assignment operator: ";
	customer3.printCustomer();
	
	// similat test method is applied to class 'priorityCustomer'
	return 0;
}
