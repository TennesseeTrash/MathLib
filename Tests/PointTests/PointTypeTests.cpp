#include <catch2/catch_test_macros.hpp>

#include <Math/Point.hpp>

TEST_CASE("Point2f constructors", "[Point][Math]")
{
    SECTION("Default Point2f constructor")
    {
        Math::Point2f p;
        REQUIRE(Math::Equal(p.x, 0.0f));
        REQUIRE(Math::Equal(p.y, 0.0f));
    }

    SECTION("Point2f constructor with a single value")
    {
        Math::Point2f p(1.0f);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 1.0f));
    }

    SECTION("Point2f full constructor")
    {
        Math::Point2f p(1.0f, 2.0f);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
    }
}

TEST_CASE("Point3f constructors", "[Point][Math]")
{
    SECTION("Point3f default constructor")
    {
        Math::Point3f p;
        REQUIRE(Math::Equal(p.x, 0.0f));
        REQUIRE(Math::Equal(p.y, 0.0f));
        REQUIRE(Math::Equal(p.z, 0.0f));
    }

    SECTION("Point3f constructor with a single value")
    {
        Math::Point3f p(1.0f);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 1.0f));
        REQUIRE(Math::Equal(p.z, 1.0f));
    }

    SECTION("Point3f full constructor")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        REQUIRE(Math::Equal(p.x, 1.0f));
        REQUIRE(Math::Equal(p.y, 2.0f));
        REQUIRE(Math::Equal(p.z, 3.0f));
    }
}
