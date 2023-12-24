#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using f32 = Math::f32;
static constexpr f32 pi = Math::Constant::Pi<f32>;
using Math::ToRadians;
using Math::ToDegrees;
using Math::Equal;

TEST_CASE("Test ToRadians conversion", "[Math][Functions]")
{
    SECTION("Test ToRadians with f32")
    {
        REQUIRE(Equal(ToRadians(f32(0.0f)), 0.0f));
        REQUIRE(Equal(ToRadians(f32(45.0f)), pi / 4.0f));
        REQUIRE(Equal(ToRadians(f32(90.0f)), pi / 2.0f));
        REQUIRE(Equal(ToRadians(f32(135.0f)), pi * 3.0f / 4.0f));
        REQUIRE(Equal(ToRadians(f32(180.0f)), pi));
        REQUIRE(Equal(ToRadians(f32(225.0f)), pi * 5.0f / 4.0f));
        REQUIRE(Equal(ToRadians(f32(270.0f)), pi * 3.0f / 2.0f));
        REQUIRE(Equal(ToRadians(f32(315.0f)), pi * 7.0f / 4.0f));
        REQUIRE(Equal(ToRadians(f32(360.0f)), pi * 2.0f));
    }

    SECTION("Test ToRadians with float")
    {
        REQUIRE(Equal(ToRadians(0.0f), 0.0f));
        REQUIRE(Equal(ToRadians(45.0f), pi / 4.0f));
        REQUIRE(Equal(ToRadians(90.0f), pi / 2.0f));
        REQUIRE(Equal(ToRadians(135.0f), pi * 3.0f / 4.0f));
        REQUIRE(Equal(ToRadians(180.0f), pi));
        REQUIRE(Equal(ToRadians(225.0f), pi * 5.0f / 4.0f));
        REQUIRE(Equal(ToRadians(270.0f), pi * 3.0f / 2.0f));
        REQUIRE(Equal(ToRadians(315.0f), pi * 7.0f / 4.0f));
        REQUIRE(Equal(ToRadians(360.0f), pi * 2.0f));
    }
}

TEST_CASE("Test ToDegrees conversion", "[Math][Functions]")
{
    SECTION("Test ToDegrees with f32")
    {
        REQUIRE(Equal(ToDegrees(f32(0.0f)), 0.0f));
        REQUIRE(Equal(ToDegrees(f32(pi / 4.0f)), 45.0f));
        REQUIRE(Equal(ToDegrees(f32(pi / 2.0f)), 90.0f));
        REQUIRE(Equal(ToDegrees(f32(pi * 3.0f / 4.0f)), 135.0f));
        REQUIRE(Equal(ToDegrees(f32(pi)), 180.0f));
        REQUIRE(Equal(ToDegrees(f32(pi * 5.0f / 4.0f)), 225.0f));
        REQUIRE(Equal(ToDegrees(f32(pi * 3.0f / 2.0f)), 270.0f));
        REQUIRE(Equal(ToDegrees(f32(pi * 7.0f / 4.0f)), 315.0f));
        REQUIRE(Equal(ToDegrees(f32(pi * 2.0f)), 360.0f));
    }

    SECTION("Test ToDegrees with float")
    {
        REQUIRE(Equal(ToDegrees(0.0f), 0.0f));
        REQUIRE(Equal(ToDegrees(pi / 4.0f), 45.0f));
        REQUIRE(Equal(ToDegrees(pi / 2.0f), 90.0f));
        REQUIRE(Equal(ToDegrees(pi * 3.0f / 4.0f), 135.0f));
        REQUIRE(Equal(ToDegrees(pi), 180.0f));
        REQUIRE(Equal(ToDegrees(pi * 5.0f / 4.0f), 225.0f));
        REQUIRE(Equal(ToDegrees(pi * 3.0f / 2.0f), 270.0f));
        REQUIRE(Equal(ToDegrees(pi * 7.0f / 4.0f), 315.0f));
        REQUIRE(Equal(ToDegrees(pi * 2.0f), 360.0f));
    }
}
