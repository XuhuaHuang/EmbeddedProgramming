/*****************************************************************//**
 * \file   lab_Circle_Colour.cpp
 * \brief  class Circle, Colour, ColouredCircle for multiple inheritance
 *  one-line default and overloaded constructor
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

#ifndef PI // if 'PI' is not defined
#define PI 3.14159265359
#endif

class Circle
{
private:
    int radius;
    double area;

public:
    // set and get functions
    // for attribute 'radius'
    void setRadius(int newRadius) { radius = newRadius; }
    int getRadius(void) const { return radius; }

    // for attribute 'area'
    void setArea(double newArea) { area = newArea; }
    double getArea(void) const { return area; }

    // default constructor
    Circle() { setRadius(0); setArea(0); }
    // overrload constructor takes radius and calculate the area
    Circle(int newRadius) { setRadius(newRadius); setArea((double)newRadius * newRadius* PI); }
};

class Colour
{
private:
    std::string lineColour;
    std::string fillColour;

public:
    // set and get functions
    // for attribute lineColour
    void setLineColour(std::string newLineColour) { lineColour = newLineColour; }
    std::string getLineColour(void) const { return lineColour; }

    // for attribute fillColoour
    void setFillColour(std::string newFillColour) { fillColour = newFillColour; }
    std::string getFillColour(void) const { return fillColour; }

    // default constructor
    Colour() { setLineColour("none"); setFillColour("none"); }
    // overload constructor
    Colour(std::string customColour) { setLineColour(customColour); setFillColour(customColour); }
};

class ColouredCircle : public Circle, public Colour
{
public:

    // default constructor
    ColouredCircle() : Circle(), Colour() {}
    // overload constructor
    ColouredCircle(int newRadius, std::string customColour) : Circle(newRadius), Colour(customColour) {}
};

int main(void)
{
    // test case 1 - default constructor
    ColouredCircle ccobj1;
    std::cout << "\nTest case 1 with default constructor." << "\n"
         << "An object called \"ccobj1\" is created: " << "\n"
         << "\tArea: " << ccobj1.getArea() << "\n"
         << "\tLine colour: " << ccobj1.getLineColour() << "\n"
         << "\tFill colour: " << ccobj1.getFillColour() << "\n";

    // test case 2 - overload constructor
    ColouredCircle ccobj2(2, "red"); // (newRadius, customColour)
    std::cout << "\nTest case 2 with overloaded constructor." << "\n"
         << "An object called \"ccobj2\" is created: " << "\n"
         << "\tArea: " << ccobj2.getArea() << "\n"
         << "\tLine colour: " << ccobj2.getLineColour() << "\n"
         << "\tFill colour: " << ccobj2.getFillColour() << "\n";

    std::cin.get();
    return 0;
}
