#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::f32;

// TODO(3011):
// Remove these when the new implementation is done.
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
