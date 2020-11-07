/* 
 * Name: Find the amount of exchange
 * Requirement: each kind of coin must present once
 * 
 * Author: Xuhua Huang
 * Last updated: Nov 06, 2020
 * Created on: Nov 06, 2020
 * 
 * Method: Enumerate and loop through all possibilities untill find solution
 *		  Sequential enumeration
 * 
 * Advantages: 
 * 1) Easy to understand algorithm
 * 2) Usually used to determine "how many combinations, if there's a solution" type of problem
 * 
 * BUT -  relys on heavy loaded calculation
 */

#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	
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

	return 0;
}
