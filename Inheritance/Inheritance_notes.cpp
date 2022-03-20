/**
 * @file Inheritance_notes.cpp
 * @author 1879700 Xuhua Huang
 * @brief lab 7 Inheritance Notes
 * mechanism to enhance existing working class
 * define new classes that are extensions of extensions of existing class
 * 
 * Contains:
 * Base Class 'Pet'
 * Derived Class 'Dog'
 * Derived Class 'Cat'
 * default / overloaded constructors
 * function definitions
 *
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Pet
{
private: // protected if tired of set*() and get*()
	string name;
	int age;

public:
	// default and overloaded constructors
	Pet();
	Pet(int newage, string newname);

	// set function:
	void setName(string newname) { name = newname; }
	void setAge(int newage) { age = newage; }

	// get function:
	string getName() const { return name; }
	int getAge() const { return age; }

};

class Dog : public Pet
{
private:
	string breed;

public:
	// default and overloaded constructor
	Dog();
	Dog(string newbreed, int newage, string newname); // : Pet(newage, newname) { setbreed(newbreed); setAge(getAge() * 7); }

	// get and set function for new element string breed:
	void setBreed(const string newbreed) { breed = newbreed; }
	string getBreed() const { return breed; }
};

class Cat : public Pet
{
private:
	int numLives;

public:
	// default and overloaded constructor
	Cat();
	Cat(int newnumLives, int newage, string newname); // : Pet(newage, newname)

	// get and set functions for new element int numLives:
	void setnumLives(const int newNumLives) { numLives = newNumLives; }
	int getnumLives(void) const { return numLives; }
};

int main(void)
{
	Pet pet1(5, "sander"); // should call the overloaded constructor for Pet class
	Dog dog1("golden retriever", 5, "doggy doggy"); // calling overloaded constructor, should aged 35
	Cat cat1;

	cout << "Pet1 age is: " << pet1.getAge() << endl << "Pet1 name is: " << pet1.getName() << endl;
	cout << "\nDog1 age is: " << dog1.getAge() << endl << "Dog1 name is: " << dog1.getName() << " of breed: " << dog1.getBreed() << endl;
	cout << "\nCat1 age is: " << cat1.getAge() << endl << "Cat1 name is: " << cat1.getName() << endl;

	cat1.setnumLives(8);
	cout << "\nCat1 has this amount of lives: " << cat1.getnumLives() << endl;

	return 0;
}

Pet::Pet() // default constructor for the Pet class
{
	setAge(0);
	setName("");
}

Pet::Pet(int newage, string newname) // overloaded constructor for the Pet class
{
	setAge(newage);
	setName(newname);
}

Dog::Dog() // default constructor for Dog class
{
	setAge(getAge() * 7); // access to class Pet is granted
}

/*
* following overloaded constructor passes newage and newname
* to parent class 'Pet' with Pet(int, string)
* reminder: Pet(int, string) itself is a overloaded constructor
* 'string newbreed' is the new element preserved for class 'Dog'
*/
Dog::Dog(string newbreed, int newage, string newname) : Pet(newage, newname)
{
	setBreed(newbreed);
	setAge(getAge() * 7); // set the human perspective age
}

Cat::Cat() // default constructor for Cat class
{
	setnumLives(9);
}

/*
* following overloaded constructor passes newage and newname
* to parent class 'Cat' with Pet(int, string)
* reminder: Pet(int, string) itself is a overloaded constructor
* 'int newnumLives' is the new element preserved for class 'Cat'
*/
Cat::Cat(int newnumLives, int newage, string newname) : Pet(newage, newname)
{
	setnumLives(newnumLives);
}
