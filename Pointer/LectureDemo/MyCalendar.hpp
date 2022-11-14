/*****************************************************************//**
 * \file   MyCalendar.hpp
 * \brief  Pointer In-class Notes - class MyCalendar Header
 *
 * Notice: ALL "std::std::cout" statements inside a function are appended
 * after signature "[fn]" which stands for printing from function
 *
 * [DECONST] printed from default constructor
 * [OLCONST] printed from overloaded constructor
 * [DEST] printed from destructor
 *
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/

#ifndef MYCALENDAR_HPP
#define MYCALENDAR_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include "MyTime.hpp"
#include "MyDate.hpp"

class MyCalendar
{
private:
    MyTime* time;
    MyDate* date;

public:

    MyCalendar(); // default constructor
    ~MyCalendar(); // destructor

    void print();

    void setTime(MyTime* newTime) { time = newTime; }
    MyTime* getTime() { return time; } // return a pointer

    void setDate(MyDate* newDate) { date = newDate; }
    MyDate* getDate() { return date; } // return a pointer

};

MyCalendar::MyCalendar()
{
    /*
    * MyTime* t = new MyTime(14, 25, 0);
    * setTime(t);
    */
    setTime(new MyTime(14, 25, 0));
    setDate(new MyDate(2020, 11, 11));

    std::cout << "\n[DECONST]Creating time and date objects." << "\n";
}

MyCalendar::~MyCalendar()
{
    delete time;
    delete date;

    std::cout << "\n[DEST]Deleting time and fate objects." << "\n";
}

void MyCalendar::print()
{
    MyTime* temp = getTime(); // creating a temporary pointer
    std::cout << "\n[fn]Printig current time: " << "\n"
        << temp->getHour() << " : "
        << temp->getMinute() << " : "
        << temp->getSecond() << "\n";

    MyDate* temp2 = getDate(); // creating a temporary pointer
    std::cout << "\n[fn]Printig current date: " << "\n"
        << temp2->getYear() << " / "
        << temp2->getMonth() << " / "
        << temp2->getDay() << "\n";

    return;
}

#endif
