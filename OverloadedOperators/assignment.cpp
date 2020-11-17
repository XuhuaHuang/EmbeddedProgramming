/*****************************************************************//**
 * \file   overload_assignment.cpp
 * \brief  Overloaded assignment operator 
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

using namespace std;

class point
{
public:
	int _x; int _y;

	point& operator= (const point&);
};

point& point::operator=(const point& otherPoint)
{
	_x = otherPoint._x;
	_y = otherPoint._y;

	return *this;
}

int main(void)
{
	point ptr1, ptr2;
	ptr1 = ptr2;

	return 0;
}
