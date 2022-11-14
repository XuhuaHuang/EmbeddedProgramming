/*****************************************************************//**
 * \file   bank_account_test.cpp
 * \brief  Testing basic implementation of BankAccount.
 *
 * \author Xuhua Huang
 * \date   November 14, 2022
 *********************************************************************/

#include <iostream>
#include <gtest/gtest.h>

#define STDTEST std::cout << "\033[32m[---TEST---]\033[m "

class BankAccount
{
public:
    // default and overloaded constructor:
    BankAccount() : balance(0.00) {}
    explicit BankAccount(const double initBalance) : balance(initBalance) {}

    // get function for variable 'balance'
    double getBalance() { return balance; }

    // global function: deposit & withdraw
    void credit(const double& deposit);
    bool debit(const double& withdraw);

private:
    double balance;

    void setBalance(const double& newBalance) {
        if (newBalance > 0.00) {
            balance = newBalance;
        }
    }

    friend struct WithdrawAccountTest;
};

void BankAccount::credit(const double& deposit)
{
    std::cout.precision(2);

    setBalance(getBalance() + deposit); // add deposit to current balance
    STDTEST << "[fn]This line indicates function \"Account::credit(double)\" is called:" << "\n";
    STDTEST << "[fn]Deposited. Your latest account balance is: $ " << std::fixed << getBalance() << "\n";
    STDTEST << "[fn]Function \"Account::credit(double)\" ends executing on this line." << "\n";

    return;
}

bool BankAccount::debit(const double& withdraw)
{
    STDTEST << "[fn]This line indicates function \"Account::debit(double)\" is called." << "\n";

    bool withdrawSuccess = false;

    if (getBalance() - withdraw > 0.0)
    {
        STDTEST << "[fn]Withdraw successfully, account balance is recalculated." << "\n";
        setBalance(getBalance() - withdraw);
        withdrawSuccess = true;
    }
    else
    {
        STDTEST << "[fn]Error! Debit amount exceeded account balance." << "\n";
        STDTEST << "[fn]Account balance remains unchanged." << "\n";
    }

    STDTEST << "[fn]Function \"Account::debit(double)\" ends executing on this line." << "\n";

    return withdrawSuccess;
}

class BankAccountTest : public ::testing::Test
{
protected:
    BankAccount* account;
public:
    BankAccountTest() {
        account = new BankAccount();
    }

    virtual ~BankAccountTest() {
        delete account;
    }
};

/* Independent AccountTest instance */
TEST(AccountTest, BankAccountInitEmpty)
{
    BankAccount testAcct;
    EXPECT_EQ(0, testAcct.getBalance());
}

/* Using predefined BankAccountTest class test suite */
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
public:
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

struct WithdrawAccountTest : public BankAccountTest, ::testing::WithParamInterface<AccountState>
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
INSTANTIATE_TEST_SUITE_P(
    Default,
    WithdrawAccountTest,
    testing::Values(
        AccountState{ 100, 50, 50, true },
        AccountState{ 100, 200, 100, false }
    )
);


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
