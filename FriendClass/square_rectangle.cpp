/*****************************************************************/ /**
                                                                     * \file   square_rectangle.cpp
                                                                     * \brief  class "Square" made friend of class
                                                                     *"rectangle"
                                                                     *
                                                                     * worth noting:
                                                                     * 1) granting the other class to access the
                                                                     *protected and private data members of the class
                                                                     *made friend with. 2) class friendship is not
                                                                     *bidirectional. Need to specify. 3) class
                                                                     *friendship is not transmissive: The friend of a
                                                                     *friend is not considered to be a friend unless
                                                                     *explicitly specified.
                                                                     *
                                                                     * \author Xuhua
                                                                     * \date   November 2020
                                                                     *********************************************************************/

#include <iostream>

class Square
{
private:
    int side;

public:
    inline void setSide(int a) { side = a; }

    // Square class allows Rectangle class to access its private data members.
    friend class Rectangle;
    // conflict the concept of class encapsulation
    // could be avoided by using public get functions (getter)
};

class Rectangle
{
private:
    int width, height;

public:
    inline constexpr int area() { return (width * height); }
    void                 convert(const Square& rhs);
};

void Rectangle::convert(const Square& a)
{
    width  = a.side;
    height = a.side;
    // Rectangle class using Square's private data members (side)

    return;
}

int main(void)
{
    Square    sqr;
    Rectangle rect;

    sqr.setSide(4);
    rect.convert(sqr); // converting a square to rectangle

    std::cout << rect.area() << "\n";

    return 0;
}
