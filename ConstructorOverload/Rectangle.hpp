/*****************************************************************//**
 * \file   Rectangle.hpp
 * \brief  Class Rectangle declaration and definition.
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

class Rectangle // Rectangle class
{
private:
    int length;
    int width;
    int area;
    int perimeter; // private attributes

public:
    // set functions prototype
    void setlength(int userlength) { length = userlength; }
    void setwidth(int userwidth) { width = userwidth; }
    void setarea(int userarea) { area = userarea; }
    void setperimeter(int userperimeter) { perimeter = userperimeter; }

    // get functions prototype
    int getlength() { return length; }
    int getwidth() { return width; }
    int getarea() { return area; }
    int getperimeter() { return perimeter; }

    // constructor and overloaded constructor prototype
    Rectangle();
    Rectangle(int, int);
    int calcArea(int, int);
    int calcPerimeter(int, int);

};

Rectangle::Rectangle() // default constructor the main will call when creating an object
{
    setlength(0);
    setwidth(0);
}

Rectangle::Rectangle(int inilength, int iniwidth) // overloaded with two arguments passed from the main
{
    setlength(inilength);
    setwidth(iniwidth);
}

int Rectangle::calcArea(int inilength, int iniwidth)
{
    int area = inilength * iniwidth;
    return area;
}

int Rectangle::calcPerimeter(int inilength, int iniwidth)
{
    int perimeter = (inilength + iniwidth) * 2;
    return perimeter;
}

#endif
