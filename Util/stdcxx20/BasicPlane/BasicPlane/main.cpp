/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   September 2022
 *********************************************************************/

//import std.core;
#include <iostream>

import BasicPlane.Figures;

int main(void)
{
    std::ios::sync_with_stdio(false);

    //Point ul{ 1, 8 };
    //Point lr{ 11, 3 };
    //Rectangle r {ul, lr};
    Rectangle r{ {1, 8}, {11, 3} };

    std::cout << "height: " << height(r) << "\n";
    std::cout << "width: " << width(r) << "\n";
    std::cout << "area: " << area(r) << "\n";

    system("pause");
    return 0;
}
