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

using namespace std;

class User
{
private:
    string firstName;
    string lastName;
    string status;

public:
    static int userCount;
    
    // set and get for private attribute firstName
    void setFirstName(string userFirstName) { firstName = userFirstName; }
    string getFirstName(void) { return firstName; }

    // set and get for private attribut lastName
    void setLastName(string userLastName) { lastName = userLastName; }
    string getLastName(void) { return lastName; }

    // set and get for private attribute status
    void setStatus(string userStatus) { status = userStatus; }
    string getStatus(void) { return status; }

    // only get function for static member userCount
    int getUserCount(void) { return userCount; }

    // constructor with iteam constructor
    User() : firstName("unknown"), lastName("unknown") { userCount++; }
    User(string initFirstN, string initLastN, string initStatus) :
        firstName(initFirstN), lastName(initLastN), status(initStatus) {
        userCount++;
    }
    // destructor
    ~User() { userCount--; }
    
    // overload operator
    // 'argUser' stands for "argument user"
    bool operator == (User argUser);
    friend ostream& operator << (ostream& output, User argUser);
    friend istream& operator >> (istream& input, User &argUser);
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

ostream& operator << (ostream& output, User argUser)
{
    output << "\nUser: " << argUser.getFirstName() << " "
           << argUser.getLastName() << endl
           << "Status: " << argUser.getStatus() << endl;
    
    return output;
}

istream& operator >> (istream &input, User &argUser)
{
    string initFirstName, initLastName, initStaus;
    input >> initFirstName >> initLastName >> initStaus;

    argUser.setFirstName(initFirstName);
    argUser.setLastName(initLastName);
    argUser.setStatus(initStaus);

    return input;
}

int main(void)
{
    User user;
    cout << "Please enter first name, last name and status "
         << "of your customized user: ";
    cin >> user;
    cout << "\nPrintint the status of the user you just initialized: " << user << endl;

    return 0;
}
