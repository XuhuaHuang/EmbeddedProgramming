/*****************************************************************//**
 * \file   main.cpp
 * \brief  Test cases for custom defined class
 *
 * \author Xuhua Huang
 * \date   March 2020
 *********************************************************************/


#include <iostream>

#include "TIme.hpp"
#include "Rectangle.hpp"
#include "Point.hpp"

int main(void)
{
    int choice;
    std::cout << "Which one is the case you want to test?" << "\n";
    std::cout << "\tEnter 1 for time.\n\tEnter 2 for rectangle.\n\tEnter 3 for point." << "\n";
    std::cin >> choice;

    if (choice == 1) // test case for 'MyTime' class
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
        userTime.setTime(12, 34); // valid hour, minute; should call MyTime::setTime(int , int)
        userTime.printTime(); // 12:34:00

        userTime.setTime(25, 34); // invalid hour and valid minute; should call MyTime::setTime(int, int)
        userTime.printTime(); // 00:34:00

        userTime.setTime(12, 60); // valid hour and invalid minute; should call MyTime::setTime(int, int)	
        userTime.printTime(); // 12:00:00

        userTime.setTime(23); // valid hour; should call MyTime::setTime(int userHour);
        userTime.printTime(); // 23:00:00

        // test cases of default and overloaded constructors
        MyTime time1;
        time1.printTime();

        MyTime time2(12, 34, 56);
        time2.printTime(); // 12:34:56

        MyTime time3(12, 34);
        time3.printTime(); // 12:34:00

        MyTime time4(12); // 12:00:00
        time4.printTime();
    }
    else if (choice == 2) // Rectangle main
    {
        Rectangle object1;
        std::cout << "A rectangle has been automatically created for you." << "\n";
        std::cout << "The length of the object is: " << object1.getlength() << "\n"; // prints 0
        std::cout << "The width of the object is: " << object1.getwidth() << "\n"; // prints 0

        std::cout << "\nWould you like to initialize it yourself?" << "\n";
        std::cout << "Enter 1 for yes or anything else to quit." << "\n";

        bool usercomfirm;
        std::cin >> usercomfirm;

        if (usercomfirm) // if user wants to initialize it
        {
            int userlength;
            int userwidth;

            std::cout << "Please enter the initial length of your rectangle." << "\n";
            std::cin >> userlength;
            std::cout << "Please enter the initial width of your rectangle." << "\n";
            std::cin >> userwidth;

            Rectangle object2(userlength, userwidth); // object2 is created HERE with overloaded constructor
            std::cout << "The length of the object is: " << object2.getlength() << "\n"; // prints length
            std::cout << "The width of the object is: " << object2.getwidth() << "\n"; // prints width

            object2.calcArea(object2.getlength(), object2.getwidth()); // area is calculated
            std::cout << "The area of the rectangle you just initialized is: " << object2.getarea() << "\n"; // prints the area

            object2.calcPerimeter(object2.getlength(), object2.getwidth()); // area is calculated
            std::cout << "The perimeter of the rectangle you just initialized is: " << object2.getperimeter() << "\n"; // prints the perimeter
        } // end if
        else
        {
            std::cout << "Have a nice day." << "\n";
        } // end else

    }
    else if (choice == 3) // point main
    {
        Point number1; // calling the default constructor
        std::cout << number1.getx() << "\n";
        std::cout << number1.gety() << "\n";

        Point number2(10, 10); // calling the overloaded constructor
        std::cout << number2.getx() << "\n";
        std::cout << number2.gety() << "\n";
    }
    else { // other inputs, considered as invalid
        std::cout << "see ya. xD" << "\n";
    }

    system("pause");
    return 0;
} // end main
