/*
* 1879700 Xuhua Huang
* Inheritance Lab Main File
* 
* Contains:
* main function
*/

// built-in library:
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

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
	
	// Test Account Class
	cout << "Testing 'Account' class..." << endl;
	
	cout << "\nCreating a new account..." << endl;
	Account myAccount1; // creating an account
	cout << "\nCurrent balance is at: " << myAccount1.getBalance() << endl; // $0
	
	cout << "\nCreating a new account with initial balance of $100.10..." << endl;
	Account my100Account(100.10); // 100 is the 'initBalance'
	cout << "\nNew account created with overloaded constructor.\n[main]Account balance is at: " << my100Account.getBalance() << endl; // $100

	cout << "\nSetting new balance to $200.20..." << endl;
	myAccount1.setBalance(200.20);
	cout << "\nMy new account balance of myAccount1 is: $ " << myAccount1.getBalance() << endl;

	cout << "\nDepositting $300.30..." << endl;
	myAccount1.credit(300.30); // 200.20 + 300.30 = 500.50
	cout << "\nAfter depositting into my credit account, latest availble balance is: $ " << myAccount1.getBalance() << endl;

	cout << "\nWithdrawing $250.25..." << endl;
	myAccount1.debit(250.25); // 500.50 - 250.25 = 250.25 without fee
	cout << "\nAfter withdrawing from debit account, latest availble balance is: $ " << myAccount1.getBalance() << endl;

	cout << "\nAttempting to withdraw $300.30..." << endl;
	myAccount1.debit(300.30); // not enough funds to withdraw, print error only
	cout << "\nKnown no changes should have been made to myAccount1. Balance remains: $ " << myAccount1.getBalance() << endl;
	
	cout << "Test cases for class \"Account\" ends here." << endl;


	return 0;
}
