#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP

#include "Shapes.hpp"
#include "../../../Transform.hpp"

// Note(3011): I'm not sure if I like this sort of interface,
// these functions might make more sense as members.

namespace Math::Geometry2D
{
    //////////////////////////////////////////////////////////////////////////
    // Point Contains functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Point<T>& other) noexcept
    {
        return Equal(point, other, Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Line<T>& line) noexcept
    {
        return Equal(point, line.Start, Constant::GeometryEpsilon<T>)
            && Equal(point, line.End, Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Circle<T>& circle) noexcept
    {
        return Equal(point, circle.Center, Constant::GeometryEpsilon<T>)
            && Equal(circle.Radius, T(0), Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Triangle<T>& triangle) noexcept
    {
        return Equal(point, triangle.Vertices[0], Constant::GeometryEpsilon<T>)
            && Equal(point, triangle.Vertices[1], Constant::GeometryEpsilon<T>)
            && Equal(point, triangle.Vertices[0], Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Rectangle<T>& rectangle) noexcept
    {
        return Equal(point, rectangle.Min, Constant::GeometryEpsilon<T>)
            && Equal(point, rectangle.Max, Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Equal(point, quadrilateral.Vertices[i], Constant::GeometryEpsilon<T>))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Point<T>& point, const Ellipse<T>& ellipse) noexcept
    {
        return Equal(point, ellipse.Center, Constant::GeometryEpsilon<T>)
            && Equal(point, ellipse.Radii.x, Constant::GeometryEpsilon<T>)
            && Equal(point, ellipse.Radii.y, Constant::GeometryEpsilon<T>);
    }



    //////////////////////////////////////////////////////////////////////////
    // Line Contains functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Point<T>& point) noexcept
    {
        Vector2T<T> t = (point - line.Start) / (line.End - line.Start);
        return Equal(t.x, t.y) && t.x >= 0 && t.x <= 1;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Line<T>& other) noexcept
    {
        return Contains(line, other.Start) && Contains(line, other.End);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Circle<T>& circle) noexcept
    {
        return Contains(line, circle.Center)
            && Equal(circle.Radius, T(0), Constant::GeometryEpsilon<T>);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Triangle<T>& triangle) noexcept
    {
        return Contains(line, triangle.Vertices[0])
            && Contains(line, triangle.Vertices[1])
            && Contains(line, triangle.Vertices[2]);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Rectangle<T>& rectangle) noexcept
    {
        return Contains(line, rectangle.Min)
            && Contains(line, rectangle.Max)
            && Contains(line, Point<T>(rectangle.Min.x, rectangle.Max.y))
            && Contains(line, Point<T>(rectangle.Max.x, rectangle.Min.y));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Contains(line, quadrilateral.Vertices[i]))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Line<T>& line, const Ellipse<T>& ellipse) noexcept
    {
        return Contains(line, ellipse.Center)
            && Equal(ellipse.Radii.x, T(0), Constant::GeometryEpsilon<T>)
            && Equal(ellipse.Radii.y, T(0), Constant::GeometryEpsilon<T>);
    }



    //////////////////////////////////////////////////////////////////////////
    // Circle Contains functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Point<T>& point) noexcept
    {
        return (point - circle.Center).Length() <= circle.Radius;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Line<T>& line) noexcept
    {
        return Contains(circle, line.Start) && Contains(circle, line.End);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Circle<T>& other) noexcept
    {
        return (circle.Center - other.Center).Length() <= Abs(circle.Radius - other.Radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Triangle<T>& triangle) noexcept
    {
        return Contains(circle, triangle.Vertices[0])
            && Contains(circle, triangle.Vertices[1])
            && Contains(circle, triangle.Vertices[2]);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Rectangle<T>& rectangle) noexcept
    {
        return Contains(circle, rectangle.Min) && Contains(circle, rectangle.Max);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Contains(circle, quadrilateral.Vertices[i]))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Circle<T>& circle, const Ellipse<T>& ellipse) noexcept
    {
        // TODO(3011): This is not going to be completely straight forward.
        return false;
    }



    //////////////////////////////////////////////////////////////////////////
    // Triangle Contains functions
    //////////////////////////////////////////////////////////////////////////

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
    bool Contains(const Triangle<T>& triangle, const Line<T>& line) noexcept
    {
        return Contains(triangle, line.Start) && Contains(triangle, line.End);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Circle<T>& circle) noexcept
    {
        // TODO(3011): Implement
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Triangle<T>& other) noexcept
    {
        return Contains(triangle, other.Vertices[0])
            && Contains(triangle, other.Vertices[1])
            && Contains(triangle, other.Vertices[2]);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Rectangle<T>& rectangle) noexcept
    {
        return Contains(triangle, rectangle.Min)
            && Contains(triangle, rectangle.Max)
            && Contains(triangle, Point<T>(rectangle.Min.x, rectangle.Max.y))
            && Contains(triangle, Point<T>(rectangle.Max.x, rectangle.Min.y));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Contains(triangle, quadrilateral.Vertices[i]))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Triangle<T>& triangle, const Ellipse<T>& ellipse) noexcept
    {
        // TODO(3011): Implement
        return false;
    }



    //////////////////////////////////////////////////////////////////////////
    // Rectangle Contains functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Point<T>& point) noexcept
    {
        return point.x >= rectangle.Min.x && point.x <= rectangle.Max.x &&
               point.y >= rectangle.Min.y && point.y <= rectangle.Max.y;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Line<T>& line) noexcept
    {
        return Contains(rectangle, line.Start) && Contains(rectangle, line.End);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Circle<T>& circle) noexcept
    {
        Vector2T<T> min = circle.Center - rectangle.Min;
        Vector2T<T> max = rectangle.Max - circle.Center;
        return (min.x >= circle.Radius) && (min.y >= circle.Radius) &&
               (max.x >= circle.Radius) && (max.y >= circle.Radius);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Triangle<T>& triangle) noexcept
    {
        return Contains(rectangle, triangle.Vertices[0])
            && Contains(rectangle, triangle.Vertices[1])
            && Contains(rectangle, triangle.Vertices[2]);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Rectangle<T>& other) noexcept
    {
        return rectangle.Min.x <= other.Min.x && rectangle.Min.y <= other.Min.y &&
               rectangle.Max.x >= other.Max.x && rectangle.Max.y >= other.Max.y;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Contains(rectangle, quadrilateral.Vertices[i]))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Rectangle<T>& rectangle, const Ellipse<T>& ellipse) noexcept
    {
        // TODO(3011): This is not going to be completely straight forward, but
        // an easy way to solve this would be to make a bounding rectangle and check that.
        return false;
    }



    //////////////////////////////////////////////////////////////////////////
    // Quadrilateral Contains functions
    //////////////////////////////////////////////////////////////////////////

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

    // TODO(3011): These are going to be a major pain to implement, because we're not enforcing
    // convexity and we want this to work for Polygons in general.



    //////////////////////////////////////////////////////////////////////////
    // Ellipse Contains functions
    //////////////////////////////////////////////////////////////////////////

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, Point<T> point) noexcept
    {
        point = Rotate(-ellipse.Angle) * Point<T>(point - ellipse.Center);
        return (Squared(point.x) / Squared(ellipse.Radii.x)) + (Squared(point.y) / Squared(ellipse.Radii.y)) <= 1;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Line<T>& line) noexcept
    {
        return Contains(ellipse, line.Start) && Contains(ellipse, line.End);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Circle<T>& circle) noexcept
    {
        // TODO(3011): Implement
        return false;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Triangle<T>& triangle) noexcept
    {
        return Contains(ellipse, triangle.Vertices[0])
            && Contains(ellipse, triangle.Vertices[1])
            && Contains(ellipse, triangle.Vertices[2]);
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Rectangle<T>& rectangle) noexcept
    {
        return Contains(ellipse, rectangle.Min)
            && Contains(ellipse, rectangle.Max)
            && Contains(ellipse, Point<T>(rectangle.Min.x, rectangle.Max.y))
            && Contains(ellipse, Point<T>(rectangle.Max.x, rectangle.Min.y));
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Quadrilateral<T>& quadrilateral) noexcept
    {
        const SizeType vertexCount = quadrilateral.Vertices.Size;
        for (SizeType i = 0; i < vertexCount; ++i)
        {
            if (!Contains(ellipse, quadrilateral.Vertices[i]))
            {
                return false;
            }
        }
        return true;
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ellipse<T>& ellipse, const Ellipse<T>& other) noexcept
    {
        // TODO(3011): Implement
        return false;
    }



    //////////////////////////////////////////////////////////////////////////
    // Ray Contains functions
    //////////////////////////////////////////////////////////////////////////
    // I'm not sure if any other Contains functions would make sense for a Ray.

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    bool Contains(const Ray<T>& ray, const Point<T>& point) noexcept
    {
        Vector2T<T> t = (point - ray.Origin) / ray.Direction;
        return Equal(t.x, t.y) && t.x >= 0;
    }
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_2D_CONTAINS_HPP
