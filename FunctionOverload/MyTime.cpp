/*****************************************************************//**
 * \file   MyTime.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   October 07, 2020
 *********************************************************************/

#include "MyTime.h"

void MyTime::setHour (int userHour) // hour should be valid form 0 to 23
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

void MyTime::setMinute (int userMinute) // minute should be valid from 0 to 59
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

void MyTime::setSecond (int userSecond) // second should be valid form 0 to 59
{
    if ((userSecond >= 0) && (userSecond<= 59))
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

void MyTime::setTime(int userHour, int userMinute, int userSecond) // original set time functions with three variables
{
    setHour(userHour);
    setMinute(userMinute);
    setSecond(userSecond);

    return;
}

void MyTime::printTime()
{
    std::cout << getHour() << ":" << getMinute() << ":" << getSecond() << "\n"; // using get functions to get value with verification

    return;
}


void MyTime::setTime(int userHour, int userMinute) // overloaded function #1
{
    setHour(userHour);
    setMinute(userMinute);

    setSecond(0); // to keep the variable from garbage variable

    return;
}


void MyTime::setTime(int userHour) // overloaded function #2
{
    setHour(userHour);

    setMinute(0); // set default value 0 for testing
    setSecond(0);

    return;
}
