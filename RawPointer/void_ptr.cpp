/**
 * @file void_ptr.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>

/**
 * @brief C++ allows pointers without a specific data type associated with them
 * These pointers are referred to as void pointers
 * Void pointers are frequently used in C to create generic methods as
 * they are not tied to particular data types
 *
 * @note Void pointers cannot be dereferenced
 * They need to be explicitly cast to another pointer type before dereferencing
 * Pointer arithmetic are not allowed on void pointers
 * Some compilers permit pointer arithmetic with void pointers, however, assuming
 * the size of void is 1 and so you are essentially working with a block of byte data
 *
 * @warning must be careful in casting, because the compiler will assume the programmers know what they are doing
 */
int main() {
  std::nullptr_t np = nullptr;
  void*          vp = nullptr;
  int*           ip = nullptr;

  // print out the size of pointers
  std::cout << "sizeof(void*) -> " << sizeof(vp) << std::endl;
  std::cout << "sizeof(int*) -> " << sizeof(ip) << std::endl;

  int x = 0xFEEDBEEF;
  ip    = &x;
  vp    = ip;

  // print out the address of both p and ip
  std::cout << "vp -> " << vp << std::endl;
  std::cout << "ip -> " << ip << std::endl;

  // dereference the int* and assign it a new value
  *ip = 0x00C0FFEE;
  // *p = 0xDEADBEEF; // void is not assignable. no type information
  *(static_cast<int*>(vp)) = 0xDEADBEEF; // this assignment will overwrite the 0xCOFFEE assignment
  // because both *p and *ip point to the same address
  // therefore, they both read the latest assignment

  // print out hexadecimal value
  std::cout << "vp -> " << vp << ", with value of " << std::hex << *(static_cast<int*>(vp)) << std::endl;
  std::cout << "ip -> " << ip << " with value of " << std::hex << *ip << std::endl;

  // c and cpp differ with the following lines
  // int* ip2 = malloc(sizeof(int)); // error in cpp, requires explicit conversion
  // prefer the explicit conversion for portability and readability
  int* ip2 = static_cast<int*>(std::malloc(sizeof(int)));
  std::free(ip2);

  return 0;
}
