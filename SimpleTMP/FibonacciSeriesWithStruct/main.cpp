// clang-format off
/*****************************************************************//**
 * \file   main.cpp
 * \brief  Main function definition to test Fibonacci series struct.
 * 
 * \author Xuhua Huang
 * \date   November 28, 2022
 *********************************************************************/
// clang-format on

#include <stdlib.h>

#include <iostream>

#include "Fibonacci.hpp"

int main(void) {
  static_assert(Fibonacci<5>::value == 5);
  static_assert(Fibonacci<10>::value == 55);

  std::cout << "Fibonacci<5>::value -> " << Fibonacci<5>::value << "\n";
  std::cout << "Fibonacci<10>::value -> " << Fibonacci<10>::value << "\n";

  std::cin.get();
  return 0;
}
