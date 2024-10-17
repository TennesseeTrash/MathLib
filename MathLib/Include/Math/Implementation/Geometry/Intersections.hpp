#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP

#include "Shapes.hpp"

namespace Math::Geometry
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Intersection<T> NearestIntersection(const Ray<T> &ray, const Interval<T> &interval, const Plane<T>& plane) noexcept
    {
        using Float = T;

        Float cosAngle = Dot(ray.Direction, plane.Normal);
        if (Equal(cosAngle, Cast<Float>(0), Math::Constant::GeometryEpsilon<Float>))
        {
            if (Equal(Dot(plane.Normal, ray.Origin - plane.Origin), Cast<Float>(0), Math::Constant::GeometryEpsilon<Float>))
            {
                return Intersection<Float>(Cast<Float>(0));
            }
            else
            {
                return Intersection<Float>(Float::NaN());
            }
        }

        Float distance = Dot(plane.Normal, plane.Origin - ray.Origin) / Dot(plane.Normal, ray.Direction);
        return Intersection<Float>(interval.Pick(distance));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Intersection<T> NearestIntersection(const Ray<T>& ray, const Interval<T>& interval, const Sphere<T>& sphere) noexcept
    {
        using Float = T;
        using VectorType = typename Ray<T>::VectorType;

        auto newOrigin = ray.Origin - sphere.Center;

        Float a = ray.Direction.LenSqr();
        Float b = 2 * Dot(VectorType(Cast<Float>(1)), ray.Direction * newOrigin);
        Float c = newOrigin.LenSqr() - Squared(sphere.Radius);

        Float discriminant = Squared(b) - 4 * a * c;

        if (discriminant < Cast<Float>(0))
        {
            return Float::NaN();
        }

        Float discriminantSqrt = Sqrt(discriminant);
        Float a2 = Cast<T>(2) * a;
        Float t0 = (-b + discriminantSqrt) / a2;
        Float t1 = (-b - discriminantSqrt) / a2;

        Float distance = interval.Pick(t0, t1);
        return Intersection<Float>(distance);
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
