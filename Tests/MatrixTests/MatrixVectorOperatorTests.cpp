#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
#include <Math/Vector.hpp>

TEST_CASE("Test matrix vector multiplication", "[Math][Matrix]")
{
    SECTION("Matrix2f * Vector2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Vector2f v(1.0f, 2.0f);
        Math::Vector2f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector2f(5.0f, 11.0f)));
    }

    SECTION("Vector2f * Matrix2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Vector2f v(1.0f, 2.0f);
        Math::Vector2f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector2f(7.0f, 10.0f)));
    }

    SECTION("Matrix3f * Vector3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Vector3f v(1.0f, 2.0f, 3.0f);
        Math::Vector3f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector3f(14.0f, 32.0f, 50.0f)));
    }

    SECTION("Vector3f * Matrix3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Vector3f v(1.0f, 2.0f, 3.0f);
        Math::Vector3f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector3f(30.0f, 36.0f, 42.0f)));
    }

    SECTION("Matrix4f * Vector4f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector4f(30.0f, 70.0f, 110.0f, 150.0f)));
    }

    SECTION("Vector4f * Matrix4f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector4f(90.0f, 100.0f, 110.0f, 120.0f)));
    }
}
