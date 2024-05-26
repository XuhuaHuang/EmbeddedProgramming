/*****************************************************************//**
 * \file   Date_time.cpp
 * \brief  example with class Time and Date on multiple inheritance
 * 
 * $ g++ -c date_time.cpp -o date_time.exe -std=c++11
 * $ ./date_time.exe
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

// first base class
class Date
{
private:
    int day;
    int month;
    int year;

public:

    // default and overload constructor
    Date() { setDay(0); setMonth(0); setYear(0); }
    Date(int d, int m, int y) { setDay(d); setMonth(m); setYear(y); }
    
    // get and set function:
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void setDay(int newday) { day = newday; }
    void setMonth(int newmonth) { month = newmonth; }
    void setYear(int newyear) { year = newyear; }
};

// second base class
class Time
{
private:
    int second;
    int minute;
    int hour;

public:

    // default and overload constructor
    Time() { setSec(0); setMin(0); setHour(0); }
    Time(int h, int m, int s) { setHour(h); setMin(m); setSec(s); }
    
    // get and set function:
    int getSecond() const { return second; }
    int getMinute() const { return minute; }
    int getHour() const { return hour; }
    void setSec(int s) { second = s; }
    void setMin(int m) { minute = m; }
    void setHour(int h) { hour = h; }
};

// derived Class
class DateTime : public Date, public Time
{
public:
    // default and overload constructor
    DateTime();
    DateTime(int d, int m, int y, int h, int min, int s);
    
    // other functions:
    void printDate();
    void printTime();
};

// default constructor - calls base class default constructors 
DateTime::DateTime() : Date(), Time() {}

// constructor - calls base class overloaded-constructors with arguments
DateTime::DateTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y), Time(h, min, s) {}

void DateTime::printTime() {
    std::cout << "Hour:Minute:Second = ";
    std::cout << getHour() << ":" << getMinute() << ":" << getSecond() << "\n";
}

void DateTime::printDate() {
    std::cout << "Day/Month/Year = ";
    std::cout << getDay() << "/" << getMonth() << "/" << getYear() << "\n";
}

int main(void)
{
    DateTime dt1;
    DateTime dt2(1, 2, 2015, 8, 42, 23);  // day, month, year, hour, minute, second

    dt1.printDate();
    dt1.printTime();
    dt2.printDate();
    dt2.printTime();

    return 0;
}
