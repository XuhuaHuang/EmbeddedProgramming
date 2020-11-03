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

	// adding n fractions numbers together


	return 0;
}
