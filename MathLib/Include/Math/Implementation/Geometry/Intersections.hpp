#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP

#include "Shapes.hpp"

namespace Math::Geometry
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool HasIntersection(const Ray<T>& ray, const Interval<T>& interval, const Sphere<T>& sphere) noexcept
    {
        using Float = T;
        using VectorType = typename Ray<T>::VectorType;

        Float a = ray.Direction.LenSqr();
        Float b = 2 * Dot(VectorType(Cast<T>(1)), ray.Direction * (ray.Origin - sphere.Center));
        Float c = (ray.Origin - sphere.Center).LenSqr() - Squared(sphere.Radius);

        return Squared(b) - 4 * a * c >= Cast<T>(0);
    }



    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Point<T> NearestIntersection(const Ray<T>& ray, const Interval<T>& interval, const Sphere<T>& sphere) noexcept
    {

    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
