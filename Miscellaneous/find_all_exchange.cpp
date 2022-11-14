/*****************************************************************//**
 * \file   find_all_exchange.cpp
 * \brief  Find the amount of exchange
 * Requirement: each kind of coin must present once
 *
 * Method: Enumerate and loop through all possibilities untill find solution
 * Sequential enumeration
 *
 * Advantages:
 * 1) Easy to understand algorithm
 * 2) Usually used to determine "how many combinations, if there's a solution" type of problem
 *
 * BUT -  relies on heavy loaded calculation
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/

#include <iostream>
#include <math.h>

int main(void)
{
    double total = 0;
    double payed = 0;

    std::cout << "Please enter total amount invoice: ";
    std::cin >> total;

    std::cout << "Please enter the amount customer payed: ";
    std::cin >> payed;

    double exchange = payed - total;
    std::cout << "The amount of exchange is: " << exchange << "\n";

    int num10Cents = 0; int num15Cents = 0; int num25Cents = 0; int num50Cents = 0;

    for (int i = 0; i < exchange / 0.10; i++) // enumerate 10Cents
    {
        for (int j = 0; j < exchange / 0.15; j++) // enumerate 15Cents
        {
            for (int k = 0; k < exchange / 0.25; k++) // enumerate 25Cents
            {
                for (int l = 0; l < exchange / 0.50; l++) // enumerate 50Cents
                {
                    if ((i * 0.1 + j * 0.15 + k * 0.25 + l * 0.50 == exchange) // if adds up to desired exchange
                        && (i != 0)
                        && (j != 0)
                        && (k != 0)
                        && (l != 0)) // each kind of coin must present once
                    {
                        std::cout << "\nOne of the solutions: " << "\n"
                            << "You will need " << i << " of 10 cents coins." << "\n"
                            << j << " of 15 cents coins." << "\n"
                            << k << " of 25 cents coins." << "\n"
                            << l << " of 50 cents coins." << "\n";
                    }
                }
            }
        }
    }

    return 0;
}
