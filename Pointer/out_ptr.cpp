/**
 * @file out_ptr.cpp
 * @author Xuhua Huang
 * @brief Demonstration of std::out_ptr with C-style API
 * @version 0.1
 * @date 2025-12-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cstdlib> // Added for malloc and free
#include <iostream>
#include <memory>

extern "C" {
// Simulating a C-style API that allocates memory and returns it via a double
// pointer
void get_data(int** ptr) {
  int* result = (int*)malloc(sizeof(int));
  *result     = 42;

  *ptr        = result;
}
}

int main() {
  // Define a unique_ptr with a custom deleter that calls 'free'
  // This is necessary because the memory is allocated with 'malloc' in the C
  // function
  std::unique_ptr<int, decltype([](int* ptr) { free(ptr); })> something;

  // Use std::out_ptr (C++23) to adapt the unique_ptr to the C-style int** API
  get_data(std::out_ptr(something));

  std::cout << *something << '\n';

  return 0;
}
