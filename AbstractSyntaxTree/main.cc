#include <cstdio>
#include <cstdlib>

#include "test.h"

// Usage: ast_demo [integer]
// Prints f(integer); the default input is 84.
int main(int argc, char* argv[]) {
  int input = 84;
  if (argc > 1) {
    input = static_cast<int>(std::strtol(argv[1], nullptr, 10));
  }

  std::printf("f(%d) = %d\n", input, f(input));
  return EXIT_SUCCESS;
}
