/**
 * @file overloaded_constructor.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-04-03
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iostream>

class Parent {
public:
  Parent() { std::cout << __LINE__ << " In Parent default constructor" << std::endl; }

  Parent([[maybe_unused]]
         int x) {
    std::cout << __LINE__ << " In Parent overloaded constructor" << std::endl;
  }
};

class Child : public Parent {
public:
  Child()
    : Parent() {
    std::cout << __LINE__ << " In Child default constructor" << std::endl;
  }

  Child(int x)
    : Parent(x) {
    std::cout << __LINE__ << " In Child overloaded constructor" << std::endl;
  }
};
int main() {
  Child c1;
  Child c2(1);
  return 0;
}
