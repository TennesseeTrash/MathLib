#include <catch2/catch_test_macros.hpp>
#include <Math/Common/Types.hpp>
#include <Math/Functions.hpp>

using Math::f32;
using Math::i32;

TEST_CASE("Test conversions from float to std::int32_t and back")
{
    SECTION("float to std::int32_t")
    {
        REQUIRE(Math::Cast<std::int32_t>(-1.0f) == -1);
        REQUIRE(Math::Cast<std::int32_t>(-0.5f) ==  0);
        REQUIRE(Math::Cast<std::int32_t>( 0.0f) ==  0);
        REQUIRE(Math::Cast<std::int32_t>( 0.5f) ==  0);
        REQUIRE(Math::Cast<std::int32_t>( 1.0f) ==  1);
    }

    SECTION("std::int32_t to float")
    {
        REQUIRE(Math::Equal(Math::Cast<float>(-1), -1.0f));
        REQUIRE(Math::Equal(Math::Cast<float>( 0),  0.0f));
        REQUIRE(Math::Equal(Math::Cast<float>( 1),  1.0f));
    }
}

TEST_CASE("Test conversions from f32 to i32 and back")
{
    SECTION("f32 to i32")
    {
        REQUIRE(Math::Cast<i32>(f32(-1.0f)) == -1);
        REQUIRE(Math::Cast<i32>(f32(-0.5f)) == 0);
        REQUIRE(Math::Cast<i32>(f32(0.0f )) == 0);
        REQUIRE(Math::Cast<i32>(f32(0.5f )) == 0);
        REQUIRE(Math::Cast<i32>(f32(1.0f )) == 1);
    }

    SECTION("i32 to f32")
    {
        REQUIRE(Math::Equal(Math::Cast<f32>(i32(-1)), -1.0f));
        REQUIRE(Math::Equal(Math::Cast<f32>(i32( 0)),  0.0f));
        REQUIRE(Math::Equal(Math::Cast<f32>(i32( 1)),  1.0f));
    }
}
