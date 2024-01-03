#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::f32;
using Math::Equal;

TEST_CASE("Test Piecewise function with two segments", "[Math][Functions]")
{
    using Linear = Math::Function::Linear<f32, 1.0f, 2.0f>;
    using Constant = Math::Function::Constant<f32, 4.0f>;
    static constexpr Math::Function::ControlPoint<f32> Boundary{ 2.0f, Math::Orientation::Left };
    using Piecewise = Math::Function::Piecewise<Linear, Constant, Boundary>;

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

TEST_CASE("Test Piecewise function with three segments")
{
    using FirstConstant = Math::Function::Constant<f32, 2.0f>;
    using Linear = Math::Function::Linear<f32, 1.0f, 2.0f>;
    using SecondConstant = Math::Function::Constant<f32, 4.0f>;

    static constexpr Math::Function::ControlPoint<f32> FirstBoundary{ 0.0f, Math::Orientation::Right };
    static constexpr Math::Function::ControlPoint<f32> SecondBoundary{ 2.0f, Math::Orientation::Left };

    using Piecewise = Math::Function::Piecewise<FirstConstant, Linear, FirstBoundary>;
    using FullPiecewise = Piecewise::AddSegment<SecondConstant, SecondBoundary>;

    SECTION("Test function values")
    {
        constexpr FullPiecewise piecewise;
        REQUIRE(Equal(piecewise(-1.0f), 2.0f));
        REQUIRE(Equal(piecewise(0.0f), 2.0f));
        REQUIRE(Equal(piecewise(1.0f), 3.0f));
        REQUIRE(Equal(piecewise(2.0f), 4.0f));
        REQUIRE(Equal(piecewise(3.0f), 4.0f));
        REQUIRE(Equal(piecewise(4.0f), 4.0f));
    }

    SECTION("Test function derivatives")
    {
        constexpr Math::Function::Derivative<FullPiecewise> derivative;
        REQUIRE(Equal(derivative(-1.0f), 0.0f));
        REQUIRE(Equal(derivative(0.0f), 1.0f));
        REQUIRE(Equal(derivative(1.0f), 1.0f));
        REQUIRE(Equal(derivative(2.0f), 1.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
    }

    SECTION("Test function second derivatives")
    {
        constexpr Math::Function::Derivative<FullPiecewise, 2> derivative;
        REQUIRE(Equal(derivative(-1.0f), 0.0f));
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 0.0f));
        REQUIRE(Equal(derivative(2.0f), 0.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
    }
}

TEST_CASE("Test Piecewise function with four segments")
{
    using FirstConstant = Math::Function::Constant<f32, 2.0f>;
    using FirstLinear = Math::Function::Linear<f32, 1.0f, 2.0f>;
    using SecondConstant = Math::Function::Constant<f32, 4.0f>;
    using SecondLinear = Math::Function::Linear<f32, 1.0f, 0.0f>;

    static constexpr Math::Function::ControlPoint<f32> FirstBoundary{ 0.0f, Math::Orientation::Right };
    static constexpr Math::Function::ControlPoint<f32> SecondBoundary{ 2.0f, Math::Orientation::Left };
    static constexpr Math::Function::ControlPoint<f32> ThirdBoundary{ 4.0f, Math::Orientation::Left };

    using Piecewise = Math::Function::Piecewise<FirstConstant, FirstLinear, FirstBoundary>;
    using FullPiecewise = Piecewise::AddSegment<SecondConstant, SecondBoundary>::AddSegment<SecondLinear, ThirdBoundary>;

    SECTION("Test function values")
    {
        constexpr FullPiecewise piecewise;
        REQUIRE(Equal(piecewise(-1.0f), 2.0f));
        REQUIRE(Equal(piecewise(0.0f), 2.0f));
        REQUIRE(Equal(piecewise(1.0f), 3.0f));
        REQUIRE(Equal(piecewise(2.0f), 4.0f));
        REQUIRE(Equal(piecewise(3.0f), 4.0f));
        REQUIRE(Equal(piecewise(4.0f), 4.0f));
        REQUIRE(Equal(piecewise(5.0f), 5.0f));
        REQUIRE(Equal(piecewise(6.0f), 6.0f));
    }

    SECTION("Test function derivatives")
    {
        constexpr Math::Function::Derivative<FullPiecewise> derivative;
        REQUIRE(Equal(derivative(-1.0f), 0.0f));
        REQUIRE(Equal(derivative(0.0f), 1.0f));
        REQUIRE(Equal(derivative(1.0f), 1.0f));
        REQUIRE(Equal(derivative(2.0f), 1.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
        REQUIRE(Equal(derivative(5.0f), 1.0f));
        REQUIRE(Equal(derivative(6.0f), 1.0f));
    }

    SECTION("Test function second derivatives")
    {
        constexpr Math::Function::Derivative<FullPiecewise, 2> derivative;
        REQUIRE(Equal(derivative(-1.0f), 0.0f));
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 0.0f));
        REQUIRE(Equal(derivative(2.0f), 0.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
        REQUIRE(Equal(derivative(5.0f), 0.0f));
        REQUIRE(Equal(derivative(6.0f), 0.0f));
    }
}
