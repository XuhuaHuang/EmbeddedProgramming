/*****************************************************************//**
 * \file   lab_Time_Date_complete.cpp
 * \brief  complete version of the lab
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;

public:

	// set functions
	void setHour(int userHour); // definiton of set functions follow with validation
	void setMinute(int userMinute);
	void setSecond(int userSecond);

	// get functions
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

	// other functions within the class
	void setTime(int userHour, int userMinute, int userSecond);
	// void printTime(); this line is commented out because void Date::printDate(Time time) {}

	// overloaded functions with the same name and different arguments
	void setTime(int userHour, int userMinnute);
	void setTime(int userHour);

	friend class Date; //  class "Time" is made friend to class "Date"
};


class Date
{
private:
	int year;
	int month;
	int day;

public:

	// set functions:
	void setMonth(int userMonth);
	void setDay(int userDay);
	void setYear(int userYear);

	// get functions:
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }

	// other functions
	void setDate(int userYear, int userMonth, int userDay);
	void printDate(Time time);

	// friend class Time;
};

int main(void)
{
	Time time; // create a Time object
	Date date; // create a data object

	// initialize diffeerent properties for object "time" and "date"
	time.setTime(14, 30, 30);
	date.setDate(2020, 11, 23);

	date.printDate(time);

	return 0;
}

// class "Time" functions:
void Time::setHour(int userHour) // hour should be valid form 0 to 23
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
		cout << "\n[fn]Invalid hour value " << userHour << endl;
		hour = 0;
	}

	return;
}

void Time::setMinute(int userMinute) // minute should be valid from 0 to 59
{
	if ((userMinute >= 0) && (userMinute <= 59))
	{
		minute = userMinute;
	}
	else
	{
		cout << "\n[fn]Invalid minute value " << userMinute << endl;
		minute = 0;
	}

	return;
}

void Time::setSecond(int userSecond) // second should be valid form 0 to 59
{
	if ((userSecond >= 0) && (userSecond <= 59))
	{
		second = userSecond;
	}
	else
	{
		cout << "\n[fn]Invalid second value " << userSecond << endl;
		second = 0;
	}

	return;
}

// original set time functions with three variables
void Time::setTime(int userHour, int userMinute, int userSecond) 
{
	setHour(userHour);
	setMinute(userMinute);
	setSecond(userSecond);

	return;
}

/*
* void Time::printTime() // not required
* {
*	cout << "\n[fn]It's " << getHour() << " : " << getMinute() << " : " << getSecond() << endl;
*	// using get functions to get value with verification
*
*	return;
* }
*/

void Time::setTime(int userHour, int userMinute) // overloaded function #1
{
	setHour(userHour);
	setMinute(userMinute);

	setSecond(0); // to keep the variable from garbage variable

	return;
}


void Time::setTime(int userHour) // overloaded function #2
{
	setHour(userHour);

	setMinute(0); // set default value 0 for testing
	setSecond(0);

	return;
}

// class "Date" class functions:
void Date::setYear(int userYear)
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

void Date::setMonth(int userMonth)
{
	if ((userMonth > 0) && (userMonth <= 12))
		month = userMonth;
	else
	{
		cout << "\n[fn]Invalid month value. Setting month to 1." << endl;
		month = 1;
	}

	return;
}

void Date::setDay(int userDay)
{
	if ((userDay > 0) && (userDay <= 31))
		day = userDay;
	else
	{
		cout << "\n[fn]Invalid day value. Setting day to 1." << endl;
		day = 1;
	}

	return;
}

void Date::setDate(int userYear, int userMonth, int userDay)
{
	setYear(userYear);
	setMonth(userMonth);
	setDay(userDay);

	return;
}

void Date::printDate(Time time)
{
	cout << "\n[fn]\"void Date::printDate(Time time)\" called" << endl
		 << "[fn]Date: " << this->getMonth() << "/" 
						 << this->getDay() << "/" 
						 << this->getYear() << endl
		 << "[fn]Time: " << time.getHour() << ":" 
						 << time.getMinute() << ":" 
						 << time.getSecond() << endl;

	return;
}
