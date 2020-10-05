#include <iostream>
#include <cmath>

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
