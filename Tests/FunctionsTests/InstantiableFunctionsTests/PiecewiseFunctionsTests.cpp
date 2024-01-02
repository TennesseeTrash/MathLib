#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::f32;
using Math::Equal;

TEST_CASE("Test Piecewise function with two sections", "[Math][Functions]")
{
    using Functions = Math::TypePack<Math::Function::Linear<f32, 1.0f, 2.0f>, Math::Function::Constant<f32, 4.0f>>;
    using Boundaries = Math::ValuePack<Math::Function::ControlPoint<f32>, Math::Function::ControlPoint<f32>{ 2.0f, Math::Orientation::Left }>;
    using Piecewise = Math::Function::Piecewise<Functions, Boundaries>;

    SECTION("Test function values")
    {
        constexpr Piecewise piecewise;
        REQUIRE(Equal(piecewise(-1.0f), 1.0f));
        REQUIRE(Equal(piecewise(0.0f), 2.0f));
        REQUIRE(Equal(piecewise(1.0f), 3.0f));
        REQUIRE(Equal(piecewise(2.0f), 4.0f));
        REQUIRE(Equal(piecewise(3.0f), 4.0f));
        REQUIRE(Equal(piecewise(4.0f), 4.0f));
    }

    SECTION("Test function derivatives")
    {
        constexpr Math::Function::Derivative<Piecewise> derivative;
        REQUIRE(Equal(derivative(-1.0f), 1.0f));
        REQUIRE(Equal(derivative(0.0f), 1.0f));
        REQUIRE(Equal(derivative(1.0f), 1.0f));
        REQUIRE(Equal(derivative(2.0f), 1.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
    }

    SECTION("Test function second derivatives")
    {
        constexpr Math::Function::Derivative<Piecewise, 2> derivative;
        REQUIRE(Equal(derivative(-1.0f), 0.0f));
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 0.0f));
        REQUIRE(Equal(derivative(2.0f), 0.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
    }
}
