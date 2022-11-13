/*****************************************************************//**
 * \file   example_Rectangle.cpp
 * \brief  example class "Rectangle" for copy constructor
 * 
 * A copy constructor is a special constructor called whenever
 * a new object is created and initialized with another object's data.
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>

class Rectangle
{
private:
    int width, height;

public:
    // set and get functions
    void setWidth(const int userWidth) { width = userWidth; }
    int getWidth(void) { return width; }

    void setHeight(const int userHeight) { height = userHeight; }
    int getHeight(void) { return height; }

    // other functions
    int area() { return (width * height); }

    // overloaded constructor
    Rectangle(const int initWidth, const int initHeight) : width(initWidth), height(initHeight) {}
    // copy constructor
    Rectangle(const Rectangle& rectangle);
};

// copy constructor
Rectangle::Rectangle(const Rectangle& rectangle)
{
    this->setWidth(rectangle.width);
    this->setHeight(rectangle.height);
}


int main(void)
{
    Rectangle rect(4, 5); // calls overloaded constructor
    Rectangle anotherRect(rect); // calls copy constructor

    std::cout << rect.area() << "\n";  // outputs 20
    std::cout << anotherRect.area() << "\n"; // outputs 20

    return 0;
}
