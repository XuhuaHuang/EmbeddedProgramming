/*
* Name: Fibonacci Series - first 25 term
* Requirement: the i-th item of the series equals to the sum of previous two
*              print a new line every five numbers in console
*
* Author: Xuhua Huang
* Last updated: Nov 06, 2020
* Created on: Nov 06, 2020
*/

#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
    int current; // currentTerm = previous + SecondPrevious
    int previous;
    int secondPrevious;

    current = previous = secondPrevious = 1;
    cout << previous << " " << current << " ";

    for (int i = 3; i <= 25; i++)
    {
        current = previous + secondPrevious;
        cout << current << " ";

        if (i % 5 == 0)
            cout << endl;

        secondPrevious = previous; // refresh the value in the series
        previous = current;
    }

    return 0;
}
