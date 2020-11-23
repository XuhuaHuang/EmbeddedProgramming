/*****************************************************************//**
 * \file   lab_Polymorphism.cpp
 * \brief  lab on polymorphism with keyword "virtual"
 * \ "virtual" grants the pointer access to polymorphism member function
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

// all overloaded constructor are removed to 
// avoid conflicting with virtual setAge function

using namespace std;

class Pet
{
protected: // X.H. changed the keyword to 'protected'
	string name;
	int age;

public:
	// default and overloaded constructors
	Pet();

	// set and get function:
	void setName(string newname) { name = newname; }
	string getName() { return name; }

	int getAge() { return age; }

	virtual void setAge(int newage) { age = 0; }
	// X.H. changed the definition of 'setAge()' to set the age to 0
	// uncomment "virtual" if need to revoke polymorphism member functions of derived class
};

class Dog : public Pet // inheritaing from class 'Pet'
{
private:
	string breed;

public:
	// dafault and overloaded constructor
	Dog();
	// Dog(string newbreed, int newage, string newname); // -> pass age and name
	// to parent class ooverloaded constructor
	// : Pet(newage, newname) { setbreed(newbreed); setAge(getAge() * 7); }

	// set and get function for new element string breed:
	void setBreed(string newbreed) { breed = newbreed; }
	string getBreed() { return breed; }

	// new setAge function
	void setAge(int newage) { age = (newage * 7); }
};

class Cat : public Pet // inheritaing from class 'Pet'
{
private:
	int numLives;

public:
	// default constructor
	Cat();

	// set and get functions for new element int numLives:
	void setnumLives(int newNumLives) { numLives = newNumLives; }
	int getnumLives(void) { return numLives; }

	// new setAge function
	void setAge(int newage) { age = newage; }
};

int main(void)
{
	Pet myPet; // created a 'Pet' object
	Pet* ptrPet = &myPet; // create a pointer of class 'Pet'
						 // and linked it to Pet 'myPet'

	Dog myDog;
	Pet* ptrDog = &myDog; // parent class pointer pointing to derived class object

	Cat myCat;
	Pet* ptrCat = &myCat; // parent class pointer pointing to derived class object

	// with three pointers, setting all ages to 2
	cout << "\nSetting ages of \"myPet\", \"myDog\" and \"myCat\" to 2." << endl;
	ptrPet->setAge(2);
	ptrDog->setAge(2);
	ptrCat->setAge(2);

	cout << "\nTest case with virtual keyword: " << endl
		 << "Obtaining age for Pet object which should be 0: " << ptrPet->getAge() << endl
		 << "Obtaining age for Dog object which shoulf be 14: " << ptrDog->getAge() << endl
		 << "Obtaining age for Cat object which should be 2: " << ptrCat->getAge() << endl;

	cout << "\nComment out the \"virtual\" keyword to verify all ages are 0." << endl
		 << "\tSince all pointers are forced to go through" << endl
		 << "\tmember function setAge() in \"Pet\" class." << endl;

	return 0;
}

Pet::Pet() // default constructor for the Pet class
{
	setAge(0);
	setName("");
}

Dog::Dog() // default constructor for Dog class
{
	setAge(getAge() * 7); // access to class Pet is granted
}

Cat::Cat() // default constructor for Cat class
{
	setnumLives(9);
}
