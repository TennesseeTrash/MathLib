#ifndef MATHLIB_IMPL_VECTOR_HPP
#define MATHLIB_IMPL_VECTOR_HPP

#include "../Functions.hpp"

// TODO(3011): Add a generic, n-dimensional vector implementation.

namespace Math
{
    template <ConceptStrongType T>
    struct Vector2T final
    {
        using ScalarType = MakeStrongType<T>;
        static constexpr SizeType Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Vector2T()           noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Vector2T(T val)      noexcept : x(val ), y(val ) {}
        constexpr          Vector2T(T xv, T yv) noexcept : x(xv  ), y(yv  ) {}

        template <typename U>
            requires (IsSpecialization<U, StaticStrongType>)
        constexpr Vector2T(const Vector2T<U>& u) noexcept : x(u.x), y(u.y) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return ::Math::Max(x, y); }
        constexpr T Min()    const noexcept { return ::Math::Min(x, y); }

        static constexpr Vector2T<T> UnitX() noexcept { return Vector2T<T>(Convert<T>(1), Convert<T>(0)); }
        static constexpr Vector2T<T> UnitY() noexcept { return Vector2T<T>(Convert<T>(0), Convert<T>(1)); }
    };

    template <ConceptStrongType T>
    struct Vector3T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 3;

        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr          Vector3T()                           noexcept : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr explicit Vector3T(T val)                      noexcept : x(val ), y(val ), z(val ) {}
        constexpr          Vector3T(T xv, T yv, T zv)           noexcept : x(xv  ), y(yv  ), z(zv  ) {}
        constexpr explicit Vector3T(const Vector2T<T>& u)       noexcept : x(u.x ), y(u.y ), z(T(0)) {}
        constexpr explicit Vector3T(const Vector2T<T>& u, T zv) noexcept : x(u.x ), y(u.y ), z(zv  ) {}

        template <typename U>
            requires (IsSpecialization<U, StaticStrongType>)
        constexpr Vector3T(const Vector3T<U>& u) noexcept : x(u.x), y(u.y), z(u.z) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return ::Math::Max(x, y, z); }
        constexpr T Min()    const noexcept { return ::Math::Min(x, y, z); }

        static constexpr Vector3T<T> UnitX() noexcept { return Vector3T<T>(Convert<T>(1), Convert<T>(0), Convert<T>(0)); }
        static constexpr Vector3T<T> UnitY() noexcept { return Vector3T<T>(Convert<T>(0), Convert<T>(1), Convert<T>(0)); }
        static constexpr Vector3T<T> UnitZ() noexcept { return Vector3T<T>(Convert<T>(0), Convert<T>(0), Convert<T>(1)); }
    };

    template <ConceptStrongType T>
    struct Vector4T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 4;

        T x = T(0);
        T y = T(0);
        T z = T(0);
        T w = T(0);

        constexpr          Vector4T()                                 noexcept : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
        constexpr explicit Vector4T(T val)                            noexcept : x(val ), y(val ), z(val ), w(val ) {}
        constexpr          Vector4T(T xv, T yv, T zv, T wv)           noexcept : x(xv  ), y(yv  ), z(zv  ), w(wv  ) {}
        constexpr explicit Vector4T(const Vector2T<T>& u)             noexcept : x(u.x ), y(u.y ), z(T(0)), w(T(0)) {}
        constexpr explicit Vector4T(const Vector2T<T>& u, T zv, T wv) noexcept : x(u.x ), y(u.y ), z(zv  ), w(wv  ) {}
        constexpr explicit Vector4T(const Vector3T<T>& u)             noexcept : x(u.x ), y(u.y ), z(u.z ), w(T(0)) {}
        constexpr explicit Vector4T(const Vector3T<T>& u, T wv)       noexcept : x(u.x ), y(u.y ), z(u.z ), w(wv  ) {}

        template <typename U>
            requires (IsSpecialization<U, StaticStrongType>)
        constexpr Vector4T(const Vector4T<U>& u) noexcept : x(u.x), y(u.y), z(u.z), w(u.w) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z + w * w; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return ::Math::Max(x, y, z, w); }
        constexpr T Min()    const noexcept { return ::Math::Min(x, y, z, w); }

        static constexpr Vector4T<T> UnitX() noexcept { return Vector4T<T>(Convert<T>(1), Convert<T>(0), Convert<T>(0), Convert<T>(0)); }
        static constexpr Vector4T<T> UnitY() noexcept { return Vector4T<T>(Convert<T>(0), Convert<T>(1), Convert<T>(0), Convert<T>(0)); }
        static constexpr Vector4T<T> UnitZ() noexcept { return Vector4T<T>(Convert<T>(0), Convert<T>(0), Convert<T>(1), Convert<T>(0)); }
        static constexpr Vector4T<T> UnitW() noexcept { return Vector4T<T>(Convert<T>(0), Convert<T>(0), Convert<T>(0), Convert<T>(1)); }
    };
}

#endif //MATHLIB_IMPL_VECTOR_HPP
