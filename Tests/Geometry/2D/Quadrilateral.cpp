#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;

TEST_CASE("Point in Quadrilateral", "[Math][Geometry][Quadrilateral]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Quadrilateral;

    Quadrilateral<f32> quadrilateral(Point<f32>(0, 0), Point<f32>(5, 0), Point<f32>(5, 5), Point<f32>(0, 5));
    Point<f32> point1(3.0f, 3.0f);
    Point<f32> point2(5.0f, 5.1f);

    REQUIRE(Math::Geometry2D::Contains(quadrilateral, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(quadrilateral, point2));
}
