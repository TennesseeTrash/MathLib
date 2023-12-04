#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using f32 = Math::f32;
namespace C = Math::Constants;

TEST_CASE("Test ToRadians conversion", "[Math][Functions]")
{
    SECTION("Test ToRadians with f32")
    {
        REQUIRE(Math::Equal(Math::ToRadians(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(45.0f)), C::Pi<f32> / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(90.0f)), C::Pi<f32> / 2.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(135.0f)), C::Pi<f32> * 3.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(180.0f)), C::Pi<f32>));
        REQUIRE(Math::Equal(Math::ToRadians(f32(225.0f)), C::Pi<f32> * 5.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(270.0f)), C::Pi<f32> * 3.0f / 2.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(315.0f)), C::Pi<f32> * 7.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(f32(360.0f)), C::Pi<f32> * 2.0f));
    }

    SECTION("Test ToRadians with float")
    {
        REQUIRE(Math::Equal(Math::ToRadians(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::ToRadians(45.0f), C::Pi<f32> / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(90.0f), C::Pi<f32> / 2.0f));
        REQUIRE(Math::Equal(Math::ToRadians(135.0f), C::Pi<f32> * 3.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(180.0f), C::Pi<f32>));
        REQUIRE(Math::Equal(Math::ToRadians(225.0f), C::Pi<f32> * 5.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(270.0f), C::Pi<f32> * 3.0f / 2.0f));
        REQUIRE(Math::Equal(Math::ToRadians(315.0f), C::Pi<f32> * 7.0f / 4.0f));
        REQUIRE(Math::Equal(Math::ToRadians(360.0f), C::Pi<f32> * 2.0f));
    }
}

TEST_CASE("Test ToDegrees conversion", "[Math][Functions]")
{
    SECTION("Test ToDegrees with f32")
    {
        REQUIRE(Math::Equal(Math::ToDegrees(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> / 4.0f)), 45.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> / 2.0f)), 90.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> * 3.0f / 4.0f)), 135.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32>)), 180.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> * 5.0f / 4.0f)), 225.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> * 3.0f / 2.0f)), 270.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> * 7.0f / 4.0f)), 315.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(f32(C::Pi<f32> * 2.0f)), 360.0f));
    }

    SECTION("Test ToDegrees with float")
    {
        REQUIRE(Math::Equal(Math::ToDegrees(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> / 4.0f), 45.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> / 2.0f), 90.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> * 3.0f / 4.0f), 135.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32>), 180.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> * 5.0f / 4.0f), 225.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> * 3.0f / 2.0f), 270.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> * 7.0f / 4.0f), 315.0f));
        REQUIRE(Math::Equal(Math::ToDegrees(C::Pi<f32> * 2.0f), 360.0f));
    }
}
