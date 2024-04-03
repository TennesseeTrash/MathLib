#include <catch2/catch_test_macros.hpp>

#include "TransformTestsCommon.hpp"
#include <Math/Matrix.hpp>

TEST_CASE("Test ToMatrix member function", "[Math][Transform]")
{
    SECTION("Transform2f::ToMatrix")
    {
        REQUIRE(Math::Equal(MakeTransform2f1().ToMatrix(), Math::Matrix3f(
            1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            0.0f, 0.0f, 1.0f
        )));
    }

    SECTION("Transform3f::ToMatrix")
    {
        REQUIRE(Math::Equal(MakeTransform3f1().ToMatrix(), Math::Matrix4f(
            1.0f,  2.0f,  3.0f,  4.0f,
            5.0f,  6.0f,  7.0f,  8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            0.0f,  0.0f,  0.0f,  1.0f
        )));
    }
}
