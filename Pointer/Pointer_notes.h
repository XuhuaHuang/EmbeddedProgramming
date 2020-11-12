/*
* Author: Xuhua Huang
* Taught by: Charmaine
* Pointer Lab In-class Notes Header File
*
* Contains declaration of:
* class 'mytime'
* class 'mydate'
* class 'Calendar'
*	- pointer to a 'mytime' object
*	- pointer to a 'mydate' object
*	- constructor and destructor
*/

class mytime
{

private:

	int hour;
	int minute;
	int second;

public:
	// default and overloaded constructor
	mytime(); // default
	mytime(int, int, int); // overloaded
	
	// set functions
	void setHour(int userHour); // definiton of set functions follow with validation
	void setMinute(int userMinute);
	void setSecond(int userSecond);

	// get functions
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

};

class mydate
{
private:
	int year;
	int month;
	int day;

public:
	
	// overloaded constructor
	mydate(int, int, int );

	// set functions:
	void setMonth(int userMonth); // definiton of set functions follow with validation
	void setDay(int userDay);
	void setYear(int userYear);

	// get functions:
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }

};

class Calendar
{
private:
	mytime* time;
	mydate* date;

public:

	Calendar(); // default constructor
	~Calendar(); // destructor

	void print();

	void setTime(mytime* newTime) { time = newTime; }
	mytime* getTime() { return time; } // return a pointer

	void setDate(mydate* newDate) { date = newDate; }
	mydate* getDate() { return date; } // return a pointer

};
