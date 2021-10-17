/*
* Author: Xuhua Huang
* Taught by: Charmaine
* Pointer Lab In-class Notes
*
* Contains function definitions of:
* mytime
* mydate
* 
* Notice: ALL "cout" statements inside a function are appended
* after signature "[fn]" which stands for printing from function
*/

#include <iostream>
#include "Pointer_notes.h"

using namespace std;

// mytime class definitions
mytime::mytime() // default constructor
{
	setHour(0);
	setMinute(0);
	setSecond(0);
}

mytime::mytime(int h, int m, int s)  // object3(h,m,s )
{
	setHour(h); // calls the set functions with verification
	setMinute(m);
	setSecond(s);
}

void mytime::setHour(int userHour) // hour should be valid form 0 to 23
{
	if ((userHour >= 0) && (userHour <= 23))
	{
		hour = userHour;
	}
	else if (userHour == 24)
	{
		cout << "\n[fn]Do you mean 0 a.m.? It is automatically set to 0 a.m." << endl;
		hour = 0;
	}
	else
	{
		cout << "\n[fn]Invalid value " << userHour << endl;
		hour = 0;
	}

	return;
}

void mytime::setMinute(int userMinute) // minute should be valid from 0 to 59
{
	if ((userMinute >= 0) && (userMinute <= 59))
	{
		minute = userMinute;
	}
	else
	{
		cout << "\n[fn]Invalid value " << userMinute << endl;
		minute = 0;
	}

	return;
}

void mytime::setSecond(int userSecond) // second should be valid form 0 to 59
{
	if ((userSecond >= 0) && (userSecond <= 59))
	{
		second = userSecond;
	}
	else
	{
		cout << "\n[fn]Invalid value " << userSecond << endl;
		second = 0;
	}

	return;
}


// my date class functions:
mydate::mydate(int userYear, int userMonth, int userDay)
{
	setYear(userYear);
	setMonth(userMonth);
	setDay(userDay);
}

void mydate::setYear(int userYear)
{
	if (userYear >= 1900)
		year = userYear;
	else
	{
		cout << "\n[fn]Invalid value. Setting year to 1900" << endl;
		year = 1900;
	}
	return;
}

void mydate::setMonth(int userMonth)
{
	if ((userMonth > 0) && (userMonth <= 12))
		month = userMonth;
	else
	{
		//cout << "Invalid month value. Setting month to 1." << endl;
		month = 1;
	}

	return;
}

void mydate::setDay(int userDay)
{
	if ((userDay > 0) && (userDay <= 31))
		day = userDay;
	else
	{
		//cout << "Invalid day value. Setting day to 1." << endl;
		day = 1;
	}

	return;
}