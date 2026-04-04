/**
 * @file constructor_destructor.cpp
 * @author Xuhua Huang
 * @brief Notes on inheritance of constructors and destructors.
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
  ~Parent() { std::cout << __LINE__ << " In Parent destructor" << std::endl; }
};

class Child : public Parent {
public:
  Child() { std::cout << __LINE__ << " In Child default constructor" << std::endl; }
  ~Child() { std::cout << __LINE__ << " In Child destructor" << std::endl; }
};

int main() {
  Parent p;
  Child  c;
  return 0;
} // c is destroyed first, then p is destroyed
