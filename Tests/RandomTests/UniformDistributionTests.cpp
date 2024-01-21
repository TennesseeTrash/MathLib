#include <catch2/catch_test_macros.hpp>
#include <Math/Random.hpp>

using Math::u32;
using Math::i32;

// TODO(3011): Add tests for unequal sizes.

namespace
{
    class ConstantFakeRNG
    {
    public:
        using ValueType = u32;
        ConstantFakeRNG(u32 value) : mValue(value) {}
        u32 operator()() { return mValue; }
        [[maybe_unused]] ConstantFakeRNG Jump() { return *this; }
        [[maybe_unused]] ConstantFakeRNG LongJump() { return *this; }
    private:
        u32 mValue;
    };
}

TEST_CASE("Basic UniformDistribution tests", "[Math][Random]")
{
    SECTION("Check correctness")
    {
        STATIC_REQUIRE(Math::Concept::RandomNumberGenerator<ConstantFakeRNG>);
        STATIC_REQUIRE(Math::Concept::Distribution<Math::UniformDistribution<u32>, ConstantFakeRNG>);
    }

    SECTION("Check u32 correctness in min/max range")
    {
        Math::UniformDistribution<u32> distribution;

        {
            ConstantFakeRNG rng(u32::Min());
            REQUIRE(distribution(rng) == u32::Min());
        }
        {
            ConstantFakeRNG rng(u32::Max() - 1);
            REQUIRE(distribution(rng) == (u32::Max() - 1));
        }
        {
            ConstantFakeRNG rng(u32::Max());
            REQUIRE(distribution(rng) == u32::Max());
        }
    }

    SECTION("Check i32 correctness in min/max range")
    {
        Math::UniformDistribution<i32> distribution;

        {
            ConstantFakeRNG rng(u32::Min());
            REQUIRE(distribution(rng) == i32::Min());
        }
        {
            ConstantFakeRNG rng(u32::Max() - 1);
            REQUIRE(distribution(rng) == (i32::Max() - 1));
        }
        {
            ConstantFakeRNG rng(u32::Max());
            REQUIRE(distribution(rng) == i32::Max());
        }
    }

    SECTION("Check u32 correctness in 0-100 range")
    {
        Math::UniformDistribution<u32> distribution(0, 100);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == i);
        }
    }

    SECTION("Check i32 correctness in 0-100 range")
    {
        Math::UniformDistribution<i32> distribution(0, 100);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == Cast<i32>(i));
        }
    }

    SECTION("Check u32 correctness in 0-100 range with 0-50 range")
    {
        Math::UniformDistribution<u32> distribution(0, 50);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == (i % 51));
        }
    }

    SECTION("Check i32 correctness in 0-100 range with 0-50 range")
    {
        Math::UniformDistribution<i32> distribution(0, 50);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == Cast<i32>(i % 51));
        }
    }

    SECTION("Check i32 correctness in -50-50 range")
    {
        Math::UniformDistribution<i32> distribution(-50, 50);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == (Cast<i32>(i) - 50));
        }
    }

    SECTION("Check i32 correctness in -50-50 range with -25-25 range")
    {
        Math::UniformDistribution<i32> distribution(-25, 25);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == (Cast<i32>(i % 51) - 25));
        }
    }

    SECTION("Check i32 correctness in -50 to -1 range")
    {
        Math::UniformDistribution<i32> distribution(-50, -1);

        for (u32 i = 0; i <= 100; ++i)
        {
            ConstantFakeRNG rng(i);
            REQUIRE(distribution(rng) == (Cast<i32>(i % 50) - 50));
        }
    }
}
