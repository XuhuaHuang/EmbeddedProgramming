/**
 * @file Inheritance_lab_main.cpp
 * @author 1879700 Xuhua Huang
 * @brief Inheritance Lab Main File
 * Contains main function - test cases for each class
 *
 * @notes: when executing, "std::cout" are printed without signatures
 * "std::cout" statements with signature "[fn]" come from functions
 * If not specified, default constructors are called
 *
 * @version 1.0
 * @date November 2020
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// built-in library:
#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <Windows.h>

// customized class:
#include "BankingAccounts.hpp"

namespace util {
namespace basic_interaction {

    void print_asterisks_separater(void) {
        CONSOLE_SCREEN_BUFFER_INFO terminal_info;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &terminal_info);
        const int _terminal_columns = terminal_info.srWindow.Right - terminal_info.srWindow.Left;
        for (int count = 0; count < _terminal_columns; ++count) {
            std::cout << "*";
        }
        std::cout << "\n";
        return;
    }

} // end interaction
} // end util


int main(void)
{
    std::cout.precision(2); // force double digits with using "std::fixed" in this scope i.e. main function

    // Testing Account Class
    system("Color 0A"); // change text color to green
    // std::cout << "\033[1;32m"; // change colour to green
    std::cout << "Testing \"Account\" class..." << "\n";

    std::cout << "\nCreating a new account..." << "\n";
    Account myAccount1; // creating an account
    std::cout << "\nCurrent balance is at: $ " << std::fixed << myAccount1.getBalance() << "\n"; // $0

    std::cout << "\nCreating a new account with initial balance of $100.10..." << "\n";
    Account my100Account(100.10); // 100 is the 'initBalance'
    std::cout << "\nNew account created with overloaded constructor.\nAccount balance is at: " << std::fixed << my100Account.getBalance() << "\n"; // $100

    std::cout << "\nSetting new balance to $200.20..." << "\n";
    myAccount1.setBalance(200.20);
    std::cout << "\nMy new account balance of myAccount1 is: $ " << std::fixed << myAccount1.getBalance() << "\n";

    std::cout << "\nDepositting $300.30..." << "\n";
    myAccount1.credit(300.30); // 200.20 + 300.30 = 500.50
    std::cout << "\nAfter depositting into my credit account, latest availble balance is: $ " << std::fixed << myAccount1.getBalance() << "\n";

    std::cout << "\nWithdrawing $250.25..." << "\n";
    myAccount1.debit(250.25); // 500.50 - 250.25 = 250.25 without fee
    std::cout << "\nAfter withdrawing from debit account, latest availble balance is: $ " << std::fixed << myAccount1.getBalance() << "\n";

    std::cout << "\nAttempting to withdraw $300.30..." << "\n";
    myAccount1.debit(300.30); // not enough funds to withdraw, print error only
    std::cout << "\nKnown no changes should have been made to myAccount1. Balance remains: $ " << std::fixed << myAccount1.getBalance() << "\n";

    std::cout << "\nTest cases for class \"Account\" end here.\n" << "\n";
    std::cout << "\033[0m"; // reset colour to white
    util::basic_interaction::print_asterisks_separater();

    // Testing SavingsAccount Class
    std::cout << "\033[1;36m"; // change colour to cyan
    std::cout << "\nTesting \"SavingsAccount\" class..." << "\n";

    SavingsAccount mySavingsAccount1; // declare an object of this class
    std::cout << "\nObject \"mySavingsAccount1\" is created.\nCurrent balance is at: $ " << std::fixed << mySavingsAccount1.getBalance() << "\n";
    std::cout << "Interest rate is at: " << std::fixed << mySavingsAccount1.getInterestRate() << "\n";

    std::cout << "\nCreating another object \"mySavingsAccount2\" of class \"SavingsAccount\" with overloaded constructor." << "\n";
    SavingsAccount mySavingsAccount2(50, 0.05); // initial balance is 50, interestrate is 5%
    std::cout << "For \"mySavingsAccount2\", initial balance is set to: $ " << std::fixed << mySavingsAccount2.getBalance() << "\n";
    std::cout << "Initial interest rate is at: " << mySavingsAccount2.getInterestRate() << "\n";

    std::cout << "\nCalculating earned interest..." << "\n";
    double interestEarnedSavings2 = mySavingsAccount2.calculateInterest();
    std::cout << "The total amount of interest earned is: $ " << std::fixed << interestEarnedSavings2 << "\n";
    std::cout << "Depositting..." << "\n";
    mySavingsAccount2.credit(mySavingsAccount2.calculateInterest());
    std::cout << "Current balance is at: $ " << std::fixed << mySavingsAccount2.getBalance() << "\n";

    std::cout << "\nTest cases for class \"SavingsAccount\" end here.\n" << "\n";
    std::cout << "\033[0m"; // reset colour to white
    util::basic_interaction::print_asterisks_separater();

    // Testing CheckingAccount Class
    std::cout << "\033[1;34m"; // change colour to blue
    std::cout << "\nTesting \"CheckingAccount\" class..." << "\n";

    CheckingAccount myCheckingAccount1; // declare an object of this class
    std::cout << "\nObject \"myCheckingAccount1\" is created.\nCurrent balance is at: $ " << std::fixed << myCheckingAccount1.getBalance() << "\n";
    std::cout << "Fee for each transaction is: " << std::fixed << myCheckingAccount1.getFee() << "\n";

    std::cout << "\nCreating another object \"myCheckingAccount2\" of class \"CheckingAccount\" with overloaded constructor." << "\n";
    CheckingAccount myCheckingAccount2(20, 0.33);
    std::cout << "For \"myCheckingAccount2\", initial balance is set to: $ " << std::fixed << myCheckingAccount2.getBalance() << "\n";
    std::cout << "Fee for each transaction is: " << myCheckingAccount2.getFee() << "\n";

    std::cout << "\nDepositting $200.20 into \"myCheckingAccount2\"..." << "\n";
    myCheckingAccount2.credit(200.20);
    std::cout << "Deposited. Your renewed balance is at: " << std::fixed << myCheckingAccount2.getBalance() << "\n";
    // 200.20 + 20 - 0.33 = 219.87

    std::cout << "\nWithdrawing $200.00 from \"myCheckingAccount2\"..." << "\n";
    myCheckingAccount2.debit(200.00);
    std::cout << "Withdrawn. Your renewed balance is at: " << std::fixed << myCheckingAccount2.getBalance() << "\n";
    // 219.87 - 200.00 - 0.33 = 19.54

    std::cout << "\nAttempting to withdraw bigger amount of money than there is from \"myCheckingAccount2\"..." << "\n";
    myCheckingAccount2.debit(2020.20);
    std::cout << "\nKnown no changes should have been made to \"myCheckingAccount2\". Balance remains: $ " << std::fixed << myCheckingAccount2.getBalance() << "\n";

    std::cout << "\nTest cases for class \"CheckingAccount\" end here." << "\n";
    std::cout << "\033[0m"; // reset colour to white

    system("pause");
    return 0;
}
