/*
* 1879700 Xuhua Huang
* Inheritance Lab - Derived Class 'SavingsAccount'
*/

#include "Account.h"

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
