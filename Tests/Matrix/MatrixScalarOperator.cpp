#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
// TODO: Remove vvv
#include <Math/Vector.hpp>
#include <Math/Implementation/Functions/Equal.hpp>

TEST_CASE("Test scalar addition operators", "[Math][Matrix]")
{
    SECTION("Scalar + Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f + m1;

        REQUIRE(Math::Equal(m2[0], 5.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f + m1[1]));
    }

    SECTION("Matrix2f + Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 + 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 5.0f));
    }

    SECTION("Scalar + Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f + m1;

        REQUIRE(Math::Equal(m2[0], 10.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f + m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f + m1[2]));
    }

    SECTION("Matrix3f + Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 + 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] + 10.0f));
    }

    SECTION("Matrix4f + Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 + 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] + 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] + 10.0f));
    }

    SECTION("Scalar + Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f + m1;

        REQUIRE(Math::Equal(m2[0], 10.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f + m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f + m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f + m1[3]));
    }
}

TEST_CASE("Test scalar subtraction operators", "[Math][Matrix]")
{
    SECTION("Scalar - Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f - m1;

        REQUIRE(Math::Equal(m2[0], 5.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f - m1[1]));
    }

    SECTION("Matrix2f - Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 - 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 5.0f));
    }

    SECTION("Scalar - Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f - m1;

        REQUIRE(Math::Equal(m2[0], 10.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f - m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f - m1[2]));
    }

    SECTION("Matrix3f - Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 - 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] - 10.0f));
    }

    SECTION("Matrix4f - Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 - 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] - 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] - 10.0f));
    }

    SECTION("Scalar - Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f - m1;

        REQUIRE(Math::Equal(m2[0], 10.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f - m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f - m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f - m1[3]));
    }
}

TEST_CASE("Test scalar multiplication operators", "[Math][Matrix]")
{
    SECTION("Scalar * Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f * m1;

        REQUIRE(Math::Equal(m2[0], 5.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f * m1[1]));
    }

    SECTION("Matrix2f * Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 * 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 5.0f));
    }

    SECTION("Scalar * Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f * m1;

        REQUIRE(Math::Equal(m2[0], 10.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f * m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f * m1[2]));
    }

    SECTION("Matrix3f * Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 * 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] * 10.0f));
    }

    SECTION("Matrix4f * Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 * 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] * 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] * 10.0f));
    }

    SECTION("Scalar * Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f * m1;

        REQUIRE(Math::Equal(m2[0], 10.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f * m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f * m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f * m1[3]));
    }
}
