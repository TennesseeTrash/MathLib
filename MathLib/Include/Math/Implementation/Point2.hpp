#ifndef MATHLIB_IMPL_POINT2_HPP
#define MATHLIB_IMPL_POINT2_HPP

#include "Matrix2.hpp"
#include "Matrix3.hpp"

namespace Math
{
    template <typename T>
    struct Point2T
    {
        using ScalarType = T;
        using VectorType = Vector2T<T>;
        using MatrixType = Matrix2T<T>;
        using ProjectiveMatrixType = Matrix3T<T>;
        static constexpr SizeType Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Point2T()                     noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Point2T(T val)                noexcept : x(val ), y(val ) {}
        constexpr          Point2T(T xv, T yv)           noexcept : x(xv  ), y(yv  ) {}
        constexpr explicit Point2T(const Vector2T<T>& v) noexcept : x(v.x ), y(v.y ) {}

        constexpr explicit operator Vector2T<T>()  const noexcept { return Vector2T<T>(x, y); }

        constexpr       T& operator[] (SizeType idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (SizeType idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T Max() noexcept { return ::Math::Max(x, y); }
        constexpr T Min() noexcept { return ::Math::Max(x, y); }
    };
}

#endif //MATHLIB_IMPL_POINT2_HPP
