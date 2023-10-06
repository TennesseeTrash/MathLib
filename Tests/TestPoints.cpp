#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Matrix.hpp>
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
