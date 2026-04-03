#include <iostream>
#include <string>
#include <string_view>

namespace constants {
constexpr double pi = 3.14159265358979323846;
}

class circle_t {
private:
  int radius{0};

public:
  circle_t() = default;

  explicit circle_t(int r)
    : radius(r) {}

  void set_radius(int r) { radius = r; }

  [[nodiscard]]
  int get_radius() const noexcept {
    return radius;
  }

  [[nodiscard]]
  double get_area() const noexcept {
    return static_cast<double>(radius) * radius * constants::pi;
  }
};

class colour_t {
private:
  std::string line_colour{"none"};
  std::string fill_colour{"none"};

public:
  colour_t() = default;

  explicit colour_t(std::string_view colour)
    : line_colour(colour)
    , fill_colour(colour) {}

  void set_line_colour(std::string_view colour) { line_colour = colour; }

  void set_fill_colour(std::string_view colour) { fill_colour = colour; }

  [[nodiscard]]
  const std::string& get_line_colour() const noexcept {
    return line_colour;
  }

  [[nodiscard]]
  const std::string& get_fill_colour() const noexcept {
    return fill_colour;
  }
};

class coloured_circle_t : public circle_t, public colour_t {
public:
  coloured_circle_t() = default;

  coloured_circle_t(int radius, std::string_view colour)
    : circle_t(radius)
    , colour_t(colour) {}
};

int main() {
  coloured_circle_t ccobj1;
  std::cout << "\nDefault constructor:\n"
            << "Area: " << ccobj1.get_area() << "\n"
            << "Line colour: " << ccobj1.get_line_colour() << "\n"
            << "Fill colour: " << ccobj1.get_fill_colour() << "\n";

  coloured_circle_t ccobj2(2, "red");
  std::cout << "\nOverloaded constructor:\n"
            << "Area: " << ccobj2.get_area() << "\n"
            << "Line colour: " << ccobj2.get_line_colour() << "\n"
            << "Fill colour: " << ccobj2.get_fill_colour() << "\n";

  return 0;
}
