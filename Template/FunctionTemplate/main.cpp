// clang-format off
/*****************************************************************//**
 * \file   main.cpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/
// clang-format on

#include <iostream>

#include "max.hpp"

int main(void) {
  // implicit template instanciation
  // T is deducted to int
  // same for std::vector
  // std::vector v { 1, 2 };
  // std::cout << max<int>(42, 77) << "\n";
  std::cout << max(42, 77) << "\n";
  std::cout << max<double>(3.14, 3.1415) << "\n";

  return 0;
}
