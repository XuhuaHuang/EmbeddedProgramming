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

	// Testing Account Class
	//system("color 0A"); // change text color to green using <Windows.h> built-in function system(color XY);
	cout << "\033[1;32m"; // change colour to green
	cout << "Testing \"Account\" class..." << endl;

	cout << "\nCreating a new account..." << endl;
	Account myAccount1; // creating an account
	cout << "\nCurrent balance is at: $ " << fixed << myAccount1.getBalance() << endl; // $0

	cout << "\nCreating a new account with initial balance of $100.10..." << endl;
	Account my100Account(100.10); // 100 is the 'initBalance'
	cout << "\nNew account created with overloaded constructor.\nAccount balance is at: " << fixed << my100Account.getBalance() << endl; // $100

	cout << "\nSetting new balance to $200.20..." << endl;
	myAccount1.setBalance(200.20);
	cout << "\nMy new account balance of myAccount1 is: $ " << fixed << myAccount1.getBalance() << endl;

	cout << "\nDepositting $300.30..." << endl;
	myAccount1.credit(300.30); // 200.20 + 300.30 = 500.50
	cout << "\nAfter depositting into my credit account, latest availble balance is: $ " << fixed << myAccount1.getBalance() << endl;

	cout << "\nWithdrawing $250.25..." << endl;
	myAccount1.debit(250.25); // 500.50 - 250.25 = 250.25 without fee
	cout << "\nAfter withdrawing from debit account, latest availble balance is: $ " << fixed << myAccount1.getBalance() << endl;

	cout << "\nAttempting to withdraw $300.30..." << endl;
	myAccount1.debit(300.30); // not enough funds to withdraw, print error only
	cout << "\nKnown no changes should have been made to myAccount1. Balance remains: $ " << fixed << myAccount1.getBalance() << endl;

	cout << "\nTest cases for class \"Account\" end here.\n" << endl;
	cout << "\033[0m"; // reset colour to white
	cout << "****************************************************************************************************************" << endl;
	
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
