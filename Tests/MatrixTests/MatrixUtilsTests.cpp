#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"

TEST_CASE("Check determinant calculations", "[Math][Matrix]")
{
    SECTION("Matrix2f determinant")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        REQUIRE(Math::Equal(Math::Determinant(m1), -2.0f));

        Math::Matrix2f m2(
            5.0f,  1.0f,
            8.0f, -9.0f);
        REQUIRE(Math::Equal(Math::Determinant(m2), -53.0f));
    }

    SECTION("Matrix3f determinant")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        REQUIRE(Math::Equal(Math::Determinant(m1), 0.0f));

        Math::Matrix3f m2(
             5.0f,  1.0f, 0.0f,
            -9.0f,  1.0f, 8.0f,
            11.0f, 19.0f, 2.0f);
        REQUIRE(Math::Equal(Math::Determinant(m2), -644.0f));
    }

    SECTION("Matrix4f determinant")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        REQUIRE(Math::Equal(Math::Determinant(m1), 0.0f));

        Math::Matrix4f m2(
            5.0f,   1.0f, 0.0f,  6.0f,
            8.0f,   7.0f, 5.0f, -9.0f,
            1.0f, -52.0f, 6.0f, 65.0f,
            0.0f,   9.0f, 3.0f,  1.0f);
        REQUIRE(Math::Equal(Math::Determinant(m2), 30240.0f));
    }
}

TEST_CASE("Check inverse calculations", "[Math][Matrix]")
{
    SECTION("Matrix2f inverse")
    {
        Math::Matrix2f m(48.0f, -0.34f,
                         1.05f, 12.43f);

        Math::Matrix2f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix2f(1.0f)));
    }

    SECTION("Matrix3f inverse")
    {
        Math::Matrix3f m(48.0f, -0.34f, 0.34f,
                         1.05f, 12.43f, 0.12f,
                         13.0f, -0.21f, -65.01f);

        Math::Matrix3f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix3f(1.0f)));
    }

    SECTION("Matrix4f inverse")
    {
        Math::Matrix4f m(48.0f, -0.34f, 0.34f,     0.0f,
                         1.05f, 12.43f, 0.12f,   -34.0f,
                         13.0f, -0.21f, -65.01f, -0.001f,
                         0.01f, -0.23f, -0.11f,   -0.45f);

        Math::Matrix4f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix4f(1.0f), 1.0e-5f));
    }
}
