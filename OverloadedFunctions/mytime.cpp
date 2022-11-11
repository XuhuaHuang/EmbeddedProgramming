#include "mytime.h"
using namespace std;

// Xuhua Huang 1879700

void mytime::setHour (int userHour) // hour should be valid form 0 to 23
{
    if ((userHour >= 0) && (userHour <= 23))
    {
        hour = userHour;
    }
    else if (userHour == 24)
    {
        cout << "Do you mean 0 a.m.? It is automatically set to 0 a.m." << endl;
        hour = 0;
    }
    else
    {
        cout << "Invalid value " << userHour << endl;
        hour = 0;
    }

    return;
}

void mytime::setMinute (int userMinute) // minute should be valid from 0 to 59
{
    if ((userMinute >= 0) && (userMinute <= 59))
    {
        minute = userMinute;
    }
    else
    {
        cout << "Invalid value " << userMinute << endl;
        minute = 0;
    }

    return;
}

void mytime::setSecond (int userSecond) // second should be valid form 0 to 59
{
    if ((userSecond >= 0) && (userSecond<= 59))
    {
        second = userSecond;
    }
    else
    {
        cout << "Invalid value " << userSecond << endl;
        second = 0;
    }

    return;
}

void mytime::setTime(int userHour, int userMinute, int userSecond) // original set time functions with three variables
{
    setHour(userHour);
    setMinute(userMinute);
    setSecond(userSecond);

    return;
}

void mytime::printTime()
{
    cout << getHour() << ":" << getMinute() << ":" << getSecond() << endl; // using get functions to get value with verification

    return;
}


void mytime::setTime(int userHour, int userMinute) // overloaded function #1
{
    setHour(userHour);
    setMinute(userMinute);
    
    setSecond(0); // to keep the variable from garbage variable

    return;
}


void mytime::setTime(int userHour) // overloaded function #2
{
    setHour(userHour);
    
    setMinute(0); // set default value 0 for testing
    setSecond(0);

    return;
}
