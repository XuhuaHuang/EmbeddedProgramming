// clang-format off
/*****************************************************************//**
 * \file   Time.hpp
 * \brief  Pointer In-class Notes - class Time Header
 *
 * Notice: ALL "std::cout" statements inside a function are appended
 * after signature "[fn]" which stands for printing from function
 * \author Xuhua Huang
 * \date   November 11, 2020
 *********************************************************************/
// clang-format on

#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    // default and overloaded constructor
    Time();              // default
    Time(int, int, int); // overloaded

    // set functions
    void setHour(int userHour); // definition of set functions follow with validation
    void setMinute(int userMinute);
    void setSecond(int userSecond);

    // get functions
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
};

Time::Time() // default constructor
{
    setHour(0);
    setMinute(0);
    setSecond(0);
}

Time::Time(int h, int m, int s) // object3(h,m,s )
{
    setHour(h); // calls the set functions with verification
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int userHour) // hour should be valid form 0 to 23
{
    if ((userHour >= 0) && (userHour <= 23))
    {
        hour = userHour;
    }
    else if (userHour == 24)
    {
        std::cout << "\n[fn]Do you mean 0 a.m.? It is automatically set to 0 a.m."
                  << "\n";
        hour = 0;
    }
    else
    {
        std::cout << "\n[fn]Invalid value " << userHour << "\n";
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
        std::cout << "\n[fn]Invalid value " << userMinute << "\n";
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
        std::cout << "\n[fn]Invalid value " << userSecond << "\n";
        second = 0;
    }

    return;
}

#endif
