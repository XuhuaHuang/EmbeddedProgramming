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

class square_t; // forward declaration

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

  void convert(const square_t& sq) noexcept;

  friend std::ostream& operator<<(std::ostream& os, const rectangle_t& rect);
};

class square_t {
  friend class rectangle_t; // allow rectangle_t to access private data

private:
  int side{0};

public:
  explicit constexpr inline square_t(int s)
    : side(s) {}

  [[nodiscard]]
  int get_side() const noexcept {
    return side;
  }
};

// Optional: keep a free function wrapper if needed
[[nodiscard]]
rectangle_t double_in_size(const rectangle_t& rect) noexcept {
  return rect.double_in_size();
}

void rectangle_t::convert(const square_t& sq) noexcept {
  width  = sq.side;
  height = sq.side;
}

std::ostream& operator<<(std::ostream& os, const rectangle_t& rect) {
  os << rect.width << " x " << rect.height;
  return os;
}

int main() {
  rectangle_t r1;
  rectangle_t r2(2, 3);

  std::cout << "Original rectangle: " << r2 << std::endl;

  r1 = double_in_size(r2);

  std::cout << __LINE__ << ": " << r1 << std::endl;
  std::cout << r1.area() << std::endl;

  rectangle_t rect;
  square_t    sqr(4);

  rect.convert(sqr);

  std::cout << __LINE__ << ": " << rect << std::endl;
  std::cout << __LINE__ << ": " << rect.area() << std::endl;

  return 0;
}
