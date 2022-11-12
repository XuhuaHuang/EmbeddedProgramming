/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang (Student #: 1879700)
 * \date   October 07, 2020
 *********************************************************************/

#include "MyTime.h"

int main (void)
{
    MyTime userTime; // declaring an object

    int userHour;
    std::cout << "Please enter the hour you want to set to." << "\n";
    std::cin >> userHour;
    userTime.setHour(userHour); // call the set function with verification

    int userMinute;
    std::cout << "Please enter the minute you want to set to." << "\n";
    std::cin >> userMinute;
    userTime.setMinute(userMinute); 

    int userSecond;
    std::cout << "Please enter the second you want to set to." << "\n";
    std::cin >> userSecond;
    userTime.setSecond(userSecond); 

    userTime.printTime(); // this line should print the time user sets to
    // asking the user to set section ends

    // test cases and print function
    std::cout << "Test case 1: valid hour and minute." << "\n";
    userTime.setTime(12,34); // valid hour, minute; should call MyTime::setTime(int , int)
    userTime.printTime(); // 12:34:00

    std::cout << "Test case 2: invalid hour and valid minute." << "\n";
    userTime.setTime(25, 34); // invalid hour and valid minute; should call MyTime::setTime(int, int)
    userTime.printTime(); // 00:34:00

    std::cout << "Test case 3: valid hour and invalid minute." << "\n";
    userTime.setTime(12, 60); // valid hour and invalid minute; should call MyTime::setTime(int, int)	
    userTime.printTime(); // 12:00:00

    std::cout << "Test case 4: valid hour4." << "\n";
    userTime.setTime(23); // valid hour; should call MyTime::setTime(int userHour);
    userTime.printTime(); // 23:00:00

    std::cout << "Test case 5: invalid hour." << "\n";
    userTime.setTime(25); // invalid hour; should call MyTime::setTime(int userHour);
    userTime.printTime(); // 00:00:00

    return 0;
}
