#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using f32 = Math::f32;
using i32 = Math::i32;
using Math::Sqrt;
using Math::Squared;

TEST_CASE("Test Sqrt with basic values", "[Math][Functions]")
{
    SECTION("Test Sqrt with f32")
    {
        REQUIRE(Equal(Sqrt(f32(0.0f)), 0.0f));
        REQUIRE(Equal(Sqrt(f32(1.0f)), 1.0f));
        REQUIRE(Equal(Sqrt(f32(2.0f)), Math::Constants::Sqrt2<f32>));
        REQUIRE(Equal(Sqrt(f32(3.0f)), Math::Constants::Sqrt3<f32>));
        REQUIRE(Equal(Sqrt(f32(4.0f)), 2.0f));
        REQUIRE(Equal(Sqrt(f32(5.0f)), Math::Constants::Sqrt5<f32>));
        REQUIRE(Equal(Sqrt(f32(16.0f)), 4.0f));
    }

    SECTION("Test Sqrt on 100 integer squares")
    {
        for (i32 i = 0; i < 100; ++i)
        {
            f32 test = Cast<f32>(i);
            REQUIRE(Equal(Sqrt(Squared(test)), test));
        }
    }
}
