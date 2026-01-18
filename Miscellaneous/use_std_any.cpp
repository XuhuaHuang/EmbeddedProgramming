/**
 * @file use_std_any.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <any>
#include <iostream>

int main() {
  std::cout << std::boolalpha;

  // any type
  std::any a = 1;
  std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
  a = true;
  std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';

  // bad cast
  try {
    a = 1;
    std::cout << std::any_cast<float>(a) << '\n';
  } catch (const std::bad_any_cast& e) {
    std::cout << e.what() << '\n';
  }

  // has value
  a = 2;
  if (a.has_value())
    std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';

  // reset
  a.reset();
  if (!a.has_value())
    std::cout << "no value\n";

  // pointer to contained data
  a      = 3;
  int* i = std::any_cast<int>(&a);
  std::cout << *i << '\n';

  return 0;
}
