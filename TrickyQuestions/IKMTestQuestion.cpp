/*****************************************************************//**
 * \file   IKMTestQuestion.cpp
 * \brief  Interesting questions during test on the IKM platform
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

/* Q1 */
template<typename T>
void cubed(T& num_to_cubed) {
    num_to_cubed = pow(num_to_cubed, 3);
}

/* Q2 */
class Base {
    int z;
public:
    Base() = delete;	// DELETED
    Base(int i) : z(i) {}
};

class Derived : public Base
{
public:
    // Derived() {}		// Error! Attempt to refer to a deleted function
    Derived(int i) : Base(i) {}
};

/* Q3 */
/* map of employee name to years of service */
map<string, int> employees{
    {"John", 3},
    {"Jill", 4},
    {"Rick", 5},
    {"Elaine", 6}
};

void print(pair<string, int> employee)
{
    if (employee.second < 5)
        std::cout << employee.first << "\n";
}

int main(void)
{
    /* Q1 */
    double d = 5;
    // cubed(&& d);
    // cubed(& d);
    // cubed(*d);
    // cubed<T>(d);
    cubed(d);
    std::cout << d << "\n";

    /* Q2 */
    Base b(5);
    // Derived d; // Error! No valid default constructor provided

    /* Q3 */
    for (map<string, int>::iterator it = employees.begin(); it != employees.end(); it++)
        if (it->second < 5)
            std::cout << it->first << "\n";

    for_each(employees.begin(), employees.end(), print);

    return 0;
}
