# Raw linear regression

This C++23 example fits `y = intercept + slope * x` using ordinary least squares. Numerical helpers use at least double precision, compensated summation, and power-of-two scaling to reduce roundoff and unnecessary intermediate overflow. Inputs require two or more paired, finite samples; mismatched lengths raise `std::domain_error`.

`covariance(x, y, x_center, y_center)` averages deviation products around the explicitly supplied centers. Pass the sample means for population covariance (division by `n`). `calculate_slope()` recenters normalized residuals before calculating `Sxy / Sxx`, so rounded centering hints do not directly bias the fit. Ordinary least squares derives and stores its slope and intercept from these centered statistics. For the first example, `Sxx = 10`, `Sxy = 6`, slope `0.6`, and intercept `2.2`.

A constant predictor is rejected; a separate error reports predictor variation that cannot be represented. Nonfinite computed statistics or coefficients also raise `std::domain_error`. Scaling and compensation improve robustness, but finite results can still round or underflow in the working type.

## Build in the Dev Container

Use CMake 3.20 or later, Ninja, and a C++23 compiler. GCC 14 and Clang 20 are the CI compiler versions. Legacy alias-template deduction requires Clang 19 or later; the canonical names are `linreg_t` and `lambda_linreg_t`.

From the repository root in the container terminal:

```sh
cd IntroductionToRobotics/MLcxx/RawLinearRegression
cmake --preset gcc_release
cmake --build --preset gcc_release --parallel
ctest --preset gcc_release
./out/build/gcc_release/raw_linear_regression
```

The presets configure this folder as a standalone project. They use Ninja and leave `CC`/`CXX` unchanged, so the GCC-trunk container's compiler selection is retained. Generated files go to `out/build/<preset>`; the existing `build/` directory and repository-level presets are separate.

Compiler labels identify independent caches. To choose a particular installed compiler, set `CXX` on the first configure:

```sh
CC=gcc CXX=g++ cmake --preset gcc_release
CC=clang CXX=clang++ cmake --preset clang_release
cmake --build --preset clang_release --parallel
ctest --preset clang_release
```

CMake caches the chosen compiler. Use the corresponding separate preset directory when switching compiler families.

For CMake Tools, select this folder as the source directory and choose its configure/build/test presets. The default Dev Container now uses the Linux-compatible Ninja generator.

## Sanitizers and tests

```sh
cmake --preset gcc_sanitizer
cmake --build --preset gcc_sanitizer --parallel
ctest --preset gcc_sanitizer
```

Use `clang_sanitizer` with `CC=clang CXX=clang++` at configure time for Clang. Sanitizer presets use `RelWithDebInfo`, AddressSanitizer, UndefinedBehaviorSanitizer, frame pointers, and immediate failure on detected errors. They require GCC or Clang with its sanitizer runtimes.

The dependency-free CTest executable always builds when `BUILD_TESTING=ON`. Installed GoogleTest, or a parent-provided `GTest::gtest_main` target, enables the additional GoogleTest suite. Configuration does not download GoogleTest. Runtime example checks remain enabled in Release.

## Callable interface

Fitted models support `fit(x)`, `fit[x]`, and `fit.at(x)`. Structured binding yields `[intercept, slope]`; `get<2>(fit)` returns the stored callable. Transformations such as `fit.abs()`, `fit.square()`, `fit.sqrt()`, and `fit.pow(exponent)` own their captured callable by value.
