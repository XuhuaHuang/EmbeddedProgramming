// clang-format off
/*****************************************************************//**
 * \file   conversion.cpp
 * \brief  Overloaded conversion operator float()
 * 
 * Document highlight: n/a
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/
// clang-format on

#include <iostream>

class Fraction {
private:
  int num;
  int den;

public:
  inline Fraction() = default;

  constexpr Fraction(int n, int d)
    : num(n)
    , den(d) {}

  constexpr Fraction(const Fraction& rhs) = default;
  virtual ~Fraction()                     = default;

  constexpr int getnum() const { return this->num; }
  constexpr int getden() const { return this->den; }

  // conversion operator: return float value of fraction
  constexpr operator float() const { return float(getnum()) / float(getden()); }
};

int main(void) {
  Fraction f(2, 5); // numerator = 2, denominator = 5

  float val = f; // float(val) is overloaded
  std::cout << val;

  return 0;
}
