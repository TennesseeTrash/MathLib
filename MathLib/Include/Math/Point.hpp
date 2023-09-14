#ifndef MATHLIB_POINT_HPP
#define MATHLIB_POINT_HPP

#include "Vector.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Basic Definitions
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct Point2T
    {
        T x = T(0);
        T y = T(0);

        constexpr          Point2T()                     noexcept : x(T(0)), y(T(0)) {}
        constexpr explicit Point2T(T val)                noexcept : x(val ), y(val ) {}
        constexpr          Point2T(T xv, T yv)           noexcept : x(xv  ), y(yv  ) {}
        constexpr explicit Point2T(const Vector2T<T>& v) noexcept : x(v.x ), y(v.y ) {}

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T Max() noexcept { return std::max(x, y); }
        constexpr T Min() noexcept { return std::min(x, y); }
    };

    template <typename T>
    struct Point3T
    {
        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr          Point3T()                          noexcept : x(T(0)), y(T(0)), z(T(0)) {}
        constexpr explicit Point3T(T val)                     noexcept : x(val ), y(val ), z(val ) {}
        constexpr          Point3T(T xv, T yv, T zv)          noexcept : x(xv  ), y(yv  ), z(zv  ) {}
        constexpr explicit Point3T(const Point2T<T>& p)       noexcept : x(p.x ), y(p.y ), z(T(0)) {}
        constexpr explicit Point3T(const Point2T<T>& p, T zv) noexcept : x(p.x ), y(p.y ), z(zv  ) {}
        constexpr explicit Point3T(const Vector2T<T>& v)      noexcept : x(v.x ), y(v.y ), z(T(0)) {}
        constexpr explicit Point3T(const Vector3T<T>& v)      noexcept : x(v.x ), y(v.y ), z(v.z ) {}

        constexpr       T& operator[] (size_t idx)       noexcept { return reinterpret_cast<      T *>(this)[idx]; }
        constexpr const T& operator[] (size_t idx) const noexcept { return reinterpret_cast<const T *>(this)[idx]; }

        constexpr T Max() noexcept { return std::max({x, y, z}); }
        constexpr T Min() noexcept { return std::min({x, y, z}); }
    };

    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Point2f = Point2T<float>;
    using Point3f = Point3T<float>;

    using Point2d = Point2T<double>;
    using Point3d = Point3T<double>;

    //////////////////////////////////////////////////////////////////////////
    // Operators
    //////////////////////////////////////////////////////////////////////////

    // Subtracting two points

    template <typename T>
    [[nodiscard]] constexpr
    Vector2T<T> operator- (const Point2T<T>& p1, const Point2T<T>& p2) noexcept
    {
        return Vector2T<T>(p1.x - p2.x, p1.y - p2.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> operator- (const Point3T<T>& p1, const Point3T<T>& p2) noexcept
    {
        return Vector3T<T>(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
    }

    // Adding a Vector to a Point

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator+ (const Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        return Point2T<T>(p.x + v.x, p.y + v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator+ (const Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        return Point3T<T>(p.x + v.x, p.y + v.y, p.z + v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator+ (const Vector2T<T>& v, const Point2T<T>& p) noexcept
    {
        return Point2T<T>(p.x + v.x, p.y + v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator+ (const Vector3T<T>& v, const Point3T<T>& p) noexcept
    {
        return Point3T<T>(p.x + v.x, p.y + v.y, p.z + v.z);
    }

    // Subtracting a Vector from a Point

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator- (const Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        return Point2T<T>(p.x - v.x, p.y - v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator- (const Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        return Point3T<T>(p.x - v.x, p.y - v.y, p.z - v.z);
    }

    // (Component-wise) multiply a Point by a Vector

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        return Point2T<T>(p.x * v.x, p.y * v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        return Point3T<T>(p.x * v.x, p.y * v.y, p.z * v.z);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Vector2T<T>& v, const Point2T<T>& p) noexcept
    {
        return Point2T<T>(p.x * v.x, p.y * v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Vector3T<T>& v, const Point3T<T>& p) noexcept
    {
        return Point3T<T>(p.x * v.x, p.y * v.y, p.z * v.z);
    }

    // (Component-wise) divide a Point by a Vector

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator/ (const Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        return Point2T<T>(p.x / v.x, p.y / v.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator/ (const Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        return Point3T<T>(p.x / v.x, p.y / v.y, p.z / v.z);
    }

    // Modifying operators

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T>& operator+= (Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        p.x += v.x;
        p.y += v.y;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T>& operator+= (Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        p.x += v.x;
        p.y += v.y;
        p.z += v.z;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T>& operator-= (Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        p.x -= v.x;
        p.y -= v.y;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T>& operator-= (Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        p.x -= v.x;
        p.y -= v.y;
        p.z -= v.z;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T>& operator*= (Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        p.x *= v.x;
        p.y *= v.y;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T>& operator*= (Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        p.x *= v.x;
        p.y *= v.y;
        p.z *= v.z;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T>& operator/= (Point2T<T>& p, const Vector2T<T>& v) noexcept
    {
        p.x /= v.x;
        p.y /= v.y;
        return p;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T>& operator/= (Point3T<T>& p, const Vector3T<T>& v) noexcept
    {
        p.x /= v.x;
        p.y /= v.y;
        p.z /= v.z;
        return p;
    }

    //////////////////////////////////////////////////////////////////////////
    // Utilities
    //////////////////////////////////////////////////////////////////////////

    // Equality checks

    template <typename T>
    [[nodiscard]] constexpr
    bool Equal(const Point2T<T>& p1, const Point2T<T>& p2, T epsilon = Constants::FloatEps<T>) noexcept
    {
        return Equal(p1.x, p2.x, epsilon)
            && Equal(p1.y, p2.y, epsilon);
    }

    template <typename T>
    [[nodiscard]] constexpr
    bool Equal(const Point3T<T>& p1, const Point3T<T>& p2, T epsilon = Constants::FloatEps<T>) noexcept
    {
        return Equal(p1.x, p2.x, epsilon)
            && Equal(p1.y, p2.y, epsilon)
            && Equal(p1.z, p2.z, epsilon);
    }

    // NaN checks

    template <typename T>
    [[nodiscard]] constexpr
    bool HasNaN(const Point2T<T>& p) noexcept
    {
        return (p.x != p.x) || (p.y != p.y);
    }

    template <typename T>
    [[nodiscard]] constexpr
    bool HasNaN(const Point3T<T>& p) noexcept
    {
        return (p.x != p.x) || (p.y != p.y) || (p.z != p.z);
    }
}

#endif //MATHLIB_POINT_HPP
