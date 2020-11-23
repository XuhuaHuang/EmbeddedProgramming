/*****************************************************************//**
 * \file   example_Square_Rectangle.cpp
 * \brief  class "Square" made friend of class "rectangle"
 * 
 * worth noting:
 * 1) granting the other class to access the protected and private
 *	  data members of the class made friend with.
 * 2) class friendship is not bidirectional. Need to specify.
 * 3) class friendship is not transmitive:
 *		The friend of a friend is not considered to be a friend
 *		unless explicitly specified.
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
using namespace std;

class Square
{
private:
	int side;

public:
	
	void setSide(int a) { side = a; }

	// Square class allows Rectangle class to access its private data members.
	friend class Rectangle;
	// conflict the concept of class encapsulation
};

class Rectangle
{
private:
	int width, height;

public:

	int area() { return (width * height); }
	void convert(Square a);
};

void Rectangle::convert(Square a)
{
	width = a.side;
	height = a.side;
	// Rectangle class using Square's private data members (side)

	return;
}

int main(void)
{
	Square sqr;
	Rectangle rect;

	sqr.setSide(4);
	rect.convert(sqr);

	cout << rect.area() << endl;

	return 0;
}
