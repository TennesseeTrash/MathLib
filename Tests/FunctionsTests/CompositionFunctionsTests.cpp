#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

namespace MF = Math::Function;
using f32 = Math::f32;

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

TEST_CASE("Test Multiply conposite function")
{
    using Linear = MF::Linear<f32, 2.0f, 0.0f>;
    using Multiplied = MF::Multiply<Linear, Linear>;

    SECTION("Multiply value")
    {
        constexpr Multiplied product;
        REQUIRE(Math::Equal(product(0.0f), 0.0f));
        REQUIRE(Math::Equal(product(1.0f), 4.0f));
        REQUIRE(Math::Equal(product(2.0f), 16.0f));
        REQUIRE(Math::Equal(product(3.0f), 36.0f));
        REQUIRE(Math::Equal(product(4.0f), 64.0f));
    }

    SECTION("Multiply derivative value")
    {
        constexpr MF::Derivative<Multiplied> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 16.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 24.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 32.0f));
    }

    SECTION("Multiply 2nd order derivative value")
    {
        constexpr MF::Derivative<Multiplied, 2> derivative;
        REQUIRE(Math::Equal(derivative(0.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(1.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 8.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 8.0f));
    }
}

TEST_CASE("Test Divide composite function")
{
    using Quadratic = MF::Quadratic<f32, 1.0f, 0.0f, 0.0f>;
    using Linear = MF::Linear<f32, 1.0f, 0.0f>;
    using Divide = MF::Divide<Quadratic, Linear>;

    SECTION("Divide value")
    {
        constexpr Divide quotient;
        REQUIRE(Math::Equal(quotient(1.0f), 1.0f));
        REQUIRE(Math::Equal(quotient(2.0f), 2.0f));
        REQUIRE(Math::Equal(quotient(3.0f), 3.0f));
        REQUIRE(Math::Equal(quotient(4.0f), 4.0f));
        REQUIRE(Math::Equal(quotient(5.0f), 5.0f));
    }

    SECTION("Divide derivative value")
    {
        constexpr MF::Derivative<Divide> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(5.0f), 1.0f));
    }

    SECTION("Divide 2nd order derivative value")
    {
        constexpr MF::Derivative<Divide, 2> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(3.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.0f));
        REQUIRE(Math::Equal(derivative(5.0f), 0.0f));
    }
}

TEST_CASE("Test Compose composite function")
{
    using Linear = MF::Linear<f32, 2.0f, 0.0f>;
    using Composed = MF::Compose<MF::NaturalLogarithm<f32>, Linear>;

    SECTION("Compose value")
    {
        static constexpr f32 e = Math::Constants::E<f32>;
        constexpr Composed composed;
        REQUIRE(Math::Equal(composed(0.5f * e), 1.0f));
        REQUIRE(Math::Equal(composed(0.5f * Math::Squared(e)), 2.0f));
        REQUIRE(Math::Equal(composed(0.5f * Math::Cubed(e)), 3.0f));
        REQUIRE(Math::Equal(composed(0.5f * Math::Pow(e, f32(4.0f))), 4.0f));
        REQUIRE(Math::Equal(composed(0.5f * Math::Pow(e, f32(5.0f))), 5.0f));
    }

    SECTION("Compose derivative value")
    {
        constexpr MF::Derivative<Composed> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), 1.0f));
        REQUIRE(Math::Equal(derivative(2.0f), 0.5f));
        REQUIRE(Math::Equal(derivative(3.0f), 1.0f / 3.0f));
        REQUIRE(Math::Equal(derivative(4.0f), 0.25f));
        REQUIRE(Math::Equal(derivative(5.0f), 0.2f));
    }

    SECTION("Compose 2nd order derivative value")
    {
        constexpr MF::Derivative<Composed, 2> derivative;
        REQUIRE(Math::Equal(derivative(1.0f), -1.0f));
        REQUIRE(Math::Equal(derivative(2.0f), -0.25f));
        REQUIRE(Math::Equal(derivative(3.0f), -1.0f / 9.0f));
        REQUIRE(Math::Equal(derivative(4.0f), -0.0625f));
        REQUIRE(Math::Equal(derivative(5.0f), -0.04f));
    }
}

TEST_CASE("Test PowerCompose composite function")
{
    using Constant = MF::Constant<f32, Math::Constants::E<f32>>;
    using Linear = MF::Linear<f32, 1.0f, 0.0f>;
    using PowerComposed = MF::PowerCompose<Constant, Linear>;

    SECTION("PowerCompose value")
    {
        constexpr PowerComposed powerComposition;
        constexpr MF::Exponential<f32> exponential;
        REQUIRE(Math::Equal(powerComposition(0.0f), exponential(0.0f)));
        REQUIRE(Math::Equal(powerComposition(1.0f), exponential(1.0f)));
        REQUIRE(Math::Equal(powerComposition(2.0f), exponential(2.0f)));
        REQUIRE(Math::Equal(powerComposition(3.0f), exponential(3.0f)));
        REQUIRE(Math::Equal(powerComposition(4.0f), exponential(4.0f)));
    }

    SECTION("PowerCompose derivative value")
    {
        constexpr MF::Derivative<PowerComposed> derivative;
        constexpr MF::Exponential<f32> exponential;
        REQUIRE(Math::Equal(derivative(0.0f), exponential(0.0f)));
        REQUIRE(Math::Equal(derivative(1.0f), exponential(1.0f)));
        REQUIRE(Math::Equal(derivative(2.0f), exponential(2.0f)));
        REQUIRE(Math::Equal(derivative(3.0f), exponential(3.0f), f32(0.000002f)));
        REQUIRE(Math::Equal(derivative(4.0f), exponential(4.0f), f32(0.000004f)));
    }

    SECTION("PowerCompose 2nd order derivative value")
    {
        constexpr MF::Derivative<PowerComposed, 2> derivative;
        constexpr MF::Exponential<f32> exponential;
        REQUIRE(Math::Equal(derivative(0.0f), exponential(0.0f)));
        REQUIRE(Math::Equal(derivative(1.0f), exponential(1.0f)));
        REQUIRE(Math::Equal(derivative(2.0f), exponential(2.0f)));
        REQUIRE(Math::Equal(derivative(3.0f), exponential(3.0f), f32(0.000005f)));
        REQUIRE(Math::Equal(derivative(4.0f), exponential(4.0f), f32(0.00001f)));
    }
}
