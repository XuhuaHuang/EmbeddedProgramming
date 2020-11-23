/*****************************************************************//**
 * \file   example_Polymorphism.cpp
 * \brief
 *   
 * 1) The virtual keyword allows a member function of a derived class 
 *	  with the same name as a member function in the base class to be 
 *	  appropriately called from a pointer.
 * 
 * 2) The type of the pointer is a pointer to the base class 
 *	  but is pointing to an object of the derived class
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;

public:

	// function prototype
	void set_values(int a, int b) { width = a; height = b; }

	// "Polygon" is a 'polymorphic class'
	virtual int area() { return 0; } // virtual keyword ensures 
	// Polygon* to access class function for address-linked-object 
};

class Rectangle : public Polygon
{
public:
	int area() { return (width * height); }
};

class Triangle : public Polygon
{
public:
	int area() { return (width * height / 2); }
};

int main()
{
	Rectangle rect;
	Triangle trgl;
	Polygon poly;
	Polygon* ppoly1;

	ppoly1 = &rect; // point to a "Rectangle" class object
	ppoly1->set_values(4, 5);
	cout << ppoly1->area() << endl; // will print 0 if without "virtual" keyword

	ppoly1 = &trgl; // pointing to a "Triangle" class object
	ppoly1->set_values(4, 5);
	cout << ppoly1->area() << endl; // will print 0 if without "virtual" keyword

	ppoly1 = &poly; // pointing to a same-base class obeject
	ppoly1->set_values(4, 5);
	cout << ppoly1->area() << endl; // 0

	return 0;
}
