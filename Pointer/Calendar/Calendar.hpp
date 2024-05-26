// clang-format off
/*****************************************************************//**
 * \file   Calendar.hpp
 * \brief  Pointer In-class Notes - class Calendar Header
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
// clang-format on

#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include "Date.hpp"
#include "Time.hpp"

class Calendar
{
private:
    Time* time;
    Date* date;

public:
    Calendar();  // default constructor
    ~Calendar(); // destructor

    void print();

    void  setTime(Time* newTime) { time = newTime; }
    Time* getTime() { return time; } // return a pointer

    void  setDate(Date* newDate) { date = newDate; }
    Date* getDate() { return date; } // return a pointer
};

Calendar::Calendar()
{
    /*
     * Time* t = new Time(14, 25, 0);
     * setTime(t);
     */
    setTime(new Time(14, 25, 0));
    setDate(new Date(2020, 11, 11));

    std::cout << "\n[DECONST]Creating time and date objects."
              << "\n";
}

Calendar::~Calendar()
{
    delete time;
    delete date;

    std::cout << "\n[DEST]Deleting time and fate objects."
              << "\n";
}

void Calendar::print()
{
    Time* temp = getTime(); // creating a temporary pointer
    std::cout << "\n[fn]Printig current time: "
              << "\n"
              << temp->getHour() << " : " << temp->getMinute() << " : " << temp->getSecond() << "\n";

    Date* temp2 = getDate(); // creating a temporary pointer
    std::cout << "\n[fn]Printig current date: "
              << "\n"
              << temp2->getYear() << " / " << temp2->getMonth() << " / " << temp2->getDay() << "\n";

    return;
}

#endif
