// clang-format off
/*****************************************************************//**
 * \file   overload_assignment.cpp
 * \brief  Overloaded assignment operator 
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>

/**
 * @class point
 * @brief A class representing a point in 2D space.
 * 
 * The point class encapsulates the coordinates of a point in a 2D space with integer values.
 * It provides default constructors, a copy constructor, and a virtual destructor.
 * 
 * @note This class uses public member variables for the coordinates.
 */
class point
{
public:
    constexpr point()                 = default;
    constexpr point(const point& rhs) = default;
    virtual ~point()                  = default;

    int _x;
    int _y;

    point& operator=(const point&);
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
