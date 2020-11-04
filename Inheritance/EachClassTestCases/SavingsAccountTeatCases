/*
* 1879700 Xuhua Huang
* Inheritance Lab Main File
*
* Contains:
* main function
* - Test cases for each class
*
* Notice: when executing, "cout" are printed without signatures
* "cout" statements with signature "[fn]" come from functions
* If not specified, default constructors are called
*/

// built-in library:
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h> // for changing colours 
//#include <iomanip>
//#include <float.h>

// customized class:
#include "Inheritance_lab_header.h"

/*
* #include "Account.h" // Base 'Class Account'
* #include "SavingsAccount.h" // Derived Class 'SavingAccount'
* #include "CheckingAccount.h" // Derived Class 'CheckingAccount'
*/

using namespace std;

int main(void)
{
	cout.precision(2); // force double digits with using "std::fixed" in this scope i.e. main function
	
	// Tesing SavingsAccount Class
	cout << "\033[1;36m"; // change colour to cyan
	cout << "\nTesting \"SavingsAccount\" class..." << endl;

	SavingsAccount mySavingsAccount1; // declare an object of this class
	cout << "\nObject \"mySavingsAccount1\" is created.\nCurrent balance is at: $ " << fixed << mySavingsAccount1.getBalance() << endl;
	cout << "Interest rate is at: " << fixed << mySavingsAccount1.getInterestRate() << endl;

	cout << "\nCreating another object \"mySavingsAccount2\" of class \"SavingsAccount\" with overloaded constructor." << endl;
	SavingsAccount mySavingsAccount2(50, 0.05); // initial balance is 50, interestrate is 5%
	cout << "For \"mySavingsAccount2\", initial balance is set to: $ " << fixed << mySavingsAccount2.getBalance() << endl;
	cout << "Initial interest rate is at: " << mySavingsAccount2.getInterestRate() << endl;

	cout << "\nCalculating earned interest..." << endl;
	double interestEarnedSavings2 = mySavingsAccount2.calculateInterest();
	cout << "The total amount of interest earned is: $ " << fixed << interestEarnedSavings2 << endl;
	cout << "Depositting..." << endl;
	mySavingsAccount2.credit(mySavingsAccount2.calculateInterest());
	cout << "Current balance is at: $ " << fixed << mySavingsAccount2.getBalance() << endl;

	cout << "\nTest cases for class \"SavingsAccount\" end here.\n" << endl;
	cout << "\033[0m"; // reset colour to white
	cout << "****************************************************************************************************************" << endl;

	return 0;
}
