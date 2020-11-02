/*
* 1879700 Xuhua Huang
* Inheritance Lab - Base Class 'Account'
*/

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
