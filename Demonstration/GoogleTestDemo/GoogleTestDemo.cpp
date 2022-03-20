/*****************************************************************//**
 * \file   GoogleTestDemo.cpp
 * \brief  Contains an example working with Google Test framework
 * using a banking class example
 * 
 * \author Xuhua Huang
 * \date   20: 36 July 29, 2021
 *********************************************************************/

#include "BankAccount.h"
#include <gtest/gtest.h>

struct BankAccountTest : testing::Test
{
	BankAccount* account;

	BankAccountTest()
	{
		account = new BankAccount();
	}

	virtual ~BankAccountTest()
	{
		delete account;
	}
};
 /* Independent AccountTest instance */
TEST(AccountTest, BankAccountInitEmpty)
{
	BankAccount testAcct;
	EXPECT_EQ(0, testAcct.getBalance());
}

/* Using predefined struct */
TEST_F(BankAccountTest, BankAccountInitEmpty_Test)
{
	EXPECT_EQ(0, account->getBalance());
}

TEST_F(BankAccountTest, CanDepositMoney)
{
	account->credit(100.00);
	EXPECT_EQ(100.00, account->getBalance());
}

TEST_F(BankAccountTest, CanWithDrawMoney)
{
	account->credit(100.00);
	EXPECT_EQ(100.00, account->getBalance());
}

/* Creating test fixtures reusing struct with parameterization */
struct AccountState
{
	double initialBalance;
	double withdrawAmount;
	double finalBalance;
	bool withdrawSuccess;

	// define an overloaded operator for user-friendly output
	friend std::ostream& operator<<(std::ostream& os, const AccountState& acctState)
	{
		return os
			<< "Initial balance: " << acctState.initialBalance
			<< "Withdraw amount: " << acctState.withdrawAmount
			<< "Final balance: " << acctState.finalBalance
			<< "Withdraw success:" << acctState.withdrawSuccess;
	}
};

struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<AccountState>
{
	WithdrawAccountTest()
	{
		account->setBalance(GetParam().initialBalance);
	}
};

TEST_P(WithdrawAccountTest, FinalBalance)
{
	auto acctState = GetParam();
	bool success = account->debit(acctState.withdrawAmount);

	EXPECT_EQ(acctState.finalBalance, account->getBalance());
	EXPECT_EQ(acctState.withdrawSuccess, success);
}

/* Parameterized test */
INSTANTIATE_TEST_CASE_P(
	Default, 
	WithdrawAccountTest,
	testing::Values(
		AccountState{ 100, 50, 50, true },
		AccountState{ 100, 200, 100, false }
	)
);


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}