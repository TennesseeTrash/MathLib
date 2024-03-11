#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP

#include "Shapes.hpp"
#include "../../../Transform.hpp"

namespace Math::Geometry2D
{
    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Point<T>& other) noexcept
    {
        return Equal(point, other);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Point<T>& point) noexcept
    {
        Vector2T<T> t = (point - line.Start) / (line.End - line.Start);
        return Equal(t.x, t.y) && t.x >= 0 && t.x <= 1;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Point<T>& point) noexcept
    {
        return (point - circle.Center).Length() <= circle.Radius;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Point<T>& point) noexcept
    {
        Array<Vector2T<T>, 3> vectors
        {
            triangle.Vertices[0] - point,
            triangle.Vertices[1] - point,
            triangle.Vertices[2] - point
        };

        Array<T, 3> areas
        {
            TriangleArea(vectors[0], vectors[1]),
            TriangleArea(vectors[1], vectors[2]),
            TriangleArea(vectors[2], vectors[0])
        };

        return Equal(areas[0] + areas[1] + areas[2], triangle.Area());
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Point<T>& point) noexcept
    {
        return point.x >= rectangle.Min.x && point.x <= rectangle.Max.x &&
               point.y >= rectangle.Min.y && point.y <= rectangle.Max.y;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Quadrilateral<T>& quadrilateral, const Point<T>& point) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        SignedSizeType windings = 0;

        for (SizeType i = 0; i < vertexCount; ++i)
        {
            Line<T> line(quadrilateral.Vertices[i], quadrilateral.Vertices[(i + 1) % vertexCount]);

            if (line.Start.y <= point.y)
            {
                if (line.End.y > point.y && line.Side(point) > 0)
                {
                    ++windings;
                }
            }
            else
            {
                if (line.End.y <= point.y && line.Side(point) < 0)
                {
                    --windings;
                }
            }
        }

        return windings != 0;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, Point<T> point) noexcept
    {
        point = Rotate(-ellipse.Angle) * Point<T>(point - ellipse.Center);
        return (Squared(point.x) / Squared(ellipse.Radii.x)) + (Squared(point.y) / Squared(ellipse.Radii.y)) <= 1;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ray<T>& ray, const Point<T>& point) noexcept
    {
        Vector2T<T> t = (point - ray.Origin) / ray.Direction;
        return Equal(t.x, t.y) && t.x >= 0;
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP
