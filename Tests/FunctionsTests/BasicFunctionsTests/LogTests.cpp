#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using f32 = Math::f32;
using i32 = Math::i32;
using Math::Equal;
using Math::Log;
using Math::Squared;
using Math::Cubed;

// TODO(3011): Think up a reasonable test suite for the natural logarithm.

TEST_CASE("Test Log with basic values", "[Math][Functions]")
{
    SECTION("Trivial case")
    {
        REQUIRE(Equal(Log(1.0f), 0.0f));
    }

    SECTION("Powers of e with f32")
    {
        static constexpr auto e = Math::Constant::E<f32>;
        static constexpr auto intPow = [](f32 base, i32 exp) constexpr noexcept
        {
            f32 result = 1.0f;
            for (i32 i = 0; i < exp; ++i) result *= base;
            return result;
        };

        for (i32 i = 0; i < 50; ++i)
        {
            REQUIRE(Equal(Log(intPow(e, i)), Cast<f32>(i)));
        }
    }
}
