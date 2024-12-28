#include <catch2/catch_test_macros.hpp>
#include <Math/Constants.hpp>
#include <Math/Functions.hpp>

#include <cmath>

using namespace Math::Types;
using namespace Math::Constant;

static constexpr SizeType totalIterations = 100;

TEST_CASE("Basic Cos tests", "[Math][Functions]")
{
    SECTION("Test basic values with f32")
    {
        REQUIRE(Math::IsNan(Math::Cos(f32::NaN())));
        REQUIRE(Math::Equal(Math::Cos(f32(0.0f)), std::cos(0.0f)));
        REQUIRE(Math::Equal(Math::Cos(PiDiv2<f32>), std::cos(PiDiv2<float>)));
        REQUIRE(Math::Equal(Math::Cos(Pi<f32>), std::cos(Pi<float>)));
        REQUIRE(Math::Equal(Math::Cos(Tau<f32>), std::cos(Tau<float>)));
    }

    SECTION("Test function period")
    {
        for (SizeType i = 0; i <= totalIterations; ++i)
        {
            f32 currentValue = Math::Lerp(Math::Cast<f32>(i) / Math::Cast<f32>(totalIterations), f32(0), Tau<f32>);
            REQUIRE(Math::Equal(Math::Cos(currentValue), std::cos(Math::ToUnderlying(currentValue))));
        }
    }

    SECTION("Test larger range")
    {
        for (SizeType i = 0; i <= totalIterations; ++i)
        {
            f32 currentValue = Math::Lerp(Math::Cast<f32>(i) / Math::Cast<f32>(totalIterations), -Tau<f32> * 10.0f, Tau<f32> * 10.0f);
            REQUIRE(Math::Equal(Math::Cos(currentValue), std::cos(Math::ToUnderlying(currentValue))));
        }
    }

    SECTION("Test basic values with f64")
    {
        REQUIRE(Math::IsNan(Math::Cos(f64::NaN())));
        REQUIRE(Math::Equal(Math::Cos(f64(0.0)), std::cos(0.0)));
        REQUIRE(Math::Equal(Math::Cos(PiDiv2<f64>), std::cos(PiDiv2<double>)));
        REQUIRE(Math::Equal(Math::Cos(Pi<f64>), std::cos(Pi<double>)));
        REQUIRE(Math::Equal(Math::Cos(Tau<f64>), std::cos(Tau<double>)));
    }

    SECTION("Test function period with f64")
    {
        for (SizeType i = 0; i <= totalIterations; ++i)
        {
            f64 currentValue = Math::Lerp(Math::Cast<f64>(i) / Math::Cast<f64>(totalIterations), f64(0), Tau<f64>);
            REQUIRE(Math::Equal(Math::Cos(currentValue), std::cos(Math::ToUnderlying(currentValue))));
        }
    }

    SECTION("Test larger range with f64")
    {
        for (SizeType i = 0; i <= totalIterations; ++i)
        {
            f64 currentValue = Math::Lerp(Math::Cast<f64>(i) / Math::Cast<f64>(totalIterations), -Tau<f64> * 10.0, Tau<f64> * 10.0);
            REQUIRE(Math::Equal(Math::Cos(currentValue), std::cos(Math::ToUnderlying(currentValue))));
        }
    }
}
