# `Eigen/Dense`

```cpp
#include <algorithm>
#include <random>
// ... other Eigen includes
VectorXd u{12};
std::mt19937 rng{std::random_device{}()};
std::uniform_real_distribution<> dist{-1, 1};
std::generate(u.data(), u.data() + u.size(), [&]() { return dist(rng); });
std::student_t_distribution<> tdist{5};
std::generate(u.data(), u.data() + u.size(), [&]() { return tdist(rng); });
auto u2 = u.array().abs();
std::cout << u2.transpose() << std::endl;
auto max_u = std::max_element(u2.begin(), u2.end() + u2.size());
std::cout << "Max: " << *max_u << std::endl;
u2 = u2.unaryExpr([](double x) { return x * x; });
// std::experimental::linalg::matrix_vector_product
// std::experimental::linalg::dot
```