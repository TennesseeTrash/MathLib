#include <catch2/catch_test_macros.hpp>
#include <Math/Transform.hpp>

TEST_CASE("Test transform multiplication", "[Math][Transform]")
{
    Math::Transform2f t21 = Math::Transform2f(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );

    Math::Transform2f t22 = Math::Transform2f(
         7.0f,  8.0f,  9.0f,
        10.0f, 11.0f, 12.0f
    );

    Math::Transform2f t23 = Math::Transform2f(
        27.0f, 30.0f,  36.0f,
        78.0f, 87.0f, 102.0f
    );

    Math::Transform3f t31 = Math::Transform3f(
        1.0f,  2.0f,  3.0f,  4.0f,
        5.0f,  6.0f,  7.0f,  8.0f,
        9.0f, 10.0f, 11.0f, 12.0f
    );

    Math::Transform3f t32 = Math::Transform3f(
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f
    );

    Math::Transform3f t33 = Math::Transform3f(
        110.0f, 116.0f, 122.0f, 132.0f,
        314.0f, 332.0f, 350.0f, 376.0f,
        518.0f, 548.0f, 578.0f, 620.0f
    );

    SECTION("Transform2f multiplication")
    {
        REQUIRE(Math::Equal(t21 * t22, t23));
    }

    SECTION("Transform3f multiplication")
    {
        REQUIRE(Math::Equal(t31 * t32, t33));
    }

    SECTION("Transform2f mutable multiplication")
    {
        t21 *= t22;
        REQUIRE(Math::Equal(t21, t23));
    }

    SECTION("Transform3f mutable multiplication")
    {
        t31 *= t32;
        REQUIRE(Math::Equal(t31, t33));
    }
}

TEST_CASE("Test transform-vector multiplication", "[Math][Transform]")
{
}

TEST_CASE("Test transform-point multiplication", "[Math][Transform]")
{
}

TEST_CASE("Test transform helpers", "[Math][Transform]")
{
}
