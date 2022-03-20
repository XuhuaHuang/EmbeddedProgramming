/**
 * @file Inheritance_lab_header.hpp
 * @author 1879700 Xuhua Huang
 * @brief Inheritance Lab Header File
 * 
 * Contains declaration of:
 * Base Class 'Account'
 * Derived Class 'SavingsAccount'
 * Derived Class 'CheckingAccount'
 * 
 * @version 1.0
 * @date November 2020
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Base class 'Account'
class Account
{
private:
	double balance;

public:
	// default and overloaded constructor:
	Account();
	Account(double initBalance);
	
	// set and get function for variable 'balance'
	void setBalance(double newBalance) { balance = newBalance; }
	double getBalance() { return balance; }
	
	// global function: deposit & withdraw
	void credit(double deposit);
	bool debit(double withdraw);
};

// First-level derived class 'SavingsAccount'
class SavingsAccount : public Account
{
private:
	double interestRate;

public:
	// default and overloaded constructor:
	SavingsAccount();
	SavingsAccount(double initBalance, double interest);

	// set and get function for variable 'interestRate'
	void setInterestRate(double newInterestRate) { interestRate = newInterestRate; }
	double getInterestRate() { return interestRate; }

	// global function:
	double calculateInterest();
};

// First-level derived class 'CheckingAccount'
class CheckingAccount : public Account
{
private:
	double fee;

public:
	// default and overloaded constructor:
	CheckingAccount();
	CheckingAccount(double initBalance, double initFee);

	// set and get function for variable 'fee'
	void setFee(double newFee) { fee = newFee; }
	double getFee() { return fee; }

	// redefined global function: deposit & withdraw
	void credit(double deposit);
	void debit(double withdraw);
};
