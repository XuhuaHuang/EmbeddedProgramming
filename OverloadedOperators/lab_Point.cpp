/*****************************************************************//**
 * \file   lab_Point.cpp
 * \brief  five overloaded operators and test cases for each one
 * 
 * 1) + addition
 * 2) - subtraction
 * 3) * multiplication
 * 4) == equal to
 * 5) << ostream
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
	int x;
	int y;

public:

	// set and get function for x attribute
	void setX(int userX) { x = userX; }
	int getX(void) { return x; }

	// set and get function for y attribute
	void setY(int userY) { y = userY; }
	int getY(void) { return y; }

	// overloaded constructor
	Point() { setX(0); setY(0); }
	Point(int userX, int userY) { setX(userX); setY(userY); }

	// overload operators prototype
	Point operator+(Point pt); // +
	Point operator-(Point pt); // -
	Point operator*(Point pt); // *
	bool operator==(Point pt); // ==
	friend ostream& operator<<(ostream& os, Point& pt); // <<
};

Point Point::operator+(Point pt)
{
	Point newPt; // represents the point before "+" sign

	// add x and y of object newPt (current object) to x and y of object pt
	newPt.setX(this->getX() + pt.getX());
	newPt.setY(this->getY() + pt.getY());

	// return an object with the new values of x and y.
	return newPt;
}

Point Point::operator-(Point pt)
{
	Point newPt;

	// subtract x and y of object newPt (current object) to x and y of object pt
	newPt.setX(this->getX() - pt.getX());
	newPt.setY(this->getY() - pt.getY());

	// return an object with the new values of x and y.
	return newPt;
}

Point Point::operator*(Point pt)
{
	Point newPt;

	// subtract x and y of object newPt (current object) to x and y of object pt
	newPt.setX(this->getX() * pt.getX());
	newPt.setY(this->getY() * pt.getY());

	// return an object with the new values of x and y.
	return newPt;
}

bool Point::operator==(Point pt)
{
	bool equal = false;
	// short circuit comparison
	if (this->getX() == pt.getX() && this->getY() == pt.getY())
		equal = true;

	return equal;
}

ostream& operator<<(ostream& os, Point& pt)
{
	os << "\n[fn]Point has the following coordinates: " << endl
	   << "[fn]x = " << pt.getX() << endl
	   << "[fn]y = " << pt.getY();
	return os;
}

int main(void)
{
	// test case 1 + and <<
	Point point1(2, 3), point2(4, 5), point3;
	cout << "Test case 1: overloaded operator \"<<\" and \"+\": " << endl
		 << "Point \"point1\" is created (2, 3), \"point2\" is created (4, 5)" << endl;
	point3 = point1 + point2; // using overloaded operator "+"
	cout << "\nPrinting \"point3\": " << point3 << endl;  // using overloaded operator "<<"
											  // point3 = (6, 8)

	// test case 2 -
	cout << "\nTest case 2: overloaded operator \"-\"" << endl
		 << "Point \"point4\" is created (5, 7)" << endl 
		 << "\"point5 = point3 - point4 = (1, 1)\"" << endl;

	Point point4(5, 7);
	Point point5 = point3 - point4; // (6, 8) - (5, 7) = (1, 1)

	cout << "\nPrinting \"point5\": " << point5 << endl;
	
	// test case 3 ==
	cout << "\nTest case 3: overloaded operator \"==\"" << endl
		 << "\"point5\" is being compared to a test point" << endl
		 << "change the coordinate for the test point if need to" << endl;
	
	Point testPoint(1, 1);
	cout << "\nPrinting \"testPoint\": " << testPoint << endl;

	// bool equal = (point5 == testPoint); // uncomment these two lines if need to
	// cout << equal << endl;
	if (point5 == testPoint)
		cout << "\n\"point5\" is equal to \"testPoint\"." << endl;
	else
		cout << "\n\"point5\" is not equal to \"testPoint\"." << endl;
	
	// test case 4 *
	point5 = point3 * point4;
	
	cout << "\nTest case 4: overloaded operator \"*\"" << endl
		 << "\"point3\" is being multiplied with \"point4\"" << endl
		 << "Result is stored in \"point5\"" << endl
		 << "\nPrinting \"point5\": " << point5 << endl;

	return 0;
}
