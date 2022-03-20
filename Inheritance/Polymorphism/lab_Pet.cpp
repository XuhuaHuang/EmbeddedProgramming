/*****************************************************************//**
 * \file   lab_Polymorphism.cpp
 * \brief  lab on polymorphism with keyword "virtual"
 * "virtual" grants the pointer access to polymorphism member function
 *
 * $ g++ .\lab_Pet.cpp -o pet
 * $ ./pet
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

class Pet
{
protected: // X.H. changed the keyword to 'protected'
    std::string name;
    int age;

public:
    // default and overloaded constructors
	Pet() {
        setAge(0);
        setName("");
    }

    // set and get function:
    void setName(std::string newname) { name = newname; }
    std::string getName() const{ return name; }

    int getAge() const { return age; }

    virtual void setAge(int newage) { age = 0; }
    // X.H. changed the definition of 'setAge()' to set the age to 0
    // uncomment "virtual" if need to revoke polymorphism member functions of derived class
};

class Dog : public Pet // inheriting from class 'Pet'
{
private:
    std::string breed;

public:
    // default and overloaded constructor
    Dog() {
        setAge(getAge() * 7); // access to class Pet is granted
    }

    // set and get function for new element std::string breed:
    void setBreed(std::string newbreed) { breed = newbreed; }
    std::string getBreed() const { return breed; }

    // new setAge function
    void setAge(int newage) override { age = (newage * 7); }
};

class Cat : public Pet // inheriting from class 'Pet'
{
private:
    int numLives;

public:
    // default constructor
    Cat() {
        setnumLives(9);
    }

    // set and get functions for new element int numLives:
    void setnumLives(int newNumLives) { numLives = newNumLives; }
    int getnumLives(void) const { return numLives; }

    // new setAge function
    void setAge(int newage) { age = newage; }
};

int main(void)
{
    Pet myPet; // created a 'Pet' object
    Pet* ptrPet = &myPet;
    // create a pointer of class 'Pet'
    // and linked it to Pet 'myPet'

    Dog myDog;
    Pet* ptrDog = &myDog; // parent class pointer pointing to derived class object

    Cat myCat;
    Pet* ptrCat = &myCat; // parent class pointer pointing to derived class object

    // with three pointers, setting all ages to 2
    std::cout << "\nSetting ages of \"myPet\", \"myDog\" and \"myCat\" to 2." << "\n";
    ptrPet->setAge(2);
    ptrDog->setAge(2);
    ptrCat->setAge(2);

    std::cout << "\nTest case with virtual keyword: " << "\n"
        << "Obtaining age for Pet object which should be 0: " << ptrPet->getAge() << "\n"
        << "Obtaining age for Dog object which should be 14: " << ptrDog->getAge() << "\n"
        << "Obtaining age for Cat object which should be 2: " << ptrCat->getAge() << "\n";

    std::cout << "\nComment out the \"virtual\" keyword to verify all ages are 0." << "\n"
        << "\tSince all pointers are forced to go through" << "\n"
        << "\tmember function setAge() in \"Pet\" class." << "\n";

    return 0;
}
