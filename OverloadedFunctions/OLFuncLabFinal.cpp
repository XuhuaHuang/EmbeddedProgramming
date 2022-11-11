#include <iostream>
#include <cmath>

using namespace std;

// 1879700 Xuhua Huang

class mytime
{
private:
    // attributes
    int hour;
    int minute;
    int second;

public:

    // set functions
    void setHour(int userHour); // definition of set functions follow with validation
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
};


class mydate
{
private:
    // attributes
    int year;
    int month;
    int day;

public:

    // set functions:
    void setMonth(int userMonth);
    void setDay(int userDay);
    void setYear(int userYear);

    // get functions:
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }

    // other functions
    void setDate(int userYear, int userMonth, int userDay);
    void printDate();

    // overloaded nextDay functions
    void nextDay(void);
    void nextDay(int dayslater);
};


int main(void)
{
    /*
    mytime userTime; // declaring an object

    int userHour;
    cout << "Please enter the hour you want to set to." << endl;
    cin >> userHour;
    userTime.setHour(userHour); // call the set function with verification

    int userMinute;
    cout << "Please enter the minute you want to set to." << endl;
    cin >> userMinute;
    userTime.setMinute(userMinute);

    int userSecond;
    cout << "Please enter the second you want to set to." << endl;
    cin >> userSecond;
    userTime.setSecond(userSecond);

    userTime.printTime(); // this line should print the time user sets to
    // asking the user to set section ends

    // test cases and print function
    userTime.setTime(12,34); // valid hour, minute; should call mytime::setTime(int , int)
    userTime.printTime(); // 12:34:00

    userTime.setTime(25, 34); // invalid hour and valid minute; should call mytime::setTime(int, int)
    userTime.printTime(); // 00:34:00

    userTime.setTime(12, 60); // valid hour and invalid minute; should call mytime::setTime(int, int)
    userTime.printTime(); // 12:00:00

    userTime.setTime(23); // valid hour; should call mytime::setTime(int userHour);
    userTime.printTime(); // 23:00:00
    */

    // test cases for mydate class:
    // void mydate::setDate(int userYear, int userMonth, int userDay)
    // yyyy/mm/dd

    mydate userDate; // creating the object

    cout << "Testing 1901/12/31" << endl;
    userDate.setDate(1901, 12, 31); // all valid
    userDate.printDate();

    cout << "\nTesting 1901/13/31" << endl;
    userDate.setDate(1901, 13, 31); // invalid month
    userDate.printDate();

    cout << "\nTesting 1901/12/32" << endl;
    userDate.setDate(1901, 12, 32); // invalid day
    userDate.printDate();

    cout << "\nTesting 1899/12/31" << endl;
    userDate.setDate(1899, 12, 31); // invalid year
    userDate.printDate();
    // test cases end here

    // nextDay functions test cases:
    cout << "\nTesting incrementing functions..." << endl;
    cout << "Initializing it to 1899/12/31" << endl;
    userDate.setDate(1899, 12, 31);
    userDate.printDate();
    userDate.nextDay();
    userDate.printDate();

    cout << "\nTesting with a loop..." << endl;
    cout << "Originally\n";
    userDate.printDate(); // current date before testing incrementing
    cout << "\nStart to increment..." << endl;

    for (int i = 0; i <= 380; i++) // 380 > 366 guaranteed to increment to next year
    {
        userDate.nextDay();
        userDate.printDate();
    }  // verified working by means of successfully incrementing within the same month, next month, next year


    // test cases for the overloaded nextDay function
    cout << "\nTest cases for overloaded nextDay(int) function:\n";
    cout << "Initializing to 2000/01/01." << endl;
    userDate.setDate(2000, 1, 1);
    userDate.printDate();

    cout << "\n5 days later..." << endl;
    userDate.nextDay(5);
    userDate.printDate();

    cout << "\n35 days later..." << endl;
    userDate.nextDay(35);
    userDate.printDate();

    cout << "\nInitializing to 2000/01/01." << endl;
    cout << "370 days later..." << endl;
    userDate.setDate(2000, 1, 1);
    userDate.nextDay(370); // doesn't work. I tried. Lost 7 days in day
    userDate.printDate();

    return 0;
}


void mytime::setHour(int userHour) // hour should be valid form 0 to 23
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

void mytime::setMinute(int userMinute) // minute should be valid from 0 to 59
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

void mytime::setSecond(int userSecond) // second should be valid form 0 to 59
{
    if ((userSecond >= 0) && (userSecond <= 59))
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

// my date class functions:
void mydate::setYear(int userYear)
{
    if (userYear >= 1900)
        year = userYear;
    else
    {
        //cout << "Invalid value. Setting year to 1900" << endl;
        year = 1900;
    }
    return;
}

void mydate::setMonth(int userMonth)
{
    if ((userMonth > 0) && (userMonth <= 12))
        month = userMonth;
    else
    {
        //cout << "Invalid month value. Setting month to 1." << endl;
        month = 1;
    }

    return;
}

void mydate::setDay(int userDay)
{
    if ((userDay > 0) && (userDay <= 31))
        day = userDay;
    else
    {
        //cout << "Invalid day value. Setting day to 1." << endl;
        day = 1;
    }

    return;
}

void mydate::setDate(int userYear, int userMonth, int userDay)
{
    setYear(userYear);
    setMonth(userMonth);
    setDay(userDay);

    return;
}

void mydate::printDate()
{
    /*
    cout << "It's the year of: " << getYear() << endl;
    cout << "It's the Month of: " << getMonth() << endl;
    cout << "It's the day of: " << getDay() << endl;
    */

    cout << "It's " << getMonth() << "/" << getDay() << "/" << getYear() << endl;

    return;
}

void mydate::nextDay(void)
{
    //cout << "\nIncrementing the day by one..." << endl;
    setDay(getDay() + 1);

    if (getDay() == 1) // increment to 32 and enter new month
        setMonth(getMonth() + 1); // current month + 1

    if ((getMonth() == 1) && (getDay() == 1))// increment to next year
        setYear(getYear() + 1); // current  year + 1

    return;
}

void mydate::nextDay(int dayslater)
{

    for (int i = 0; i < dayslater; i++)
    {
        nextDay();
    }

    return;
}
