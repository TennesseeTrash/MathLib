#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;
using namespace Math::Geometry2D;
namespace C = Math::Constant;

TEST_CASE("Test Triangle Contains Functions", "[Math][Geometry][Triangle]")
{
    SECTION("Triangle Contains Point")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Point<f32> point1(3, 3);
        Point<f32> point2(3, 5.1f);

        REQUIRE(Contains(triangle, point1));
        REQUIRE_FALSE(Contains(triangle, point2));
    }

    SECTION("Triangle Contains Line")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Line<f32> line1(Point<f32>(0, 0), Point<f32>(3, 3));
        Line<f32> line2(Point<f32>(0, 0), Point<f32>(5, 5.1f));

        REQUIRE(Contains(triangle, line1));
        REQUIRE_FALSE(Contains(triangle, line2));
    }

    SECTION("Triangle Contains Circle")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Circle<f32> circle1(Point<f32>(4, 1), 1);
        Circle<f32> circle2(Point<f32>(2, 1), 1);

        REQUIRE(Contains(triangle, circle1));
        REQUIRE_FALSE(Contains(triangle, circle2));
    }

    SECTION("Triangle Contains Triangle")
    {
        Triangle<f32> triangle1(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Triangle<f32> triangle2(Point<f32>(1, 1), Point<f32>(4, 1), Point<f32>(4, 4));
        Triangle<f32> triangle3(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(0, 5.1f));

        REQUIRE(Contains(triangle1, triangle1));
        REQUIRE(Contains(triangle1, triangle2));
        REQUIRE_FALSE(Contains(triangle1, triangle3));
    }

    SECTION("Triangle Contains Rectangle")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Rectangle<f32> rectangle1(Point<f32>(3, 0), Point<f32>(4, 3));
        Rectangle<f32> rectangle2(Point<f32>(0, 0), Point<f32>(5, 5));

        REQUIRE(Contains(triangle, rectangle1));
        REQUIRE_FALSE(Contains(triangle, rectangle2));
    }

    SECTION("Triangle Contains Quadrilateral")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Quadrilateral<f32> quadrilateral1(Point<f32>(1, 0), Point<f32>(4, 0), Point<f32>(4, 4), Point<f32>(3, 3));
        Quadrilateral<f32> quadrilateral2(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5.1f), Point<f32>(0, 5));

        REQUIRE(Contains(triangle, quadrilateral1));
        REQUIRE_FALSE(Contains(triangle, quadrilateral2));
    }

    SECTION("Triangle Contains Ellipse")
    {
        Triangle<f32> triangle(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5));
        Ellipse<f32> ellipse1(Point<f32>(3, 1), {1.0f, 0.5f}, C::Pi<f32> / 4);
        Ellipse<f32> ellipse2(Point<f32>(2, 1), {1.0f, 0.5f}, 0);

        REQUIRE(Contains(triangle, ellipse1));
        REQUIRE_FALSE(Contains(triangle, ellipse2));
    }
}
