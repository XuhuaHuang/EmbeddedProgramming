// clang-format off
/*****************************************************************//**
 * \file   interface_design_date.cpp
 * \brief  first hands-on experience with API design with
 *         the goal "easy to use, hard to break" 
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/
// clang-format on

#include <iostream>
#include <string>

/* define structures offer explicit conversion constructor */
class Month
{
public:
    // get function
    std::string getMonth() const
    {
        switch (_month)
        {
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
        default:
            return "Jan";
        } // end switch
    } // end getMonth()

    // default constructor
    explicit Month() { _month = 1; }

    // functions that return static Month objects
    // with private overloaded constructor
    static Month Jan() { return Month(1); }
    static Month Feb() { return Month(2); }
    static Month Mar() { return Month(3); }
    static Month Apr() { return Month(4); }
    static Month May() { return Month(5); }
    static Month Jun() { return Month(6); }
    static Month Jul() { return Month(7); }
    static Month Aug() { return Month(8); }
    static Month Sep() { return Month(9); }
    static Month Oct() { return Month(10); }
    static Month Nov() { return Month(11); }
    static Month Dec() { return Month(12); }

private:
    /* prevent creation of other Month values */
    /* with private constructor */
    explicit Month(int m)
        : _month(m)
    {
    }
    int _month;
};

struct Day
{
    int getDay() const { return _day; }
    /* default and overloaded constructor with explicit conversion */
    explicit Day() = default;
    explicit Day(int d)
    {
        if (d > 0 && d <= 31)
        {
            _day = d;
        }
        else
        {
            _day = 0;
        }
    }

private:
    int _day;
};

struct Year
{
    int getYear() const { return _year; }
    /* default and overloaded constructor with explicit conversion */
    explicit Year() { _year = 2000; }
    explicit Year(int y)
    {
        if (y > 1900 && y <= 2100)
        {
            _year = y;
        }
        else
        {
            _year = 1900;
        }
    }

private:
    int _year;
};

class Date
{
public:
    // default constructor with member initialization list
    Date() = default;

    // overloaded constructor with constant reference
    Date(const Month& m, const Day& d, const Year& y);
    // function to print information
    void printDate();

private:
    Month month;
    Day   day;
    Year  year;
};

Date::Date(const Month& m, const Day& d, const Year& y)
{
    // invoking compiler generated copy constructor
    month = Month(m);
    if (m.getMonth() == "Feb" && d.getDay() <= 29)
        day = Day(d);
    else
        day = Day(d);
    year = Year(y);
}

void Date::printDate()
{
    std::cout << "[fn][Date::printDate()]"
              << "\n"
              << this->month.getMonth() << " " << this->day.getDay() << ", " << this->year.getYear() << "\n";
}

int main(void)
{
    Date myDate(Month::Mar(), Day(8), Year(2021));
    myDate.printDate();

    return 0;
}
