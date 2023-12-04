#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using i32 = Math::i32;
using f32 = Math::f32;

TEST_CASE("Test Sign function", "[Math][Functions]")
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
}

TEST_CASE("Test Abs function", "[Math][Functions]")
{
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
