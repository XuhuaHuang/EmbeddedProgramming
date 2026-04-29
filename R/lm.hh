#ifndef LM_HH
#define LM_HH

#include <cmath>
#include <vector>

namespace statistics {

inline double mean(const std::vector<double>& data) {
  double sum = 0.0;
  for (double value : data) {
    sum += value;
  }
  return sum / data.size();
}

inline double variance(const std::vector<double>& data) {
  double mean_value       = mean(data);
  double sum_squared_diff = 0.0;
  for (double value : data) {
    sum_squared_diff += (value - mean_value) * (value - mean_value);
  }
  return sum_squared_diff / (data.size() - 1); // Sample variance
}

inline double standard_deviation(const std::vector<double>& data) {
  return std::sqrt(variance(data));
}

} // namespace statistics

#endif // !LM_HH
