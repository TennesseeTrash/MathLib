#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
#include <Math/Point.hpp>
#include <Math/Implementation/Functions/Equal.hpp>

TEST_CASE("Point2f-Matrix2f operators", "[Point][Math]")
{
    SECTION("Point2f * Matrix2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Matrix2f m(1.0f, 2.0f,
                         3.0f, 4.0f);
        Math::Point2f p2 = p * m;
        REQUIRE(Math::Equal(p2.x, 7.0f));
        REQUIRE(Math::Equal(p2.y, 10.0f));
    }

    SECTION("Matrix2f * Point2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Matrix2f m(1.0f, 2.0f,
                         3.0f, 4.0f);
        Math::Point2f p2 = m * p;
        REQUIRE(Math::Equal(p2.x, 5.0f));
        REQUIRE(Math::Equal(p2.y, 11.0f));
    }
}

TEST_CASE("Point2f-Matrix3f operators", "[Point][Math]")
{
    SECTION("Point2f * Matrix3f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Matrix3f m(1.0f, 2.0f, 0.0f,
                         4.0f, 5.0f, 0.0f,
                         7.0f, 8.0f, 1.0f);
        Math::Point2f p2 = p * m;
        REQUIRE(Math::Equal(p2.x, 16.0f));
        REQUIRE(Math::Equal(p2.y, 20.0f));
    }

    SECTION("Matrix3f * Point2f")
    {
        Math::Point2f p(1.0f, 2.0f);
        Math::Matrix3f m(1.0f, 2.0f, 3.0f,
                         4.0f, 5.0f, 6.0f,
                         0.0f, 0.0f, 1.0f);
        Math::Point2f p2 = m * p;
        REQUIRE(Math::Equal(p2.x,  8.0f));
        REQUIRE(Math::Equal(p2.y, 20.0f));
    }
}

TEST_CASE("Point3f-Matrix3f operators", "[Point][Math]")
{
    SECTION("Point3f * Matrix3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Matrix3f m(1.0f, 2.0f, 3.0f,
                         4.0f, 5.0f, 6.0f,
                         7.0f, 8.0f, 9.0f);
        Math::Point3f p2 = p * m;
        REQUIRE(Math::Equal(p2.x, 30.0f));
        REQUIRE(Math::Equal(p2.y, 36.0f));
        REQUIRE(Math::Equal(p2.z, 42.0f));
    }

    SECTION("Matrix3f * Point3f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Matrix3f m(1.0f, 2.0f, 3.0f,
                         4.0f, 5.0f, 6.0f,
                         7.0f, 8.0f, 9.0f);
        Math::Point3f p2 = m * p;
        REQUIRE(Math::Equal(p2.x, 14.0f));
        REQUIRE(Math::Equal(p2.y, 32.0f));
        REQUIRE(Math::Equal(p2.z, 50.0f));
    }
}

TEST_CASE("Point3f-Matrix4f operators", "[Point][Math]")
{
    SECTION("Point3f * Matrix4f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Matrix4f m( 1.0f,  2.0f,  3.0f, 0.0f,
                          5.0f,  6.0f,  7.0f, 0.0f,
                          9.0f, 10.0f, 11.0f, 0.0f,
                         13.0f, 14.0f, 15.0f, 1.0f);
        Math::Point3f p2 = p * m;
        REQUIRE(Math::Equal(p2.x,  51.0f));
        REQUIRE(Math::Equal(p2.y,  58.0f));
        REQUIRE(Math::Equal(p2.z,  65.0f));
    }

    SECTION("Point3f * Matrix4f")
    {
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Matrix4f m( 1.0f,  2.0f,  3.0f,  4.0f,
                          5.0f,  6.0f,  7.0f,  8.0f,
                          9.0f, 10.0f, 11.0f, 12.0f,
                          0.0f,  0.0f,  0.0f,  1.0f);
        Math::Point3f p2 = m * p;
        REQUIRE(Math::Equal(p2.x,  18.0f));
        REQUIRE(Math::Equal(p2.y,  46.0f));
        REQUIRE(Math::Equal(p2.z,  74.0f));
    }
}
