/*****************************************************************//**
 * \file   gtest_trim_str.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <iostream>
#include <gtest/gtest.h>
#include "trimstr.hpp"

#define STDTEST std::cout << "\033[32m[---TEST---]\033[m "

class TrimStrTest : public ::testing::Test
{
public:
    void SetUp(void) override {}
    void TearDown(void) override {}
    TrimStrTest() {}
    virtual ~TrimStrTest() {}
};

TEST_F(TrimStrTest, TrimFront_Test)
{
    EXPECT_EQ(std::string((std::ranges::to<std::string>(std::string_view{ "    test" } | trim_front)).c_str()), "test");
}

TEST_F(TrimStrTest, TrimBack_Test)
{
    EXPECT_EQ(std::string((std::ranges::to<std::string>(std::string_view{ "test    " } | trim_back)).c_str()), "test");
}

TEST_F(TrimStrTest, TrimFrontAndBack_Test)
{
    EXPECT_EQ(std::string((std::ranges::to<std::string>(std::string_view{ "    test    "} | trim_spaces)).c_str()), "test");
}

TEST_F(TrimStrTest, TrimStrFn_Test)
{
    EXPECT_EQ(trim_str("    test    "), "test");
}
