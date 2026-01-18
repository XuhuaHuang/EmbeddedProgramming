/**
 * @file use_std_make_any.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <any>
#include <complex>
#include <functional>
#include <iostream>
#include <string>

int main() {
  auto a0 = std::make_any<std::string>("Hello, std::any!\n");
  auto a1 = std::make_any<std::complex<double>>(0.1, 2.3);

  std::cout << std::any_cast<std::string&>(a0);
  std::cout << std::any_cast<std::complex<double>&>(a1) << '\n';

  using lambda = std::function<void(void)>;

  // Put a lambda into std::any. Attempt #1 (failed).
  std::any a2 = [] { std::cout << "Lambda #1.\n"; };
  std::cout << "a2.type() = \"" << a2.type().name() << "\"\n";

  // any_cast casts to <void(void)> but actual type is not
  // a std::function..., but ~ main::{lambda()#1}, and it is
  // unique for each lambda. So, this throws...
  try {
    std::any_cast<lambda>(a2)();
  } catch (const std::bad_any_cast& ex) {
    std::cout << ex.what() << '\n';
  }

  // Put a lambda into std::any. Attempt #2 (successful).
  auto a3 = std::make_any<lambda>([] { std::cout << "Lambda #2.\n"; });
  std::cout << "a3.type() = \"" << a3.type().name() << "\"\n";
  std::any_cast<lambda>(a3)();

  return 0;
}
