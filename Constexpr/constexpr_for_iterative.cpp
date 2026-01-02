/**
 * @file constexpr_for_iterative.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-02
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <array>
#include <iostream>
#include <utility>

// ------------------------------------------------------------
// 1. constexpr factorial — evaluated completely at compile time
// ------------------------------------------------------------
constexpr unsigned long long factorial(unsigned int n) {
  unsigned long long a = 1;
  for (unsigned int i = n; i > 0; --i) {
    a *= i;
  }
  return a;
}

// ------------------------------------------------------------
// 2. A compile-time list of inputs
// ------------------------------------------------------------
constexpr std::array<unsigned, 5> inputs = {0, 1, 3, 5, 7};

// ------------------------------------------------------------
// 3. for_each_constexpr — functional iteration at compile time
//    Equivalent to Racket’s (for-each …)
// ------------------------------------------------------------
template <typename Fn, typename... Ts>
constexpr void for_each_constexpr(Fn f, Ts... xs) {
  (f(xs), ...); // fold expression over comma operator
}

int main() {
  // Generate factorials at compile time
  // with immediately invoked lambda expression
  constexpr auto outputs =
      [](void) -> std::array<unsigned long long, inputs.size()> {
    std::array<unsigned long long, inputs.size()> out{};
    for (std::size_t i = 0; i < inputs.size(); ++i) {
      out[i] = factorial(inputs[i]); // constexpr evaluated
    }
    return out;
  }
  ();

  // Runtime printing (the values were computed at compile time)
  for_each_constexpr([](auto val) -> void { std::cout << val << "\n"; },
                     outputs[0], outputs[1], outputs[2], outputs[3],
                     outputs[4]);

  return 0;
}
