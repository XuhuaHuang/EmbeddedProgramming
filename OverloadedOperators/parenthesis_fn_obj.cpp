/*****************************************************************//**
 * \file   parenthesis_fn_obj.cpp
 * \brief  overloading the parenthesis operator with function objects
 * 
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Compare
{
public:

	// overloading the "()" operator to compare two int
	// return either 'true/1' or 'false/0'
	string operator()(int a, int b) { 
		string result = "false";
		if (a < b)
			result = "true";
		
		return result; 
	}
};

int main(void)
{
	Compare compare; // create a function object
	int a = 5;
	int b = 7;
	string ans = compare(a, b); // using the overloaded () operator
								// of the "Compare" class
	cout << ans << endl;
	
	// fun with nested for loops
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			string ans = compare(i, j);
			cout << "\nFor " << i << " < " << j << " is " << ans << endl;
		}
	}

	return 0;
}
