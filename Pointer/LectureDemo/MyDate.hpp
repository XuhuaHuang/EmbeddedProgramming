/*****************************************************************//**
 * \file   MyDate.hpp
 * \brief  Pointer In-class Notes - class MyDate Header
 *
 * Notice: ALL "std::cout" statements inside a function are appended
 * after signature "[fn]" which stands for printing from function
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#ifndef MyDate_HPP
#define MyDate_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

class MyDate
{
private:
    int year;
    int month;
    int day;

public:
    // overloaded constructor
    MyDate(int, int, int);

    // set functions:
    void setMonth(int userMonth); // definition of set functions follow with validation
    void setDay(int userDay);
    void setYear(int userYear);

    // get functions:
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }
};

MyDate::MyDate(int userYear, int userMonth, int userDay)
{
    setYear(userYear);
    setMonth(userMonth);
    setDay(userDay);
}

void MyDate::setYear(int userYear)
{
    if (userYear >= 1900)
    {
        year = userYear;
    }
    else
    {
        std::cout << "\n[fn]Invalid value. Setting year to 1900" << "\n";
        year = 1900;
    }
    return;
}

void MyDate::setMonth(int userMonth)
{
    if ((userMonth > 0) && (userMonth <= 12))
    {
        month = userMonth;
    }
    else
    {
        //std::cout << "Invalid month value. Setting month to 1." << "\n";
        month = 1;
    }

    return;
}

void MyDate::setDay(int userDay)
{
    if ((userDay > 0) && (userDay <= 31))
    {
        day = userDay;
    }
    else
    {
        //std::cout << "Invalid day value. Setting day to 1." << "\n";
        day = 1;
    }

    return;
}

#endif
