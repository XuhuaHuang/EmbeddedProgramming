/* clang-format off */
/*****************************************************************//**
 * \file   main.cpp
 * \brief  Scratch program using refactoring approach.
 *
 * \author Xuhua Huang
 * \date   September 2021
 *********************************************************************/
/* clang-format on */

#include <array>
#include <iostream>
#include <stdlib.h>
#include <string>

#ifndef DEBUG
#define DEBUG 1
#if DEBUG
#define DEBUG(output) std::cout << output << "\n"
#endif
#endif

#ifndef _MAXSIZE
#define _MAXSIZE 20
#endif

enum Sex
{
    female = 0,
    male   = 1
};

class Person
{
public:
    /* Public default and overloaded constructor. */
    /* Default constructor */
    explicit Person()
        : _name("")
        , _sex(Sex::female)
        , _tell("")
        , _email("")
        , _addr("")
    {
        DEBUG("Default constructor for class Person");
    }
    /* Overloaded constructor */
    explicit Person(const std::string name,
                    const int         sex,
                    const std::string tell,
                    const std::string email,
                    const std::string addr = "")
    {
        DEBUG("Overloaded constructor for class Person");
        this->setName(name);
        this->setSex(sex);
        this->setTell(tell);
        this->setEmail(email);
        this->setAddr(addr);
    }
    virtual ~Person() = default;

    /**
     * Provide mutator and accessors for private members.
     */
    void setName(const std::string name)
    {
        if (name != "\n")
            _name = name;
        else
            DEBUG("Error occurred while setting name! Empty argument.");
    }

    void setSex(const int sex)
    {
        if (sex)
            _sex = Sex::male;
        else if (!sex)
            _sex = Sex::female;
        else
            DEBUG("Error occurred while setting sex! Non-binary argument.");
    }

    void setTell(const std::string tell)
    {
        if (tell != "\n")
            _tell = tell;
        else
            DEBUG("Error occurred while setting phone number! Empty argument.");
    }

    void setEmail(const std::string email)
    {
        if (email != "\n")
            _email = email;
        else
            DEBUG("Error occurred while setting phone number! Empty argument.");
    }

    void setAddr(const std::string addr)
    {
        _addr = addr; // with provided default argument in overloaded constructor
    }

    std::string name() const { return _name; }
    std::string sex() const { return _sex ? "Male" : "Female"; }
    std::string tell() const { return _tell; }
    std::string email() const { return _email; }
    std::string addr() const { return _addr; }

    /* Add support for use case like "std::cout << person;" */
    friend std::istream& operator>>(std::istream& input, Person& argPerson);
    friend std::ostream& operator<<(std::ostream&, const Person&);

private:
    Person(const Person&) = delete;

    /* Private attributes associated with individuals. */
    std::string _name;
    int         _sex;
    std::string _tell;
    std::string _email;
    std::string _addr;
};

/* UI namespace contains all required function for View. */
namespace UI
{

namespace interact
{
/* Print instruction in terminal and store answer in reference variable. */
void input(const std::string instruction, std::string& answer)
{
    if (instruction != "\n")
    {
        std::cout << instruction;
        std::getline(std::cin, answer);
    }
    else
        DEBUG("Error occurred while asking for input! Invalid instruction.");
}
} // namespace interact

namespace display
{

void printAsterisks(const int numToPrint = 43, const std::string arg = "")
{
    for (int i = 0; i < numToPrint; ++i)
    {
        std::cout << "*";
    }
    std::cout << "\n";
}

void printInstructions(const std::string arg = "")
{
    printAsterisks();
    std::cout << "*** Press 0 to print all saved contacts ***"
              << "\n"
              << "*** Press 1 to add a new contact to App ***"
              << "\n"
              << "*** Press 2 to look up saved individual ***"
              << "\n"
              << "*** Press 3 to delete a contact by name ***"
              << "\n"
              << "*** Press 4 to remove all saved contact ***"
              << "\n";
    printAsterisks();
}

void clearScreen()
{
    system("CLS");
}
} // namespace display
} // namespace UI

std::istream& operator>>(std::istream& input, Person& argPerson)
{
    std::string name, sex, tell, email, address;

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

std::ostream& operator<<(std::ostream& output, const Person& argPerson)
{
    output << "\nPerson: " << argPerson.name() << ", " << argPerson.sex() << "\n"
           << "Tell: " << argPerson.tell() << "\n"
           << "Email: " << argPerson.email() << "\n"
           << "Address: " << argPerson.addr() << "\n";

    return output;
}


/* Define a Model class to contain data for Contacts Manager. */
class Model
{
public:
private:
    std::array<Person, _MAXSIZE> ContactsData;
};


/* Define a Controller class to control the flow of the program.
 * Need o provide the following functionality:
 * 1) insert
 * 2) look for
 *      i. output
 *      ii. delete
 *      iii. modify and save
 */
class Controller
{
public:
private:
};


/* Main function; Debug mode. */
int main(int argc, char* argv)
{
    Person demoPersonToAdd;
    std::cin >> demoPersonToAdd;
    std::cout << demoPersonToAdd;

    UI::display::printAsterisks();
    UI::display::printInstructions();

    system("pause");
    return 0;
}