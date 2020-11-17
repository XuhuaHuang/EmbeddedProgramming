/*****************************************************************//**
 * \file   STL_template.cpp
 * \brief  Introduction on template in C++
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>

using namespace std;

// overload functions
int sum(int num1, int num2) { return num1 + num2; }
double sum(double num1, double num2) { return num1 + num2; }

// function templates
template<class Custom> // class type is a variable
Custom sum(Custom num1, Custom num2) // when calling: sum<Custom>(num1, num2)
{
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	return num1 + num2;
}

template<class Custom, int N>
Custom fixedMultiply(Custom val) // when calling: fixedMultiply<Custom, N>(val)
{
	cout << val << " is being multipled with " << N << endl;
	return val * N;
}

int main(void)
{
	cout << "\nWith overloading functions" << endl;
	cout << sum(10, 20) << endl; // 30
	cout << sum(10.01, 20.02) << endl; // 30.03

	/**
	 * syntax of C++ template
	 * 
	 * template <class sometype>
	 * sometype sum(sometype a, sometype b) { return a + b; }
	 * 
	 * In this way, the type of the parameters become variables
	 */
	
	cout << "\nWith function template" << endl;
	cout << sum<int>(10, 20) << endl;
	cout << sum<double>(10.01, 20.02) << endl;

	cout << "\nWith function template \"fixedMultiply\"" << endl;
	cout.precision(2); // set double digits precision
	cout << fixed << fixedMultiply<double, 4>(20.00) << endl;

	return 0;
}
