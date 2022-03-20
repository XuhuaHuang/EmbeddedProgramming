/**
 * @file Inheritance_lab_functions.cpp
 * @author 1879700 Xuhua Huang
 * @brief Inheritance Lab Function File
 * default / overloaded constructors
 * function definitions
 * 
 * @note ALL "std::cout" statements inside a function are appended
 * after signature "[fn]" which stands for printing from function
 * 
 * @version 1.0
 * @date November 2020
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// built-in library:
#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _INC_MATH
#include <math.h>
#endif

// customized class:
#include "BankingAccounts.hpp"

// Base class 'Account' function definitions:
Account::Account() // default constructor for base class 'Account'
{
	setBalance(0.0);
}

Account::Account(double initBalance)
{
	std::cout.precision(2);

	if (initBalance >= 0.0)
	{
		setBalance(initBalance); // set the balance only if it is greater than 0
		std::cout << "\n[fn]Overloaded constructor \"Account::Account(double)\" is called with valid initial balance." << "\n";
		std::cout << "[fn]Your initial balance is set to: $ " << std::fixed << getBalance() << "\n";
	}
	else
	{
		std::cout << "\n[fn]Overloaded constructor \"Account::Account(double)\" is called with invalid initial balance." << "\n";
		std::cout << "[fn]Error message: Invalid. Current balance can not be set to a negative number. Please try again." << "\n";
		std::cout << "[fn]Current balance is automatically initialized to 0." << "\n";
		setBalance(0.0);
	}

}

void Account::credit(double deposit)
{
	std::cout.precision(2);

	setBalance(getBalance() + deposit); // add deposit to current balance
	std::cout << "\n[fn]This line indicates function \"Account::credit(double)\" is called:" << "\n";
	std::cout << "[fn]Deposited. Your latest account balance is: $ " << std::fixed << getBalance() << "\n";
	std::cout << "[fn]Function \"Account::credit(double)\" ends executing on this line." << "\n";

	return;
}

bool Account::debit(double withdraw)
{
	std::cout << "\n[fn]This line indicates function \"Account::debit(double)\" is called." << "\n";

	bool withdrawSuccess = false; // set the default value to false

	if (getBalance() - withdraw > 0.0)
	{
		std::cout << "[fn]Withdraw successfully, account balance is recalculated." << "\n";
		setBalance(getBalance() - withdraw);
		withdrawSuccess = true;
	}
	else
	{
		std::cout << "\n[fn]Error! Debit amount exceeded account balance." << "\n";
		std::cout << "[fn]Account balance remains unchanged." << "\n";
	}

	std::cout << "[fn]Function \"Account::debit(double)\" ends executing on this line." << "\n";

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
	std::cout << "\n[fn]Overloaded constructor \"SavingsAccount::SavingsAccount(double, double)\" is called with valid initial balance." << "\n";
	std::cout << "[fn]Your initial balance is set to: $ " << std::fixed << getBalance() << "\n";
	std::cout << "[fn]Your initial interest rate is set to: " << std::fixed << getInterestRate() << "\n";
	
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
	
	std::cout << "\n[fn]Overloaded constructor \"CheckingAccount::CheckingAccount(double, double)\" is called with valid initial balance." << "\n";
	std::cout << "[fn]Your initial balance is set to: $ " << std::fixed << getBalance() << "\n";
	std::cout << "[fn]Your fee for each transaction is: " << std::fixed << getFee() << "\n";
}

void CheckingAccount::credit(double deposit)
{
	/**
	 * @brief invoke Account class member function with updated argument (fee subtracted)
	 * Account::credit(deposit);
	 * setBalance(getBalance() - getFee());
	 */
	Account::credit(deposit - getFee());

	return;
}

void CheckingAccount::debit(double withdraw)
{
	std::cout.precision(2);

	std::cout << "\n[fn]This line indicates function \"CheckingAccount::debit(double)\" is called." << "\n";

	bool withdrawFeeStatus = Account::debit(withdraw);
	if (withdrawFeeStatus)
	{
		setBalance(getBalance() - getFee()); // only deduct the fee applied
		std::cout << "[fn]Withdrawing fee deducted. Your new balance is: $ " << std::fixed << getBalance() << "\n";
	}
	else
	{
		std::cout << "[fn]Error! Debit amount exceeded account balance." << "\n";
		std::cout << "[fn]Account balance remains unchanged. Withdraw fee not deducted." << "\n";
	}

	std::cout << "[fn]Function \"CheckingAccount::debit(double)\" ends executing on this line." << "\n";

	return;
}
