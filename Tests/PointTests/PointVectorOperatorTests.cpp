#include <catch2/catch_test_macros.hpp>

#include <Math/Point.hpp>
#include <Math/Vector.hpp>

TEST_CASE("Point2f-Vector2f operators", "[Point][Math]")
{
    SECTION("Point2f + Vector2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        Math::Point2f p2 = p + v;
        REQUIRE(Math::Equal(p2.x, 4.0f));
        REQUIRE(Math::Equal(p2.y, 6.0f));
    }

    SECTION("Vector2f + Point2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        Math::Point2f p2 = v + p;
        REQUIRE(Math::Equal(p2.x, 4.0f));
        REQUIRE(Math::Equal(p2.y, 6.0f));
    }

    SECTION("Point2f - Vector2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        Math::Point2f p2 = p - v;
        REQUIRE(Math::Equal(p2.x, -2.0f));
        REQUIRE(Math::Equal(p2.y, -2.0f));
    }

    SECTION("Vector2f - Point2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        Math::Point2f p2 = v - p;
        REQUIRE(Math::Equal(p2.x, 2.0f));
        REQUIRE(Math::Equal(p2.y, 2.0f));
    }

    SECTION("Point2f += Vector2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        p += v;
        REQUIRE(Math::Equal(p.x, 4.0f));
        REQUIRE(Math::Equal(p.y, 6.0f));
    }

    SECTION("Point2f -= Vector2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(3.0f, 4.0f);
        p -= v;
        REQUIRE(Math::Equal(p.x, -2.0f));
        REQUIRE(Math::Equal(p.y, -2.0f));
    }
}

TEST_CASE("Point3f-Vector3f operators")
{
    SECTION("Point3f + Vector3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        Math::Point3f p2 = p + v;
        REQUIRE(Math::Equal(p2.x, 5.0f));
        REQUIRE(Math::Equal(p2.y, 7.0f));
        REQUIRE(Math::Equal(p2.z, 9.0f));
    }

    SECTION("Vector3f + Point3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        Math::Point3f p2 = v + p;
        REQUIRE(Math::Equal(p2.x, 5.0f));
        REQUIRE(Math::Equal(p2.y, 7.0f));
        REQUIRE(Math::Equal(p2.z, 9.0f));
    }

    SECTION("Point3f - Vector3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        Math::Point3f p2 = p - v;
        REQUIRE(Math::Equal(p2.x, -3.0f));
        REQUIRE(Math::Equal(p2.y, -3.0f));
        REQUIRE(Math::Equal(p2.z, -3.0f));
    }

    SECTION("Vector3f - Point3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        Math::Point3f p2 = v - p;
        REQUIRE(Math::Equal(p2.x, 3.0f));
        REQUIRE(Math::Equal(p2.y, 3.0f));
        REQUIRE(Math::Equal(p2.z, 3.0f));
    }

    SECTION("Point3f += Vector3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        p += v;
        REQUIRE(Math::Equal(p.x, 5.0f));
        REQUIRE(Math::Equal(p.y, 7.0f));
        REQUIRE(Math::Equal(p.z, 9.0f));
    }

    SECTION("Point3f -= Vector3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(4.0f, 5.0f, 6.0f);
        p -= v;
        REQUIRE(Math::Equal(p.x, -3.0f));
        REQUIRE(Math::Equal(p.y, -3.0f));
        REQUIRE(Math::Equal(p.z, -3.0f));
    }
}
