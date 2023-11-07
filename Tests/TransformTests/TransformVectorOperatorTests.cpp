#include <catch2/catch_test_macros.hpp>

#include "TransformTestsCommon.hpp"
#include <Math/Vector.hpp>

TEST_CASE("Test transform-vector multiplication", "[Math][Transform]")
{
    SECTION("Test Transform2f with Vector2f and Vector3f")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Vector2f(1.0f, 2.0f), Math::Vector2f(5.0f, 14.0f)));
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Vector3f(1.0f, 2.0f, 3.0f), Math::Vector3f(14.0f, 32.0f, 3.0f)));
    }

    SECTION("Test Transform3f with Vector3f and Vector4f")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Vector3f(1.0f, 2.0f, 3.0f), Math::Vector3f(14.0f, 38.0f, 62.0f)));
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f), Math::Vector4f(30.0f, 70.0f, 110.0f, 4.0f)));
    }
}
