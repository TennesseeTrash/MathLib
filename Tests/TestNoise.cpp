#include <catch2/catch_test_macros.hpp>
#include <Math/Noise/Perlin.hpp>

TEST_CASE("Test Perlin noise", "[Math][Noise]")
{
    Math::PerlinNoise<Math::f32> noise;

    SECTION("Test consistency")
    {
        auto sample1 = noise(0.0f, 0.0f);
        auto sample2 = noise(0.0f, 0.0f);
        REQUIRE(Math::Equal(sample1, sample2));

        auto sample3 = noise(1.0f, 1.0f, 1.0f);
        auto sample4 = noise(1.0f, 1.0f, 1.0f);
        REQUIRE(Math::Equal(sample3, sample4));

        auto sample5 = noise(1.0f, 1.0f, 1.0f, 1.0f);
        auto sample6 = noise(1.0f, 1.0f, 1.0f, 1.0f);
        REQUIRE(Math::Equal(sample5, sample6));
    }

    SECTION("Test range")
    {
        auto sample1 = noise(0.0f, 0.0f);
        REQUIRE(sample1 >= 0.0f);
        REQUIRE(sample1 <= 1.0f);

        auto sample2 = noise(1.0f, 1.0f, 1.0f);
        REQUIRE(sample2 >= 0.0f);
        REQUIRE(sample2 <= 1.0f);

        auto sample3 = noise(1.0f, 1.0f, 1.0f, 1.0f);
        REQUIRE(sample3 >= 0.0f);
        REQUIRE(sample3 <= 1.0f);
    }
}
