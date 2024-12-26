#include <catch2/catch_test_macros.hpp>
#include <Math/Base.hpp>
#include <Math/Functions.hpp>

using namespace Math::Types;

TEST_CASE("Test whether the StrongTypes satisfy their constraints", "[Static]")
{
    SECTION("SignedSizeType")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<SizeType>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<SizeType>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<SizeType>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<SizeType>);
    }

    SECTION("SizeType")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<SizeType>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<SizeType>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<SizeType>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<SizeType>);
    }



    SECTION("i8")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<i8>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<i8>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<i8>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<i8>);
    }

    SECTION("i16")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<i16>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<i16>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<i16>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<i16>);
    }

    SECTION("i32")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<i32>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<i32>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<i32>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<i32>);
    }

    SECTION("i64")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<i64>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<i64>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<i64>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<i64>);
    }



    SECTION("u8")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<u8>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<u8>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<u8>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<u8>);
    }

    SECTION("u16")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<u16>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<u16>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<u16>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<u16>);
    }

    SECTION("u32")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<u32>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<u32>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<u32>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<u32>);
    }

    SECTION("u64")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<u64>);
        STATIC_REQUIRE(Math::Concept::StrongIntegerType<u64>);
        STATIC_REQUIRE(!Math::Concept::StrongFloatType<u64>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<u64>);
    }



    SECTION("f32")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<f32>);
        STATIC_REQUIRE(Math::Concept::StrongFloatType<f32>);
        STATIC_REQUIRE(!Math::Concept::StrongIntegerType<f32>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<f32>);
    }

    SECTION("f64")
    {
        STATIC_REQUIRE(Math::Concept::StrongType<f64>);
        STATIC_REQUIRE(Math::Concept::StrongFloatType<f64>);
        STATIC_REQUIRE(!Math::Concept::StrongIntegerType<f64>);

        STATIC_REQUIRE(Math::Concept::ArithmeticType<f64>);
    }
}

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
