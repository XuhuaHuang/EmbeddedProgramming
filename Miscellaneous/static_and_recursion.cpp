/*****************************************************************//**
 * \file   static_and_recursion.cpp
 * \brief  Variable Scope inside function and function recursion
 *
 * g++ -c .\static_and_recursion.cpp -o static_and_recursion.exe
 * ./static_and_recursion.exe
 *
 * \author Xuhua Huang
 * \date   March 06, 2021
 *********************************************************************/

#include <iostream>
#include <math.h>

// function prototype:
// recursion:
int multiRecursion(int k);
int summation(int n);
// static variable inside scope:
void staticGlobalValTest();
// end of function prototype

int main(void)
{
    /**
     * recursion: a function calls itself deirectly inside of the defiition
     * other: calling itself indirectly.
     */
    int result = multiRecursion(5);
    std::cout << "\nResult from main(void) is: " << result << "\n";

    /**
     * scope of static and non-static variable
     * keyword 'static' grants dedicated non-erased memory allocation.
     */
    std::cout << "\nCalling function \"staticGlobalValTest()\" to verify output."
              << "\n";
    std::cout << "Calling first time: "
              << "\n";
    staticGlobalValTest();

    std::cout << "Called second time: "
              << "\n";
    staticGlobalValTest();

    std::cout << "Called thrid time: "
              << "\n";
    staticGlobalValTest();

    std::cout << "\nFinding sum of integers from 1 to 100 with recursion function."
              << "\n"
              << "Sum found: " << summation(100) << "\n";

    return 0;
}

int multiRecursion(int k)
{
    /**
     * can be avoided with proper manipulation with loops
     * logic for the following function 'multiRecursion'
     *
     * example calling with 5: 5 + 4 + 3 + 2 + 1 = 15
     * considered complete iteration
     *
     * subsequent calling listed as following:
     * calling with 4: 4 + 3 + 2 + 1 = 10
     * calling with 3: 3 + 2 + 1 = 6
     * calling with 2: 2 + 1 = 3
     * calling with 1: 1 + 0 = 1
     */
    int result = 0;

    if (k > 0)
    {
        result = k + multiRecursion(k - 1);
        std::cout << "Variable \"K\" is: " << k << "\n"
                  << "Variable \"result\" is: " << result << "\n";
    }
    else
        result = 0;

    return result;
}

int summation(int n)
{
    /**
     * recursion
     * n + (n - 1) + (n - 2) + (n - 3) + ... + 3 + 2 + 1
     */
    int sum = 0;

    if (n == 1)
        sum = 1;
    else if (n > 1) // last availible n = 2, n - 1 = 1
        sum = n + summation(n - 1);

    return sum;
}

void staticGlobalValTest()
{
    /**
     * keyword "static" allocates the memory for the variable and never erases it
     * nonStaticVal is of type 'auto' allocation of memory
     * variable declared with keyword 'static' can be accessed from outside of the function
     * scope of non-static variable is limited inside the function
     */
    static int staticVal    = 10; // keyword 'static'
    int        nonStaticVal = 10;

    std::cout << "\nPrinting from function \"staticGlobalValTest()\":"
              << "\n"
              << "Staic value is: " << staticVal << "\n"
              << "Non-static value is: " << nonStaticVal << "\n";

    staticVal += 10;
    nonStaticVal += 10;

    return;
}
