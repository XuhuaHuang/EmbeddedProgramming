/*****************************************************************//**
 * \file   BasicPlane.Figures-Rectangle.ixx
 * \brief  
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 2022
 *********************************************************************/

// define the module partition Rectangle
export module BasicPlane.Figures:Rectangle;
// export module module_name:partition_name

import :Point;

export struct Rectangle
{
    Point ul; // upper left corner coordinate
    Point lr; // lower right corner coordinate
};

// the following functions are declared, but will
// be defined in a module implementation file:
// "BasicPlane.Figures-Rectangle.cpp"
export int area(const Rectangle& rec);
export int height(const Rectangle& rec);
export int width(const Rectangle& rec);
