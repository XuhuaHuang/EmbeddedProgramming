/**
 * @file composition_over_inheritance.cpp
 * @brief Demonstration of composition over inheritance using runtime strategies
 *
 * Key ideas:
 * - Prefer HAS-A over IS-A
 * - Compose behavior dynamically
 * - Keep components orthogonal and swappable
 */

#include <iostream>
#include <memory>
#include <vector>

namespace experimental {
template <typename MovementPolicy, typename PowerPolicy>
class vehicle_t;
}

class movement_t {
public:
  virtual ~movement_t()                = default;
  virtual void        move() const     = 0;
  virtual const char* describe() const = 0;
};

class power_source_t {
public:
  virtual ~power_source_t()                = default;
  virtual void        supply_power() const = 0;
  virtual const char* describe() const     = 0;
};

class wheel_movement_t : public movement_t {
public:
  void move() const override { std::cout << "Moving on wheels\n"; }

  const char* describe() const override { return "Wheel-based movement"; }
};

class flying_movement_t : public movement_t {
public:
  void move() const override { std::cout << "Flying in the air\n"; }

  const char* describe() const override { return "Aerial movement"; }
};

class gas_engine_t : public power_source_t {
public:
  void supply_power() const override { std::cout << "Supplying power from gas engine\n"; }

  const char* describe() const override { return "Gas engine"; }
};

class electric_battery_t : public power_source_t {
public:
  void supply_power() const override { std::cout << "Supplying power from battery\n"; }

  const char* describe() const override { return "Electric battery"; }
};

class solar_panel_t : public power_source_t {
public:
  void supply_power() const override { std::cout << "Supplying power from solar energy\n"; }

  const char* describe() const override { return "Solar panel"; }
};

// Composite power source (aggregation of multiple sources)
class hybrid_power_t : public power_source_t {
public:
  void add_source(std::unique_ptr<power_source_t> source) { sources.push_back(std::move(source)); }

  void supply_power() const override {
    std::cout << "Hybrid power system engaged:\n";
    for (const auto& src : sources) {
      src->supply_power();
    }
  }

  const char* describe() const override { return "Hybrid power system"; }

private:
  std::vector<std::unique_ptr<power_source_t>> sources;
};

class vehicle_t {
public:
  vehicle_t(std::unique_ptr<movement_t> movement, std::unique_ptr<power_source_t> power_source)
    : movement(std::move(movement))
    , power_source(std::move(power_source)) {}

  void operate() const {
    std::cout << "[Vehicle Start]\n";
    std::cout << "Movement: " << movement->describe() << "\n";
    std::cout << "Power: " << power_source->describe() << "\n";

    power_source->supply_power();
    movement->move();

    std::cout << "[Vehicle End]\n\n";
  }

private:
  std::unique_ptr<movement_t>     movement;
  std::unique_ptr<power_source_t> power_source;
};

int main() {
  vehicle_t car(std::make_unique<wheel_movement_t>(), std::make_unique<gas_engine_t>());

  vehicle_t ev(std::make_unique<wheel_movement_t>(), std::make_unique<electric_battery_t>());

  vehicle_t drone(std::make_unique<flying_movement_t>(), std::make_unique<electric_battery_t>());

  // Hybrid example: battery + solar
  auto hybrid_power = std::make_unique<hybrid_power_t>();
  hybrid_power->add_source(std::make_unique<electric_battery_t>());
  hybrid_power->add_source(std::make_unique<solar_panel_t>());

  vehicle_t futuristic_vehicle(std::make_unique<flying_movement_t>(), std::move(hybrid_power));

  car.operate();
  ev.operate();
  drone.operate();
  futuristic_vehicle.operate();
}
