/*****************************************************************//**
 * \file   interface.cpp
 * \brief  pure virtual function in C++
 *		     can not instantiate instances without implementing
 *		     pure virtual function in the base class
 *
 * \author Xhuhua Huang
 * \date   March 2021
 *********************************************************************/

#include <iostream>
#include <string>

using namespace std;

// class Printable only contains a pure virtual function that
// acts like an interface keyword in other programming languages
class Printable
{
public:
	// create an interface that every derived class has to implement
	// pure virtual function
	virtual string getClassName() = 0;
};

// function prototype
void printClassName(Printable* obj);

class Entity : public Printable
{
private:
	string className;
public:
	// implement defined interface
	string getClassName() override { return "Entity : public Printable"; }
};

class User : public Entity
{
private:
	string firstName;
	string lastName;
public:
	// implement defined interface
	string getClassName() override { return "User : public Entity"; }

	// constructor wiht member intialization list
	User(string fn, string ln) : firstName(fn), lastName(ln) {}
	
	// get function
	string getUserName() { return firstName + lastName; }
};

void printClassName(Printable* obj)
{
	cout << "Print class name: " << obj->getClassName() << endl;
}

int main(void)
{
	Entity* e = new Entity();
	printClassName(e);

	User* u = new User("Xuhua", "Huang");
	printClassName(u);

	delete e;
	delete u;
	return 0;
}
