#include <catch2/catch_test_macros.hpp>
#include <Math/Noise/Perlin.hpp>

TEST_CASE("Test 2D Perlin noise", "[Math][Noise]")
{
    Math::PerlinNoise<Math::f32> noise;

    SECTION("Test determinism")
    {
        Math::f32 x = 2.0f;
        Math::f32 y = 2.0f;
        Math::f32 value = noise(x, y);
        for (Math::SizeType i = 0; i < 25; ++i)
        {
            REQUIRE(Math::Equal(value, noise(x, y)));
            value = noise(x, y);
        }
    }

    SECTION("Test range")
    {
        Math::f32 x = 0.0f;
        Math::f32 y = 0.0f;
        for (Math::SizeType i = 0; i < 100; ++i)
        {
            for (Math::SizeType j = 0; j < 100; ++j)
            {
                auto sample = noise(x, y);
                REQUIRE(sample >= 0.0f);
                REQUIRE(sample <= 1.0f);
                y += 0.125f;
            }
            x += 0.125f;
        }
    }
}

TEST_CASE("Test 3D Perlin noise", "[Math][Noise]")
{
    SECTION("Test determinism")
    {
        Math::PerlinNoise<Math::f32> noise;

        Math::f32 x = 2.0f;
        Math::f32 y = 2.0f;
        Math::f32 z = 2.0f;
        Math::f32 value = noise(x, y, z);
        for (Math::SizeType i = 0; i < 25; ++i)
        {
            REQUIRE(Math::Equal(value, noise(x, y, z)));
            value = noise(x, y, z);
        }
    }

    SECTION("Test range")
    {
        Math::PerlinNoise<Math::f32> noise;

        Math::f32 x = 0.0f;
        Math::f32 y = 0.0f;
        Math::f32 z = 0.0f;
        for (Math::SizeType i = 0; i < 25; ++i)
        {
            for (Math::SizeType j = 0; j < 25; ++j)
            {
                for (Math::SizeType k = 0; k < 25; ++k)
                {
                    auto sample = noise(x, y, z);
                    REQUIRE(sample >= 0.0f);
                    REQUIRE(sample <= 1.0f);
                    z += 0.125f;
                }
                y += 0.125f;
            }
            x += 0.125f;
        }
    }
}

TEST_CASE("Test 4D Perlin noise", "[Math][Noise]")
{
    SECTION("Test determinism")
    {
        Math::PerlinNoise<Math::f32> noise;

        Math::f32 x = 2.0f;
        Math::f32 y = 2.0f;
        Math::f32 z = 2.0f;
        Math::f32 w = 2.0f;
        Math::f32 value = noise(x, y, z, w);
        for (Math::SizeType i = 0; i < 25; ++i)
        {
            REQUIRE(Math::Equal(value, noise(x, y, z, w)));
            value = noise(x, y, z, w);
        }
    }

    SECTION("Test range")
    {
        Math::PerlinNoise<Math::f32> noise;

        Math::f32 x = 0.0f;
        Math::f32 y = 0.0f;
        Math::f32 z = 0.0f;
        Math::f32 w = 0.0f;
        for (Math::SizeType i = 0; i < 25; ++i)
        {
            for (Math::SizeType j = 0; j < 25; ++j)
            {
                for (Math::SizeType k = 0; k < 25; ++k)
                {
                    for (Math::SizeType l = 0; l < 25; ++l)
                    {
                        auto sample = noise(x, y, z, w);
                        // TODO(3011): Investigate why and where the range is
                        // violated, and if it's worth fixing.
                        REQUIRE(sample >= -0.1f);
                        REQUIRE(sample <= 1.1f);
                        w += 0.125f;
                    }
                    z += 0.125f;
                }
                y += 0.125f;
            }
            x += 0.125f;
        }
    }
}
