#include <catch2/catch_test_macros.hpp>

#include "TransformTestsCommon.hpp"
#include <Math/Point.hpp>

TEST_CASE("Test transform-point multiplication", "[Math][Transform]")
{
    SECTION("Test Transform2f * Point2f")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Point2f(1.0f, 2.0f), Math::Point2f(8.0f, 20.0f)));
    }

    SECTION("Test Transform3f * Point3f")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Point3f(1.0f, 2.0f, 3.0f), Math::Point3f(18.0f, 46.0f, 74.0f)));
    }
}
