/*****************************************************************//**
 * \file   TimeDate.cpp
 * \brief  contains function definitions for class Time and Date
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include "TimeDate.hpp"

// class "Time" functions:
void Time::setHour(int userHour) // hour should be valid form 0 to 23
{
    if ((userHour >= 0) && (userHour <= 23))
    {
        hour = userHour;
    }
    else if (userHour == 24)
    {
        std::cout << "\n[fn]Do you mean 0 a.m.? It is automatically set to 0 a.m." << "\n";
        hour = 0;
    }
    else
    {
        std::cout << "\n[fn]Invalid hour value " << userHour << "\n";
        hour = 0;
    }

    return;
}

void Time::setMinute(int userMinute) // minute should be valid from 0 to 59
{
    if ((userMinute >= 0) && (userMinute <= 59))
    {
        minute = userMinute;
    }
    else
    {
        std::cout << "\n[fn]Invalid minute value " << userMinute << "\n";
        minute = 0;
    }

    return;
}

void Time::setSecond(int userSecond) // second should be valid form 0 to 59
{
    if ((userSecond >= 0) && (userSecond <= 59))
    {
        second = userSecond;
    }
    else
    {
        std::cout << "\n[fn]Invalid second value " << userSecond << "\n";
        second = 0;
    }

    return;
}

// original set time functions with three variables
void Time::setTime(int userHour, int userMinute, int userSecond)
{
    setHour(userHour);
    setMinute(userMinute);
    setSecond(userSecond);

    return;
}

/*
* void Time::printTime() // not required
* {
*   std::cout << "\n[fn]It's " << getHour() << " : " << getMinute() << " : " << getSecond() << "\n";
*   // using get functions to get value with verification
*
*   return;
* }
*/

void Time::setTime(int userHour, int userMinute) // overloaded function #1
{
    setHour(userHour);
    setMinute(userMinute);

    setSecond(0); // to keep the variable from garbage variable

    return;
}


void Time::setTime(int userHour) // overloaded function #2
{
    setHour(userHour);

    setMinute(0); // set default value 0 for testing
    setSecond(0);

    return;
}

// class "Date" class functions:
void Date::setYear(int userYear)
{
    if (userYear >= 1900)
        year = userYear;
    else
    {
        std::cout << "\n[fn]Invalid value. Setting year to 1900" << "\n";
        year = 1900;
    }
    return;
}

void Date::setMonth(int userMonth)
{
    if ((userMonth > 0) && (userMonth <= 12))
        month = userMonth;
    else
    {
        std::cout << "\n[fn]Invalid month value. Setting month to 1." << "\n";
        month = 1;
    }

    return;
}

void Date::setDay(int userDay)
{
    if ((userDay > 0) && (userDay <= 31))
        day = userDay;
    else
    {
        std::cout << "\n[fn]Invalid day value. Setting day to 1." << "\n";
        day = 1;
    }

    return;
}

void Date::setDate(int userYear, int userMonth, int userDay)
{
    setYear(userYear);
    setMonth(userMonth);
    setDay(userDay);

    return;
}

void Date::printDate(Time time)
{
    std::cout << "\n[fn]\"void Date::printDate(Time time)\" called" << "\n"
         << "[fn]Date: " << "\nMonth/day/Year" << "\n"
         << this->getMonth() << "/"
         << this->getDay() << "/"
         << this->getYear() << "\n"
         << "[fn]Time: " << "\nHour:Minute:Second" << "\n"
         << time.getHour() << ":"
         << time.getMinute() << ":"
         << time.getSecond() << "\n";

    return;
}
