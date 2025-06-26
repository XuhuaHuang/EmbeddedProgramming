# `Eigen/Dense`

| **BLAS Function** | **P1673 Function** | **Description** |
| --- | --- | --- |
| DSCAL | `scale` | Multiplication of a vector **v** by a scalar **α** |
| DCOPY | `copy` | Copy a vector to another vector |
| DAXPY | `add` | Calculates **αx + y**, vectors **x** & **y**, scalar **α** |
| DDOT | `dot` | Dot (inner) product of two vectors |
| DNRM2 | `vector_norm2` | Euclidean norm of a vector |
| DGEMV | `matrix_vector_product` | Calculates **αA**x + **βy**, matrix **A**, vector **y**, scalars **α** & **β** |
| DSYMV | `symmetric_matrix_vector_product` | Same as `matrix_vector_product` but where **A** is symmetric |
| DGEMM | `matrix_product` | Calculates **αAB + βC**, for matrices **A**, **B**, & **C**, and scalars **α** & **β** |

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
