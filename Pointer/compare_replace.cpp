/*****************************************************************//**
 * \file   Pointer_compare.cpp
 * \brief  Modified program using References in C++
 * 
 * \author Xuhua Huang
 * \date   July 2021
 *********************************************************************/
#include <iostream>

using namespace std;

void compare(int a, int b, int& addr_greater, int& addr_smaller)
{
	if (a > b)
	{
		addr_greater = a;
		addr_smaller = b;
	}
	else
	{
		addr_greater = b;
		addr_smaller = a;
	}

	return;
}

// Driver code 
int main(void)
{
	int greaterNum, smallerNum, num1, num2;

	cout << "Enter the first number of two to compare: ";
	cin >> num1;
	cout << "Enter the second number of two to compare: ";
	cin >> num2;

	// The last two arguments are passed
	// by giving addresses of memory locations
	compare(num1, num2, greaterNum, smallerNum);
	
	cout << "\nThe greater number is: " << greaterNum << endl
		 << "The smaller number is: " << smallerNum << endl;

	return 0;
}
