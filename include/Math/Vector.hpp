#ifndef _CC_MATH_VECTOR_HPP
#define _CC_MATH_VECTOR_HPP

#include <cmath>

namespace cc
{
    //////////////////////////////////////////////////////////////////////////
    // Basic Definitions
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct Vector2T final
    {
        T x = T(0);
        T y = T(0);

        constexpr explicit Vector2T()           noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Vector2T(T val)      noexcept : x(val),  y(val)  {}
        constexpr          Vector2T(T xv, T yv) noexcept : x(xv),   y(yv)   {}

        constexpr       T& operator[] (int idx)       { reinterpret_cast<T *>(this)[idx]; }
        constexpr const T& operator[] (int idx) const { reinterpret_cast<T *>(this)[idx]; }

        constexpr T LenSqr() noexcept { return x * x + y * y; }
        constexpr T Length() noexcept { return std::sqrt(LenSqr()); }
    };

    template <typename T>
    struct Vector3T final
    {
        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr explicit Vector3T()                           noexcept : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr explicit Vector3T(T val)                      noexcept : x(val),  y(val),  z(val)  {}
        constexpr          Vector3T(T xv, T yv, T zv)           noexcept : x(xv),   y(yv),   z(zv)   {}
        constexpr explicit Vector3T(const Vector2T<T>& u)       noexcept : x(u.x),  y(u.y),  z(T(0)) {}
        constexpr explicit Vector3T(const Vector2T<T>& u, T zv) noexcept : x(u.x),  y(u.y),  z(zv)   {}

        constexpr       T& operator[] (int idx)       { reinterpret_cast<T *>(this)[idx]; }
        constexpr const T& operator[] (int idx) const { reinterpret_cast<T *>(this)[idx]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z; }
        constexpr T Length() const noexcept { return std::sqrt(LenSqr()); }
    };

    template <typename T>
    struct Vector4T final
    {
        T x = T(0);
        T y = T(0);
        T z = T(0);
        T w = T(0);

        constexpr explicit Vector4T()                                 noexcept : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
        constexpr explicit Vector4T(T val)                            noexcept : x(val),  y(val),  z(val),  w(val)  {}
        constexpr          Vector4T(T xv, T yv, T zv, T wv)           noexcept : x(xv),   y(yv),   z(zv),   w(wv)   {}
        constexpr explicit Vector4T(const Vector2T<T>& u)             noexcept : x(u.x),  y(u.y),  z(T(0)), w(T(0)) {}
        constexpr explicit Vector4T(const Vector2T<T>& u, T zv, T wv) noexcept : x(u.x),  y(u.y),  z(zv),   w(wv)   {}
        constexpr explicit Vector4T(const Vector3T<T>& u)             noexcept : x(u.x),  y(u.y),  z(u.z),  w(T(0)) {}
        constexpr explicit Vector4T(const Vector3T<T>& u, T wv)       noexcept : x(u.x),  y(u.y),  z(u.z),  w(wv)   {}

        constexpr       T& operator[] (int idx)       { reinterpret_cast<T *>(this)[idx]; }
        constexpr const T& operator[] (int idx) const { reinterpret_cast<T *>(this)[idx]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z + w * w; }
        constexpr T Length() const noexcept { return std::sqrt(LenSqr()); }
    };

    //////////////////////////////////////////////////////////////////////////
    // Operators
    //////////////////////////////////////////////////////////////////////////

    // Basic (component-wise) arithmetic
    // +

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator+ (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T(u.x + v.x, u.y + v.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator+ (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T(u.x + v.x, u.y + v.y, u.z + v.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator+ (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
    }

    // - (binary)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator- (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T(u.x - v.x, u.y - v.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator- (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator- (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
    }

    // *

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator* (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T(u.x * v.x, u.y * v.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator* (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T(u.x * v.x, u.y * v.y, u.z * v.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator* (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);
    }

    // /

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator/ (const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return Vector2T(u.x / v.x, u.y / v.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator/ (const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return Vector3T(u.x / v.x, u.y / v.y, u.z / v.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator/ (const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return Vector4T(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);
    }

    // - (unary)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator- (const Vector2T<T>& u) noexcept
    {
        return Vector2T(-u.x, -u.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator- (const Vector3T<T>& u) noexcept
    {
        return Vector3T(-u.x, -u.y, -u.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator- (const Vector4T<T>& u) noexcept
    {
        return Vector4T(-u.x, -u.y, -u.z, -u.w);
    }

    // +=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator+= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator+= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        u.z += v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator+= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x += v.x;
        u.y += v.y;
        u.z += v.z;
        u.w += v.w;
        return u;
    }

    // -=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator-= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator-= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        u.z -= v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator-= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x -= v.x;
        u.y -= v.y;
        u.z -= v.z;
        u.w -= v.w;
        return u;
    }

    // *=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator*= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator*= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        u.z *= v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator*= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x *= v.x;
        u.y *= v.y;
        u.z *= v.z;
        u.w *= v.w;
        return u;
    }

    // /=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator/= (Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator/= (Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        u.z /= v.z;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator/= (Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        u.x /= v.x;
        u.y /= v.y;
        u.z /= v.z;
        u.w /= v.w;
        return u;
    }

    // Basic scalar operations
    // + (add scalar to each vector component)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator+ (const Vector2T<T>& u, T s)
    {
        return Vector2T(u.x + s, u.y + s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator+ (const Vector3T<T>& u, T s)
    {
        return Vector2T(u.x + s, u.y + s, u.z + s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator+ (const Vector4T<T>& u, T s)
    {
        return Vector2T(u.x + s, u.y + s, u.z + s, u.w + s);
    }

     template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator+ (T s, const Vector2T<T>& u)
    {
        return Vector2T(s + u.x, s + u.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator+ (T s, const Vector3T<T>& u)
    {
        return Vector2T(s + u.x, s + u.y, s + u.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator+ (T s, const Vector4T<T>& u)
    {
        return Vector2T(s + u.x, s + u.y, s + u.z, s + u.w);
    }

    // - (sub scalar from each vector component)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator- (const Vector2T<T>& u, T s)
    {
        return Vector2T(u.x - s, u.y - s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator- (const Vector3T<T>& u, T s)
    {
        return Vector2T(u.x - s, u.y - s, u.z - s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator- (const Vector4T<T>& u, T s)
    {
        return Vector2T(u.x - s, u.y - s, u.z - s, u.w - s);
    }

     template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator- (T s, const Vector2T<T>& u)
    {
        return Vector2T(s - u.x, s - u.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator- (T s, const Vector3T<T>& u)
    {
        return Vector2T(s - u.x, s - u.y, s - u.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator- (T s, const Vector4T<T>& u)
    {
        return Vector2T(s - u.x, s - u.y, s - u.z, s - u.w);
    }

    // * (mult each component with scalar)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator* (const Vector2T<T>& u, T s)
    {
        return Vector2T(u.x * s, u.y * s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator* (const Vector3T<T>& u, T s)
    {
        return Vector2T(u.x * s, u.y * s, u.z * s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator* (const Vector4T<T>& u, T s)
    {
        return Vector2T(u.x * s, u.y * s, u.z * s, u.w * s);
    }

     template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator* (T s, const Vector2T<T>& u)
    {
        return Vector2T(s * u.x, s * u.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator* (T s, const Vector3T<T>& u)
    {
        return Vector2T(s * u.x, s * u.y, s * u.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator* (T s, const Vector4T<T>& u)
    {
        return Vector2T(s * u.x, s * u.y, s * u.z, s * u.w);
    }

    // / (scalar is divisor)

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator/ (const Vector2T<T>& u, T s)
    {
        return Vector2T(u.x / s, u.y / s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator/ (const Vector3T<T>& u, T s)
    {
        return Vector2T(u.x / s, u.y / s, u.z / s);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator/ (const Vector4T<T>& u, T s)
    {
        return Vector2T(u.x / s, u.y / s, u.z / s, u.w / s);
    }

    // +=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator+= (Vector2T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator+= (Vector3T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        u.z += s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator+= (Vector4T<T>& u, T s) noexcept
    {
        u.x += s;
        u.y += s;
        u.z += s;
        u.w += s;
        return u;
    }

    // -=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator-= (Vector2T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator-= (Vector3T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        u.z -= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator-= (Vector4T<T>& u, T s) noexcept
    {
        u.x -= s;
        u.y -= s;
        u.z -= s;
        u.w -= s;
        return u;
    }

    // *=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator*= (Vector2T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator*= (Vector3T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        u.z *= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator*= (Vector4T<T>& u, T s) noexcept
    {
        u.x *= s;
        u.y *= s;
        u.z *= s;
        u.w *= s;
        return u;
    }

    // /=

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector2T<T> operator/= (Vector2T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector3T<T> operator/= (Vector3T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        u.z /= s;
        return u;
    }

    template <typename T>
    [[maybe_unused]] inline constexpr
    Vector4T<T> operator/= (Vector4T<T>& u, T s) noexcept
    {
        u.x /= s;
        u.y /= s;
        u.z /= s;
        u.w /= s;
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Utilities
    //////////////////////////////////////////////////////////////////////////

    // Dot product

    template <typename T>
    [[nodiscard]] inline constexpr
    T Dot(const Vector2T<T>& u, const Vector2T<T>& v) noexcept
    {
        return (u.x * v.x) + (u.y * v.y);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Dot(const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Dot(const Vector4T<T>& u, const Vector4T<T>& v) noexcept
    {
        return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
    }

    // Normalization functions

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> Normalize(const Vector2T<T>& u)
    {
        T len = u.Length();
        return u / len;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> Normalize(const Vector3T<T>& u)
    {
        T len = u.Length();
        return u / len;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> Normalize(const Vector4T<T>& u)
    {
        T len = u.Length();
        return u / len;
    }

    // Perpendicular operations

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> Perp(const Vector2T<T>& u) noexcept
    {
        return Vector2T(u.y, -u.x);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> Cross(const Vector3T<T>& u, const Vector3T<T>& v) noexcept
    {
        Vector3T<T> w;
        w.x = u.y * v.z - u.z * v.y;
        w.y = u.z * v.x - u.x * v.z;
        w.z = u.x * v.y - u.y * v.x;
        return w;
    }
}

#endif //_CC_MATH_VECTOR_HPP
