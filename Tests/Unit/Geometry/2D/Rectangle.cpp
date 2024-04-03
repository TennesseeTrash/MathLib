#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;
using namespace Math::Geometry2D;

TEST_CASE("Test Rectangle Contains Functions", "[Math][Geometry][Rectangle]")
{
    SECTION("Rectangle Contains Point")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Point<f32> point1(3, 3);
        Point<f32> point2(3, 5.1f);

        REQUIRE(Contains(rectangle, point1));
        REQUIRE_FALSE(Contains(rectangle, point2));
    }

    SECTION("Rectangle Contains Line")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Line<f32> line1(Point<f32>(0, 0), Point<f32>(3, 3));
        Line<f32> line2(Point<f32>(0, 0), Point<f32>(5, 5.1f));

        REQUIRE(Contains(rectangle, line1));
        REQUIRE_FALSE(Contains(rectangle, line2));
    }

    SECTION("Rectangle Contains Circle")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Circle<f32> circle1(Point<f32>(0, 0), 0);
        Circle<f32> circle2(Point<f32>(0, 1), 5);

        REQUIRE(Contains(rectangle, circle1));
        REQUIRE_FALSE(Contains(rectangle, circle2));
    }

    SECTION("Rectangle Contains Triangle")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Triangle<f32> triangle1(Point<f32>(0, 0), Point<f32>(5, 3), Point<f32>(5, 5));
        Triangle<f32> triangle2(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5.1f));

        REQUIRE(Contains(rectangle, triangle1));
        REQUIRE_FALSE(Contains(rectangle, triangle2));
    }

    SECTION("Rectangle Contains Rectangle")
    {
        Rectangle<f32> rectangle1(Point<f32>(0, 0), Point<f32>(5, 5));
        Rectangle<f32> rectangle2(Point<f32>(3, 3), Point<f32>(3, 4));
        Rectangle<f32> rectangle3(Point<f32>(0, 0), Point<f32>(5, 5));
        Rectangle<f32> rectangle4(Point<f32>(-1, 0), Point<f32>(5, 5.1f));

        REQUIRE(Contains(rectangle1, rectangle2));
        REQUIRE(Contains(rectangle1, rectangle3));
        REQUIRE_FALSE(Contains(rectangle1, rectangle4));
    }

    SECTION("Rectangle Contains Quadrilateral")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Quadrilateral<f32> quadrilateral1(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5), Point<f32>(0, 5));
        Quadrilateral<f32> quadrilateral2(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5.1f), Point<f32>(0, 5));

        REQUIRE(Contains(rectangle, quadrilateral1));
        REQUIRE_FALSE(Contains(rectangle, quadrilateral2));
    }

    SECTION("Rectangle Contains Ellipse")
    {
        Rectangle<f32> rectangle(Point<f32>(0, 0), Point<f32>(5, 5));
        Ellipse<f32> ellipse1(Point<f32>(2, 1), {2.0f, 1.0f}, Math::Constant::Pi<f32>);
        Ellipse<f32> ellipse2(Point<f32>(0, 0), {5.1f, 2.5f}, Math::Constant::Pi<f32>);

        REQUIRE(Contains(rectangle, ellipse1));
        REQUIRE_FALSE(Contains(rectangle, ellipse2));
    }
}
