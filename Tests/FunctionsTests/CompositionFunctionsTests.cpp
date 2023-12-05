#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

namespace MF = Math::Function;
using f32 = Math::f32;

// TODO(3011): Add tests for Minus, Subtract, Multiply, Divide, Compose and PowerCompose

TEST_CASE("Test Minus composite function")
{
    using Linear = MF::Linear<f32, 2.0f, 1.0f>;
    using Minus = MF::Minus<Linear>;

    SECTION("Minus value")
    {
        constexpr Minus minus;
        REQUIRE(Math::Equal(minus(0.0f), -1.0f));
        REQUIRE(Math::Equal(minus(1.0f), -3.0f));
        REQUIRE(Math::Equal(minus(2.0f), -5.0f));
        REQUIRE(Math::Equal(minus(3.0f), -7.0f));
        REQUIRE(Math::Equal(minus(4.0f), -9.0f));
    }

    SECTION("Minus derivative value")
    {
        constexpr MF::Derivative<Minus> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), -2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), -2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), -2.0f));
        REQUIRE(Math::Equal(derivative(3.0f), -2.0f));
        REQUIRE(Math::Equal(derivative(4.0f), -2.0f));
    }

    SECTION("Minus 2nd order derivative value")
    {
        constexpr MF::Derivative<Minus, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.0f));
    }
}

TEST_CASE("Test Add composite function")
{
    using Constant = MF::Constant<f32, 4.0f>;
    using Linear = MF::Linear<f32, 2.0f, 1.0f>;
    using Power = MF::Power<f32, 2.0f>;
    using Add = MF::Add<Constant, Linear, Power>;

    SECTION("Add value")
    {
        constexpr Add sum;
        REQUIRE(Math::Equal(sum(0.0f), 5.0f));
        REQUIRE(Math::Equal(sum(1.0f), 8.0f));
        REQUIRE(Math::Equal(sum(2.0f), 13.0f));
        REQUIRE(Math::Equal(sum(3.0f), 20.0f));
        REQUIRE(Math::Equal(sum(4.0f), 29.0f));
    }

    SECTION("Add derivative value")
    {
        constexpr MF::Derivative<Add> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 4.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 10.0f));
    }

    SECTION("Add 2nd order derivative value")
    {
        constexpr MF::Derivative<Add, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 2.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 2.0f));
    }
}

TEST_CASE("Test Subtract composite function")
{
    using Quadratic = MF::Quadratic<f32, 3.0f, 2.0f, 1.0f>;
    using Linear = MF::Linear<f32, 2.0f, 1.0f>;
    using Subtract = MF::Subtract<Quadratic, Linear>;

    SECTION("Subtract value")
    {
        constexpr Subtract difference;
        REQUIRE(Math::Equal(difference(0.0f), 0.0f));
        REQUIRE(Math::Equal(difference(1.0f), 3.0f));
        REQUIRE(Math::Equal(difference(2.0f), 12.0f));
        REQUIRE(Math::Equal(difference(3.0f), 27.0f));
        REQUIRE(Math::Equal(difference(4.0f), 48.0f));
    }

    SECTION("Subtract derivative value")
    {
        constexpr MF::Derivative<Subtract> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 12.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 18.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 24.0f));
    }

    SECTION("Subtract 2nd order derivative value")
    {
        constexpr MF::Derivative<Subtract, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 6.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 6.0f));
    }
}
