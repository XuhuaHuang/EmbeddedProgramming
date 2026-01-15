/**
 * @file static_scope_binding.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

// Global variable
int n; // global scope

// Procedure 'first' modifies the variable 'n' in its lexical scope
void first() {
  n = 1;
}

// Procedure 'second' has its own local 'n'
void second() {
  int n;   // local to 'second'
  first(); // calls 'first', which modifies *global* n (due to static scoping)
  n = 2;   // modifies local n inside 'second'
}

int main() {
  n = 2;

  int input;
  std::cin >> input;

  if (input > 0)
    second(); // calls second(), which has local n and calls first()
  else
    first(); // modifies global n directly

  std::cout << n << std::endl; // always prints the global n
  return 0;
}
