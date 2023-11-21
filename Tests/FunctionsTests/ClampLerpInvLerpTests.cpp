#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using i32 = Math::i32;
using f32 = Math::f32;

TEST_CASE("Test Clamp function", "[Math][Functions]")
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
}

TEST_CASE("Test Lerp function", "[Math][Functions]")
{
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
}

TEST_CASE("Test InvLerp function", "[Math][Functions]")
{
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
