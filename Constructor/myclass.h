#include <iostream>
#include <cmath>

// 1879700 Xuhua Huang


class mytime // mytime class
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
		
		// default and overloaded constructor
		mytime(); // default
		mytime(int, int, int); // overloaded
		mytime(int, int);
		mytime(int);
};



class rectangle // rectangle class
{
	
	private:
		int length;
		int width;
		int area;
		int perimeter; // private attributes
	
	public:
		// set functions prototype
		void setlength(int userlength) {length = userlength;}
		void setwidth(int userwidth) {width = userwidth;}
		void setarea(int userarea) {area = userarea;}
		void setperimeter(int userperimeter) {perimeter = userperimeter;}
		
		// get functions prototype
		int getlength() {return length;}
		int getwidth() {return width;}
		int getarea() {return area;}
		int getperimeter() {return perimeter;}
		
		// construtor and overloaded constructor prototype
		rectangle();
		rectangle(int, int);
		int calcArea(int, int);
		int calcPerimeter(int, int);
		
};


class Point // point class
{
	private:
		int x;
		int y;
	
	public:
		// set functions
		void setx(int userNum1) {x = userNum1;}
		void sety(int userNum2) {y = userNum2;}
		
		// get functions
		int getx() {return x;}
		int gety() {return y;}
		
		//constructer
		Point(); // no return type NOT even "void"
		Point(int iniX, int iniY); // overload constructor prototype
};
