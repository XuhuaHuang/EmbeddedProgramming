/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/

#define INSTANCE

#define TYPE int
#include "collection.def"
#undef TYPE

#define TYPE double
#include "collection.def"
#undef TYPE

#include <iostream>

int main(void) {
    Collection_int collInt = make_Collection_int(5);
    Collection_double collDbl = make_Collection_double(10);

    return 0;
}
