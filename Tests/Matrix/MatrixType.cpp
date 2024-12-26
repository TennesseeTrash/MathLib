#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
// TODO: Remove vvv
#include <Math/Vector.hpp>
#include <Math/Implementation/Functions/Equal.hpp>

TEST_CASE("Check default constructors", "[Math][Matrix]")
{
    SECTION("Matrix2f default constructor")
    {
        Math::Matrix2f m;

        REQUIRE(Math::Equal(m[0], Math::Vector2f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(0.0f)));
    }

    SECTION("Matrix3f default constructor")
    {
        Math::Matrix3f m;

        REQUIRE(Math::Equal(m[0], Math::Vector3f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(0.0f)));
    }

    SECTION("Matrix4f default constructor")
    {
        Math::Matrix4f m;

        REQUIRE(Math::Equal(m[0], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(0.0f)));
    }
}

TEST_CASE("Check diagonal constructor", "[Math][Matrix]")
{
    SECTION("Matrix2f diagonal constructor")
    {
        Math::Matrix2f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector2f(1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(0.0f, 1.0f)));
    }

    SECTION("Matrix3f diagonal constructor")
    {
        Math::Matrix3f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector3f(1.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(0.0f, 0.0f, 1.0f)));
    }

    SECTION("Matrix4f diagonal constructor")
    {
        Math::Matrix4f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector4f(1.0f, 0.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f(0.0f, 1.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f(0.0f, 0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(0.0f, 0.0f, 0.0f, 1.0f)));
    }
}

TEST_CASE("Check full constructors", "[Math][Matrix]")
{
    SECTION("Matrix2f full constructor")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();

        REQUIRE(Math::Equal(m[0], Math::Vector2f(1.0f, 2.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(3.0f, 4.0f)));
    }

    SECTION("Matrix3f full constructor")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();

        REQUIRE(Math::Equal(m[0], Math::Vector3f(1.0f, 2.0f, 3.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(4.0f, 5.0f, 6.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(7.0f, 8.0f, 9.0f)));
    }

    SECTION("Matrix4f full constructor")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();

        REQUIRE(Math::Equal(m[0], Math::Vector4f( 1.0f,  2.0f,  3.0f,  4.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f( 5.0f,  6.0f,  7.0f,  8.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f( 9.0f, 10.0f, 11.0f, 12.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(13.0f, 14.0f, 15.0f, 16.0f)));
    }
}
