#include <iostream>

class complex_t {
private:
  double real{0.0};
  double imag{0.0};

public:
  complex_t() = default;

  complex_t(double re, double im) noexcept
    : real(re)
    , imag(im) {}

  [[nodiscard]]
  inline double get_real() const noexcept {
    return real;
  }
  [[nodiscard]]
  inline double get_imag() const noexcept {
    return imag;
  }

  [[nodiscard]]
  inline complex_t operator+(const complex_t& other) const noexcept {
    return complex_t(real + other.real, imag + other.imag);
  }
};

int main() {
  complex_t c1(1.0, 1.0);
  complex_t c2(2.0, 2.0);

  complex_t c3 = c1 + c2;

  std::cout << "Result: (" << c3.get_real() << ", " << c3.get_imag() << ")\n";

  return 0;
}
