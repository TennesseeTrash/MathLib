#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using i32 = Math::i32;
using f32 = Math::f32;
using Math::Equal;

TEST_CASE("Test Sign function", "[Math][Functions]")
{
    using Math::Sign;

    SECTION("Test Sign with i32")
    {
        REQUIRE(Sign(i32(0)) == 0);
        REQUIRE(Sign(i32(5)) == 1);
        REQUIRE(Sign(i32(-5)) == -1);
    }

    SECTION("Test Sign with std::int32_t")
    {
        REQUIRE(Sign(std::int32_t(0)) == 0);
        REQUIRE(Sign(std::int32_t(5)) == 1);
        REQUIRE(Sign(std::int32_t(-5)) == -1);
    }

    SECTION("Test Sign with f32")
    {
        REQUIRE(Equal(Sign(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Sign(f32(5.0f)), 1.0f));
        REQUIRE(Equal(Sign(f32(-5.0f)), -1.0f));
    }

    SECTION("Test Sign with float")
    {
        REQUIRE(Equal(Sign(0.0f), 0.0f));
        REQUIRE(Equal(Sign(5.0f), 1.0f));
        REQUIRE(Equal(Sign(-5.0f), -1.0f));
    }
}

TEST_CASE("Test Abs function", "[Math][Functions]")
{
    using Math::Abs;

    SECTION("Test Abs with i32")
    {
        REQUIRE(Abs(i32(0)) == 0);
        REQUIRE(Abs(i32(1)) == 1);
        REQUIRE(Abs(i32(-1)) == 1);
    }

    SECTION("Test Abs with std::int32_t")
    {
        REQUIRE(Abs(std::int32_t(0)) == 0);
        REQUIRE(Abs(std::int32_t(1)) == 1);
        REQUIRE(Abs(std::int32_t(-1)) == 1);
    }

    SECTION("Test Abs with f32")
    {
        REQUIRE(Equal(Abs(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Abs(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Abs(f32(-1.0f)), 1.0f));
    }

    SECTION("Test Abs with float")
    {
        REQUIRE(Equal(Abs(0.0f), 0.0f));
        REQUIRE(Equal(Abs(1.0f), 1.0f));
        REQUIRE(Equal(Abs(-1.0f), 1.0f));
    }
}
