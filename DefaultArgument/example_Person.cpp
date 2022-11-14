/*****************************************************************//**
 * \file   example_Person.cpp
 * \brief  In-class example, provide an example on default argument
 *
 * Things to know: When a function has a mixture of parameters
 * both with and without default arguments
 * parameters with default arguments must be declared last.
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>

class Person
{
public:
    // get and set functions for private attributes
    void setName(std::string userName) { name = userName; }
    std::string getName() { return name; }

    void setAge(int userAge) { age = userAge; }
    int getAge() { return age; }

    // other functions:
    void setData(std::string userUame, int age = 12);
    void printData();

private:
    std::string name;
    int age;
};

void Person::setData(std::string userName, int age)
{
    setName(userName);
    setAge(age);
}

void Person::printData()
{
    std::cout << "Person's name is: " << name << " of " << age << " years old." << "\n";
}

int main(void)
{
    // test case 1
    Person person1;
    person1.setData("hello", 24); // overwrite the age to 24
    person1.printData(); // print age = 24

    /*
    person1.setData("Charles"); // age will be set to 12
    person1.printData(); // Charles, 12
    */

    // test case 2
    Person person2;
    person2.setData("world"); // age is default to 12
    person2.printData(); // print age = 12

    return 0;
}
