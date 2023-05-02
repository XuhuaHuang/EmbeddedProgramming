// clang-format off
/*****************************************************************//**
 * \file   area_triangle.cpp
 * \brief  g++ -c area_triangle.cpp -o area_triangle.exe
 * ./area_triangle.exe
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <cmath>
#include <iostream>

int main(void)
{
    double a = 0, b = 0, c = 0;
    std::cout << "Please enter the length of the first side of the triangle: ";
    std::cin >> a;

    std::cout << "Please enter the length of the second side of the triangle: ";
    std::cin >> b;

    std::cout << "Please enter the third length of the side of the triangle: ";
    std::cin >> c;

    double s    = (0.5) * (a + b + c);
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    std::cout << "\nThe area of the triangle you just entered is: " << area << "\n";

    return 0;
}
