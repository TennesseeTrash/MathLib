#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;
using namespace Math::Geometry2D;

TEST_CASE("Test Circle Contains functions", "[Math][Geometry][Circle]")
{
    SECTION("Circle Contains Point")
    {
        Circle<f32> circle(Point<f32>(0, 0), 5);
        Point<f32> point1(3, 4);
        Point<f32> point2(0, 5.1f);

        REQUIRE(Contains(circle, point1));
        REQUIRE_FALSE(Contains(circle, point2));
    }

    SECTION("Circle Contains Line")
    {
        Circle<f32> circle(Point<f32>(0, 0), 5);
        Line<f32> line1(Point<f32>(0, 0), Point<f32>(3, 4));
        Line<f32> line2(Point<f32>(0, 0), Point<f32>(0, 5.1f));

        REQUIRE(Contains(circle, line1));
        REQUIRE_FALSE(Contains(circle, line2));
    }

    SECTION("Circle Contains Circle")
    {
        Circle<f32> circle1(Point<f32>(0, 0), 5);
        Circle<f32> circle2(Point<f32>(0, 2), 3);
        Circle<f32> circle3(Point<f32>(0, 1), 5.1f);
        Circle<f32> circle4(Point<f32>(1, 2), 2.5f);

        REQUIRE(Contains(circle1, circle2));
        REQUIRE_FALSE(Contains(circle1, circle3));
        REQUIRE(Contains(circle1, circle4));
    }

    SECTION("Circle Contains Triangle")
    {
        Circle<f32> circle(Point<f32>(1, 2), 5);
        Triangle<f32> triangle1(Point<f32>(-1, -1), Point<f32>(3, 4), Point<f32>(0, 3));
        Triangle<f32> triangle2(Point<f32>(-5, -5), Point<f32>(0, -2), Point<f32>(-7, 5));

        REQUIRE(Contains(circle, triangle1));
        REQUIRE_FALSE(Contains(circle, triangle2));
    }

    SECTION("Circle Contains Rectangle")
    {
        Circle<f32> circle(Point<f32>(1, 2), 5);
        Rectangle<f32> rectangle1(Point<f32>(-1, -1), Point<f32>(3, 4));
        Rectangle<f32> rectangle2(Point<f32>(-5, -5), Point<f32>(0, -2));

        REQUIRE(Contains(circle, rectangle1));
        REQUIRE_FALSE(Contains(circle, rectangle2));
    }

    SECTION("Circle Contains Quadrilateral")
    {
        Circle<f32> circle(Point<f32>(1, 2), 5);
        Quadrilateral<f32> quad1(Point<f32>(-1, -1), Point<f32>(3, 4), Point<f32>(0, 3), Point<f32>(-1, 3));
        Quadrilateral<f32> quad2(Point<f32>(-5, -5), Point<f32>(0, -2), Point<f32>(-7, 5), Point<f32>(-5, 5));

        REQUIRE(Contains(circle, quad1));
        REQUIRE_FALSE(Contains(circle, quad2));
    }

    SECTION("Circle Contains Ellipse")
    {
        // NOT IMPLEMENTED
        //Circle<f32> circle(Point<f32>(1, 2), 5);
        //Ellipse<f32> ellipse1(Point<f32>(-1, -1), {3, 2}, Math::Constant::Pi<f32>);
        //Ellipse<f32> ellipse2(Point<f32>(-5, -5), {3, 2}, Math::Constant::Pi<f32>);
        //
        //REQUIRE(Contains(circle, ellipse1));
        //REQUIRE_FALSE(Contains(circle, ellipse2));
    }
}
