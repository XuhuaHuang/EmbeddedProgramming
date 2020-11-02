/*
* 1879700 Xuhua Huang
* Inheritance Lab - Derived Class 'CheckingAccount'
*/

#include "Account.hpp"

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
