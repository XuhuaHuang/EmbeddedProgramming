/*****************************************************************//**
 * \file   math_with_loops.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 06, 2020
 *********************************************************************/

#include <cmath>
#include <iostream>

int main(void)
{
    // add num 1-100 using while loop
    std::cout << "Adding number 1-100 with while loop."
              << "\n";
    int sum      = 0;
    int numtoAdd = 0;

    while (numtoAdd < 101)
    {
        sum += numtoAdd;
        // sum = sum + numtoAdd;
        numtoAdd++;
    }

    std::cout << sum << "\n";

    // 20*19*18*17*...*1 with while loop
    std::cout << "\nMultiplying 20, 19, 18, ...3, 2, 1 together."
              << "\n";
    long long product       = 1;
    int       numtoMultiply = 1;
    while (numtoMultiply < 21)
    {
        product *= numtoMultiply;
        numtoMultiply++;
    }
    std::cout << product << "\n";

    // calculating the number of digit of a number
    int userInput = 0;
    int numDigits = 0;
    std::cout << "\nHelp to determine the number of digits of a number."
              << "\n"
              << "Please enter the number to determine number of digits: ";

    std::cin >> userInput;
    int tempStorage = userInput;

    userInput /= 10;
    numDigits++;

    /*
    while (userInput)
    {
        userInput /= 10;
        numDigits++;
    }
    std::cout << "The number " << tempStorage << " is a number of " << numDigits << " digit(s). "<< "\n";
    */

    // with do-whil loop:
    do
    {
        userInput /= 10;
        numDigits++;
    } while (userInput);
    std::cout << "The number " << tempStorage << " is a number of " << numDigits << " digit(s). "
              << "\n";

    /*
     * Taylor Series
     * adding n fractions numbers together
     * numFraction: userinput, stands for number of fraction being added together
     * sign: determine the sign of each fraction in this series
     */
    int numFraction = 0;
    std::cout << "Generating a Taylor Series of customized number of fractions"
              << "\n"
              << "Please enter the number of the fraction numbers in the taylor series: ";

    std::cin >> numFraction; // index of denominator
    // creating required variables
    double result = 0.0;
    double term   = 0.0; // i_th term = sign / index
    double sign   = 1.0;

    for (int i = 1; i <= numFraction; i++)
    {
        term = sign / numFraction;
        result += term;
        sign *= -1;
    }
    std::cout << "With " << numFraction << " number of fractions, the result of the series is: " << result << "\n";

    // output all the even number within the range of 1-100
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0)
            std::cout << i << " is an even numer"
                      << "\n";
        // else if (i % 2)
        // std::cout << i << " is an odd number." << "\n";
    }

    // creating a right-angle-triangle with "numCh" amount of "userCh"
    // determine the relationship between number of characters and the line index of nested for loops
    char userCh;
    std::cin >> userCh;
    int numCh;
    std::cin >> numCh;

    for (int i = 0; i < numCh; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            std::cout << userCh;
        }
        std::cout << "\n";
    }

    return 0;
}
