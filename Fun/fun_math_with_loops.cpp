#include <iostream>
#include <cmath>

using namespace std;

// Nov 2, 2020 23:00 DST

int main(void)
{
	// add num 1-100 using while loop
	int sum = 0;
	int numtoAdd = 0;
	
	while (numtoAdd < 101)
	{
		sum += numtoAdd;
		// sum = sum + numtoAdd;
		numtoAdd++;
	}

	cout << sum << endl;


	// 20*19*18*17*...*1 with while loop
	long long product = 1;
	int numtoMultiply = 1;
	while (numtoMultiply < 21)
	{
		product *= numtoMultiply;
		numtoMultiply++;
	}
	cout << product << endl;


	// calculating the number of digit of a number
	int userInput = 0;
	int numDigits = 0;

	cout << "Please enter the number to determine number of digits: ";
	cin >> userInput;
	int tempStorage = userInput;

	userInput /= 10;
	numDigits++;

	/*while (userInput)
	{
		userInput /= 10;
		numDigits++;
	}
	
	cout << "The number " << tempStorage << " is a number of " << numDigits << " digit(s). "<< endl;
	*/
	
	// with do-whil loop:
	do
	{
		userInput /= 10;
		numDigits++;
	} while (userInput);
	cout << "The number " << tempStorage << " is a number of " << numDigits << " digit(s). " << endl;

	/*
	* Taylor Series
	* Analysis: adding n fractions numbers together
	* numFraction: userinput, stands for number of fraction being added together
	* sign: determine the sign of each fraction in this series
	*/
	int numFraction = 0;
	cout << "Generating a Taylor Seiries of customized number of fractions" << endl
		 << "Please enter the number of the fraction numbers in the taylor series: ";

	cin >> numFraction;	 // index of denominator
	
	// creating required variables
	double result = 0.0;
	double  term = 0.0; // i_th term = sign / index
	double sign = 1.0;

	for (int i = 1; i <= numFraction; i++)
	{
		term = sign / numFraction;
		result += term;
		sign *= -1;
	}
	cout << "With " << numFraction << " number of fractions, the result of the series is: " << result << endl;

	// output all the even number within the range of 1-100
	for (int i = 1; i <= 100; i++)
	{
		if ( i % 2 == 0 )
			cout << i << " is an even numer" << endl;
		//else if (i % 2)
			//cout << i << " is an odd number." << endl;
	}

	// creating a right-angle-triangle with "numCh" amount of "userCh"
	// Hint: determine the relationship between number of characters and the line index of nested for loops
	char userCh; // custom character to create right-angle triangle with
	cin >> userCh;
	int numCh; // number of character to form the side
	cin >> numCh;

	for (int i = 0; i < numCh; i++)
	{
		for (int j = 0; j < (i + 1); j++) // 'j< (i + 1);' is the key statement
		{
			cout << userCh;
		}
		cout << endl;
	}

	return 0;
}
