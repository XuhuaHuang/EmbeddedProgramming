#include <iostream>
#include <cmath>

// Xuhua Huang
// Created on: Nov 11, 2020

class mytime
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
		int getHour() {return hour;}
		int getMinute() {return minute;}
		int getSecond() {return second;}
		
		// other functions within the class
		void setTime(int userHour, int userMinute, int userSecond);
		void printTime();
		
		// overloaded functions with the same name and different arguments
		void setTime(int userHour, int userMinnute);
		void setTime(int userHour);
};


class mydate
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
		int getMonth() {return month;}
		int getDay() {return day;}
		int getYear() {return year;}
	
		// other functions
		void setDate(int userYear, int userMonth, int userDay);
		void printDate();
		
		// overloaded nextDay functions
		void nextDay(void);
		void nextDay(int dayslater);
		
};
