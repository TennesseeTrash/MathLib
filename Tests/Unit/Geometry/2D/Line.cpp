#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;
using namespace Math::Geometry2D;

TEST_CASE("Test Line Contains Functions", "[Math][Geometry][Line]")
{
    SECTION("Line Contains Point")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Point<f32> point1(3.0f, 3.0f);
        Point<f32> point2(3.0f, 3.2f);

        REQUIRE(Math::Geometry2D::Contains(line, point1));
        REQUIRE_FALSE(Math::Geometry2D::Contains(line, point2));
    }

    SECTION("Line Contains Line")
    {
        Line<f32> line1(Point<f32>(0, 0), Point<f32>(5, 5));
        Line<f32> line2(Point<f32>(1, 1), Point<f32>(4, 4));
        Line<f32> line3(Point<f32>(0, 0), Point<f32>(5.1f, 5.1f));

        REQUIRE(Math::Geometry2D::Contains(line1, line1));
        REQUIRE(Math::Geometry2D::Contains(line1, line2));
        REQUIRE_FALSE(Math::Geometry2D::Contains(line1, line3));
    }

    SECTION("Line Contains Circle")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Circle<f32> circle1(Point<f32>(0, 0), 0);
        Circle<f32> circle2(Point<f32>(0, 1), 1);

        REQUIRE(Contains(line, circle1));
        REQUIRE_FALSE(Contains(line, circle2));
    }

    SECTION("Line Contains Triangle")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Triangle<f32> triangle1(Point<f32>(0, 0), Point<f32>(3, 3), Point<f32>(5, 5));
        Triangle<f32> triangle2(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(0, 5.1f));

        REQUIRE(Contains(line, triangle1));
        REQUIRE_FALSE(Contains(line, triangle2));
    }

    SECTION("Line Contains Rectangle")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Rectangle<f32> rectangle1(Point<f32>(3, 3), Point<f32>(3, 3));
        Rectangle<f32> rectangle2(Point<f32>(0, 0), Point<f32>(5, 5));

        REQUIRE(Contains(line, rectangle1));
        REQUIRE_FALSE(Contains(line, rectangle2));
    }

    SECTION("Line Contains Quadrilateral")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Quadrilateral<f32> quadrilateral1(Point<f32>(0, 0), Point<f32>(5, 5), Point<f32>(3, 3), Point<f32>(2, 2));
        Quadrilateral<f32> quadrilateral2(Point<f32>(0, 0), Point<f32>(5, 5), Point<f32>(5, 0), Point<f32>(0, 5.1f));

        REQUIRE(Contains(line, quadrilateral1));
        REQUIRE_FALSE(Contains(line, quadrilateral2));
    }

    SECTION("Line Contains Ellipse")
    {
        Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
        Ellipse<f32> ellipse1(Point<f32>(0, 0), {0, 0}, 0);
        Ellipse<f32> ellipse2(Point<f32>(0, 0), {1, 1}, 0);

        REQUIRE(Contains(line, ellipse1));
        REQUIRE_FALSE(Contains(line, ellipse2));
    }
}
