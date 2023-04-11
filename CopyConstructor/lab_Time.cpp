// clang-format off
/*****************************************************************//**
 * \file   lab_Time.cpp
 * \brief  class Time to demonstrate copy constructor
 *
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    // set and functions
    void setHour(int userHour); // definition of set functions follow with validation
    int  getHour() { return hour; }

    void setMinute(int userMinute);
    int  getMinute() { return minute; }

    void setSecond(int userSecond);
    int  getSecond() { return second; }

    // overloaded constructor
    Time(int userHour, int userMinute, int userSecond);
    // copy constructor
    Time(const Time& time);

    // print time function
    void printTime();
};

int main(void)
{
    // Time(int userHour, int userMinute, int userSecond);
    Time time1(18, 30, 30);
    std::cout << "\nAn object named \"time1\" of class \"Time\" is created."
              << "\n"
              << "Calling the printTime() function."
              << "\n";
    time1.printTime();

    Time timeCopy(time1);
    std::cout << "\nAn object named \"timeCopy\" of class \"Time\" is created "
              << "with copy constructor."
              << "\n"
              << "Test case to test the copy constructor"
              << "\n";
    timeCopy.printTime();

    return 0;
}

// class "Time" functions:
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

// overloaded constructor
// Time(int userHour, int userMinute, int userSecond);
Time::Time(int userHour, int userMinute, int userSecond)
{
    setHour(userHour);
    setMinute(userMinute);
    setSecond(userSecond);
}

// copy constructor
Time::Time(const Time& time)
{
    this->setHour(time.hour);
    this->setMinute(time.minute);
    this->setSecond(time.second);
}

void Time::printTime() // not required
{
    std::cout << "\n[fn]\"void Time::printTime()\" called."
              << "\n"
              << "[fn]\tHour:Minute:Second"
              << "\n"
              << "[fn]\t" << getHour() << ":" << getMinute() << ":" << getSecond() << "\n";
    // using get functions to get stored value with verification

    return;
}
