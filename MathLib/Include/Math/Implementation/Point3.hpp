#ifndef MATHLIB_IMPL_POINT3_HPP
#define MATHLIB_IMPL_POINT3_HPP

#include "Point2.hpp"
#include "Matrix4.hpp"

namespace Math
{
    template <typename T>
    struct Point3T
    {
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        using MatrixType = Matrix3T<T>;
        using ProjectiveMatrixType = Matrix4T<T>;
        static constexpr size_t Dimension = 3;

        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr          Point3T()                           noexcept : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr explicit Point3T(T val)                      noexcept : x(val ), y(val ), z(val ) {}
        constexpr          Point3T(T xv, T yv, T zv)           noexcept : x(xv  ), y(yv  ), z(zv  ) {}
        constexpr explicit Point3T(const Point2T<T>& p)        noexcept : x(p.x ), y(p.y ), z(T(0)) {}
        constexpr explicit Point3T(const Point2T<T>& p, T zv)  noexcept : x(p.x ), y(p.y ), z(zv  ) {}
        constexpr explicit Point3T(const Vector2T<T>& v)       noexcept : x(v.x ), y(v.y ), z(T(0)) {}
        constexpr explicit Point3T(const Vector2T<T>& v, T zv) noexcept : x(v.x ), y(v.y ), z(zv  ) {}
        constexpr explicit Point3T(const Vector3T<T>& v)       noexcept : x(v.x ), y(v.y ), z(v.z ) {}

        constexpr explicit operator Vector3T<T>()  const noexcept { return Vector3T<T>(x, y, z); }

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T Max() noexcept { return ::Math::Max({x, y, z}); }
        constexpr T Min() noexcept { return ::Math::Max({x, y, z}); }
    };
}

#endif //MATHLIB_IMPL_POINT3_HPP
