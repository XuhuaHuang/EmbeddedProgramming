/*****************************************************************//**
 * \file   lab_Time_Date.h
 * \brief  class Time and Date
 *		   class Time is made friend of class Date
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#pragma once
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
