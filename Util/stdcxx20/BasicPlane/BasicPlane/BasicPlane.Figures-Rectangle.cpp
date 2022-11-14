/*****************************************************************//**
 * \file   BasicPlane.Figures-Rectangle.cpp
 * \brief  
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 2022
 *********************************************************************/

module;

// global module fragment area. Put #iclude directives here.

module BasicPlane.Figures:Rectangle;

int area(const Rectangle& rec) {
    return height(rec) * width(rec);
}

int height(const Rectangle& rec) {
    return rec.ul.y - rec.lr.y;
}

int width(const Rectangle& rec) {
    return rec.lr.x - rec.ul.x;
}
