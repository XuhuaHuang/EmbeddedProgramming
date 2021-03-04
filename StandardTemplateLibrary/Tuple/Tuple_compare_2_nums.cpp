/*
* Topic: tuple
* Type: example to compare two numbers
* Xuhua Huang
* Created on: Nov 13, 2020
* Last updated: Nov 13, 2020
* 
* Member function:
*	operator =				- assign content
*	swap					- swap content
*
* Non-member function:
*	make_tuple				- create a tuple object
*	tie						- unpack a tuple into individual objects
*	forward_as_tuple		- creates a tuple of forwarding references
*	tuple_cat				- creates a tuple by coinvatening tuples
*	std::get				- tuple accesses specified element
* 
* Operator:
*	==
*	!=	<	<=	>	>=		removed in C++ 20
*	<=> added in C++ 20
* 
* Helper classes:
*	tuple_size				- obtains the size of a tuble
*	tuple_element			- obtains the type of specified element
*	ignore					- placeholder to skip an element when unpacking a tuple using tie
*/

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, int> findGreaterSmaller(int num1, int num2)
{
    if (num1 < num2)
        return make_tuple(num1, num2);
    else if (num1 > num2)
        return make_tuple(num2, num1);
}

int main(void)
{
    int num1, num2;   
    cout << "Enter the first number of two to compare: ";
    cin >> num1;
    cout << "Enter the second number of two to compare: ";
    cin >> num2;
    
    int min, max;
    tie(min, max) = findGreaterSmaller(num1, num2);
    
    /* 
    * 'findGreaterSmaller' is the name of the function
    * function argument: int, int
    * 
    * return type: tuple<int, int>
    * tie() function groupes int min and max together to be a tuple
    * to receive result of the function
    * 
    * after variables in tuples are assgined value
    * variables can be accessed individually 
    */

    cout << "The greater number is: " << max << endl
         << "The smaller number is: " << min << endl;

    return 0;
}
