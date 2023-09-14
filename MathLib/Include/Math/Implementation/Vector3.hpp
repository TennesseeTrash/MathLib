#ifndef MATHLIB_IMPL_VECTOR3_HPP
#define MATHLIB_IMPL_VECTOR3_HPP

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Type definition
    //////////////////////////////////////////////////////////////////////////

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

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> Cross(const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        Vector3T<T> w;
        w.x = u.y * v.z - u.z * v.y;
        w.y = u.z * v.x - u.x * v.z;
        w.z = u.x * v.y - u.y * v.x;
        return w;
    }

    //////////////////////////////////////////////////////////////////////////
    // Basic arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator+ (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T<T>(u.x + v.x, u.y + v.y, u.z + v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator- (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T<T>(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator* (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T<T>(u.x * v.x, u.y * v.y, u.z * v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator/ (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T<T>(u.x / v.x, u.y / v.y, u.z / v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator- (const Vector3T<T>& u) noexcept
    {
        return Vector3T<T>(-u.x, -u.y, -u.z);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator+= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        u.z += v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator-= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        u.z -= v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator*= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        u.z *= v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator/= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        u.z /= v.z;
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Scalar arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator+ (const Vector3T<T>& u, T s) noexcept
    {
        return Vector3T<T>(u.x + s, u.y + s, u.z + s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator+ (T s, const Vector3T<T>& u) noexcept
    {
        return Vector3T<T>(s + u.x, s + u.y, s + u.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator- (const Vector3T<T>& u, T s) noexcept
    {
        return Vector3T<T>(u.x - s, u.y - s, u.z - s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator* (const Vector3T<T>& u, T s) noexcept
    {
        return Vector3T<T>(u.x * s, u.y * s, u.z * s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator* (T s, const Vector3T<T>& u) noexcept
    {
        return Vector3T<T>(s * u.x, s * u.y, s * u.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator/ (const Vector3T<T>& u, T s) noexcept
    {
        return Vector3T<T>(u.x / s, u.y / s, u.z / s);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator+= (Vector3T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        u.z += s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator-= (Vector3T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        u.z -= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator*= (Vector3T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        u.z *= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector3T<T> operator/= (Vector3T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        u.z /= s;
        return u;
    }
}

#endif //MATHLIB_IMPL_VECTOR3_HPP
