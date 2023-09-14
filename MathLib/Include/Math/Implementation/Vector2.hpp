#ifndef MATHLIB_IMPL_VECTOR2_HPP
#define MATHLIB_IMPL_VECTOR2_HPP

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Type definition
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct Vector2T final
    {
        using ScalarType = T;
        static constexpr size_t Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Vector2T()           noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Vector2T(T val)      noexcept : x(val ), y(val ) {}
        constexpr          Vector2T(T xv, T yv) noexcept : x(xv  ), y(yv  ) {}

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y; }
        constexpr T Length() const noexcept { return std::sqrt(LenSqr()); }

        constexpr T Max() noexcept { return ::Math::Max(x, y); }
        constexpr T Min() noexcept { return ::Math::Min(x, y); }
    };

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> Perp(const Vector2T<T>& u) noexcept
    {
        return Vector2T<T>(u.y, -u.x);
    }

    //////////////////////////////////////////////////////////////////////////
    // Basic arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator+ (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T<T>(u.x + v.x, u.y + v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator- (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T<T>(u.x - v.x, u.y - v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator* (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T<T>(u.x * v.x, u.y * v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator/ (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T<T>(u.x / v.x, u.y / v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator- (const Vector2T<T>& u) noexcept
    {
        return Vector2T<T>(-u.x, -u.y);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator+= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator-= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator*= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator/= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Scalar arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator+ (const Vector2T<T>& u, T s) noexcept
    {
        return Vector2T<T>(u.x + s, u.y + s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator+ (T s, const Vector2T<T>& u) noexcept
    {
        return Vector2T<T>(s + u.x, s + u.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator- (const Vector2T<T>& u, T s) noexcept
    {
        return Vector2T<T>(u.x - s, u.y - s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator* (const Vector2T<T>& u, T s) noexcept
    {
        return Vector2T<T>(u.x * s, u.y * s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator* (T s, const Vector2T<T>& u) noexcept
    {
        return Vector2T<T>(s * u.x, s * u.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator/ (const Vector2T<T>& u, T s) noexcept
    {
        return Vector2T<T>(u.x / s, u.y / s);
    }



    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator+= (Vector2T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator-= (Vector2T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator/= (Vector2T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] constexpr
    Vector2T<T> operator*= (Vector2T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        return u;
    }
}

#endif //MATHLIB_IMPL_VECTOR2_HPP
