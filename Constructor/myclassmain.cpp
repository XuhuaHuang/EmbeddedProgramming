/*****************************************************************//**
 * \file   myclassmain.cpp
 * \brief  contains test cases for custom defined class
 * 
 * \author Xuhua Huang
 * \date   March 2020
 *********************************************************************/

#include "myclass.h"

using namespace std;

int main (void)
{
	int choice;
	cout << "Which one is the case you want to test?" << endl;
	cout << "\tEnter 1 for time.\n\tEnter 2 for rectangle.\n\tEnter 3 for point." << endl;
	cin >> choice;
	
		if(choice ==1) // test case for 'mytime' class
		{
			mytime userTime; // declaring an object
		
			int userHour;
			cout << "Please enter the hour you want to set to." << endl;
			cin >> userHour;
			userTime.setHour(userHour); // call the set function with verification
	
			int userMinute;
			cout << "Please enter the minute you want to set to." << endl;
			cin >> userMinute;
			userTime.setMinute(userMinute); 
	
			int userSecond;
			cout << "Please enter the second you want to set to." << endl;
			cin >> userSecond;
			userTime.setSecond(userSecond); 
	
			userTime.printTime(); // this line should print the time user sets to
			// asking the user to set section ends
	
			// test cases and print function
			userTime.setTime(12,34); // valid hour, minute; should call mytime::setTime(int , int)
			userTime.printTime(); // 12:34:00
	
			userTime.setTime(25, 34); // invalid hour and valid minute; should call mytime::setTime(int, int)
			userTime.printTime(); // 00:34:00
		
			userTime.setTime(12, 60); // valid hour and invalid minute; should call mytime::setTime(int, int)	
			userTime.printTime(); // 12:00:00

			userTime.setTime(23); // valid hour; should call mytime::setTime(int userHour);
			userTime.printTime(); // 23:00:00
	
			// test cases of default and overloaded constructors
			mytime time1;
			time1.printTime();
	
			mytime time2(12, 34, 56);
			time2.printTime(); // 12:34:56
	
			mytime time3(12, 34);
			time3.printTime(); // 12:34:00
	
			mytime time4(12); // 12:00:00
			time4.printTime();
		}
		else if (choice == 2) // rectangle main
		{
			rectangle object1;
			cout << "A rectangle has been automatically created for you." << endl;
			cout << "The length of the object is: " << object1.getlength() << endl; // prints 0
			cout << "The width of the object is: " << object1.getwidth() << endl; // prints 0
	
			cout << "\nWould you like to initialize it yourself?" << endl;
			cout << "Enter 1 for yes or anything else to quit." << endl;
	
			bool usercomfirm;
			cin >> usercomfirm;
	
			if (usercomfirm) // if user wants to initialize it
			{	
				int userlength;
				int userwidth;
		
				cout << "Please enter the initial length of your rectangle." << endl;
				cin >> userlength;
				cout << "Please enter the initial width of your rectangle." << endl;
				cin >> userwidth;
		
				rectangle object2(userlength, userwidth); // object2 is created HERE with overloaded constructor	
				cout << "The length of the object is: " << object2.getlength() << endl; // prints length
				cout << "The width of the object is: " << object2.getwidth() << endl; // prints width
		
				object2.calcArea(object2.getlength(), object2.getwidth()); // area is calculated
				cout << "The area of the rectangle you just initialized is: " << object2.getarea() << endl; // prints the area
		
				object2.calcPerimeter(object2.getlength(), object2.getwidth()); // area is calculated
				cout << "The perimeter of the rectangle you just initialized is: " << object2.getperimeter() << endl; // prints the perimeter
			} // end if
			else
			{
				cout << "Have a nice day." << endl;		
			} // end else
		
		}
		else if (choice == 3) // point main
		{
			
			Point number1; // calling the default constructor
			cout << number1.getx() << endl;
			cout << number1.gety() << endl;
	
			Point number2(10, 10); // calling the overloaded constructor
			cout << number2.getx() << endl;
			cout << number2.gety() << endl;
		}
		else // other inputs, considered as invalid
			cout << "see ya. xD" << endl;

	return 0;
} // end main
