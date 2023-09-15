#ifndef MATHLIB_IMPL_VECTOR4_HPP
#define MATHLIB_IMPL_VECTOR4_HPP

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Type definition
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct Vector4T final
    {
        using ScalarType = T;
        static constexpr size_t Dimension = 4;

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

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z + w * w; }
        constexpr T Length() const noexcept { return std::sqrt(LenSqr()); }

        constexpr T Max() noexcept { return ::Math::Max({x, y, z, w}); }
        constexpr T Min() noexcept { return ::Math::Min({x, y, z, w}); }
    };

    //////////////////////////////////////////////////////////////////////////
    // Basic arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator+ (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T<T>(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator- (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T<T>(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator* (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T<T>(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator/ (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T<T>(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator- (const Vector4T<T>& u) noexcept
    {
        return Vector4T<T>(-u.x, -u.y, -u.z, -u.w);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator+= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        u.z += v.z;
        u.w += v.w;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator-= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        u.z -= v.z;
        u.w -= v.w;
        return u;
    }
    
    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator*= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        u.z *= v.z;
        u.w *= v.w;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator/= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        u.z /= v.z;
        u.w /= v.w;
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Scalar arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator+ (const Vector4T<T>& u, T s) noexcept
    {
        return Vector4T<T>(u.x + s, u.y + s, u.z + s, u.w + s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator+ (T s, const Vector4T<T>& u) noexcept
    {
        return Vector4T<T>(s + u.x, s + u.y, s + u.z, s + u.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator- (const Vector4T<T>& u, T s) noexcept
    {
        return Vector4T<T>(u.x - s, u.y - s, u.z - s, u.w - s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator- (T s, const Vector4T<T>& u) noexcept
    {
        return Vector4T<T>(s - u.x, s - u.y, s - u.z, s - u.w);
    }


    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator* (const Vector4T<T>& u, T s) noexcept
    {
        return Vector4T<T>(u.x * s, u.y * s, u.z * s, u.w * s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator* (T s, const Vector4T<T>& u) noexcept
    {
        return Vector4T<T>(s * u.x, s * u.y, s * u.z, s * u.w);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector4T<T> operator/ (const Vector4T<T>& u, T s) noexcept
    {
        return Vector4T<T>(u.x / s, u.y / s, u.z / s, u.w / s);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator+= (Vector4T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        u.z += s;
        u.w += s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator-= (Vector4T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        u.z -= s;
        u.w -= s;
        return u;
    } 

    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator*= (Vector4T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        u.z *= s;
        u.w *= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector4T<T> operator/= (Vector4T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        u.z /= s;
        u.w /= s;
        return u;
    }
}

#endif //MATHLIB_IMPL_VECTOR4_HPP
