/**
 * @file basic.cpp
 * @author Xuhua Huang
 * @brief Basic exception handling example
 * The C++ standard provides a base class specifically designed to declare objects to be thrown as exceptions
 * and to be caught by handlers. This class is called std::exception and is defined in the <exception> header file.
 * The std::exception class has a virtual member function called what() that returns a C-style string describing
 * the exception. This function can be overridden in derived classes to provide more specific information about the
 * exception.
 *
 * `std::bad_alloc`, `std::runtime_error` and `std::invalid_argument`
 *
 * @version 0.1
 * @date 2026-04-04
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <iostream>
#include <stdexcept> // for std::runtime_error and std::invalid_argument
#include <string>

class invalid_sensor_data_error_t : public std::runtime_error {
public:
  explicit invalid_sensor_data_error_t(const std::string& message)
    : std::runtime_error(message) {}
};

class sensor_processor_t {
public:
  double process_reading(double value) const {
    if (value < 0.0) {
      throw invalid_sensor_data_error_t("Negative sensor value detected");
    } else if (value > 1000.0) {
      throw invalid_sensor_data_error_t("Sensor value exceeds safe threshold");
    }
    // Simulated processing
    return value * 0.5;
  }
};

int main() {
  try {
    throw 500;      //  generates the exception
  } catch (int e) { // matches the catch block with the type of data (int) thrown
    std::cout << "An exception occurred. We saw exception: " << e << std::endl;
  } catch (char e) {
    std::cout << "char exception: " << e << std::endl;
  } catch (...) {
    // match any type of exception and is used to handle anything not caught by any of the other catch blocks
    std::cout << "default exception" << std::endl;
  }
  // After an exception is handled, execution resumes after the try-catch block,
  // and the program continues as normal.
  std::cout << "Program continues after handling the exception." << std::endl;

  try {
    throw std::runtime_error("Something bad happened");
  } catch (const std::exception& e) {
    std::cout << "An exception occurred: " << e.what() << std::endl;
  }

  sensor_processor_t processor;

  constexpr double readings[] = {25.0, -5.0, 2000.0};
  for (double value : readings) {
    try {
      double result = processor.process_reading(value);
      std::cout << "Processed value: " << result << std::endl;
    } catch (const invalid_sensor_data_error_t& e) {
      std::cerr << "Custom exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
      std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }
  }

  return 0;
}
