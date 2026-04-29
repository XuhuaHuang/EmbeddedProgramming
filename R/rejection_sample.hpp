#ifndef REJECTION_SAMPLE_HPP
#define REJECTION_SAMPLE_HPP

#include <random>

namespace statistics {

template <typename FuncF, typename FuncG>
double rejection_sample(FuncF f, FuncG g, double M, std::mt19937& rng) {
  std::uniform_real_distribution<double> u_dist(0.0, 1.0);

  while (true) {
    double x = g.sample(rng); // assume g has a sample method
    double u = u_dist(rng);

    if (u <= f(x) / (M * g.pdf(x))) {
      return x;
    }
  }
}

} // namespace statistics

#endif // !REJECTION_SAMPLE_HPP
