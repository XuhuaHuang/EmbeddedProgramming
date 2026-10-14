/**
 * @file gtest_raw_linear_regression.cpp
 * @brief Optional GoogleTest coverage for the basic regression example.
 */
#include <gtest/gtest.h>

#include <vector>

#include "raw_linear_regression.hpp"

namespace robotics::mlcxx::test {

class raw_linear_regression_test_t : public ::testing::Test {
protected:
  const std::vector<double> x{1.0, 2.0, 3.0, 4.0, 5.0};
  const std::vector<double> y{2.0, 4.0, 5.0, 4.0, 5.0};
};

TEST_F(raw_linear_regression_test_t, calculates_mean) {
  EXPECT_NEAR(mean(x), 3.0, 1e-12);
}

TEST_F(raw_linear_regression_test_t, calculates_population_covariance) {
  // Sxy = 6, so population covariance is Sxy / n = 6 / 5.
  EXPECT_NEAR(covariance(x, y, mean(x), mean(y)), 1.2, 1e-12);
}

TEST_F(raw_linear_regression_test_t, calculates_slope) {
  EXPECT_NEAR(calculate_slope(x, y, mean(x), mean(y)), 0.6, 1e-12);
}

TEST_F(raw_linear_regression_test_t, calculates_intercept) {
  const auto slope = calculate_slope(x, y, mean(x), mean(y));
  EXPECT_NEAR(calculate_intercept(slope, mean(x), mean(y)), 2.2, 1e-12);
}

} // namespace robotics::mlcxx::test
