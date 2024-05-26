/**
 * @file notes.cpp
 * @author Xuhua Huang
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
 * $ g++ -c notes.cpp -o notes.exe -std=c++11
 * $ .\notes
 *
 * @version 1.0
 * @date November 2020
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cmath>
#include <iostream>
#include <string>

class Pet
{
private: // protected if tired of set*() and get*()
    std::string name;
    int         age;

public:
    // default and overloaded constructors
    Pet();
    Pet(int newage, std::string newname);

    // set function:
    void setName(std::string newname) { name = newname; }
    void setAge(int newage) { age = newage; }

    // get function:
    std::string getName() const { return name; }
    int         getAge() const { return age; }
};

class Dog : public Pet
{
private:
    std::string breed;

public:
    // default and overloaded constructor
    Dog();
    Dog(std::string newbreed,
        int         newage,
        std::string newname); // : Pet(newage, newname) { setbreed(newbreed); setAge(getAge() * 7); }

    // get and set function for new element string breed:
    void        setBreed(const std::string newbreed) { breed = newbreed; }
    std::string getBreed() const { return breed; }
};

class Cat : public Pet
{
private:
    int numLives;

public:
    // default and overloaded constructor
    Cat();
    Cat(int newnumLives, int newage, std::string newname); // : Pet(newage, newname)

    // get and set functions for new element int numLives:
    void setnumLives(const int newNumLives) { numLives = newNumLives; }
    int  getnumLives(void) const { return numLives; }
};

int main(void)
{
    Pet pet1(5, "sander");                          // should call the overloaded constructor for Pet class
    Dog dog1("golden retriever", 5, "doggy doggy"); // calling overloaded constructor, should aged 35
    Cat cat1;

    std::cout << "Pet1 age is: " << pet1.getAge() << "\n"
              << "Pet1 name is: " << pet1.getName() << "\n";
    std::cout << "\nDog1 age is: " << dog1.getAge() << "\n"
              << "Dog1 name is: " << dog1.getName() << " of breed: " << dog1.getBreed() << "\n";
    std::cout << "\nCat1 age is: " << cat1.getAge() << "\n"
              << "Cat1 name is: " << cat1.getName() << "\n";

    cat1.setnumLives(8);
    std::cout << "\nCat1 has this amount of lives: " << cat1.getnumLives() << "\n";

    return 0;
}

Pet::Pet() // default constructor for the Pet class
{
    setAge(0);
    setName("");
}

Pet::Pet(int newage, std::string newname) // overloaded constructor for the Pet class
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
Dog::Dog(std::string newbreed, int newage, std::string newname)
    : Pet(newage, newname)
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
Cat::Cat(int newnumLives, int newage, std::string newname)
    : Pet(newage, newname)
{
    setnumLives(newnumLives);
}
