/*****************************************************************//**
 * \file   BankAccount.h
 * \brief  Contains BankAccount class definition
 * 
 * \author Xuhua Huang
 * \date   July 2021
 *********************************************************************/

#pragma once
#include <iostream>

class BankAccount
{
private:
	double balance;

public:
	// default and overloaded constructor:
	BankAccount() : balance(0.00) {}
	explicit BankAccount(const double initBalance) : balance(initBalance) {}

	// set and get function for variable 'balance'
	void setBalance(const double& newBalance) {
		if (newBalance > 0.00)
			balance = newBalance;
	}
	double getBalance() { return balance; }

	// global function: deposit & withdraw
	void credit(const double& deposit);
	bool debit(const double& withdraw);
};

void BankAccount::credit(const double& deposit)
{
	using namespace std;
	cout.precision(2);

	setBalance(getBalance() + deposit); // add deposit to current balance
	cout << "\n[fn]This line indicates function \"Account::credit(double)\" is called:" << endl;
	cout << "[fn]Deposited. Your latest account balance is: $ " << fixed << getBalance() << endl;
	cout << "[fn]Function \"Account::credit(double)\" ends executing on this line." << endl;

	return;
}

bool BankAccount::debit(const double& withdraw)
{
	using namespace std;
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