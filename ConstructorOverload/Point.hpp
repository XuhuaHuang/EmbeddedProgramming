/*****************************************************************//**
 * \file   Point.hpp
 * \brief  Class Point declaration and definition.
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

class Point
{
private:
    int x;
    int y;

public:
    // set functions
    void setx(int userNum1) { x = userNum1; }
    void sety(int userNum2) { y = userNum2; }

    // get functions
    int getx() { return x; }
    int gety() { return y; }

    //constructor
    Point(); // no return type NOT even "void"
    Point(int initX, int initY); // overload constructor prototype
};

Point::Point() // default cinstructor // constructors always have the same name with the class
{
    setx(0); // calling the set functions with argument 0
    sety(0);
}

Point::Point(int initX, int initY)
{
    setx(initX);
    sety(initY);
}

#endif
