/*****************************************************************//**
 * \file   matrix_base_ext.hpp
 * \brief
 *
 * \author Xuhua Huang
 * \date   January 02, 2023
 *********************************************************************/

#include <Eigen/Core>

inline Scalar at(uint i, uint j) const { return this->operator()(i, j); }
inline Scalar& at(uint i, uint j) { return this->operator()(i, j); }
inline Scalar at(uint i) const { return this->operator[](i); }
inline Scalar& at(uint i) { return this->operator[](i); }

inline RealScalar squaredLength() const { return squaredNorm(); }
inline RealScalar length() const { return norm(); }
inline RealScalar invLength(void) const { return fast_inv_sqrt(squaredNorm()); }

template<typename OtherDerived>
inline Scalar squaredDistanceTo(const MatrixBase<OtherDerived>& other) const
{
    return (derived() - other.derived()).squaredNorm();
}

template<typename OtherDerived>
inline RealScalar distanceTo(const MatrixBase<OtherDerived>& other) const
{
    return internal::sqrt(derived().squaredDistanceTo(other));
}

inline void scaleTo(RealScalar l) { RealScalar vl = norm(); if (vl > 1e-9) derived() *= (l / vl); }

inline Transpose<Derived> transposed() { return this->transpose(); }
inline const Transpose<Derived> transposed() const { return this->transpose(); }

inline uint minComponentId(void) const { int i; this->minCoeff(&i); return i; }
inline uint maxComponentId(void) const { int i; this->maxCoeff(&i); return i; }

template<typename OtherDerived>
void makeFloor(const MatrixBase<OtherDerived>& other) { derived() = derived().cwiseMin(other.derived()); }

template<typename OtherDerived>
void makeCeil(const MatrixBase<OtherDerived>& other) { derived() = derived().cwiseMax(other.derived()); }

const CwiseBinaryOp<internal::scalar_sum_op<Scalar>, const Derived, const ConstantReturnType>
operator+(const Scalar& scalar) const
{
    return CwiseBinaryOp<internal::scalar_sum_op<Scalar>, const Derived, const ConstantReturnType>(derived(), Constant(rows(), cols(), scalar));
}

friend const CwiseBinaryOp<internal::scalar_sum_op<Scalar>, const ConstantReturnType, Derived>
operator+(const Scalar& scalar, const MatrixBase<Derived>& mat)
{
    return CwiseBinaryOp<internal::scalar_sum_op<Scalar>, const ConstantReturnType, Derived>(Constant(rows(), cols(), scalar), mat.derived());
}
