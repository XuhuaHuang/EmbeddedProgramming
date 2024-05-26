/*****************************************************************//**
 * \file   main.cpp
 * \brief  Pointer In-class Notes Main Function
 *         Contains main function working with class 'MyCalendar'
 *
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#include <iostream>
#include "Calendar.hpp"

auto main(void) -> int {
    Calendar calendar;
    calendar.print();

    return EXIT_SUCCESS;
}
