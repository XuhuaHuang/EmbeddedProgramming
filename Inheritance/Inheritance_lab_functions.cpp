/*
* 1879700 Xuhua Huang
* Inheritance Lab Function File
*
* Contains:
* default / overloaded constructors
* function definitions
* 
* Notice: ALL "cout" statements inside a function are appended
* after signature "[fn]" which stands for printing from function
*/

// built-in library:
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
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

// Base class 'Account' function definitions:
Account::Account() // default constructor for base class 'Account'
{
	setBalance(0.0);
}

Account::Account(double initBalance)
{
	cout.precision(2);

	if (initBalance >= 0.0)
	{
		setBalance(initBalance); // set the balance only if it is greater than 0
		cout << "\n[fn]Overloaded constructor \"Account::Account(double)\" is called with valid initial balance." << endl;
		cout << "[fn]Your initial balance is set to: $ " << fixed << getBalance() << endl;
	}
	else
	{
		cout << "\n[fn]Overloaded constructor \"Account::Account(double)\" is called with invalid initial balance." << endl;
		cout << "[fn]Error message: Invalid. Current balance can not be set to a negative number. Please try again." << endl;
		cout << "[fn]Current balance is automatically initialized to 0." << endl;
		setBalance(0.0);
	}

}

void Account::credit(double deposit)
{
	cout.precision(2);

	setBalance(getBalance() + deposit); // add deposit to current balance
	cout << "\n[fn]This line indicates function \"Account::credit(double)\" is called:" << endl;
	cout << "[fn]Deposited. Your latest account balance is: $ " << fixed << getBalance() << endl;
	cout << "[fn]Function \"Account::credit(double)\" ends executing on this line." << endl;

	return;
}

bool Account::debit(double withdraw)
{
	cout << "\n[fn]This line indicates function \"Account::debit(double)\" is called." << endl;

	bool withdrawSuccess = false; // set the default value to false

	if (getBalance() - withdraw > 0.0)
	{
		cout << "[fn]Withdraw successfully, account balance is recalculated." << endl;
		setBalance(getBalance() - withdraw);
		withdrawSuccess = true;
	}
	else
	{
		cout << "\n[fn]Error! Debit amount exceeded account balance." << endl;
		cout << "[fn]Account balance remains unchanged." << endl;
	}

	cout << "[fn]Function \"Account::debit(double)\" ends executing on this line." << endl;

	return withdrawSuccess;
}

// Derived class 'SavingsAccount' function definitions:
SavingsAccount::SavingsAccount()
{
	setBalance(0.0); // 'Account' class member function
	setInterestRate(0.03); // 'SavingsAccount' class member function
	// double interestRate is default to 3%
}

SavingsAccount::SavingsAccount(double initBalance, double interest) : Account(initBalance)
{
	cout << "\n[fn]Overloaded constructor \"SavingsAccount::SavingsAccount(double, double)\" is called with valid initial balance." << endl;
	cout << "[fn]Your initial balance is set to: $ " << fixed << getBalance() << endl;
	cout << "[fn]Your initial interest rate is set to: " << fixed << getInterestRate() << endl;
	
	setInterestRate(interest);
}

double SavingsAccount::calculateInterest()
{
	double interestEarned = getBalance() * getInterestRate();

	return interestEarned;
}

// Derived class 'CheckingAccount' function definitions:
CheckingAccount::CheckingAccount()
{
	setBalance(0.0); // 'Account' class member function
	setFee(0.25); // 'CheckingAccount' class member function
	// 'double fee' is default to 0.25
}

CheckingAccount::CheckingAccount(double initBalance, double initFee) : Account(initBalance)
{
	setFee(initFee);
	
	cout << "\n[fn]Overloaded constructor \"CheckingAccount::CheckingAccount(double, double)\" is called with valid initial balance." << endl;
	cout << "[fn]Your initial balance is set to: $ " << fixed << getBalance() << endl;
	cout << "[fn]Your fee for each transaction is: " << fixed << getFee() << endl;
}

void CheckingAccount::credit(double deposit)
{
	Account::credit(deposit - getFee());

	/*
	* invoke Account class member function with updated argument (fee subtracted)
	* Account::credit(deposit);
	* setBalance(getBalance() - getFee());
	*/

	return;
}

void CheckingAccount::debit(double withdraw)
{
	cout.precision(2);

	cout << "\n[fn]This line indicates function \"CheckingAccount::debit(double)\" is called." << endl;

	bool withdrawFeeStatus = Account::debit(withdraw);
	if (withdrawFeeStatus)
	{
		setBalance(getBalance() - getFee()); // only deduct the fee applied
		cout << "[fn]Withdrawing fee deducted. Your new balance is: $ " << fixed << getBalance() << endl;
	}
	else
	{
		cout << "[fn]Error! Debit amount exceeded account balance." << endl;
		cout << "[fn]Account balance remains unchanged. Withdraw fee not deducted." << endl;
	}

	cout << "[fn]Function \"CheckingAccount::debit(double)\" ends executing on this line." << endl;

	return;
}
