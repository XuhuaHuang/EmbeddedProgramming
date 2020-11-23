/*****************************************************************//**
 * \file   lab_Time_Date_main.cpp
 * \brief  test case for Time and Date friend class
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include "lab_Time_Date.h"

using namespace std;

int main(void)
{
	Time time; // create a Time object
	Date date; // create a data object

	// initialize diffeerent properties for object "time" and "date"
	time.setTime(14, 30, 30);
	date.setDate(2020, 11, 23);

	date.printDate(time);

	return 0;
}
