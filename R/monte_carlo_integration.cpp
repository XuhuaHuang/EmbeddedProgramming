#include <iostream>
#include <random>

int main() {
  std::mt19937 rng(std::random_device{}());

  std::uniform_real_distribution<double> dist(0.0, 1.0);

  const int n   = 1'000'000;
  double    sum = 0.0;

  for (int i = 0; i < n; ++i) {
    double u = dist(rng);
    sum += u * u;
  }

  double estimate = sum / n;

  std::cout << "Estimate: " << estimate << "\n";
}
