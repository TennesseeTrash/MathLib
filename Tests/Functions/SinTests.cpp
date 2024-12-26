#include <catch2/catch_test_macros.hpp>
#include <Math/Constants.hpp>
#include <Math/Functions.hpp>

#include <cmath>

using namespace Math::Types;
using namespace Math::Constant;

static constexpr f32 epsilon = 1e-14f;

TEST_CASE("Basic Sin tests", "[Math][Functions]")
{
    SECTION("Test basic values")
    {
        REQUIRE(Math::Equal(Math::Sin(f32(0.0f)), std::sinf(0.0f), epsilon));
        REQUIRE(Math::Equal(Math::Sin(Pi<f32>), std::sinf(Pi<float>), epsilon));
    }
}
