#include <catch2/catch_test_macros.hpp>
#include <Math/Geometry.hpp>

using Math::f32;
using Math::Vector2f;

TEST_CASE("Point on Ray", "[Math][Geometry][Ray]")
{
    using Math::Geometry2D::Point;
    using Math::Geometry2D::Ray;

    Ray<f32> ray(Point<f32>(0, 0), Vector2f(1, 1));
    Point<f32> point1(3.0f, 3.0f);
    Point<f32> point2(3.0f, 3.1f);

    REQUIRE(Math::Geometry2D::Contains(ray, point1));
    REQUIRE_FALSE(Math::Geometry2D::Contains(ray, point2));
}
