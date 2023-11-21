#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
// TODO(3011): Remove vvv
#include <Math/Vector.hpp>

TEST_CASE("Test addition operators", "[Math][Matrix]")
{
    SECTION("Matrix2f addition")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
    }

    SECTION("Matrix3f addition")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] + m2[2]));
    }

    SECTION("Matrix4f addition")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] + m2[2]));
        REQUIRE(Math::Equal(m3[3], m1[3] + m2[3]));
    }
}

TEST_CASE("Test subtraction operators", "[Math][Matrix]")
{
    SECTION("Matrix2f subtraction")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
    }

    SECTION("Matrix3f subtraction")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] - m2[2]));
    }

    SECTION("Matrix4f subtraction")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] - m2[2]));
        REQUIRE(Math::Equal(m3[3], m1[3] - m2[3]));
    }
}

TEST_CASE("Test matrix multiplication", "[Math][Matrix]")
{
    SECTION("Matrix2f multiplication")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector2f(19.0f, 22.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector2f(43.0f, 50.0f)));
    }

    SECTION("Matrix3f multiplication")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector3f( 84.0f,  90.0f,  96.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector3f(201.0f, 216.0f, 231.0f)));
        REQUIRE(Math::Equal(m3[2], Math::Vector3f(318.0f, 342.0f, 366.0f)));
    }

    SECTION("Matrix4f multiplication")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector4f( 250.0f,  260.0f,  270.0f,  280.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector4f( 618.0f,  644.0f,  670.0f,  696.0f)));
        REQUIRE(Math::Equal(m3[2], Math::Vector4f( 986.0f, 1028.0f, 1070.0f, 1112.0f)));
        REQUIRE(Math::Equal(m3[3], Math::Vector4f(1354.0f, 1412.0f, 1470.0f, 1528.0f)));
    }
}
