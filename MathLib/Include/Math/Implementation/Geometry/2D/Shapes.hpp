#ifndef MATHLIB_IMPLEMENTATION_GEOMETRY_2D_SHAPES_HPP
#define MATHLIB_IMPLEMENTATION_GEOMETRY_2D_SHAPES_HPP

#include "../../../Base.hpp"
#include "../../../Constants.hpp"
#include "../../../Functions.hpp"
#include "../../../Vector.hpp"
#include "../../../Point.hpp"
#include "../../../Transform.hpp"

namespace Math::Geometry2D
{
    template <Concept::StrongFloatType T>
    using Point = Point2T<T>;

    template <Concept::StrongFloatType T>
    struct Line
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;

        [[nodiscard]] constexpr
        Line(const Point<T>& start, const Point<T>& end) noexcept
            : Start(start), End(end)
        {}

        [[nodiscard]] constexpr
        ScalarType Length() const noexcept
        {
            return (End - Start).Length();
        }

        [[nodiscard]] constexpr
        ScalarType Midpoint() const noexcept
        {
            return PointType((Vector2T<T>(Start) + Vector2T<T>(End)) / ScalarType(2));
        }

        [[nodiscard]] constexpr
        ScalarType Side(const Point<T>& point) const noexcept
        {
            Vector2T<T> line = End - Start;
            Vector2T<T> pointLine = point - Start;
            return line.x * pointLine.y - line.y * pointLine.x;
        }

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return ScalarType(0);
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            return Length();
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return Midpoint();
        }

        PointType Start;
        PointType End;
    };

    template <Concept::StrongFloatType T>
    struct Circle
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;

        [[nodiscard]] constexpr
        Circle(const PointType& center, ScalarType radius) noexcept
            : Center(center), Radius(radius)
        {}

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return Constant::Pi<ScalarType> * Squared(Radius);
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            return ScalarType(2) * Constant::Pi<ScalarType> * Radius;
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return Center;
        }

        PointType  Center;
        ScalarType Radius;
    };

    template <Concept::StrongFloatType T>
    struct Triangle
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;

        [[nodiscard]] constexpr
        Triangle(const PointType& a, const PointType& b, const PointType& c) noexcept
            : Vertices({ a, b, c })
        {}

        [[nodiscard]] constexpr
        Array<Line<T>, 3> Edges() const noexcept
        {
            return Array<Line<T>, 3>
            {
                Line<T>(Vertices[0], Vertices[1]),
                Line<T>(Vertices[1], Vertices[2]),
                Line<T>(Vertices[2], Vertices[0])
            };
        }

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return TriangleArea(Vertices[0] - Vertices[1], Vertices[0] - Vertices[2]);
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            return (Vertices[0] - Vertices[1]).Length() +
                   (Vertices[1] - Vertices[2]).Length() +
                   (Vertices[2] - Vertices[0]).Length();
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return PointType((Vector2T<T>(Vertices[0])
                            + Vector2T<T>(Vertices[1])
                            + Vector2T<T>(Vertices[2])) / ScalarType(3));
        }

        Array<PointType, 3> Vertices;
    };

    template <Concept::StrongFloatType T>
    struct Rectangle
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;

        [[nodiscard]] constexpr
        Rectangle(const PointType& min, const PointType& max) noexcept
            : Min(Math::Min(min.x, max.x), Math::Min(min.y, max.y))
            , Max(Math::Max(min.x, max.x), Math::Max(min.y, max.y))
        {}

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return (Max.x - Min.x) * (Max.y - Min.y);
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            return ScalarType(2) * ((Max.x - Min.x) + (Max.y - Min.y));
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return PointType((Vector2T<T>(Min) + Vector2T<T>(Max)) / ScalarType(2));
        }

        PointType Min;
        PointType Max;
    };

    template <Concept::StrongFloatType T>
    struct Quadrilateral
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;

        [[nodiscard]] constexpr
        Quadrilateral(const PointType& a, const PointType& b, const PointType& c, const PointType& d) noexcept
            : Vertices({ a, b, c, d })
        {}

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return ((Vertices[0].x * Vertices[1].y + Vertices[1].x * Vertices[2].y
                   + Vertices[2].x * Vertices[3].y + Vertices[3].x * Vertices[0].y)
                   -(Vertices[1].x * Vertices[0].y + Vertices[2].x * Vertices[1].y
                   + Vertices[3].x * Vertices[2].y + Vertices[0].x * Vertices[3].y)) / ScalarType(2);
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            return (Vertices[0] - Vertices[1]).Length() +
                   (Vertices[1] - Vertices[2]).Length() +
                   (Vertices[2] - Vertices[3]).Length() +
                   (Vertices[3] - Vertices[0]).Length();
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return PointType((Vector2T<T>(Vertices[0])
                            + Vector2T<T>(Vertices[1])
                            + Vector2T<T>(Vertices[2])
                            + Vector2T<T>(Vertices[3])) / ScalarType(4));
        }

        Array<PointType, 4> Vertices;
    };

    template <Concept::StrongFloatType T>
    struct Ellipse
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;
        using VectorType = Vector2T<T>;

        [[nodiscard]] constexpr
        Ellipse(const PointType& center, const VectorType& radii, ScalarType angle = ScalarType(0)) noexcept
            : Center(center), Radii(radii), Angle(angle)
        {}

        [[nodiscard]] constexpr
        ScalarType Eccentricity() const noexcept
        {
            return Sqrt(ScalarType(1) - Squared(Max(Radii) / Min(Radii)));
        }

        Array<PointType, 2> Foci() const noexcept
        {
            ScalarType centerOffset = Sqrt(Abs(Squared(Radii.x) - Squared(Radii.y)));
            Array<PointType, 2> foci;
            if (Radii.x >= Radii.y)
            {
                foci[0] = PointType(-centerOffset, ScalarType(0));
                foci[1] = PointType( centerOffset, ScalarType(0));
            }
            else
            {
                foci[0] = PointType(ScalarType(0), -centerOffset);
                foci[1] = PointType(ScalarType(0),  centerOffset);
            }

            Transform2T<T> rotation = Rotate(Angle);
            foci[0] = Center + rotation * VectorType(foci[0]);
            foci[1] = Center + rotation * VectorType(foci[1]);
            return foci;
        }

        [[nodiscard]] constexpr
        ScalarType Area() const noexcept
        {
            return Constant::Pi<ScalarType> * Radii.x * Radii.y;
        }

        [[nodiscard]] constexpr
        ScalarType Perimeter() const noexcept
        {
            // Ramanujan's approximation
            ScalarType h = Squared(Radii.x - Radii.y) / Squared(Radii.x + Radii.y);
            return Constant::Pi<ScalarType> * (Radii.x + Radii.y)
                * (ScalarType(1) + (ScalarType(3) * h) / (ScalarType(10) + Sqrt(ScalarType(4) - ScalarType(3) * h)));
        }

        [[nodiscard]] constexpr
        PointType Centroid() const noexcept
        {
            return Center;
        }

        PointType  Center;
        VectorType Radii;
        ScalarType Angle;
    };



    template <Concept::StrongFloatType T>
    struct Interval
    {
    public:
        using ScalarType = T;

        [[nodiscard]] constexpr
        Interval(ScalarType min, ScalarType max) noexcept
            : Min(min), Max(max)
        {}

        ScalarType Min;
        ScalarType Max;
    };

    template <Concept::StrongFloatType T>
    struct Ray
    {
    public:
        using ScalarType = T;
        using PointType  = Point<T>;
        using VectorType = Vector2T<T>;

        [[nodiscard]] constexpr
        Ray(const PointType& origin, const VectorType& direction) noexcept
            : Origin(origin), Direction(Normalize(direction))
        {}

        [[nodiscard]] constexpr
        PointType Project(ScalarType scale)
        {
            return Origin + (scale * Direction);
        }

        PointType  Origin;
        VectorType Direction;
    };
}

#endif //MATHLIB_IMPLEMENTATION_GEOMETRY_2D_SHAPES_HPP
