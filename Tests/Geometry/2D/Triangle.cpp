#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;

TEST_CASE("Point in Triangle", "[Math][Geometry][Triangle]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Triangle;

    Triangle<f32> triangle(Point<f32>(8, 15), Point<f32>(25, 17), Point<f32>(3, 4));
    Point<f32> point1(7, 5);
    Point<f32> point2(3, 4.1f);

    REQUIRE(Math::Geometry2D::Contains(triangle, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(triangle, point2));
}
