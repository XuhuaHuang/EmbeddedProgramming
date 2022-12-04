/*****************************************************************//**
 * \file   example_Polygon.cpp
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

class Polygon
{
protected:
    int width, height;

public:

    // function prototype
    void set_values(int a, int b) { width = a; height = b; }

    // "Polygon" is a 'polymorphic class'
    virtual int area() const { return 0; } // virtual keyword ensures
    // Polygon* to access class function for address-linked-object
};

class Rectangle : public Polygon
{
public:
    int area() const override { return (width * height); }
};

class Triangle : public Polygon
{
public:
    int area() const override { return (width * height / 2); }
};

int main()
{
    Rectangle rect;
    Triangle trgl;
    Polygon poly;
    Polygon* ppoly;

    ppoly = &rect; // point to a "Rectangle" class object
    ppoly->set_values(4, 5);
    std::cout << ppoly->area() << "\n"; // will print 0 if without "virtual" keyword

    ppoly = &trgl; // pointing to a "Triangle" class object
    ppoly->set_values(4, 5);
    std::cout << ppoly->area() << "\n"; // will print 0 if without "virtual" keyword

    ppoly = &poly; // pointing to a same-base class object
    ppoly->set_values(4, 5);
    std::cout << ppoly->area() << "\n"; // 0

    return 0;
}
