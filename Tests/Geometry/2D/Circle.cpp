#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;

TEST_CASE("Point in Circle", "[Math][Geometry][Circle]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Circle;

    Circle<f32> circle(Point<f32>(0, 0), 5);
    Point<f32> point1(3, 4);
    Point<f32> point2(0, 5.1f);

    REQUIRE(Math::Geometry2D::Contains(circle, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(circle, point2));
}
