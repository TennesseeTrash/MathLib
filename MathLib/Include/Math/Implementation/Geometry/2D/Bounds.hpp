#ifndef MATHLIB_IMPLEMENTATION_GEOEMTRY_2D_BOUNDING_RECTANGLE_HPP
#define MATHLIB_IMPLEMENTATION_GEOEMTRY_2D_BOUNDING_RECTANGLE_HPP

#include "Shapes.hpp"
#include "../../../Transform.hpp"

namespace Math::Geometry2D
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Point<T>& point) noexcept
    {
        return Rectangle<T>(point, point);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Line<T>& line) noexcept
    {
        Point<T> min(
            Min(line.Start.x, line.End.x),
            Min(line.Start.y, line.End.y)
        );

        Point<T> max(
            Max(line.Start.x, line.End.x),
            Max(line.Start.y, line.End.y)
        );

        return Rectangle<T>(min, max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Circle<T>& circle) noexcept
    {
        Point<T> min = circle.Center - Vector2T<T>(circle.Radius);
        Point<T> max = circle.Center + Vector2T<T>(circle.Radius);
        return Rectangle<T>(min, max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Triangle<T>& triangle) noexcept
    {
        Point<T> min(
            Min(triangle.Vertices[0].x, triangle.Vertices[1].x, triangle.Vertices[2].x),
            Min(triangle.Vertices[0].y, triangle.Vertices[1].y, triangle.Vertices[2].y)
        );

        Point<T> max(
            Max(triangle.Vertices[0].x, triangle.Vertices[1].x, triangle.Vertices[2].x),
            Max(triangle.Vertices[0].y, triangle.Vertices[1].y, triangle.Vertices[2].y)
        );

        return Rectangle<T>(min, max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Rectangle<T>& rectangle) noexcept
    {
        return Rectangle<T>(rectangle.Min, rectangle.Max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Quadrilateral<T>& quadrilateral) noexcept
    {
        Point<T> min(
            Min(quadrilateral.Vertices[0].x, quadrilateral.Vertices[1].x, quadrilateral.Vertices[2].x, quadrilateral.Vertices[3].x),
            Min(quadrilateral.Vertices[0].y, quadrilateral.Vertices[1].y, quadrilateral.Vertices[2].y, quadrilateral.Vertices[3].y)
        );

        Point<T> max(
            Max(quadrilateral.Vertices[0].x, quadrilateral.Vertices[1].x, quadrilateral.Vertices[2].x, quadrilateral.Vertices[3].x),
            Max(quadrilateral.Vertices[0].y, quadrilateral.Vertices[1].y, quadrilateral.Vertices[2].y, quadrilateral.Vertices[3].y)
        );

        return Rectangle<T>(min, max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Rectangle<T> BoundingRectangle(const Ellipse<T>& ellipse) noexcept
    {
        Vector2T<T> majorAxis(
            ellipse.Radii.x * Cos(ellipse.Angle),
            ellipse.Radii.x * Sin(ellipse.Angle)
        );

        Vector2T<T> minorAxis(
            ellipse.Radii.y * Cos(ellipse.Angle + Constant::PiDiv2<T>),
            ellipse.Radii.y * Sin(ellipse.Angle + Constant::PiDiv2<T>)
        );

        Vector2T<T> centerOffset(
            Squared(majorAxis.x) + Squared(minorAxis.x),
            Squared(majorAxis.y) + Squared(minorAxis.y)
        );

        return Rectangle<T>(ellipse.Center - centerOffset, ellipse.Center + centerOffset);
    }



    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Point<T>& point) noexcept
    {
        return Circle<T>(point, T(0));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Line<T>& line) noexcept
    {
        Point<T> center = (line.Start + line.End) / T(2);
        T        radius = (line.Start - center).Length();
        return Circle<T>(center, radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Circle<T>& circle) noexcept
    {
        return Circle<T>(circle.Center, circle.Radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Triangle<T>& triangle) noexcept
    {
        Array<T, 3> squaredLengths(
            Vector2T<T>(triangle.Vertices[0]).LenSqr(),
            Vector2T<T>(triangle.Vertices[1]).LenSqr(),
            Vector2T<T>(triangle.Vertices[2]).LenSqr()
        );

        T d = (triangle.Vertices[0].x * (triangle.Vertices[1].y - triangle.Vertices[2].y) +
               triangle.Vertices[1].x * (triangle.Vertices[2].y - triangle.Vertices[0].y) +
               triangle.Vertices[2].x * (triangle.Vertices[0].y - triangle.Vertices[1].y));

        Point<T> center(
            (squaredLengths[0] * (triangle.Vertices[1].y - triangle.Vertices[2].y) +
             squaredLengths[1] * (triangle.Vertices[2].y - triangle.Vertices[0].y) +
             squaredLengths[2] * (triangle.Vertices[0].y - triangle.Vertices[1].y)) / d,
            (squaredLengths[0] * (triangle.Vertices[2].x - triangle.Vertices[1].x) +
             squaredLengths[1] * (triangle.Vertices[0].x - triangle.Vertices[2].x) +
             squaredLengths[2] * (triangle.Vertices[1].x - triangle.Vertices[0].x)) / d
        );

        T cosAngle = Dot(triangle.Vertices[1] - triangle.Vertices[0], triangle.Vertices[2] - triangle.Vertices[0]);
        T sinAngle = Sqrt(1 - Squared(cosAngle));
        T radius = (triangle.Vertices[1] - triangle.Vertices[2]).Length() / (2 * sinAngle);

        return Circle<T>(center, radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Rectangle<T>& rectangle) noexcept
    {
        Point<T> center = Point<T>((Vector2T<T>(rectangle.Min) + Vector2T<T>(rectangle.Max)) / T(2));
        T        radius = (center - rectangle.Min).Length();
        return Circle<T>(center, radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Quadrilateral<T>& quadrilateral) noexcept
    {
        // TODO(3011): Actually implement properly, this will never
        // be a tight bounding circle for any non-rectangular shape.
        // Problems to solve:
        //   - It would be nice to have this work for a general polygon.
        //   - Using a proper algorithm to find the minimum bounding circle.
        //     (Ideally with a convex hull.)
        //       - For that, the constraint of not using any dynamic allocations must be solved.
        return BoundingCircle(BoundingRectangle(quadrilateral));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Circle<T> BoundingCircle(const Ellipse<T>& ellipse) noexcept
    {
        return Circle<T>(ellipse.Center, Max(ellipse.Radii));
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOEMTRY_2D_BOUNDING_RECTANGLE_HPP
