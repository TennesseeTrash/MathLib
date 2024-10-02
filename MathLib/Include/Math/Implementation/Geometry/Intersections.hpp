#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP

#include "Shapes.hpp"

namespace Math::Geometry
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Intersection<T> NearestIntersection(const Ray<T>& ray, const Interval<T>& interval, const Sphere<T>& sphere) noexcept
    {
        using Float = T;
        using VectorType = typename Ray<T>::VectorType;

        auto newOrigin = ray.Origin - sphere.Center;

        Float a = ray.Direction.LenSqr();
        Float b = 2 * Dot(VectorType(Cast<T>(1)), ray.Direction * newOrigin);
        Float c = newOrigin.LenSqr() - Squared(sphere.Radius);

        Float discriminant = Squared(b) - 4 * a * c;

        if (discriminant < Cast<T>(0))
        {
            return T::NaN();
        }

        Float discriminantSqrt = Sqrt(discriminant);
        Float a2 = Cast<T>(2) * a;
        Float t0 = (-b + discriminantSqrt) / a2;
        Float t1 = (-b - discriminantSqrt) / a2;

        Float distance = interval.Pick(t0, t1);
        if (distance != distance)
        {
            return Intersection<T>(distance);
        }

        VectorType normal = sphere.Normal(ray.Project(distance));
        return Intersection<T>(distance, normal);
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
