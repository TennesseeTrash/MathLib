#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_SHAPES_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_SHAPES_HPP

#include "../../Vector.hpp"
#include "../../Point.hpp"
#include "../../Transform.hpp"

namespace Math::Geometry
{
    template <Concept::StrongFloatType T>
    using Point = Point3T<T>;

    template <Concept::StrongFloatType T>
    struct Plane
    {
    public:
        using ScalarType = T;
        using PointType = Point<T>;
        using VectorType = Vector3T<T>;

        [[nodiscard]] constexpr
        Plane(const PointType& origin, const VectorType& normal) noexcept
            : Origin(origin), Normal(normal)
        {}

        [[nodiscard]] constexpr
        VectorType SurfaceNormal([[maybe_unused]] const PointType& surfacePoint) const noexcept
        {
            return Normal;
        }

        PointType Origin;
        VectorType Normal;
    };

    template <Concept::StrongFloatType T>
    struct Triangle
    {
    public:
        using PointType = Point<T>;
        using VectorType = Vector3T<T>;

        [[nodiscard]] constexpr
        Triangle(const PointType& a, const PointType& b, const PointType& c)
            : A(a), B(b), C(c)
        {}

        [[nodiscard]] constexpr
        VectorType SurfaceNormal([[maybe_unused]] const PointType& surfacePoint) const noexcept
        {
            return Cross(B - A, C - A);
        }

        PointType A;
        PointType B;
        PointType C;
    };

    template <Concept::StrongFloatType T>
    struct Sphere
    {
    public:
        using ScalarType = T;
        using PointType = Point<T>;
        using VectorType = Vector3T<T>;

        [[nodiscard]] constexpr
        Sphere(const PointType& center, ScalarType radius) noexcept
            : Center(center), Radius(radius)
        {}

        VectorType SurfaceNormal(const PointType& surfacePoint) const noexcept
        {
            return Normalize(surfacePoint - Center);
        }

        PointType Center;
        ScalarType Radius;
    };

    template <Concept::StrongFloatType T>
    struct Box
    {
    public:
        using PointType = Point<T>;

        [[nodiscard]] constexpr
        Box(const PointType& min, const PointType& max)
            : Min(Math::Min(min.x, max.x), Math::Min(min.y, max.y), Math::Min(min.z, max.z)),
              Max(Math::Max(min.x, max.x), Math::Max(min.y, max.y), Math::Max(min.z, max.z))
        {}

        PointType Min;
        PointType Max;
    };


    template <Concept::StrongFloatType T>
    struct Interval
    {
    public:
        using ScalarType = T;

        [[nodiscard]] constexpr
        Interval(ScalarType min = Constant::GeometryEpsilon<T>, ScalarType max = ScalarType::Max()) noexcept
            : Min(min), Max(max)
        {}

        [[nodiscard]] constexpr
        ScalarType Pick(ScalarType t0) const noexcept
        {
            if (Min <= t0 && t0 <= Max)
            {
                return t0;
            }

            return ScalarType::NaN();
        }

        [[nodiscard]] constexpr
        ScalarType Pick(ScalarType t0, ScalarType t1) const noexcept
        {
            ScalarType min = Math::Min(t0, t1);
            if (Min <= min && min <= Max)
            {
                return min;
            }

            ScalarType max = Math::Max(t0, t1);
            if (Min <= max && max <= Max)
            {
                return max;
            }

            return ScalarType::NaN();
        }

        ScalarType Min;
        ScalarType Max;
    };

    template <Concept::StrongFloatType T>
    struct Intersection
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;

        [[nodiscard]] constexpr
        Intersection(ScalarType distance) noexcept
            : Distance(distance)
        {}

        [[nodiscard]] constexpr
        bool IsValid() const noexcept
        {
            return Distance == Distance;
        }

        [[nodiscard]] constexpr explicit
        operator bool () const noexcept
        {
            return IsValid();
        }

        ScalarType Distance;
    };

    template <Concept::StrongFloatType T>
    struct Ray
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        using PointType = Point<T>;

        [[nodiscard]] constexpr
        Ray(const PointType& origin, const VectorType& direction) noexcept
            : Origin(origin), Direction(direction)
        {}

        [[nodiscard]] constexpr
        PointType Project(ScalarType scale) const noexcept
        {
            return Origin + (scale * Direction);
        }

        PointType Origin;
        VectorType Direction;
    };
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_SHAPES_HPP
