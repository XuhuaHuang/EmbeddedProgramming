/*****************************************************************//**
 * \file   insertion_extraction.cpp
 * \brief  custom class 'User' for demonstractig overloading operator
 *
 * 1) == equal to
 * 2) << ostream
 * 3) >> istream
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

class User
{
private:
    std::string firstName;
    std::string lastName;
    std::string status;

public:
    static int userCount;

    // set and get for private attribute firstName
    void setFirstName(std::string userFirstName) { firstName = userFirstName; }
    std::string getFirstName(void) { return firstName; }

    // set and get for private attribut lastName
    void setLastName(std::string userLastName) { lastName = userLastName; }
    std::string getLastName(void) { return lastName; }

    // set and get for private attribute status
    void setStatus(std::string userStatus) { status = userStatus; }
    std::string getStatus(void) { return status; }

    // only get function for static member userCount
    int getUserCount(void) { return userCount; }

    // constructor with iteam constructor
    User() : firstName("unknown"), lastName("unknown") { userCount++; }
    User(std::string initFirstN, std::string initLastN, std::string initStatus) :
        firstName(initFirstN), lastName(initLastN), status(initStatus) {
        userCount++;
    }
    // destructor
    ~User() { userCount--; }

    // overload operator
    // 'argUser' stands for "argument user"
    bool operator == (User argUser);
    friend std::ostream& operator << (std::ostream& output, User argUser);
    friend std::istream& operator >> (std::istream& input, User& argUser);
};

int User::userCount = 0; // initialize with one line assignment -std=c++11

bool User::operator == (User argUser)
{
    bool equal = false;

    if (this->getFirstName() == argUser.getFirstName() &&
        this->getLastName() == argUser.getLastName() &&
        this->getStatus() == argUser.getStatus()) {
        equal = true;
    } // end if

    return equal;
}

std::ostream& operator << (std::ostream& output, User argUser)
{
    output << "\nUser: " << argUser.getFirstName() << " "
        << argUser.getLastName() << "\n"
        << "Status: " << argUser.getStatus() << "\n";

    return output;
}

std::istream& operator >> (std::istream& input, User& argUser)
{
    std::string initFirstName, initLastName, initStaus;
    input >> initFirstName >> initLastName >> initStaus;

    argUser.setFirstName(initFirstName);
    argUser.setLastName(initLastName);
    argUser.setStatus(initStaus);

    return input;
}

int main(void)
{
    User user;
    std::cout << "Please enter first name, last name and status "
        << "of your customized user: ";
    std::cin >> user;
    std::cout << "\nPrintint the status of the user you just initialized: " << user << "\n";

    return 0;
}
