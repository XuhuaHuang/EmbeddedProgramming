/**
 * @file modern_square_rectangle.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-04-04
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iostream>

class rectangle_t {
private:
  int width{0};
  int height{0};

public:
  constexpr inline rectangle_t() = default;

  constexpr inline rectangle_t(int w, int h)
    : width(w)
    , height(h) {}

  void set_width(int w) noexcept { width = w; }
  void set_height(int h) noexcept { height = h; }

  [[nodiscard]]
  int get_width() const noexcept {
    return width;
  }

  [[nodiscard]]
  int get_height() const noexcept {
    return height;
  }

  [[nodiscard]]
  int area() const noexcept {
    return width * height;
  }

  // Preferred: member function instead of friend
  [[nodiscard]]
  rectangle_t double_in_size() const noexcept {
    return rectangle_t(width * 2, height * 2);
  }
};

// Optional: keep a free function wrapper if needed
[[nodiscard]]
rectangle_t double_in_size(const rectangle_t& rect) noexcept {
  return rect.double_in_size();
}

int main() {
  rectangle_t r1;
  rectangle_t r2(2, 3);

  r1 = double_in_size(r2);

  std::cout << r1.area() << std::endl;

  return 0;
}
