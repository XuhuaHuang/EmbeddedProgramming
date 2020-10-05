#include <iostream>

using namespace std;

class rectangle
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

int main(void)
{
	
	rectangle object1;
	cout << "A rectangle has been automatically created for you." << endl;
	cout << "The length of the object is: " << object1.getlength() << endl; // prints 0
	cout << "The width of the object is: " << object1.getwidth() << endl; // prints 0
	
	cout << "\nWould you like to initialize it yourself?" << endl;
	cout << "Enter 1 for yes or anything else to quit." << endl;
	
	bool usercomfirm;
	cin >> usercomfirm;
	
	if (usercomfirm) // if user wants to initialize it
	{	
		int userlength;
		int userwidth;
		
		cout << "Please enter the initial length of your rectangle." << endl;
		cin >> userlength;
		cout << "Please enter the initial width of your rectangle." << endl;
		cin >> userwidth;
		
		rectangle object2(userlength, userwidth); // object2 is created HERE with overloaded constructor	
		cout << "The length of the object is: " << object2.getlength() << endl; // prints length
		cout << "The width of the object is: " << object2.getwidth() << endl; // prints width
		
		object2.calcArea(object2.getlength(), object2.getwidth()); // area is calculated
		cout << "The area of the rectangle you just initialized is: " << object2.getarea() << endl; // prints the area
		
		object2.calcPerimeter(object2.getlength(), object2.getwidth()); // area is calculated
		cout << "The perimeter of the rectangle you just initialized is: " << object2.getperimeter() << endl; // prints the perimeter
	} // end if
	else
	{
		cout << "Have a nice day." << endl;		
	} // end else
	
	return 0;
} // end main

rectangle::rectangle() // default constructor the main will call when creating an object
{
	setlength(0);
	setwidth(0);
}

rectangle::rectangle(int inilength, int iniwidth) // overloaded with two arguments passed from the main
{
	setlength(inilength);
	setwidth(iniwidth);
}

int rectangle::calcArea(int inilength, int iniwidth)
{
	int area = inilength * iniwidth;
	return area;
}

int rectangle::calcPerimeter(int inilength, int iniwidth)
{
	int perimeter = ( inilength + iniwidth ) *2;
	return perimeter;
}
