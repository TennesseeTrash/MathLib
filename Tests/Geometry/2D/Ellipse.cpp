#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;

TEST_CASE("Point in Ellipse", "[Math][Geometry][Ellipse]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Ellipse;

    Ellipse<f32> ellipse(Point<f32>(3, 15), {2.0f, 1.0f}, Math::Constant::Pi<f32>);
    Point<f32> point1(3.0f, 15.9f);
    Point<f32> point2(3.0f, 13.9f);

    REQUIRE(Math::Geometry2D::Contains(ellipse, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(ellipse, point2));
}
