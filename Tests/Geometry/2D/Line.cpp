#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;

TEST_CASE("Point on Line", "[Math][Geometry][Line]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Line;

    Line<f32> line(Point<f32>(0, 0), Point<f32>(5, 5));
    Point<f32> point1(3.0f, 3.0f);
    Point<f32> point2(3.0f, 3.2f);

    REQUIRE(Math::Geometry2D::Contains(line, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(line, point2));
}
