#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>
#include <Math/Constants.hpp>

using i32 = Math::i32;
using f32 = Math::f32;

TEST_CASE("Test Squared function", "[Math][Functions]")
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
}

TEST_CASE("Test Cubed function", "[Math][Functions]")
{
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

TEST_CASE("Test Pow function", "[Math][Functions]")
{
    // TODO(3011): Add tests for Pow function. (Quite a few of them, they will
    // be useful for custom implementation later.)
    //  - Test at least ten bases with a few positive and a few negative exponents.
}

TEST_CASE("Test Sqrt function", "[Math][Functions]")
{
    SECTION("Test Sqrt with f32")
    {
        REQUIRE(Math::Equal(Math::Sqrt(f32(0.0f)), 0.0f));
        REQUIRE(Math::Equal(Math::Sqrt(f32(1.0f)), 1.0f));
        REQUIRE(Math::Equal(Math::Sqrt(f32(2.0f)), Math::Constants::Sqrt2<f32>));
        REQUIRE(Math::Equal(Math::Sqrt(f32(3.0f)), Math::Constants::Sqrt3<f32>));
        REQUIRE(Math::Equal(Math::Sqrt(f32(4.0f)), 2.0f));
        REQUIRE(Math::Equal(Math::Sqrt(f32(5.0f)), Math::Constants::Sqrt5<f32>));
        REQUIRE(Math::Equal(Math::Sqrt(f32(16.0f)), 4.0f));
    }
}
