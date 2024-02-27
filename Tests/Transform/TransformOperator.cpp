#include <catch2/catch_test_macros.hpp>

#include "TransformTestsCommon.hpp"

TEST_CASE("Test transform multiplication", "[Math][Transform]")
{
    SECTION("Transform2f multiplication")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * MakeTransform2f2(), MakeTransform2f3()));
    }

    SECTION("Transform3f multiplication")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * MakeTransform3f2(), MakeTransform3f3()));
    }

    SECTION("Transform2f mutable multiplication")
    {
        auto t1 = MakeTransform2f1();
        t1 *= MakeTransform2f2();
        REQUIRE(Math::Equal(t1, MakeTransform2f3()));
    }

    SECTION("Transform3f mutable multiplication")
    {
        auto t1 = MakeTransform3f1();
        t1 *= MakeTransform3f2();
        REQUIRE(Math::Equal(t1, MakeTransform3f3()));
    }
}
