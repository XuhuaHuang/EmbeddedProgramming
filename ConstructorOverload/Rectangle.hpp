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
    inline void setlength(int userlength) { length = userlength; }
    inline void setwidth(int userwidth) { width = userwidth; }
    inline void setarea(int userarea) { area = userarea; }
    inline void setperimeter(int userperimeter) { perimeter = userperimeter; }

    // get functions prototype
    inline int getlength() { return length; }
    inline int getwidth() { return width; }
    inline int getarea() { return area; }
    inline int getperimeter() { return perimeter; }

    // constructor and overloaded constructor prototype
    constexpr Rectangle();
    constexpr Rectangle(int, int);
    constexpr int calcArea(int, int);
    constexpr int calcPerimeter(int, int);

};

constexpr Rectangle::Rectangle() // default constructor the main will call when creating an object
    : length(0)
    , width(0)
    , area(0)
    , perimeter(0)
{
}

constexpr Rectangle::Rectangle(int inilength, int iniwidth) // overloaded with two arguments passed from the main
    : length(inilength)
    , width(iniwidth)
    , area(inilength * iniwidth)
    , perimeter((inilength + iniwidth) * 2)
{
}

[[gnu::const]] constexpr int Rectangle::calcArea(int inilength, int iniwidth)
{
    int area = inilength * iniwidth;
    return area;
}

[[gnu::const]] constexpr int Rectangle::calcPerimeter(int inilength, int iniwidth)
{
    int perimeter = (inilength + iniwidth) * 2;
    return perimeter;
}

#endif
