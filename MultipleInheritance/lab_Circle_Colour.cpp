/*****************************************************************//**
 * \file   lab_Circle_Colour.cpp
 * \brief  class Circle, Colour, CC for multiple inheritance
 *	   one-line default and overloaded constructor
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

#ifndef PI // if 'PI' is not defined
#define PI 3.14159265359
#endif

using namespace std;

class Circle
{
private:
	int radius;
	double area;

public:
	// set and get functions
	// for attribute 'radius'
	void setRadius(int newRadius) { radius = newRadius; }
	int getRadius(void) { return radius; }

	// for attribute 'area'
	void setArea(double newArea) { area = newArea; }
	double getArea(void) { return area; }

	// default constructor
	Circle() { setRadius(0); setArea(0); }
	// overrload constructor takes radius and calculate the area
	Circle(int newRadius) { setRadius(newRadius); setArea((double)newRadius * newRadius* PI); }
};

class Colour
{
private:
	string lineColour;
	string fillColour;

public:
	// set and get functions
	// for attribute lineColour
	void setLineColour(string newLineColour) { lineColour = newLineColour; }
	string getLineColour(void) { return lineColour; }

	// for attribute fillColoour
	void setFillColour(string newFillColour) { fillColour = newFillColour; }
	string getFillColour(void) { return fillColour; }

	// default constructor
	Colour() { setLineColour("none"); setFillColour("none"); }
	// overload constructor
	Colour(string customColour) { setLineColour(customColour); setFillColour(customColour); }
};

class CC : public Circle, public Colour
{
public:

	// default constructor
	CC() : Circle(), Colour() {}
	// overload constructor
	CC(int newRadius, string customColour) : Circle(newRadius), Colour(customColour) {}
};

int main(void)
{
	// test case 1 - default constructor
	CC ccobj1;
	cout << "\nTest case 1 with default constructor." << endl
	     << "An object called \"ccobj1\" is created: " << endl
	     << "\tArea: " << ccobj1.getArea() << endl
	     << "\tLine colour: " << ccobj1.getLineColour() << endl
	     << "\tFill colour: " << ccobj1.getFillColour() << endl;

	// test case 2 - overload constructor
	CC ccobj2(2, "red"); // (newRadius, customColour)
	cout << "\nTest case 2 with overloaded constructor." << endl
	     << "An object called \"ccobj2\" is created: " << endl
	     << "\tArea: " << ccobj2.getArea() << endl
	     << "\tLine colour: " << ccobj2.getLineColour() << endl
	     << "\tFill colour: " << ccobj2.getFillColour() << endl;

	return 0;
}
