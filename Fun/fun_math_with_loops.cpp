#include <iostream>
#include <cmath>

using namespace std;

/*
* Last updated: Nov 06, 2020
* Created: Nov 02, 2020 23:00 DST
*
* To-do list:
* Number of daffodils
* Recurrance
* Enumeration
*/

int main(void)
{
	// add num 1-100 using while loop
	cout << "Adding number 1-100 with while loop." << endl;
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
	cout << "\nMultiplying 20, 19, 18, ...3, 2, 1 together." << endl;
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
	cout << "\nHelp to determine the number of digits of a number." << endl
		 << "Please enter the number to determine number of digits: ";

	cin >> userInput;
	int tempStorage = userInput;

	userInput /= 10;
	numDigits++;

	/*
	while (userInput)
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
	* adding n fractions numbers together
	* numFraction: userinput, stands for number of fraction being added together
	* sign: determine the sign of each fraction in this series
	*/
	int numFraction = 0;
	cout << "Generating a Taylor Series of customized number of fractions" << endl
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
	// determine the relationship between number of characters and the line index of nested for loops
	char userCh;
	cin >> userCh;
	int numCh;
	cin >> numCh;

	for (int i = 0; i < numCh; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			cout << userCh;
		}
		cout << endl;
	}


	/* 
	* Name: Find the amount of exchange
	* Requirement: each kind of coin must present once
	* 
	* Last updated: Nov 06, 2020
	* Created on: Nov 06, 2020
	* 
	* Method: Enumerate and loop through all possibilities until find solution
	*		  Sequential enumeration
	* 
	* Advantages: 
	* 1) Easy to understand algorithm
	* 2) Usually used to determine "how many combinations, if there's a solution" type of problem
	* 
	* BUT -  relies on heavy loaded calculation
	*/
	double total = 0;
	double payed = 0;
	
	cout << "Please enter total amount invoice: ";
	cin >> total;
	
	cout << "Please enter the amount customer payed: ";
	cin >> payed;
	
	double exchange = payed - total;
	cout << "The amount of exchange is: " << exchange << endl;

	int num10Cents = 0; int num15Cents = 0; int num25Cents = 0; int num50Cents = 0;

	for (int i = 0; i < exchange / 0.10; i++) // enumerate 10Cents
	{
		for (int j = 0; j < exchange / 0.15; j++) // enumerate 15Cents
		{
			for (int k = 0; k < exchange / 0.25; k++) // enumerate 25Cents
			{
				for (int l = 0; l < exchange / 0.50; l++) // enumerate 50Cents
				{
					if ( (i * 0.1 + j * 0.15 + k * 0.25 + l * 0.50 == exchange) // if adds up to desired exchange
						&& (i != 0) 
						&& (j != 0) 
						&& (k != 0) 
						&& (l != 0) ) // each kind of coin must present once
					{
						cout << "\nOne of the solutions: " << endl
							 << "You will need " << i << " of 10 cents coins." << endl
							 << j << " of 15 cents coins." << endl
							 << k << " of 25 cents coins." << endl
							 << l << " of 50 cents coins." << endl;
					}
				}
			}
		}
	}
	
	
	/*
	* Name: Fibonacci Series - first 25 term
	* Requirement: the i-th item of the series equals to the sum of previous two
	*	       print a new line every five numbers in console
	*
	* Author: Xuhua Huang
	* Last updated: Nov 06, 2020
	* Created on: Nov 06, 2020
	*/
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
