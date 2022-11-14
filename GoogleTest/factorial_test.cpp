/*****************************************************************//**
 * \file   factorial_test.cpp
 * \brief  Testing basic implementation of Factorial function.
 *
 * \author Xuhua Huang
 * \date   November 14, 2022
 *********************************************************************/

#include <iostream>
#include <gtest/gtest.h>

namespace GoogleTestUtil {
    namespace Math {

        int factorial(int n) {
            if ((n == 0) || (n == 1))
                return 1;
            else
                return n * factorial(n - 1);
        }

    } // Math
} // GoogleTestUtil

/**
 * Create a simple test
 *
 * Use TEST() macro to define and name test function
 * ordinary C++ functions that do not return a value
 * result is determined by assertions
 *
 * TEST(TestSuiteName, TestName) {
 *	// ... test body ...
 * }
 */

// Tests factorial of 0
TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(GoogleTestUtil::Math::factorial(0), 1);
}

// Tests factorial of positive numbers
TEST(FactorialTest, HandlesPositiveInput) {
    std::vector<int> posInput = { 1, 2, 3, 8 };
    std::vector<int> expResult = { 1, 2, 6, 40320 };
    for (int i = 0; i < posInput.size(); ++i) {
        EXPECT_EQ(GoogleTestUtil::Math::factorial(posInput[i]), expResult[i]);
    }
}
