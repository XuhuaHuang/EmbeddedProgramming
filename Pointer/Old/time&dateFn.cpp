#include "mytime.h"
using namespace std;

// Xuhua Huang 1879700

// mytime class functions:
void mytime::setHour (int userHour) // hour should be valid form 0 to 23
{
	if ((userHour >= 0) && (userHour <= 23))
	{
		hour = userHour;
	}	
	else if (userHour == 24)
	{
		cout << "Do you mean 0 a.m.? It is automatically set to 0 a.m." << endl;
		hour = 0;
	}
	else
	{
		cout << "Invalid value " << userHour << endl;
		hour = 0;
	}
	
	return;
}

void mytime::setMinute (int userMinute) // minute should be valid from 0 to 59
{
	if ((userMinute >= 0) && (userMinute <= 59))
	{
		minute = userMinute;
	}	
	else
	{
		cout << "Invalid value " << userMinute << endl;
		minute = 0;
	}
	
	return;
}

void mytime::setSecond (int userSecond) // second should be valid form 0 to 59
{
	if ((userSecond >= 0) && (userSecond<= 59))
	{
		second = userSecond;
	}	
	else
	{
		cout << "Invalid value " << userSecond << endl;
		second = 0;
	}
	
	return;
}

void mytime::setTime(int userHour, int userMinute, int userSecond) // original set time functions with three variables
{
	setHour(userHour);
	setMinute(userMinute);
	setSecond(userSecond);
	
	return;
}

void mytime::printTime()
{
	cout << getHour() << ":" << getMinute() << ":" << getSecond() << endl; // using get functions to get value with verification
	
	return;
}


void mytime::setTime(int userHour, int userMinute) // overloaded function #1
{
	setHour(userHour);
	setMinute(userMinute);
	
	setSecond(0); // to keep the variable from garbage variable
	
	return;
}


void mytime::setTime(int userHour) // overloaded function #2
{
	setHour(userHour);
	
	setMinute(0); // set default value 0 for testing
	setSecond(0);
	
	return;
}


// my date class functions:
void mydate::setYear(int userYear)
{
	 if(userYear >= 1900) 
		year = userYear;
	else
	{
		//cout << "Invalid value. Setting year to 1900" << endl;
		year = 1900;
	}		
	return;
}

void mydate::setMonth(int userMonth)
{
	 if ( (userMonth > 0) && (userMonth <= 12) )
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
	if ( (userDay > 0) && (userDay <= 31) )
		day = userDay;
	else
	{
		//cout << "Invalid day value. Setting day to 1." << endl;
		day = 1;
	}
	
	return;
}

void mydate::setDate(int userYear, int userMonth, int userDay)
{
	setYear(userYear);
	setMonth(userMonth);
	setDay(userDay);

	return;
}
	
void mydate::printDate()
{
	/*
	cout << "It's the year of: " << getYear() << endl;
	cout << "It's the Month of: " << getMonth() << endl;
	cout << "It's the day of: " << getDay() << endl;	
	*/
	
	cout << "It's " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
	
	return;
}

void mydate::nextDay(void)
{
	//cout << "\nIncrementing the day by one..." << endl;
	setDay( getDay()+1 );
	
	if( getDay() == 1 ) // increment to 32 and enter new month
		setMonth( getMonth()+1 ); // current month + 1
	
	if( (getMonth() == 1) && (getDay() == 1) )// increment to next year
		setYear( getYear() + 1 ); // current  year + 1
	
	return;
}

void mydate::nextDay(int dayslater)
{
	
	for(int i = 0; i < dayslater; i++)
	{
		nextDay();		
	}
		
	return;
}
