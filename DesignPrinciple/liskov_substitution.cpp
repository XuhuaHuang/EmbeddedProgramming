// Subtypes must be substitutable for their base types

#include <iostream>
#include <memory>

// class rectangle_t {
// public:
//   virtual ~rectangle_t() = default;

//   virtual void set_width(double w) { width = w; }
//   virtual void set_height(double h) { height = h; }

//   double area() const { return width * height; }

// protected:
//   double width{0};
//   double height{0};
// };

// class square_t : public rectangle_t {
// public:
//   void set_width(double w) override { width = height = w; }

//   void set_height(double h) override { width = height = h; }
// };

class shape_t {
public:
  virtual ~shape_t()          = default;
  virtual double area() const = 0;
};

class rectangle_t : public shape_t {
public:
  rectangle_t(double w, double h)
    : width(w)
    , height(h) {}

  double area() const override { return width * height; }

private:
  double width;
  double height;
};

class square_t : public shape_t {
public:
  explicit square_t(double side)
    : side(side) {}

  double area() const override { return side * side; }

private:
  double side;
};

void print_area(const shape_t& shape) {
  std::cout << "Area: " << shape.area() << '\n';
}

int main() {
  rectangle_t rect(5, 10);
  square_t    square(5);

  print_area(rect);   // OK
  print_area(square); // OK
}
