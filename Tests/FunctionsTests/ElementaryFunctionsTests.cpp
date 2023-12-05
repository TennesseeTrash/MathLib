#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

namespace MF = Math::Function;
using f32 = Math::f32;

TEST_CASE("Test Constant function and its derivatives")
{
    using Constant = MF::Constant<f32, 4.0f>;

    SECTION("Constant value")
    {
        constexpr Constant constant;
        REQUIRE(Math::Equal(constant(0.0f), 4.0f));
        REQUIRE(Math::Equal(constant(1.0f), 4.0f));
        REQUIRE(Math::Equal(constant(2.0f), 4.0f));
        REQUIRE(Math::Equal(constant(3.0f), 4.0f));
        REQUIRE(Math::Equal(constant(4.0f), 4.0f));
    }

    SECTION("Constant derivative value")
    {
        constexpr MF::Derivative<Constant> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.0f));
    }

    SECTION("Constant 2nd order derivative value")
    {
        constexpr MF::Derivative<Constant, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.0f));
    }
}

TEST_CASE("Test Linear function and its derivatives")
{
    using Linear = MF::Linear<f32, 2.0f, 1.0f>;

    SECTION("Linear value")
    {
        constexpr Linear linear;
        REQUIRE(Math::Equal(linear(0.0f), 1.0f));
        REQUIRE(Math::Equal(linear(1.0f), 3.0f));
        REQUIRE(Math::Equal(linear(2.0f), 5.0f));
        REQUIRE(Math::Equal(linear(3.0f), 7.0f));
        REQUIRE(Math::Equal(linear(4.0f), 9.0f));
    }

    SECTION("Linear derivative value")
    {
        constexpr MF::Derivative<Linear> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 2.0f));
    }

    SECTION("Linear 2nd order derivative value")
    {
        constexpr MF::Derivative<Linear, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.0f));
    }
}

TEST_CASE("Test Quadratic function and its derivatives")
{
    using Quadratic = MF::Quadratic<f32, 1.0f, 2.0f, 3.0f>;

    SECTION("Quadratic value")
    {
        constexpr Quadratic quadratic;
        REQUIRE(Math::Equal(quadratic(0.0f), 3.0f));
        REQUIRE(Math::Equal(quadratic(1.0f), 6.0f));
        REQUIRE(Math::Equal(quadratic(2.0f), 11.0f));
        REQUIRE(Math::Equal(quadratic(3.0f), 18.0f));
        REQUIRE(Math::Equal(quadratic(4.0f), 27.0f));
    }

    SECTION("Quadratic derivative value")
    {
        constexpr MF::Derivative<Quadratic> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 4.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 10.0f));
    }

    SECTION("Quadratic 2nd order derivative value")
    {
        constexpr MF::Derivative<Quadratic, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 2.0f));
    }
}

TEST_CASE("Test Power function and its derivatives")
{
    using Power = MF::Power<f32, 2.0f>;

    SECTION("Power value")
    {
        constexpr Power power;
        REQUIRE(Math::Equal(power(0.0f), 0.0f));
        REQUIRE(Math::Equal(power(1.0f), 1.0f));
        REQUIRE(Math::Equal(power(2.0f), 4.0f));
        REQUIRE(Math::Equal(power(3.0f), 9.0f));
        REQUIRE(Math::Equal(power(4.0f), 16.0f));
    }

    SECTION("Power derivative value")
    {
        constexpr MF::Derivative<Power> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 4.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 8.0f));
    }

    SECTION("Power 2nd order derivative value")
    {
        constexpr MF::Derivative<Power, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 2.0f));
    }
}

TEST_CASE("Test Exponential and its derivatives")
{
    SECTION("Basic Exponential value")
    {
        constexpr MF::Exponential<f32> exponential;
        REQUIRE(Math::Equal(exponential(0.0f), 1.0f));
        REQUIRE(Math::Equal(exponential(1.0f), Math::Constants::E<f32>));
        REQUIRE(Math::Equal(exponential(2.0f), Math::Squared(Math::Constants::E<f32>)));
        REQUIRE(Math::Equal(exponential(3.0f), Math::Cubed(Math::Constants::E<f32>)));
        REQUIRE(Math::Equal(exponential(4.0f), Math::Pow(Math::Constants::E<f32>, f32(4.0f))));
    }

    // TODO(3011): Broken due to non-constexpr Log, implement or wait until C++26
    //SECTION("Basic Exponential derivative value")
    //{
    //    constexpr MF::Derivative<MF::Exponential<f32>> derivative;
    //    REQUIRE(Math::Equal(derivative(0.0f), 1.0f));
    //    REQUIRE(Math::Equal(derivative(1.0f), Math::Constants::E<f32>));
    //    REQUIRE(Math::Equal(derivative(2.0f), Math::Squared(Math::Constants::E<f32>)));
    //    REQUIRE(Math::Equal(derivative(3.0f), Math::Cubed(Math::Constants::E<f32>)));
    //    REQUIRE(Math::Equal(derivative(4.0f), Math::Pow(Math::Constants::E<f32>, f32(4.0f))));
    //}

    //SECTION("Basic Exponential 2nd order derivative value")
    //{
    //    constexpr MF::Derivative<MF::Exponential<f32>, 2> derivative;
    //    REQUIRE(Math::Equal(derivative(0.0f), 1.0f));
    //    REQUIRE(Math::Equal(derivative(1.0f), Math::Constants::E<f32>));
    //    REQUIRE(Math::Equal(derivative(2.0f), Math::Squared(Math::Constants::E<f32>)));
    //    REQUIRE(Math::Equal(derivative(3.0f), Math::Cubed(Math::Constants::E<f32>)));
    //    REQUIRE(Math::Equal(derivative(4.0f), Math::Pow(Math::Constants::E<f32>, f32(4.0f))));
    //}
}

TEST_CASE("Test NaturalLogarithm and its derivatives")
{
    SECTION("NaturalLogarithm value")
    {
        constexpr MF::NaturalLogarithm<f32> naturalLogarithm;
        REQUIRE(Math::Equal(naturalLogarithm(1.0f), 0.0f));
        REQUIRE(Math::Equal(naturalLogarithm(Math::Constants::E<f32>), 1.0f));
        REQUIRE(Math::Equal(naturalLogarithm(Math::Squared(Math::Constants::E<f32>)), 2.0f));
        REQUIRE(Math::Equal(naturalLogarithm(Math::Cubed(Math::Constants::E<f32>)), 3.0f));
        REQUIRE(Math::Equal(naturalLogarithm(Math::Pow(Math::Constants::E<f32>, f32(4.0f))), 4.0f));
    }

    SECTION("NaturalLogarithm derivative value")
    {
        constexpr MF::Derivative<MF::NaturalLogarithm<f32>> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.5f));
        REQUIRE(Math::Equal(derivative(3.0f), 1.0f / 3.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.25f));
        REQUIRE(Math::Equal(derivative(5.0f), 0.2f));
    }

    SECTION("NaturalLogarithm 2nd order derivative value")
    {
        constexpr MF::Derivative<MF::NaturalLogarithm<f32>, 2> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), -1.0f));
        REQUIRE(Math::Equal(derivative(2.0f), -0.25f));
        REQUIRE(Math::Equal(derivative(3.0f), -1.0f / 9.0f));
        REQUIRE(Math::Equal(derivative(4.0f), -0.0625f));
        REQUIRE(Math::Equal(derivative(5.0f), -0.04f));
    }
}

TEST_CASE("Test Logarithm and its derivatives")
{
    SECTION("Logarithm (base 10) value")
    {
        constexpr MF::Logarithm<f32, 10.0f> logarithm;
        REQUIRE(Math::Equal(logarithm(1.0f), 0.0f));
        REQUIRE(Math::Equal(logarithm(10.0f), 1.0f));
        REQUIRE(Math::Equal(logarithm(100.0f), 2.0f));
        REQUIRE(Math::Equal(logarithm(1000.0f), 3.0f));
        REQUIRE(Math::Equal(logarithm(10000.0f), 4.0f));
    }

    // TODO(3011): Broken due to non-constexpr Log, implement or wait until C++26
    //SECTION("Logarithm (base 10) derivative value")
    //{
    //    constexpr MF::Derivative<MF::Logarithm<f32, 10.0f>> derivative;
    //    REQUIRE(Math::Equal(derivative(1.0f), 1.0f));
    //    REQUIRE(Math::Equal(derivative(10.0f), 0.1f));
    //    REQUIRE(Math::Equal(derivative(100.0f), 0.01f));
    //    REQUIRE(Math::Equal(derivative(1000.0f), 0.001f));
    //    REQUIRE(Math::Equal(derivative(10000.0f), 0.0001f));
    //}

    //SECTION("Logarithm (base 10) 2nd order derivative value")
    //{
    //    constexpr MF::Derivative<MF::Logarithm<f32, 10.0f>, 2> derivative;
    //    REQUIRE(Math::Equal(derivative(1.0f), -1.0f));
    //    REQUIRE(Math::Equal(derivative(10.0f), -0.01f));
    //    REQUIRE(Math::Equal(derivative(100.0f), -0.0001f));
    //    REQUIRE(Math::Equal(derivative(1000.0f), -0.000001f));
    //    REQUIRE(Math::Equal(derivative(10000.0f), -0.00000001f));
    //}
}
