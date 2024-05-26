/*****************************************************************//**
 * \file   Time.hpp
 * \brief  Class Time declaration and definition.
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#ifndef TIME_HPP
#define TIME_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    // set functions
    void setHour(int userHour); // definiton of set functions follow with validation
    void setMinute(int userMinute);
    void setSecond(int userSecond);

    // get functions
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }

    // other functions within the class
    void setTime(int userHour, int userMinute, int userSecond);
    void printTime();

    // overloaded functions with the same name and different arguments
    void setTime(int userHour, int userMinnute);
    void setTime(int userHour);

    // default and overloaded constructor
    Time(); // default
    Time(int, int, int); // overloaded
    Time(int, int);
    Time(int);
};

Time::Time() // default constructor
{
    setHour(0);
    setMinute(0);
    setSecond(0);
}

Time::Time(int h, int m, int s)  // object3(h,m,s )
{
    setHour(h); // calls the set functions with verification
    setMinute(m);
    setSecond(s);
}

Time::Time(int h, int m)
{
    setHour(h);
    setMinute(m);
    setSecond(0); // set second to 0 by default
}

Time::Time(int h)
{
    setHour(h);
    setMinute(0); // set minute to 0 by default
    setSecond(0); // set second to 0 by default
}

void Time::setHour(int userHour) // hour should be valid form 0 to 23
{
    if ((userHour >= 0) && (userHour <= 23))
    {
        hour = userHour;
    }
    else if (userHour == 24)
    {
        std::cout << "Do you mean 0 a.m.? It is automatically set to 0 a.m." << "\n";
        hour = 0;
    }
    else
    {
        std::cout << "Invalid value " << userHour << "\n";
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
        std::cout << "Invalid value " << userMinute << "\n";
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
        std::cout << "Invalid value " << userSecond << "\n";
        second = 0;
    }

    return;
}

void Time::setTime(int userHour, int userMinute, int userSecond) // original set time functions with three variables
{
    setHour(userHour);
    setMinute(userMinute);
    setSecond(userSecond);

    return;
}

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

void Time::printTime()
{
    // using get functions to get value with verification
    std::cout << getHour() << ":" << getMinute() << ":" << getSecond() << "\n";

    return;
}

#endif
