// clang-format off
/*****************************************************************//**
 * \file   class_notes_User.cpp
 * \brief  brief notes on class
 *         By convention is to use smaller thing in structure
 *         more complex things in class
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>

class User
{
public:
    inline User();
    inline ~User();

    static inline int getUserCount(void) { return userCount; }

    inline void        setFirstName(std::string userFirstName) { firstName = userFirstName; }
    inline std::string getFirstName(void) { return firstName; }

    inline void        setLastName(std::string userLastName) { lastName = userLastName; }
    inline std::string getLastName(void) { return lastName; }

    inline void        setStatus(std::string userStatus) { status = userStatus; }
    inline std::string getStatus(void) { return status; }

    inline void printInfo(void);

private:
    static int  userCount; // a private static member data of the "User" class
    std::string firstName;
    std::string lastName;
    std::string status;
};

// initialized static class member data
int User::userCount = 0;

User::User() // default constructor
{
    userCount++; // increment static member data "userCount"
    // when a User object is created
}

inline User::~User() // destructor
{
    userCount--; // decrement static member data "userCount"
    // when a User object is destroyed
}

inline void User::printInfo(void)
{
    std::cout << "User " << firstName << " " << lastName << " is of status " << status << "\n";
}

int main(void)
{
    User user;
    user.setFirstName("Xuhua");
    user.setLastName("Huang");
    user.setStatus("Student");

    user.printInfo();

    return 0;
}
