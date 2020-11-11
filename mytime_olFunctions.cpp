#include <iostream>
#include <cmath>

using namespace std;

// 1879700 Xuhua Huang

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


int main (void)
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
	return 0;
}


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
