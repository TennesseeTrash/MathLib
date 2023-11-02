#include <catch2/catch_test_macros.hpp>

#include "MatrixTestsCommon.hpp"
// TODO(3011): Remove vvv
#include <Math/Vector.hpp>
#include <Math/Point.hpp>

TEST_CASE("Test matrix point multiplication")
{
    SECTION("Matrix2f * Point2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(1.0f, 2.0f);

        REQUIRE(Math::Equal(Math::Vector2f(m * p), m * v));
    }

    SECTION("Point2f * Matrix2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector2f v(1.0f, 2.0f);

        REQUIRE(Math::Equal(Math::Vector2f(p * m), v * m));
    }

    SECTION("Matrix3f * Point2f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector3f v(1.0f, 2.0f, 1.0f);
        v = m * v;
        v /= v.z;

        REQUIRE(Math::Equal(Math::Vector3f(m * p), v));
    }

    SECTION("Point2f * Matrix3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Point2f p(1.0f, 2.0f);
        Math::Vector3f v(1.0f, 2.0f, 1.0f);
        v = v * m;
        v /= v.z;

        REQUIRE(Math::Equal(Math::Vector3f(p * m), v));
    }

    SECTION("Matrix3f * Point3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(1.0f, 2.0f, 3.0f);

        REQUIRE(Math::Equal(Math::Vector3f(m * p), m * v));
    }

    SECTION("Point3f * Matrix3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector3f v(1.0f, 2.0f, 3.0f);

        REQUIRE(Math::Equal(Math::Vector3f(p * m), v * m));
    }

    SECTION("Matrix4f * Point3f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 1.0f);
        v = m * v;
        v /= v.w;

        REQUIRE(Math::Equal(Math::Vector4f(m * p), v));
    }

    SECTION("Point3f * Matrix4f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Point3f p(1.0f, 2.0f, 3.0f);
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 1.0f);
        v = v * m;
        v /= v.w;

        REQUIRE(Math::Equal(Math::Vector4f(p * m), v));
    }
}
