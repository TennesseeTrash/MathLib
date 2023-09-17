#ifndef MATHLIB_IMPL_VECTOR3_HPP
#define MATHLIB_IMPL_VECTOR3_HPP

#include "Vector2.hpp"

namespace Math
{
    template <typename T>
    struct Vector3T final
    {
        using ScalarType = T;
        static constexpr size_t Dimension = 3;

        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr          Vector3T()                           noexcept : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr explicit Vector3T(T val)                      noexcept : x(val ), y(val ), z(val ) {}
        constexpr          Vector3T(T xv, T yv, T zv)           noexcept : x(xv  ), y(yv  ), z(zv  ) {}
        constexpr explicit Vector3T(const Vector2T<T>& u)       noexcept : x(u.x ), y(u.y ), z(T(0)) {}
        constexpr explicit Vector3T(const Vector2T<T>& u, T zv) noexcept : x(u.x ), y(u.y ), z(zv  ) {}

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z; }
        constexpr T Length() const noexcept { return std::sqrt(LenSqr()); }

        constexpr T Max() noexcept { return ::Math::Max({x, y, z}); }
        constexpr T Min() noexcept { return ::Math::Min({x, y, z}); }
    };
}

#endif //MATHLIB_IMPL_VECTOR3_HPP
