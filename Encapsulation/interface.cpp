/*****************************************************************//**
 * \file   interface.cpp
 * \brief  pure virtual function in C++
 *         can not instantiate instances without implementing
 *         pure virtual function in the base class
 *
 * \author Xuhua Huang
 * \date   September 24, 2022
 *********************************************************************/

#include <iostream>
#include <string>

// class Printable only contains a pure virtual function that
// acts like an interface keyword in other programming languages
class Printable
{
public:
    // create an interface that every derived class has to implement
    // pure virtual function
    virtual std::string getClassName() = 0;
};

// function prototype
constexpr inline void printClassName(Printable* obj) {
    std::cout << "Print class name: " << obj->getClassName() << "\n";
}

class Entity : public Printable
{
private:
    std::string className;
public:
    // implement defined interface
    std::string getClassName() override { return "Entity : public Printable"; }
};

class User : public Entity
{
private:
    std::string firstName;
    std::string lastName;
public:
    // implement defined interface
    std::string getClassName() override { return "User : public Entity"; }

    // constructor with member initialization list
    User(std::string fn, std::string ln) : firstName(fn), lastName(ln) {}

    // get function
    std::string getUserName() { return firstName + lastName; }
};

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
