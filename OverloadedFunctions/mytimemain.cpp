#include "mytime.h"
using namespace std;

// Xuhua Huang 1879700

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
	cout << "Test case 1: valid hour and minute." << endl;
	userTime.setTime(12,34); // valid hour, minute; should call mytime::setTime(int , int)
	userTime.printTime(); // 12:34:00
	
	cout << "Test case 2: invalid hour and valid minute." << endl;
	userTime.setTime(25, 34); // invalid hour and valid minute; should call mytime::setTime(int, int)
	userTime.printTime(); // 00:34:00
	
	cout << "Test case 3: valid hour and invalid minute." << endl;
	userTime.setTime(12, 60); // valid hour and invalid minute; should call mytime::setTime(int, int)	
	userTime.printTime(); // 12:00:00

	cout << "Test case 4: valid hour4." << endl;
	userTime.setTime(23); // valid hour; should call mytime::setTime(int userHour);
	userTime.printTime(); // 23:00:00
	
	cout << "Test case 5: invalid hour." << endl;
	userTime.setTime(25); // invalid hour; should call mytime::setTime(int userHour);
	userTime.printTime(); // 00:00:00
	
	return 0;
}
