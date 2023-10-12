#ifndef MATHLIB_IMPL_VECTOR2_HPP
#define MATHLIB_IMPL_VECTOR2_HPP

#include "../Functions.hpp"

#include <cmath>

namespace Math
{
    template <typename T>
    struct Vector2T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Vector2T()           noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Vector2T(T val)      noexcept : x(val ), y(val ) {}
        constexpr          Vector2T(T xv, T yv) noexcept : x(xv  ), y(yv  ) {}

        constexpr       T& operator[] (SizeType idx)       noexcept { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const noexcept { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y; }
        constexpr T Length() const noexcept { return std::sqrt(ToUnderlying(LenSqr())); }

        constexpr T Max() noexcept { return ::Math::Max(x, y); }
        constexpr T Min() noexcept { return ::Math::Min(x, y); }
    };
}

#endif //MATHLIB_IMPL_VECTOR2_HPP
