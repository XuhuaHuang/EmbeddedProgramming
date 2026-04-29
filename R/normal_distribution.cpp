#include <iostream>
#include <random>

int main() {
  std::random_device rd;        // seed source
  std::mt19937       gen(rd()); // Mersenne Twister engine

  std::normal_distribution<double> dist(0.0, 1.0); // mean=0, stddev=1

  for (int i = 0; i < 10; ++i) {
    double x = dist(gen);
    std::cout << x << '\n';
  }

  return 0;
}
