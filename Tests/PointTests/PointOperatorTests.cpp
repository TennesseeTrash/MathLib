#include <catch2/catch_test_macros.hpp>

#include <Math/Point.hpp>
#include <Math/Vector.hpp>

TEST_CASE("Point-Point operators", "[Point][Math]")
{
    SECTION("Point2f subtraction")
    {
        Math::Point2f p1(1.0f, 2.0f);
        Math::Point2f p2(3.0f, 4.0f);
        Math::Vector2f v = p1 - p2;
        REQUIRE(Math::Equal(v.x, -2.0f));
        REQUIRE(Math::Equal(v.y, -2.0f));
    }

    SECTION("Point3f subtraction")
    {
        Math::Point3f p1(1.0f, 2.0f, 3.0f);
        Math::Point3f p2(4.0f, 5.0f, 6.0f);
        Math::Vector3f v = p1 - p2;
        REQUIRE(Math::Equal(v.x, -3.0f));
        REQUIRE(Math::Equal(v.y, -3.0f));
        REQUIRE(Math::Equal(v.z, -3.0f));
    }
}
