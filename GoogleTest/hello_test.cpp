/*****************************************************************//**
 * \file   hello_test.cpp
 * \brief  Testing GoogleTest project/directory setup.
 * 
 * \author Xuhua Huang
 * \date   November 14, 2022
 *********************************************************************/

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    EXPECT_STREQ("Hello", "Hello");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}
