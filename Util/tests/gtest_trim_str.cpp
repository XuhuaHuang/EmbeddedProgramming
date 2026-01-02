// clang-format off
/*****************************************************************//**
 * \file   gtest_trim_str.cpp
 * \brief Unit tests for trimstr.hpp
 * $ g++ gtest_trim_str.cpp -o runTests -std=c++23 -lgtest -lgtest_main -pthread
 *
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/
// clang-format on

#include <gtest/gtest.h>

#include <iostream>

#include "trimstr.hpp"

#define STDTEST std::cout << "\033[32m[---TEST---]\033[m "

class TrimStrTest : public ::testing::Test {
public:
  void SetUp(void) override {}
  void TearDown(void) override {}
  TrimStrTest() {}
  virtual ~TrimStrTest() {}
};

TEST_F(TrimStrTest, TrimFront_Test) {
  EXPECT_EQ(std::string((std::ranges::to<std::string>(
                             std::string_view{"    test"} | trim_front))
                            .c_str()),
            "test");
}

TEST_F(TrimStrTest, TrimBack_Test) {
  EXPECT_EQ(std::string((std::ranges::to<std::string>(
                             std::string_view{"test    "} | trim_back))
                            .c_str()),
            "test");
}

TEST_F(TrimStrTest, TrimFrontAndBack_Test) {
  EXPECT_EQ(std::string((std::ranges::to<std::string>(
                             std::string_view{"    test    "} | trim_spaces))
                            .c_str()),
            "test");
}

TEST_F(TrimStrTest, TrimStrFn_Test) {
  EXPECT_EQ(trim_str("    test    "), "test");
}

// Test 1: Standard trimming (front and back)
TEST(TrimStrTest, StandardTrimming) {
  std::string input = "   Hello World   ";
  std::string expected = "Hello World";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 2: Trim front only
TEST(TrimStrTest, TrimFrontOnly) {
  std::string input = "   C++23";
  std::string expected = "C++23";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 3: Trim back only
TEST(TrimStrTest, TrimBackOnly) {
  std::string input = "Ranges   ";
  std::string expected = "Ranges";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 4: No trimming needed
TEST(TrimStrTest, NoTrimmingNeeded) {
  std::string input = "Clean";
  std::string expected = "Clean";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 5: String containing only spaces
TEST(TrimStrTest, AllSpaces) {
  std::string input = "      ";
  std::string expected = "";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 6: Empty string
TEST(TrimStrTest, EmptyString) {
  std::string input = "";
  std::string expected = "";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 7: Embedded spaces should be preserved
TEST(TrimStrTest, PreserveEmbeddedSpaces) {
  std::string input = "  A B  C  ";
  std::string expected = "A B  C";
  EXPECT_EQ(util::trim_str(input), expected);
}

// Test 8: Newlines and Tabs
TEST(TrimStrTest, NewlinesAndTabs) {
  std::string input = "\t  Multi Line \n ";
  std::string expected = "Multi Line";
  EXPECT_EQ(trim_str(input), expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
