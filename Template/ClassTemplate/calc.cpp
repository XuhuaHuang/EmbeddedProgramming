#include <iostream>

template <typename T>
class calc_t {
public:
  [[nodiscard]]
  constexpr T multiply(T x, T y) const noexcept {
    return x * y;
  }

  [[nodiscard]]
  constexpr T add(T x, T y) const noexcept {
    return x + y;
  }
};

int main() {
  calc_t<int> c;

  std::cout << c.add(10, 20) << std::endl;

  return 0;
}
