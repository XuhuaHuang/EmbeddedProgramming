/**
 * @file composition_over_inheritance.cpp
 * @author Xuhua Huang
 * @brief Inheritance establishes an IS-A relaHonship
 * Composition/aggregation establish a HAS-A relaHonship – this can often be preferable
 *
 * Aggregation
 * An object comprised of other objects uses those objects
 * Those objects exist outside of the object
 * When the object is destroyed, the objects that comprise it remain
 *
 * @version 0.1
 * @date 2026-04-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iostream>
#include <memory>
// #include <string>

class IMovement {
public:
  virtual ~IMovement()      = default;
  virtual void move() const = 0;
};

class IPowerSource {
public:
  virtual ~IPowerSource()           = default;
  virtual void supply_power() const = 0;
};

class WheelMovement : public IMovement {
public:
  void move() const override { std::cout << "Moving on wheels\n"; }
};

class FlyingMovement : public IMovement {
public:
  void move() const override { std::cout << "Flying in the air\n"; }
};

class GasEngine : public IPowerSource {
public:
  void supply_power() const override { std::cout << "Supplying power from gas engine\n"; }
};

class ElectricBattery : public IPowerSource {
public:
  void supply_power() const override { std::cout << "Supplying power from battery\n"; }
};

class Vehicle {
public:
  Vehicle(std::unique_ptr<IMovement> movement, std::unique_ptr<IPowerSource> power_source)
    : movement(std::move(movement))
    , power_source(std::move(power_source)) {}

  void operate() const {
    power_source->supply_power();
    movement->move();
  }

private:
  std::unique_ptr<IMovement>    movement;
  std::unique_ptr<IPowerSource> power_source;
};

int main() {
  // Traditional car
  Vehicle car(std::make_unique<WheelMovement>(), std::make_unique<GasEngine>());

  // Electric car
  Vehicle ev(std::make_unique<WheelMovement>(), std::make_unique<ElectricBattery>());

  // Futuristic flying electric vehicle
  Vehicle drone(std::make_unique<FlyingMovement>(), std::make_unique<ElectricBattery>());

  car.operate();
  ev.operate();
  drone.operate();
}

class SolarPanel : public IPowerSource {
public:
  void supply_power() const override { std::cout << "Supplying power from solar energy\n"; }
};
