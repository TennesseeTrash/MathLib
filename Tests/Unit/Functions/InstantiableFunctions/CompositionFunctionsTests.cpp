#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using f32 = Math::f32;
using Math::Equal;

TEST_CASE("Test Minus composite function")
{
    using Linear = Math::Function::Linear<f32, 2.0f, 1.0f>;
    using Minus = Math::Function::Minus<Linear>;

    SECTION("Minus value")
    {
        constexpr Minus minus;
        REQUIRE(Equal(minus(0.0f), -1.0f));
        REQUIRE(Equal(minus(1.0f), -3.0f));
        REQUIRE(Equal(minus(2.0f), -5.0f));
        REQUIRE(Equal(minus(3.0f), -7.0f));
        REQUIRE(Equal(minus(4.0f), -9.0f));
    }

    SECTION("Minus derivative value")
    {
        constexpr Math::Function::Derivative<Minus> derivative;
        REQUIRE(Equal(derivative(0.0f), -2.0f));
        REQUIRE(Equal(derivative(1.0f), -2.0f));
        REQUIRE(Equal(derivative(2.0f), -2.0f));
        REQUIRE(Equal(derivative(3.0f), -2.0f));
        REQUIRE(Equal(derivative(4.0f), -2.0f));
    }

    SECTION("Minus 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Minus, 2> derivative;
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 0.0f));
        REQUIRE(Equal(derivative(2.0f), 0.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
    }
}

TEST_CASE("Test Add composite function")
{
    using Constant = Math::Function::Constant<f32, 4.0f>;
    using Linear = Math::Function::Linear<f32, 2.0f, 1.0f>;
    using Power = Math::Function::Power<f32, 2.0f>;
    using Add = Math::Function::Add<Constant, Linear, Power>;

    SECTION("Add value")
    {
        constexpr Add sum;
        REQUIRE(Equal(sum(0.0f), 5.0f));
        REQUIRE(Equal(sum(1.0f), 8.0f));
        REQUIRE(Equal(sum(2.0f), 13.0f));
        REQUIRE(Equal(sum(3.0f), 20.0f));
        REQUIRE(Equal(sum(4.0f), 29.0f));
    }

    SECTION("Add derivative value")
    {
        constexpr Math::Function::Derivative<Add> derivative;
        REQUIRE(Equal(derivative(0.0f), 2.0f));
        REQUIRE(Equal(derivative(1.0f), 4.0f));
        REQUIRE(Equal(derivative(2.0f), 6.0f));
        REQUIRE(Equal(derivative(3.0f), 8.0f));
        REQUIRE(Equal(derivative(4.0f), 10.0f));
    }

    SECTION("Add 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Add, 2> derivative;
        REQUIRE(Equal(derivative(0.0f), 2.0f));
        REQUIRE(Equal(derivative(1.0f), 2.0f));
        REQUIRE(Equal(derivative(2.0f), 2.0f));
        REQUIRE(Equal(derivative(3.0f), 2.0f));
        REQUIRE(Equal(derivative(4.0f), 2.0f));
    }
}

TEST_CASE("Test Subtract composite function")
{
    using Quadratic = Math::Function::Quadratic<f32, 3.0f, 2.0f, 1.0f>;
    using Linear = Math::Function::Linear<f32, 2.0f, 1.0f>;
    using Subtract = Math::Function::Subtract<Quadratic, Linear>;

    SECTION("Subtract value")
    {
        constexpr Subtract difference;
        REQUIRE(Equal(difference(0.0f), 0.0f));
        REQUIRE(Equal(difference(1.0f), 3.0f));
        REQUIRE(Equal(difference(2.0f), 12.0f));
        REQUIRE(Equal(difference(3.0f), 27.0f));
        REQUIRE(Equal(difference(4.0f), 48.0f));
    }

    SECTION("Subtract derivative value")
    {
        constexpr Math::Function::Derivative<Subtract> derivative;
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 6.0f));
        REQUIRE(Equal(derivative(2.0f), 12.0f));
        REQUIRE(Equal(derivative(3.0f), 18.0f));
        REQUIRE(Equal(derivative(4.0f), 24.0f));
    }

    SECTION("Subtract 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Subtract, 2> derivative;
        REQUIRE(Equal(derivative(0.0f), 6.0f));
        REQUIRE(Equal(derivative(1.0f), 6.0f));
        REQUIRE(Equal(derivative(2.0f), 6.0f));
        REQUIRE(Equal(derivative(3.0f), 6.0f));
        REQUIRE(Equal(derivative(4.0f), 6.0f));
    }
}

TEST_CASE("Test Multiply conposite function")
{
    using Linear = Math::Function::Linear<f32, 2.0f, 0.0f>;
    using Multiplied = Math::Function::Multiply<Linear, Linear>;

    SECTION("Multiply value")
    {
        constexpr Multiplied product;
        REQUIRE(Equal(product(0.0f), 0.0f));
        REQUIRE(Equal(product(1.0f), 4.0f));
        REQUIRE(Equal(product(2.0f), 16.0f));
        REQUIRE(Equal(product(3.0f), 36.0f));
        REQUIRE(Equal(product(4.0f), 64.0f));
    }

    SECTION("Multiply derivative value")
    {
        constexpr Math::Function::Derivative<Multiplied> derivative;
        REQUIRE(Equal(derivative(0.0f), 0.0f));
        REQUIRE(Equal(derivative(1.0f), 8.0f));
        REQUIRE(Equal(derivative(2.0f), 16.0f));
        REQUIRE(Equal(derivative(3.0f), 24.0f));
        REQUIRE(Equal(derivative(4.0f), 32.0f));
    }

    SECTION("Multiply 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Multiplied, 2> derivative;
        REQUIRE(Equal(derivative(0.0f), 8.0f));
        REQUIRE(Equal(derivative(1.0f), 8.0f));
        REQUIRE(Equal(derivative(2.0f), 8.0f));
        REQUIRE(Equal(derivative(3.0f), 8.0f));
        REQUIRE(Equal(derivative(4.0f), 8.0f));
    }
}

TEST_CASE("Test Divide composite function")
{
    using Quadratic = Math::Function::Quadratic<f32, 1.0f, 0.0f, 0.0f>;
    using Linear = Math::Function::Linear<f32, 1.0f, 0.0f>;
    using Divide = Math::Function::Divide<Quadratic, Linear>;

    SECTION("Divide value")
    {
        constexpr Divide quotient;
        REQUIRE(Equal(quotient(1.0f), 1.0f));
        REQUIRE(Equal(quotient(2.0f), 2.0f));
        REQUIRE(Equal(quotient(3.0f), 3.0f));
        REQUIRE(Equal(quotient(4.0f), 4.0f));
        REQUIRE(Equal(quotient(5.0f), 5.0f));
    }

    SECTION("Divide derivative value")
    {
        constexpr Math::Function::Derivative<Divide> derivative;
        REQUIRE(Equal(derivative(1.0f), 1.0f));
        REQUIRE(Equal(derivative(2.0f), 1.0f));
        REQUIRE(Equal(derivative(3.0f), 1.0f));
        REQUIRE(Equal(derivative(4.0f), 1.0f));
        REQUIRE(Equal(derivative(5.0f), 1.0f));
    }

    SECTION("Divide 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Divide, 2> derivative;
        REQUIRE(Equal(derivative(1.0f), 0.0f));
        REQUIRE(Equal(derivative(2.0f), 0.0f));
        REQUIRE(Equal(derivative(3.0f), 0.0f));
        REQUIRE(Equal(derivative(4.0f), 0.0f));
        REQUIRE(Equal(derivative(5.0f), 0.0f));
    }
}

TEST_CASE("Test Compose composite function")
{
    using Linear = Math::Function::Linear<f32, 2.0f, 0.0f>;
    using Composed = Math::Function::Compose<Math::Function::NaturalLogarithm<f32>, Linear>;

    SECTION("Compose value")
    {
        static constexpr f32 e = Math::Constant::E<f32>;
        constexpr Composed composed;
        REQUIRE(Equal(composed(0.5f * e), 1.0f));
        REQUIRE(Equal(composed(0.5f * Math::Squared(e)), 2.0f));
        REQUIRE(Equal(composed(0.5f * Math::Cubed(e)), 3.0f));
        REQUIRE(Equal(composed(0.5f * Math::Pow(e, f32(4.0f))), 4.0f));
        REQUIRE(Equal(composed(0.5f * Math::Pow(e, f32(5.0f))), 5.0f));
    }

    SECTION("Compose derivative value")
    {
        constexpr Math::Function::Derivative<Composed> derivative;
        REQUIRE(Equal(derivative(1.0f), 1.0f));
        REQUIRE(Equal(derivative(2.0f), 0.5f));
        REQUIRE(Equal(derivative(3.0f), 1.0f / 3.0f));
        REQUIRE(Equal(derivative(4.0f), 0.25f));
        REQUIRE(Equal(derivative(5.0f), 0.2f));
    }

    SECTION("Compose 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<Composed, 2> derivative;
        REQUIRE(Equal(derivative(1.0f), -1.0f));
        REQUIRE(Equal(derivative(2.0f), -0.25f));
        REQUIRE(Equal(derivative(3.0f), -1.0f / 9.0f));
        REQUIRE(Equal(derivative(4.0f), -0.0625f));
        REQUIRE(Equal(derivative(5.0f), -0.04f));
    }
}

TEST_CASE("Test PowerCompose composite function")
{
    using Constant = Math::Function::Constant<f32, Math::Constant::E<f32>>;
    using Linear = Math::Function::Linear<f32, 1.0f, 0.0f>;
    using PowerComposed = Math::Function::PowerCompose<Constant, Linear>;
    constexpr Math::Function::Exponential<f32> exponential;

    SECTION("PowerCompose value")
    {
        constexpr PowerComposed powerComposition;
        REQUIRE(Equal(powerComposition(0.0f), exponential(0.0f)));
        REQUIRE(Equal(powerComposition(1.0f), exponential(1.0f)));
        REQUIRE(Equal(powerComposition(2.0f), exponential(2.0f)));
        REQUIRE(Equal(powerComposition(3.0f), exponential(3.0f)));
        REQUIRE(Equal(powerComposition(4.0f), exponential(4.0f)));
    }

    SECTION("PowerCompose derivative value")
    {
        constexpr Math::Function::Derivative<PowerComposed> derivative;
        REQUIRE(Equal(derivative(0.0f), exponential(0.0f)));
        REQUIRE(Equal(derivative(1.0f), exponential(1.0f)));
        REQUIRE(Equal(derivative(2.0f), exponential(2.0f)));
        REQUIRE(Equal(derivative(3.0f), exponential(3.0f), f32(0.000002f)));
        REQUIRE(Equal(derivative(4.0f), exponential(4.0f), f32(0.000004f)));
    }

    SECTION("PowerCompose 2nd order derivative value")
    {
        constexpr Math::Function::Derivative<PowerComposed, 2> derivative;
        REQUIRE(Equal(derivative(0.0f), exponential(0.0f)));
        REQUIRE(Equal(derivative(1.0f), exponential(1.0f)));
        REQUIRE(Equal(derivative(2.0f), exponential(2.0f)));
        REQUIRE(Equal(derivative(3.0f), exponential(3.0f), f32(0.000005f)));
        REQUIRE(Equal(derivative(4.0f), exponential(4.0f), f32(0.00001f)));
    }
}
