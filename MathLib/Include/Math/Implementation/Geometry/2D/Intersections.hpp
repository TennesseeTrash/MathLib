#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_2D_INTERSECTIONS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_2D_INTERSECTIONS_HPP

#include "Shapes.hpp"

namespace Math::Geometry2D
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool HasIntersection(const Ray<T>& ray, const Interval<T>& interval, const Circle<T>& circle) noexcept
    {
        return false;
    }



    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    T NearestIntersection(const Ray<T>& ray, const Interval<T>& interval, const Circle<T>& circle) noexcept
    {
        return T(0);
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_2D_INTERSECTIONS_HPP
