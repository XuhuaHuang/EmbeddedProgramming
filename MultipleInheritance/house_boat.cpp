#include <iostream>

class house_t {
protected:
  int residents{0};

public:
  house_t() = default;

  explicit house_t(int num)
    : residents(num) {}

  void set_residents(int num) noexcept { residents = num; }

  [[nodiscard]]
  int get_residents() const noexcept {
    return residents;
  }
};

class boat_t {
protected:
  float max_speed{0.0f};

public:
  boat_t() = default;

  explicit boat_t(float speed)
    : max_speed(speed) {}

  void set_max_speed(float speed) noexcept { max_speed = speed; }

  [[nodiscard]]
  float get_max_speed() const noexcept {
    return max_speed;
  }
};

class house_boat_t : public house_t, public boat_t {
public:
  house_boat_t() = default;

  house_boat_t(int residents, float speed)
    : house_t(residents)
    , boat_t(speed) {}
};

int main() {
  house_boat_t hb;
  hb.set_residents(4);
  hb.set_max_speed(10.0f);

  std::cout << "This dwelling has " << hb.get_residents() << " residents and a max speed of " << hb.get_max_speed()
            << std::endl;

  return 0;
}
