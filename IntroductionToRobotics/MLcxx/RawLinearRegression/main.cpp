/**
 * @file main.cpp
 * @author Xuhua Huang
 * @brief Examples and runtime checks for ordinary least-squares regression.
 * @version 0.1
 * @date 2023-11-11
 * @copyright Copyright (c) 2023
 */

#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "raw_linear_regression.hpp"

namespace {

constexpr double tolerance = 1.0e-12;

void require_close(const double actual, const double expected, const char* message) {
  if (!(std::abs(actual - expected) <= tolerance)) {
    throw std::runtime_error(message);
  }
}

} // namespace

int main() {
  try {
    using namespace robotics::mlcxx;

    constexpr std::array<double, 5> x{1.0, 2.0, 3.0, 4.0, 5.0};
    constexpr std::array<double, 5> y{2.0, 4.0, 5.0, 4.0, 5.0};

    const auto x_mean        = mean(x);
    const auto y_mean        = mean(y);
    const auto raw_slope     = calculate_slope(x, y, x_mean, y_mean);
    const auto raw_intercept = calculate_intercept(raw_slope, x_mean, y_mean);

    require_close(raw_slope, 0.6, "Unexpected slope for the first example.");
    require_close(raw_intercept, 2.2, "Unexpected intercept for the first example.");
    std::cout << std::setprecision(12) << "Slope: " << raw_slope << '\n' << "Intercept: " << raw_intercept << '\n';

    constexpr linreg_t lr{x, y};
    require_close(lr.x[0], 1.0, "Unexpected first x sample.");
    require_close(lr.x[1], 2.0, "Unexpected second x sample.");
    {
      using namespace robotics::mlcxx::indexing;
      require_close(lr[0_x], 1.0, "Unexpected indexed x sample.");
      require_close(lr[0_y], 2.0, "Unexpected first indexed y sample.");
      require_close(lr[1_y], 4.0, "Unexpected second indexed y sample.");
      require_close(lr[2_y], 5.0, "Unexpected third indexed y sample.");
    }

    const lambda_linreg_t fit = simple_ordinary_least_squares(x, y);
    std::cout << fit << '\n';
    require_close(fit(0.0), 2.2, "Unexpected fitted value at x = 0.");
    require_close(fit(1.0), 2.8, "Unexpected fitted value at x = 1.");

    const auto [intercept, slope] = fit;
    require_close(intercept, 2.2, "Unexpected bound intercept.");
    require_close(slope, 0.6, "Unexpected bound slope.");
    const auto fx = get<2>(fit);
    require_close(fx(2.0), 3.4, "Unexpected extracted callable value.");

    constexpr std::array<double, 4> x2{1.0, 3.0, 7.0, 12.0};
    constexpr std::array<double, 4> y2{8.0, 13.0, 26.0, 35.0};
    const lambda_linreg_t           fit2 = simple_ordinary_least_squares(x2, y2);
    const auto [intercept2, slope2]      = fit2;
    require_close(intercept2, 1719.0 / 283.0, "Unexpected second-example intercept.");
    require_close(slope2, 710.0 / 283.0, "Unexpected second-example slope.");
    require_close(fit2(2.0), 3139.0 / 283.0, "Unexpected second-example prediction.");

    std::cout << fit2 << '\n'
              << std::setprecision(12) << "f(x) = " << intercept2 << " + " << slope2 << "*x\n"
              << "f(2) = " << fit2(2.0) << '\n';
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
