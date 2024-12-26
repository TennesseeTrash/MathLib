#include <catch2/catch_test_macros.hpp>
#include <Math/Random.hpp>

using namespace Math::Types;
using Math::Cast;

// TODO(3011): Add tests for unequal sizes.

#include <iostream>
#include <iomanip>

namespace
{
    template <typename T = u32>
    class ConstantFakeRNG
    {
    public:
        using ValueType = T;
        ConstantFakeRNG(T value) : mValue(value) {}
        ValueType operator()() { return mValue; }

        // These are here to satisfy the RandomNumberGenerator concept.
        [[maybe_unused]] ConstantFakeRNG Jump() { return *this; }
        [[maybe_unused]] ConstantFakeRNG LongJump() { return *this; }
    private:
        ValueType mValue;
    };

    // Deduction guide
    template <typename T>
    ConstantFakeRNG(T) -> ConstantFakeRNG<T>;
}

TEST_CASE("Make sure the fake RNG implementation is valid", "[Math][Random]")
{
    STATIC_REQUIRE(Math::Concept::RandomNumberGenerator<ConstantFakeRNG<u32>>);
    STATIC_REQUIRE(Math::Concept::Distribution<Math::UniformDistribution<u32>, ConstantFakeRNG<u32>>);
}

TEST_CASE("UniformDistribution tests with equal type sizes", "[Math][Random]")
{
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

TEST_CASE("UniformDistribution tests when RNG has a larger size type", "[Math][Random]")
{
    // Note(3011): An implementation detail that might help in understanding these is that
    // the uniform distribution discards the lower bits when the value type is smaller
    // than the RNG's value type.

    SECTION("Check u64 distribution correctness with a u32 RNG")
    {
        Math::UniformDistribution<u32> distribution;
        {
            ConstantFakeRNG rng(u64::Min());
            REQUIRE(distribution(rng) == u32::Min());
        }
        {
            ConstantFakeRNG rng(u64::Min() + 1);
            REQUIRE(distribution(rng) == u32::Min());
        }
        {
            ConstantFakeRNG rng(Math::Cast<u64>(u32::Max()));
            REQUIRE(distribution(rng) == 0u);
        }
        {
            ConstantFakeRNG rng(u64::Max() - 1);
            REQUIRE(distribution(rng) == u32::Max());
        }
        {
            ConstantFakeRNG rng(u64::Max());
            REQUIRE(distribution(rng) == u32::Max());
        }
    }

    SECTION("Check i32 distribution correctness with a u64 RNG")
    {
        Math::UniformDistribution<i32> distribution;
        {
            ConstantFakeRNG rng(u64::Min());
            REQUIRE(distribution(rng) == i32::Min());
        }
        {
            ConstantFakeRNG rng(Cast<u64>(u32::Max()));
            REQUIRE(distribution(rng) == i32::Min());
        }
        {
            ConstantFakeRNG rng(u64::Max());
            REQUIRE(distribution(rng) == i32::Max());
        }
    }

    // TODO(3011): These tests are still woefully incomplete.
}

TEST_CASE("UniformDistribution with a floating point type", "[Math][Random]")
{
    // Note(3011): When these tests are built, the compiler will shout that there
    // are unsafe float comparisons, but that is intentional here.

    SECTION("Check f32 correctness in 0.0-1.0 range")
    {
        Math::UniformDistribution<f32> distribution;
        {
            ConstantFakeRNG rng(u32::Min());
            REQUIRE(distribution(rng) == 0.0f);
        }
        {
            ConstantFakeRNG rng(u32::Max() - 512);
            REQUIRE(distribution(rng) < 1.0f);
        }
        {
            ConstantFakeRNG rng(u32::Max());
            REQUIRE(distribution(rng) == 1.0f);
        }
    }

    SECTION("Check f64 correctness in 0.0-1.0 range")
    {
        Math::UniformDistribution<f64> distribution;
        {
            ConstantFakeRNG<u64> rng(u64::Min());
            REQUIRE(distribution(rng) == 0.0);
        }
        {
            ConstantFakeRNG<u64> rng(u64::Max() - 8192);
            REQUIRE(distribution(rng) < 1.0);
        }
        {
            ConstantFakeRNG<u64> rng(u64::Max());
            REQUIRE(distribution(rng) == 1.0);
        }
    }
}
