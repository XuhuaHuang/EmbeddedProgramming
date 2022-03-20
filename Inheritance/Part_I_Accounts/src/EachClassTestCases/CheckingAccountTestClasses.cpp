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

	// Testing CheckingAccount Class
	cout << "\033[1;34m"; // change colour to blue
	cout << "\nTesting \"CheckingAccount\" class..." << endl;

	CheckingAccount myCheckingAccount1; // declare an object of this class
	cout << "\nObject \"myCheckingAccount1\" is created.\nCurrent balance is at: $ " << fixed << myCheckingAccount1.getBalance() << endl;
	cout << "Fee for each transaction is: " << fixed << myCheckingAccount1.getFee() << endl;

	cout << "\nCreating another object \"myCheckingAccount2\" of class \"CheckingAccount\" with overloaded constructor." << endl;
	CheckingAccount myCheckingAccount2(20, 0.33);
	cout << "For \"myCheckingAccount2\", initial balance is set to: $ " << fixed << myCheckingAccount2.getBalance() << endl;
	cout << "Fee for each transaction is: " << myCheckingAccount2.getFee() << endl;

	cout << "\nDepositting $200.20 into \"myCheckingAccount2\"..." << endl;
	myCheckingAccount2.credit(200.20);
	cout << "Deposited. Your renewed balance is at: " << fixed << myCheckingAccount2.getBalance() << endl;
	// 200.20 + 20 - 0.33 = 219.87

	cout << "\nWithdrawing $200.00 from \"myCheckingAccount2\"..." << endl;
	myCheckingAccount2.debit(200.00);
	cout << "Withdrawn. Your renewed balance is at: " << fixed << myCheckingAccount2.getBalance() << endl;
	// 219.87 - 200.00 - 0.33 = 19.54

	cout << "\nAttempting to withdraw bigger amout of money than there is from \"myCheckingAccount2\"..." << endl;
	myCheckingAccount2.debit(2020.20);
	cout << "\nKnown no changes should have been made to \"myCheckingAccount2\". Balance remains: $ " << fixed << myCheckingAccount2.getBalance() << endl;
	
	cout << "\nTest cases for class \"CheckingAccount\" end here." << endl;
	cout << "\033[0m"; // reset colour to white

	return 0;
}
