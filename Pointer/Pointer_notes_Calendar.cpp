/*
* Author: Xuhua Huang
* Taught by: Charmaine
* Pointer Lab In-class Notes - Calendar Class Functions
*
* Contains function definitions of:
* Class 'Calendar'
*	- constructor
*	- destructor
*	- print
* 
* Notice: ALL "cout" statements inside a function are appened
* after signature "[fn]" which stands for printing from function
* [DECONST] printed from default constructor
* [OLCONST] printed from overloaded constructor
* [DEST] printed from destructor
*/

#include <iostream>
#include <cmath>
#include "Pointer_notes.h"

using namespace std;

// Xuhua Huang
// Created on: Nov 11, 2020

Calendar::Calendar()
{
	/*
	* mytime* t = new mytime(14, 25, 0);
	* setTime(t);
	*/
	setTime(new mytime(14, 25, 0));
	setDate(new mydate(2020, 11, 11));

	cout << "\n[DECONST]Creating time and date objects." << endl;
}

Calendar::~Calendar()
{
	delete time;
	delete date;

	cout << "\n[DEST]Deleting time and fate objects." << endl;
}

void Calendar::print()
{
	mytime* temp = getTime(); // creating a temporary pointer
	cout << "\n[fn]Printig current time: " << endl
		 << temp->getHour() << " : "
		 << temp->getMinute() << " : "
		 << temp->getSecond() << endl;
	
	mydate* temp2 = getDate(); // creating a temporary pointer
	cout << "\n[fn]Printig current date: " << endl
		 << temp2->getYear() << " / "
		 << temp2->getMonth() << " / "
		 << temp2->getDay() << endl;

	return;
}
