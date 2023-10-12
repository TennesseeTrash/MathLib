#include <catch2/catch_test_macros.hpp>
#include <Math/Common/Types.hpp>
#include <Math/Functions.hpp>

using Math::f32;
using Math::f64;
using Math::i32;

TEST_CASE("Test Sign and Abs functions", "[Math][Functions]")
{
    SECTION("Test Sign with i32")
    {
        REQUIRE(Math::Sign(i32(0)) == 0);
        REQUIRE(Math::Sign(i32(5)) == 1);
        REQUIRE(Math::Sign(i32(-5)) == -1);
    }

    SECTION("Test Sign with std::int32_t")
    {
        REQUIRE(Math::Sign(std::int32_t(0)) == 0);
        REQUIRE(Math::Sign(std::int32_t(5)) == 1);
        REQUIRE(Math::Sign(std::int32_t(-5)) == -1);
    }

    SECTION("Test Sign with f32")
    {
        REQUIRE(Math::Equal(Math::Sign(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Sign(f32(5.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Sign(f32(-5.0f)), -1.0f));
    }

    SECTION("Test Sign with float")
    {
        REQUIRE(Math::Equal(Math::Sign(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Sign(5.0f), 1.0f));
        REQUIRE(Math::Equal(Math::Sign(-5.0f), -1.0f));
    }

    SECTION("Test Abs with i32")
    {
        REQUIRE(Math::Abs(i32(0)) == 0);
        REQUIRE(Math::Abs(i32(1)) == 1);
        REQUIRE(Math::Abs(i32(-1)) == 1);
    }

    SECTION("Test Abs with std::int32_t")
    {
        REQUIRE(Math::Abs(std::int32_t(0)) == 0);
        REQUIRE(Math::Abs(std::int32_t(1)) == 1);
        REQUIRE(Math::Abs(std::int32_t(-1)) == 1);
    }

    SECTION("Test Abs with f32")
    {
        REQUIRE(Math::Equal(Math::Abs(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Abs(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Abs(f32(-1.0f)), 1.0f));
    }

    SECTION("Test Abs with float")
    {
        REQUIRE(Math::Equal(Math::Abs(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Abs(1.0f), 1.0f));
        REQUIRE(Math::Equal(Math::Abs(-1.0f), 1.0f));
    }
}

TEST_CASE("Test Squared and Cubed functions", "[Math][Functions]")
{
    SECTION("Test Squared with i32")
    {
        REQUIRE(Math::Squared(i32(0)) == 0);
        REQUIRE(Math::Squared(i32(1)) == 1);
        REQUIRE(Math::Squared(i32(2)) == 4);
        REQUIRE(Math::Squared(i32(5)) == 25);
        REQUIRE(Math::Squared(i32(-1)) == 1);
        REQUIRE(Math::Squared(i32(-2)) == 4);
    }

    SECTION("Test Squared with f32")
    {
        REQUIRE(Math::Equal(Math::Squared(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Squared(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Squared(f32(2.0f)), 4.0f));
        REQUIRE(Math::Equal(Math::Squared(f32(5.0f)), 25.0f));
        REQUIRE(Math::Equal(Math::Squared(f32(-1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Squared(f32(-2.0f)), 4.0f));
    }

    SECTION("Test Cubed with i32")
    {
        REQUIRE(Math::Cubed(i32(0)) == 0);
        REQUIRE(Math::Cubed(i32(1)) == 1);
        REQUIRE(Math::Cubed(i32(2)) == 8);
        REQUIRE(Math::Cubed(i32(5)) == 125);
        REQUIRE(Math::Cubed(i32(-1)) == -1);
        REQUIRE(Math::Cubed(i32(-2)) == -8);
    }

    SECTION("Test Cubed with f32")
    {
        REQUIRE(Math::Equal(Math::Cubed(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Cubed(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Cubed(f32(2.0f)), 8.0f));
        REQUIRE(Math::Equal(Math::Cubed(f32(5.0f)), 125.0f));
        REQUIRE(Math::Equal(Math::Cubed(f32(-1.0f)), -1.0f));
        REQUIRE(Math::Equal(Math::Cubed(f32(-2.0f)), -8.0f));
    }
}

TEST_CASE("Test Clamp, Lerp and InvLerp", "[Math][Functions]")
{
    SECTION("Test Clamp with i32")
    {
        REQUIRE(Math::Clamp(i32(0), i32(0), i32(1)) == 0);
        REQUIRE(Math::Clamp(i32(1), i32(0), i32(1)) == 1);
        REQUIRE(Math::Clamp(i32(2), i32(0), i32(1)) == 1);
        REQUIRE(Math::Clamp(i32(-1), i32(0), i32(1)) == 0);
        REQUIRE(Math::Clamp(i32(-2), i32(0), i32(1)) == 0);
    }

    SECTION("Test Clamp with f32")
    {
        REQUIRE(Math::Equal(Math::Clamp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Clamp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Clamp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Math::Equal(Math::Clamp(f32(2.0f), f32(0.0f), f32(1.5f)), 1.5f));
        REQUIRE(Math::Equal(Math::Clamp(f32(-1.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Clamp(f32(-2.0f), f32(0.0f), f32(1.0f)), 0.0f));
    }

    SECTION("Test Lerp with f32")
    {
        REQUIRE(Math::Equal(Math::Lerp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Lerp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Math::Equal(Math::Lerp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));

        REQUIRE(Math::Equal(Math::Lerp(f32(0.0f), f32(-8.0f), f32(8.0f)), -8.0f));
        REQUIRE(Math::Equal(Math::Lerp(f32(0.25f), f32(-8.0f), f32(8.0f)), -4.0f));
        REQUIRE(Math::Equal(Math::Lerp(f32(0.5f), f32(-8.0f), f32(8.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Lerp(f32(0.75f), f32(-8.0f), f32(8.0f)), 4.0f));
        REQUIRE(Math::Equal(Math::Lerp(f32(1.0f), f32(-8.0f), f32(8.0f)), 8.0f));
    }

    SECTION("Test InvLerp with f32")
    {
        REQUIRE(Math::Equal(Math::InvLerp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));

        REQUIRE(Math::Equal(Math::InvLerp(f32(-8.0f), f32(-8.0f), f32(8.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(-4.0f), f32(-8.0f), f32(8.0f)), 0.25f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(0.0f), f32(-8.0f), f32(8.0f)), 0.5f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(4.0f), f32(-8.0f), f32(8.0f)), 0.75f));
        REQUIRE(Math::Equal(Math::InvLerp(f32(8.0f), f32(-8.0f), f32(8.0f)), 1.0f));
    }
}

TEST_CASE("Test Floor/Ceil functions", "[Math][Functions]")
{
    SECTION("Test Floor with f32 as parameter and i32 as return type")
    {
        REQUIRE(Math::Floor<i32>(f32(-3.5f)) == -4);
        REQUIRE(Math::Floor<i32>(f32(-2.5f)) == -3);
        REQUIRE(Math::Floor<i32>(f32(-1.0f)) == -1);
        REQUIRE(Math::Floor<i32>(f32(0.0f)) == 0);
        REQUIRE(Math::Floor<i32>(f32(0.25f)) == 0);
        REQUIRE(Math::Floor<i32>(f32(0.5f)) == 0);
        REQUIRE(Math::Floor<i32>(f32(0.75f)) == 0);
        REQUIRE(Math::Floor<i32>(f32(1.0f)) == 1);
        REQUIRE(Math::Floor<i32>(f32(1.5f)) == 1);
    }

    SECTION("Test Floor with float as parameter and std::int32_t as return type")
    {
        REQUIRE(Math::Floor<std::int32_t>(-3.5f) == -4);
        REQUIRE(Math::Floor<std::int32_t>(-2.5f) == -3);
        REQUIRE(Math::Floor<std::int32_t>(-1.0f) == -1);
        REQUIRE(Math::Floor<std::int32_t>(0.0f) == 0);
        REQUIRE(Math::Floor<std::int32_t>(0.25f) == 0);
        REQUIRE(Math::Floor<std::int32_t>(0.5f) == 0);
        REQUIRE(Math::Floor<std::int32_t>(0.75f) == 0);
        REQUIRE(Math::Floor<std::int32_t>(1.0f) == 1);
        REQUIRE(Math::Floor<std::int32_t>(1.5f) == 1);
    }

    SECTION("Test Ceil with f32 as parameter and i32 as return type")
    {
        REQUIRE(Math::Ceil<i32>(f32(-3.5f)) == -3);
        REQUIRE(Math::Ceil<i32>(f32(-2.5f)) == -2);
        REQUIRE(Math::Ceil<i32>(f32(-1.0f)) == -1);
        REQUIRE(Math::Ceil<i32>(f32(0.0f)) == 0);
        REQUIRE(Math::Ceil<i32>(f32(0.25f)) == 1);
        REQUIRE(Math::Ceil<i32>(f32(0.5f)) == 1);
        REQUIRE(Math::Ceil<i32>(f32(0.75f)) == 1);
        REQUIRE(Math::Ceil<i32>(f32(1.0f)) == 1);
        REQUIRE(Math::Ceil<i32>(f32(1.5f)) == 2);
    }

    SECTION("Test Ceil with float as parameter and std::int32_t as return type")
    {
        REQUIRE(Math::Ceil<std::int32_t>(-3.5f) == -3);
        REQUIRE(Math::Ceil<std::int32_t>(-2.5f) == -2);
        REQUIRE(Math::Ceil<std::int32_t>(-1.0f) == -1);
        REQUIRE(Math::Ceil<std::int32_t>(0.0f) == 0);
        REQUIRE(Math::Ceil<std::int32_t>(0.25f) == 1);
        REQUIRE(Math::Ceil<std::int32_t>(0.5f) == 1);
        REQUIRE(Math::Ceil<std::int32_t>(0.75f) == 1);
        REQUIRE(Math::Ceil<std::int32_t>(1.0f) == 1);
        REQUIRE(Math::Ceil<std::int32_t>(1.5f) == 2);
    }

    SECTION("Test Floor with f32")
    {
        REQUIRE(Math::Equal(Math::Floor(f32(-3.5f)), -4.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(-2.5f)), -3.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(-1.0f)), -1.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(0.25f)), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(0.5f)), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(0.75f)), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(f32(1.5f)), 1.0f));
    }

    SECTION("Test Floor with float")
    {
        REQUIRE(Math::Equal(Math::Floor(-3.5f), -4.0f));
        REQUIRE(Math::Equal(Math::Floor(-2.5f), -3.0f));
        REQUIRE(Math::Equal(Math::Floor(-1.0f), -1.0f));
        REQUIRE(Math::Equal(Math::Floor(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(1.0f), 1.0f));
        REQUIRE(Math::Equal(Math::Floor(0.25f), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(0.5f), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(0.75f), 0.0f));
        REQUIRE(Math::Equal(Math::Floor(1.5f), 1.0f));
    }

    SECTION("Test Ceil with f32")
    {
        REQUIRE(Math::Equal(Math::Ceil(f32(-3.5f)), -3.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(-2.5f)), -2.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(-1.0f)), -1.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(0.25f)), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(0.5f)), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(0.75f)), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(f32(1.5f)), 2.0f));
    }

    SECTION("Test Ceil with float")
    {
        REQUIRE(Math::Equal(Math::Ceil(-3.5f), -3.0f));
        REQUIRE(Math::Equal(Math::Ceil(-2.5f), -2.0f));
        REQUIRE(Math::Equal(Math::Ceil(-1.0f), -1.0f));
        REQUIRE(Math::Equal(Math::Ceil(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Ceil(0.25f), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(0.5f), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(0.75f), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(1.0f), 1.0f));
        REQUIRE(Math::Equal(Math::Ceil(1.5f), 2.0f));
    }
}

TEST_CASE("Test Smooth(er)step functions and derivatives", "[Math][Functions]")
{
    SECTION("Test Smoothstep")
    {
        // This mostly just checks if it compiles
        REQUIRE(Math::Equal(Math::Smoothstep(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Smoothstep(0.0f, 0.5f, 1.0f), 0.0f));
    }

    SECTION("Test Smootherstep")
    {
        // This mostly just checks if it compiles
        REQUIRE(Math::Equal(Math::Smootherstep(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Smootherstep(0.0f, 0.5f, 1.0f), 0.0f));
    }

    SECTION("Test SmoothstepDerivative")
    {
        // This mostly just checks if it compiles
        REQUIRE(Math::Equal(Math::SmoothstepDerivative(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::SmoothstepDerivative(0.0f, 0.5f, 1.0f), 0.0f));
    }

    SECTION("Test SmootherstepDerivative")
    {
        // This mostly just checks if it compiles
        REQUIRE(Math::Equal(Math::SmootherstepDerivative(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::SmootherstepDerivative(0.0f, 0.5f, 1.0f), 0.0f));
    }
}

TEST_CASE("Test Radians/Degrees conversions")
{
    namespace C = Math::Constants;

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

TEST_CASE("Test Min/Max functions", "[Math][Functions]")
{
    SECTION("Check Min")
    {
        REQUIRE(Math::Min(1) == 1);
        REQUIRE(Math::Min(1, 2) == 1);
        REQUIRE(Math::Min(2, 1, 3) == 1);
        REQUIRE(Math::Min(2, 3, 1, 4) == 1);
        REQUIRE(Math::Min(2, 3, 4, 1, 5) == 1);
    }

    SECTION("Check Max")
    {
        REQUIRE(Math::Max(1) == 1);
        REQUIRE(Math::Max(1, 2) == 2);
        REQUIRE(Math::Max(2, 1, 3) == 3);
        REQUIRE(Math::Max(2, 3, 1, 4) == 4);
        REQUIRE(Math::Max(2, 3, 4, 1, 5) == 5);
    }
}
