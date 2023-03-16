#include <catch2/catch_test_macros.hpp>
#include <Math/Matrix.hpp>
#include <Math/Debug/StreamOperators.hpp>

TEST_CASE("Check inverse calculations", "[Math][Matrix]")
{
    SECTION("Matrix2f inverse")
    {
        cc::Matrix2f m(48.0f, -0.34f,
                       1.05f, 12.43f);

        cc::Matrix2f m_inverse = cc::Invert(m);

        REQUIRE(cc::Equal((m * m_inverse), cc::Matrix2f(1.0f)));
    }

    SECTION("Matrix3f inverse")
    {
        cc::Matrix3f m(48.0f, -0.34f, 0.34f,
                       1.05f, 12.43f, 0.12f,
                       13.0f, -0.21f, -65.01f);

        cc::Matrix3f m_inverse = cc::Invert(m);

        REQUIRE(cc::Equal((m * m_inverse), cc::Matrix3f(1.0f)));
    }

    SECTION("Matrix4f inverse")
    {
        cc::Matrix4f m(48.0f, -0.34f, 0.34f, 0.0f,
                       1.05f, 12.43f, 0.12f, -34.0f,
                       13.0f, -0.21f, -65.01f, -0.001f,
                       0.01f, -0.23f, -0.11f, -0.45f);

        cc::Matrix4f m_inverse = cc::Invert(m);

        REQUIRE(cc::Equal((m * m_inverse), cc::Matrix4f(1.0f)));
    }
}
