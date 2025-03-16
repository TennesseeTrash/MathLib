#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using i32 = Math::i32;
using f32 = Math::f32;
using Math::Equal;

TEST_CASE("Test Clamp function", "[Math][Functions]")
{
    using Math::Clamp;

    SECTION("Test Clamp with i32")
    {
        REQUIRE(Clamp(i32(0), i32(0), i32(1)) == 0);
        REQUIRE(Clamp(i32(1), i32(0), i32(1)) == 1);
        REQUIRE(Clamp(i32(2), i32(0), i32(1)) == 1);
        REQUIRE(Clamp(i32(-1), i32(0), i32(1)) == 0);
        REQUIRE(Clamp(i32(-2), i32(0), i32(1)) == 0);
    }

    SECTION("Test Clamp with f32")
    {
        REQUIRE(Equal(Clamp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Equal(Clamp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));
        REQUIRE(Equal(Clamp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Equal(Clamp(f32(2.0f), f32(0.0f), f32(1.5f)), 1.5f));
        REQUIRE(Equal(Clamp(f32(-1.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Equal(Clamp(f32(-2.0f), f32(0.0f), f32(1.0f)), 0.0f));
    }
}

TEST_CASE("Test Lerp function", "[Math][Functions]")
{
    using Math::Lerp;

    SECTION("Test Lerp with f32")
    {
        REQUIRE(Equal(Lerp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Equal(Lerp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Equal(Lerp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));

        REQUIRE(Equal(Lerp(f32(0.0f), f32(-8.0f), f32(8.0f)), -8.0f));
        REQUIRE(Equal(Lerp(f32(0.25f), f32(-8.0f), f32(8.0f)), -4.0f));
        REQUIRE(Equal(Lerp(f32(0.5f), f32(-8.0f), f32(8.0f)), 0.0f));
        REQUIRE(Equal(Lerp(f32(0.75f), f32(-8.0f), f32(8.0f)), 4.0f));
        REQUIRE(Equal(Lerp(f32(1.0f), f32(-8.0f), f32(8.0f)), 8.0f));
    }
}

TEST_CASE("Test InvLerp function", "[Math][Functions]")
{
    using Math::InvLerp;

    SECTION("Test InvLerp with f32")
    {
        REQUIRE(Equal(InvLerp(f32(0.0f), f32(0.0f), f32(1.0f)), 0.0f));
        REQUIRE(Equal(InvLerp(f32(0.5f), f32(0.0f), f32(1.0f)), 0.5f));
        REQUIRE(Equal(InvLerp(f32(1.0f), f32(0.0f), f32(1.0f)), 1.0f));

        REQUIRE(Equal(InvLerp(f32(-8.0f), f32(-8.0f), f32(8.0f)), 0.0f));
        REQUIRE(Equal(InvLerp(f32(-4.0f), f32(-8.0f), f32(8.0f)), 0.25f));
        REQUIRE(Equal(InvLerp(f32(0.0f), f32(-8.0f), f32(8.0f)), 0.5f));
        REQUIRE(Equal(InvLerp(f32(4.0f), f32(-8.0f), f32(8.0f)), 0.75f));
        REQUIRE(Equal(InvLerp(f32(8.0f), f32(-8.0f), f32(8.0f)), 1.0f));
    }
}

TEST_CASE("Test Squared function", "[Math][Functions]")
{
    using Math::Squared;

    SECTION("Test Squared with i32")
    {
        REQUIRE(Squared(i32(0)) == 0);
        REQUIRE(Squared(i32(1)) == 1);
        REQUIRE(Squared(i32(2)) == 4);
        REQUIRE(Squared(i32(5)) == 25);
        REQUIRE(Squared(i32(-1)) == 1);
        REQUIRE(Squared(i32(-2)) == 4);
    }

    SECTION("Test Squared with f32")
    {
        REQUIRE(Equal(Squared(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Squared(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Squared(f32(2.0f)), 4.0f));
        REQUIRE(Equal(Squared(f32(5.0f)), 25.0f));
        REQUIRE(Equal(Squared(f32(-1.0f)), 1.0f));
        REQUIRE(Equal(Squared(f32(-2.0f)), 4.0f));
    }
}

TEST_CASE("Test Cubed function", "[Math][Functions]")
{
    using Math::Cubed;

    SECTION("Test Cubed with i32")
    {
        REQUIRE(Cubed(i32(0)) == 0);
        REQUIRE(Cubed(i32(1)) == 1);
        REQUIRE(Cubed(i32(2)) == 8);
        REQUIRE(Cubed(i32(5)) == 125);
        REQUIRE(Cubed(i32(-1)) == -1);
        REQUIRE(Cubed(i32(-2)) == -8);
    }

    SECTION("Test Cubed with f32")
    {
        REQUIRE(Equal(Cubed(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Cubed(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Cubed(f32(2.0f)), 8.0f));
        REQUIRE(Equal(Cubed(f32(5.0f)), 125.0f));
        REQUIRE(Equal(Cubed(f32(-1.0f)), -1.0f));
        REQUIRE(Equal(Cubed(f32(-2.0f)), -8.0f));
    }
}

TEST_CASE("Test Trunc functions", "[Math][Functions]")
{
    using Math::Trunc;

    SECTION("Test Trunc with f32 as parameter as i32 as return type")
    {
        REQUIRE(Trunc<i32>(f32(-3.5f)) == -3);
        REQUIRE(Trunc<i32>(f32(-2.5f)) == -2);
        REQUIRE(Trunc<i32>(f32(-1.0f)) == -1);
        REQUIRE(Trunc<i32>(f32(0.0f)) == 0);
        REQUIRE(Trunc<i32>(f32(0.25f)) == 0);
        REQUIRE(Trunc<i32>(f32(0.5f)) == 0);
        REQUIRE(Trunc<i32>(f32(0.75f)) == 0);
        REQUIRE(Trunc<i32>(f32(1.0f)) == 1);
        REQUIRE(Trunc<i32>(f32(1.5f)) == 1);
    }

    SECTION("Test Trunc with float as parameter as std::int32_t as return type")
    {
        REQUIRE(Trunc<std::int32_t>(-3.5f) == -3);
        REQUIRE(Trunc<std::int32_t>(-2.5f) == -2);
        REQUIRE(Trunc<std::int32_t>(-1.0f) == -1);
        REQUIRE(Trunc<std::int32_t>(0.0f) == 0);
        REQUIRE(Trunc<std::int32_t>(0.25f) == 0);
        REQUIRE(Trunc<std::int32_t>(0.5f) == 0);
        REQUIRE(Trunc<std::int32_t>(0.75f) == 0);
        REQUIRE(Trunc<std::int32_t>(1.0f) == 1);
        REQUIRE(Trunc<std::int32_t>(1.5f) == 1);
    }

    SECTION("Test Trunc with f32")
    {
        REQUIRE(Equal(Trunc(f32(-3.5f)), -3.0f));
        REQUIRE(Equal(Trunc(f32(-2.5f)), -2.0f));
        REQUIRE(Equal(Trunc(f32(-1.0f)), -1.0f));
        REQUIRE(Equal(Trunc(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Trunc(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Trunc(f32(0.25f)), 0.0f));
        REQUIRE(Equal(Trunc(f32(0.5f)), 0.0f));
        REQUIRE(Equal(Trunc(f32(0.75f)), 0.0f));
        REQUIRE(Equal(Trunc(f32(1.5f)), 1.0f));
    }

    SECTION("Test Trunc with float")
    {
        REQUIRE(Equal(Trunc(-3.5f), -3.0f));
        REQUIRE(Equal(Trunc(-2.5f), -2.0f));
        REQUIRE(Equal(Trunc(-1.0f), -1.0f));
        REQUIRE(Equal(Trunc(0.0f), 0.0f));
        REQUIRE(Equal(Trunc(1.0f), 1.0f));
        REQUIRE(Equal(Trunc(0.25f), 0.0f));
        REQUIRE(Equal(Trunc(0.5f), 0.0f));
        REQUIRE(Equal(Trunc(0.75f), 0.0f));
        REQUIRE(Equal(Trunc(1.5f), 1.0f));
    }
}

TEST_CASE("Test Floor functions", "[Math][Functions]")
{
    using Math::Floor;

    SECTION("Test Floor with f32 as parameter and i32 as return type")
    {
        REQUIRE(Floor<i32>(f32(-3.5f)) == -4);
        REQUIRE(Floor<i32>(f32(-2.5f)) == -3);
        REQUIRE(Floor<i32>(f32(-1.0f)) == -1);
        REQUIRE(Floor<i32>(f32(0.0f)) == 0);
        REQUIRE(Floor<i32>(f32(0.25f)) == 0);
        REQUIRE(Floor<i32>(f32(0.5f)) == 0);
        REQUIRE(Floor<i32>(f32(0.75f)) == 0);
        REQUIRE(Floor<i32>(f32(1.0f)) == 1);
        REQUIRE(Floor<i32>(f32(1.5f)) == 1);
    }

    SECTION("Test Floor with float as parameter and std::int32_t as return type")
    {
        REQUIRE(Floor<std::int32_t>(-3.5f) == -4);
        REQUIRE(Floor<std::int32_t>(-2.5f) == -3);
        REQUIRE(Floor<std::int32_t>(-1.0f) == -1);
        REQUIRE(Floor<std::int32_t>(0.0f) == 0);
        REQUIRE(Floor<std::int32_t>(0.25f) == 0);
        REQUIRE(Floor<std::int32_t>(0.5f) == 0);
        REQUIRE(Floor<std::int32_t>(0.75f) == 0);
        REQUIRE(Floor<std::int32_t>(1.0f) == 1);
        REQUIRE(Floor<std::int32_t>(1.5f) == 1);
    }

    SECTION("Test Floor with f32")
    {
        REQUIRE(Equal(Floor(f32(-3.5f)), -4.0f));
        REQUIRE(Equal(Floor(f32(-2.5f)), -3.0f));
        REQUIRE(Equal(Floor(f32(-1.0f)), -1.0f));
        REQUIRE(Equal(Floor(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Floor(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Floor(f32(0.25f)), 0.0f));
        REQUIRE(Equal(Floor(f32(0.5f)), 0.0f));
        REQUIRE(Equal(Floor(f32(0.75f)), 0.0f));
        REQUIRE(Equal(Floor(f32(1.5f)), 1.0f));
    }

    SECTION("Test Floor with float")
    {
        REQUIRE(Equal(Floor(-3.5f), -4.0f));
        REQUIRE(Equal(Floor(-2.5f), -3.0f));
        REQUIRE(Equal(Floor(-1.0f), -1.0f));
        REQUIRE(Equal(Floor(0.0f), 0.0f));
        REQUIRE(Equal(Floor(1.0f), 1.0f));
        REQUIRE(Equal(Floor(0.25f), 0.0f));
        REQUIRE(Equal(Floor(0.5f), 0.0f));
        REQUIRE(Equal(Floor(0.75f), 0.0f));
        REQUIRE(Equal(Floor(1.5f), 1.0f));
    }
}

TEST_CASE("Test Ceil functions", "[Math][Functions]")
{
    using Math::Ceil;

    SECTION("Test Ceil with f32 as parameter and i32 as return type")
    {
        REQUIRE(Ceil<i32>(f32(-3.5f)) == -3);
        REQUIRE(Ceil<i32>(f32(-2.5f)) == -2);
        REQUIRE(Ceil<i32>(f32(-1.0f)) == -1);
        REQUIRE(Ceil<i32>(f32(0.0f)) == 0);
        REQUIRE(Ceil<i32>(f32(0.25f)) == 1);
        REQUIRE(Ceil<i32>(f32(0.5f)) == 1);
        REQUIRE(Ceil<i32>(f32(0.75f)) == 1);
        REQUIRE(Ceil<i32>(f32(1.0f)) == 1);
        REQUIRE(Ceil<i32>(f32(1.5f)) == 2);
    }

    SECTION("Test Ceil with float as parameter and std::int32_t as return type")
    {
        REQUIRE(Ceil<std::int32_t>(-3.5f) == -3);
        REQUIRE(Ceil<std::int32_t>(-2.5f) == -2);
        REQUIRE(Ceil<std::int32_t>(-1.0f) == -1);
        REQUIRE(Ceil<std::int32_t>(0.0f) == 0);
        REQUIRE(Ceil<std::int32_t>(0.25f) == 1);
        REQUIRE(Ceil<std::int32_t>(0.5f) == 1);
        REQUIRE(Ceil<std::int32_t>(0.75f) == 1);
        REQUIRE(Ceil<std::int32_t>(1.0f) == 1);
        REQUIRE(Ceil<std::int32_t>(1.5f) == 2);
    }

    SECTION("Test Ceil with f32")
    {
        REQUIRE(Equal(Ceil(f32(-3.5f)), -3.0f));
        REQUIRE(Equal(Ceil(f32(-2.5f)), -2.0f));
        REQUIRE(Equal(Ceil(f32(-1.0f)), -1.0f));
        REQUIRE(Equal(Ceil(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Ceil(f32(0.25f)), 1.0f));
        REQUIRE(Equal(Ceil(f32(0.5f)), 1.0f));
        REQUIRE(Equal(Ceil(f32(0.75f)), 1.0f));
        REQUIRE(Equal(Ceil(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Ceil(f32(1.5f)), 2.0f));
    }

    SECTION("Test Ceil with float")
    {
        REQUIRE(Equal(Ceil(-3.5f), -3.0f));
        REQUIRE(Equal(Ceil(-2.5f), -2.0f));
        REQUIRE(Equal(Ceil(-1.0f), -1.0f));
        REQUIRE(Equal(Ceil(0.0f), 0.0f));
        REQUIRE(Equal(Ceil(0.25f), 1.0f));
        REQUIRE(Equal(Ceil(0.5f), 1.0f));
        REQUIRE(Equal(Ceil(0.75f), 1.0f));
        REQUIRE(Equal(Ceil(1.0f), 1.0f));
        REQUIRE(Equal(Ceil(1.5f), 2.0f));
    }
}

TEST_CASE("Test Frac functions", "[Math][Functions]")
{
    using Math::Frac;

    SECTION("Test Frac with f32", "[Math][Functions]")
    {
        REQUIRE(Equal(Frac(f32(-3.5f)), -0.5f));
        REQUIRE(Equal(Frac(f32(-2.5f)), -0.5f));
        REQUIRE(Equal(Frac(f32(-1.0f)), 0.0f));
        REQUIRE(Equal(Frac(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Frac(f32(1.0f)), 0.0f));
        REQUIRE(Equal(Frac(f32(0.25f)), 0.25f));
        REQUIRE(Equal(Frac(f32(0.5f)), 0.5f));
        REQUIRE(Equal(Frac(f32(0.75f)), 0.75f));
        REQUIRE(Equal(Frac(f32(1.5f)), 0.5f));
        REQUIRE(Equal(Frac(f32(2.5f)), 0.5f));
    }

    SECTION("Test Frac with float", "[Math][Functions]")
    {
        REQUIRE(Equal(Frac(-3.5f), -0.5f));
        REQUIRE(Equal(Frac(-2.5f), -0.5f));
        REQUIRE(Equal(Frac(-1.0f), 0.0f));
        REQUIRE(Equal(Frac(0.0f), 0.0f));
        REQUIRE(Equal(Frac(1.0f), 0.0f));
        REQUIRE(Equal(Frac(0.25f), 0.25f));
        REQUIRE(Equal(Frac(0.5f), 0.5f));
        REQUIRE(Equal(Frac(0.75f), 0.75f));
        REQUIRE(Equal(Frac(1.5f), 0.5f));
        REQUIRE(Equal(Frac(2.5f), 0.5f));
    }
}
