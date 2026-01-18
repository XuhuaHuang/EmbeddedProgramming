/**
 * @file main.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2026-01-16
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

// y = a*x + b for a 1D array
py::array_t<double> axpb(py::array_t<double, py::array::c_style | py::array::forcecast> x, double a, double b) {
  auto                xin = x.unchecked<1>();
  py::array_t<double> y(xin.shape(0));
  auto                yout = y.mutable_unchecked<1>();

  for (py::ssize_t i = 0; i < xin.shape(0); ++i) {
    yout(i) = a * xin(i) + b;
  }
  return y;
}

PYBIND11_MODULE(linear, m) {
  m.def("axpb", &axpb, "Compute y = a*x + b for a 1D NumPy array");
}
