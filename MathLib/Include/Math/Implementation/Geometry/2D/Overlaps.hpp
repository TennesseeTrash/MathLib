#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_2D_OVERLAPS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_2D_OVERLAPS_HPP

#include "Shapes.hpp"
#include "Contains.hpp"

namespace Math::Geometry2D
{
    //////////////////////////////////////////////////////////////////////////
    // Point Overlaps functions
    //////////////////////////////////////////////////////////////////////////
    // Does the rest make sense?

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Point<T>& point, const Point<T>& other) noexcept
    {
        return Equals(point, other, Constant::GeometryEpsilon<T>);
    }



    //////////////////////////////////////////////////////////////////////////
    // Line Overlaps functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Point<T>& point) noexcept
    {
        return Contains(line, point);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Line<T>& other) noexcept
    {
        // TODO(3011): Check if the two lines have an intersection
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Circle<T>& circle) noexcept
    {
        // TODO(3011): Check if there are any intersections
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Triangle<T>& triangle) noexcept
    {
        // TODO(3011): Check if any of the line ends are inside the triangle
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Rectangle<T>& rectangle) noexcept
    {
        // TODO(3011): heh
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Quadrilateral<T>& quad) noexcept
    {
        // TODO(3011): dedge
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Overlaps(const Line<T>& line, const Ellipse<T>& ellipse) noexcept
    {
        // TODO(3011): bruh
        return false;
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_2D_OVERLAPS_HPP
