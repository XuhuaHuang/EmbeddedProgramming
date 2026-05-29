/**
 * @file vector_addition.cu
 * @author Xuhua Huang
 * @brief This file contains functions for vector addition using CUDA.
 * nvcc vector_addition.cu -lcublas -o vector_addition -Wno-deprecated-gpu-targets
 * @version 0.1
 * @date 2025-03-31
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cublas_v2.h>
#include <cuda_runtime.h>

#include <iostream>

#define N 3

int main() {
  cublasHandle_t handle;
  cublasCreate(&handle);

  float h_A[N] = {1.0, 2.0, 3.0};
  float h_B[N] = {4.0, 5.0, 6.0};
  float h_C[N];

  float *d_A, *d_B, *d_C;
  cudaMalloc((void**)&d_A, N * sizeof(float));
  cudaMalloc((void**)&d_B, N * sizeof(float));
  cudaMalloc((void**)&d_C, N * sizeof(float));

  cudaMemcpy(d_A, h_A, N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, h_B, N * sizeof(float), cudaMemcpyHostToDevice);

  const float alpha = 1.0;
  cublasSaxpy(handle, N, &alpha, d_A, 1, d_B, 1);

  cudaMemcpy(h_C, d_B, N * sizeof(float), cudaMemcpyDeviceToHost);

  std::cout << "Result: ";
  for (int i = 0; i < N; ++i)
    std::cout << h_C[i] << " ";

  cublasDestroy(handle);
  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C);

  return 0;
}
