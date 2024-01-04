#ifndef MATHLIB_IMPLEMENTATION_POINT_HPP
#define MATHLIB_IMPLEMENTATION_POINT_HPP

#include "Vector.hpp"

namespace Math
{
    template <ConceptStrongType T>
    struct Point2T
    {
        using ScalarType = T;
        using VectorType = Vector2T<T>;
        static constexpr SizeType Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Point2T()                     noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Point2T(T val)                noexcept : x(val ), y(val ) {}
        constexpr          Point2T(T xv, T yv)           noexcept : x(xv  ), y(yv  ) {}
        constexpr explicit Point2T(const Vector2T<T>& v) noexcept : x(v.x ), y(v.y ) {}

        constexpr explicit operator Vector2T<T>()  const noexcept { return Vector2T<T>(x, y); }
        constexpr explicit operator Vector3T<T>()  const noexcept { return Vector3T<T>(x, y, Cast<T>(1)); }

        constexpr       T& operator[] (SizeType idx)       noexcept { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const noexcept { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T Max() const noexcept { return Math::Max(x, y); }
        constexpr T Min() const noexcept { return Math::Max(x, y); }
    };

    template <ConceptStrongType T>
    struct Point3T
    {
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        static constexpr SizeType Dimension = 3;

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
        constexpr explicit operator Vector4T<T>()  const noexcept { return Vector4T<T>(x, y, z, Cast<T>(1)); }

        constexpr       T& operator[] (SizeType idx)       noexcept { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const noexcept { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T Max() const noexcept { return Math::Max({x, y, z}); }
        constexpr T Min() const noexcept { return Math::Max({x, y, z}); }
    };
}

#endif //MATHLIB_IMPLEMENTATION_POINT_HPP
