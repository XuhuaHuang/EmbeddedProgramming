// clang-format off
/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 15, 2022
 *********************************************************************/
// clang-format on

#include <customer.hpp>
#include <iostream>
#include <string>

int main(void) {
  Customer c("Tim", "Starr", 42);
  auto [f, l, v] = c;
  std::cout << "f/l/v: " << f << " " << l << " " << v << "\n";

  auto&& [f2, l2, v2] = c;

  std::string s = std::move(f2);
  f2            = "Ringo";
  v2 += 10;
  std::cout << "f2/l2/v2: " << f << " " << l << " " << v << "\n";

  std::cin.get();
  return 0;
}
