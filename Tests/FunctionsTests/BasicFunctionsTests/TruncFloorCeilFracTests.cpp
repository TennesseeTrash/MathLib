#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using i32 = Math::i32;
using f32 = Math::f32;

TEST_CASE("Test Trunc functions", "[Math][Functions]")
{
    SECTION("Test Trunc with f32 as parameter as i32 as return type")
    {
        REQUIRE(Math::Trunc<i32>(f32(-3.5f)) == -3);
        REQUIRE(Math::Trunc<i32>(f32(-2.5f)) == -2);
        REQUIRE(Math::Trunc<i32>(f32(-1.0f)) == -1);
        REQUIRE(Math::Trunc<i32>(f32(0.0f)) == 0);
        REQUIRE(Math::Trunc<i32>(f32(0.25f)) == 0);
        REQUIRE(Math::Trunc<i32>(f32(0.5f)) == 0);
        REQUIRE(Math::Trunc<i32>(f32(0.75f)) == 0);
        REQUIRE(Math::Trunc<i32>(f32(1.0f)) == 1);
        REQUIRE(Math::Trunc<i32>(f32(1.5f)) == 1);
    }

    SECTION("Test Trunc with float as parameter as std::int32_t as return type")
    {
        REQUIRE(Math::Trunc<std::int32_t>(-3.5f) == -3);
        REQUIRE(Math::Trunc<std::int32_t>(-2.5f) == -2);
        REQUIRE(Math::Trunc<std::int32_t>(-1.0f) == -1);
        REQUIRE(Math::Trunc<std::int32_t>(0.0f) == 0);
        REQUIRE(Math::Trunc<std::int32_t>(0.25f) == 0);
        REQUIRE(Math::Trunc<std::int32_t>(0.5f) == 0);
        REQUIRE(Math::Trunc<std::int32_t>(0.75f) == 0);
        REQUIRE(Math::Trunc<std::int32_t>(1.0f) == 1);
        REQUIRE(Math::Trunc<std::int32_t>(1.5f) == 1);
    }

    SECTION("Test Trunc with f32")
    {
        REQUIRE(Math::Equal(Math::Trunc(f32(-3.5f)), -3.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(-2.5f)), -2.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(-1.0f)), -1.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(0.25f)), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(0.5f)), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(0.75f)), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(f32(1.5f)), 1.0f));
    }

    SECTION("Test Trunc with float")
    {
        REQUIRE(Math::Equal(Math::Trunc(-3.5f), -3.0f));
        REQUIRE(Math::Equal(Math::Trunc(-2.5f), -2.0f));
        REQUIRE(Math::Equal(Math::Trunc(-1.0f), -1.0f));
        REQUIRE(Math::Equal(Math::Trunc(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(1.0f), 1.0f));
        REQUIRE(Math::Equal(Math::Trunc(0.25f), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(0.5f), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(0.75f), 0.0f));
        REQUIRE(Math::Equal(Math::Trunc(1.5f), 1.0f));
    }
}

TEST_CASE("Test Floor functions", "[Math][Functions]")
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
}

TEST_CASE("Test Ceil functions", "[Math][Functions]")
{
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

TEST_CASE("Test Frac functions", "[Math][Functions]")
{
    SECTION("Test Frac with f32", "[Math][Functions]")
    {
        REQUIRE(Math::Equal(Math::Frac(f32(-3.5f)), -0.5f));
        REQUIRE(Math::Equal(Math::Frac(f32(-2.5f)), -0.5f));
        REQUIRE(Math::Equal(Math::Frac(f32(-1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(f32(1.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(f32(0.25f)), 0.25f));
        REQUIRE(Math::Equal(Math::Frac(f32(0.5f)), 0.5f));
        REQUIRE(Math::Equal(Math::Frac(f32(0.75f)), 0.75f));
        REQUIRE(Math::Equal(Math::Frac(f32(1.5f)), 0.5f));
        REQUIRE(Math::Equal(Math::Frac(f32(2.5f)), 0.5f));
    }

    SECTION("Test Frac with float", "[Math][Functions]")
    {
        REQUIRE(Math::Equal(Math::Frac(-3.5f), -0.5f));
        REQUIRE(Math::Equal(Math::Frac(-2.5f), -0.5f));
        REQUIRE(Math::Equal(Math::Frac(-1.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(0.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(1.0f), 0.0f));
        REQUIRE(Math::Equal(Math::Frac(0.25f), 0.25f));
        REQUIRE(Math::Equal(Math::Frac(0.5f), 0.5f));
        REQUIRE(Math::Equal(Math::Frac(0.75f), 0.75f));
        REQUIRE(Math::Equal(Math::Frac(1.5f), 0.5f));
        REQUIRE(Math::Equal(Math::Frac(2.5f), 0.5f));
    }
}
