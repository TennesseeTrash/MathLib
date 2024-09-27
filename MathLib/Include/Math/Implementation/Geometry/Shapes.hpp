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

    };

    template <Concept::StrongFloatType T>
    struct Triangle
    {
    public:

    };

    template <Concept::StrongFloatType T>
    struct Sphere
    {
    public:
        using ScalarType = T;
        using PointType = Point<T>;

        [[nodiscard]] constexpr
        Sphere(const PointType& center, ScalarType radius) noexcept
            : Center(center), Radius(radius)
        {}

        PointType Center;
        ScalarType Radius;
    };



    template <Concept::StrongFloatType T>
    struct Interval
    {
    public:
        using ScalarType = T;

        [[nodiscard]] constexpr
        Interval(ScalarType min = ScalarType::Min(), ScalarType max = ScalarType::Max()) noexcept
        {}

        ScalarType Min;
        ScalarType Max;
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
