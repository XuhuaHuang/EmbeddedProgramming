#include <algorithm>
#include <execution>
#include <random>
#include <vector>

int main() {
  std::vector<double> samples(1'000'000);

  std::mt19937                     gen(std::random_device{}());
  std::normal_distribution<double> dist(0.0, 1.0);

  std::generate(std::execution::par_unseq, samples.begin(), samples.end(), [&]() { return dist(gen); });

  return 0;
}
