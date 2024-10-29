#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_INTERSECTIONS_HPP

#include "Shapes.hpp"

namespace Math::Geometry
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Intersection<T> NearestIntersection(const Ray<T> &ray, const Interval<T>& interval, const Plane<T>& plane) noexcept
    {
        using Float = T;

        Float cosIncidence = Dot(ray.Direction, plane.Normal);
        if (Equal(cosIncidence, Cast<Float>(0), Math::Constant::GeometryEpsilon<Float>))
        {
            if (Equal(Dot(plane.Normal, plane.Origin - ray.Origin), Cast<Float>(0), Math::Constant::GeometryEpsilon<Float>))
            {
                return Intersection<Float>(Cast<Float>(0));
            }
            else
            {
                return Intersection<Float>(Float::NaN());
            }
        }

        Float distance = Dot(plane.Normal, plane.Origin - ray.Origin) / cosIncidence;
        return Intersection<Float>(interval.Pick(distance));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Intersection<T> NearestIntersection(const Ray<T>& ray, const Interval<T>& interval, const Triangle<T>& triangle) noexcept
    {
        using Float = T;
        using PointType = typename Ray<Float>::PointType;
        using VectorType = typename Ray<Float>::VectorType;

        VectorType u = triangle.B - triangle.A;
        VectorType v = triangle.C - triangle.A;

        VectorType normal = Cross(u, v);
        if (Equal(normal, VectorType(Cast<Float>(0))))
        {
            return Intersection<Float>(Float::NaN());
        }

        Float a = -Dot(normal, ray.Origin - triangle.A);
        Float b = Dot(normal, ray.Direction);
        if (Equal(b, Cast<Float>(0), Constant::GeometryEpsilon<Float>))
        {
            if (Equal(a, Cast<Float>(0), Constant::GeometryEpsilon<Float>))
            {
                return Intersection<Float>(Cast<Float>(0));
            }
            else
            {
                return Intersection<Float>(Float::NaN());
            }
        }

        Float distance = a / b;
        if (distance < Cast<Float>(0))
        {
            return Intersection<Float>(Float::NaN());
        }

        PointType intersect = ray.Project(distance);
        VectorType w = intersect - triangle.A;
        Float det = Squared(Dot(u, v)) - u.LenSqr() * v.LenSqr();
        Float s = (Dot(u, v) * Dot(w, v) - v.LenSqr() * Dot(u, w)) / det;
        Float t = (Dot(u, v) * Dot(u, w) - u.LenSqr() * Dot(w, v)) / det;

        if (s > Cast<Float>(0) && t > Cast<Float>(0) && (s + t) <= Cast<Float>(1))
        {
            return Intersection<Float>(interval.Pick(distance));
        }
        else
        {
            return Intersection<Float>(Float::NaN());
        }
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
