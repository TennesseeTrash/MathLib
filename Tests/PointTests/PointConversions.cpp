#include <catch2/catch_test_macros.hpp>

#include <Math/Point.hpp>
#include <Math/Vector.hpp>
#include <Math/Implementation/Functions/Equal.hpp>

TEST_CASE("Conversion constructors", "[Point][Math]")
{
    SECTION("Point2f to Point3f")
    {
        Math::Point2f p1(1.0f, 2.0f);
        Math::Point3f p2(p1);
        REQUIRE(Math::Equal(p2.x, 1.0f));
        REQUIRE(Math::Equal(p2.y, 2.0f));
        REQUIRE(Math::Equal(p2.z, 0.0f));
    }

    SECTION("Point2f to Point3f with z value")
    {
        Math::Point2f p1(1.0f, 2.0f);
        Math::Point3f p2(p1, 3.0f);
        REQUIRE(Math::Equal(p2.x, 1.0f));
        REQUIRE(Math::Equal(p2.y, 2.0f));
        REQUIRE(Math::Equal(p2.z, 3.0f));
    }

    SECTION("Point2f from Vector2f")
    {
        Math::Vector2f v(1.0f, 2.0f);
        Math::Point2f p(v);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
    }

    SECTION("Vector2f from Point2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(p);
        REQUIRE(Math::Equal(v.x, 1.0f));
        REQUIRE(Math::Equal(v.y, 2.0f));
    }

    SECTION("Point3f from Vector2f")
    {
        Math::Vector2f v(1.0f, 2.0f);
        Math::Point3f p(v);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
        REQUIRE(Math::Equal(p.z, 0.0f));
    }

    SECTION("Point3f from Vector2f with z value")
    {
        Math::Vector2f v(1.0f, 2.0f);
        Math::Point3f p(v, 3.0f);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
        REQUIRE(Math::Equal(p.z, 3.0f));
    }

    SECTION("Point3f from Vector3f")
    {
        Math::Vector3f v(1.0f, 2.0f, 3.0f);
        Math::Point3f p(v);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
        REQUIRE(Math::Equal(p.z, 3.0f));
    }
}
