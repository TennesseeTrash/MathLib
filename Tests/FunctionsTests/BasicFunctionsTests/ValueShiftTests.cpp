#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

TEST_CASE("Test ValueShift functions with identical types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8")
    {
        using i8 = Math::i8;

        REQUIRE(Math::ValueShift<i8>(i8::Min()) == i8::Min());
        REQUIRE(Math::ValueShift<i8>(i8(-128 )) == i8(-128));
        REQUIRE(Math::ValueShift<i8>(i8(0    )) == i8(0));
        REQUIRE(Math::ValueShift<i8>(i8(127  )) == i8(127));
        REQUIRE(Math::ValueShift<i8>(i8::Max()) == i8::Max());
    }

    SECTION("Test ValueShift with u8")
    {
        using u8 = Math::u8;

        REQUIRE(Math::ValueShift<u8>(u8::Min()) == u8::Min());
        REQUIRE(Math::ValueShift<u8>(u8(0    )) == u8(0));
        REQUIRE(Math::ValueShift<u8>(u8(128  )) == u8(128));
        REQUIRE(Math::ValueShift<u8>(u8(255  )) == u8(255));
        REQUIRE(Math::ValueShift<u8>(u8::Max()) == u8::Max());
    }

    SECTION("Test ValueShift with i16")
    {
        using i16 = Math::i16;

        REQUIRE(Math::ValueShift<i16>(i16::Min()) == i16::Min());
        REQUIRE(Math::ValueShift<i16>(i16(-32768)) == i16(-32768));
        REQUIRE(Math::ValueShift<i16>(i16(0     )) == i16(0));
        REQUIRE(Math::ValueShift<i16>(i16(32767 )) == i16(32767));
        REQUIRE(Math::ValueShift<i16>(i16::Max()) == i16::Max());
    }

    SECTION("Test ValueShift with u16")
    {
        using u16 = Math::u16;

        REQUIRE(Math::ValueShift<u16>(u16::Min()) == u16::Min());
        REQUIRE(Math::ValueShift<u16>(u16(0    )) == u16(0));
        REQUIRE(Math::ValueShift<u16>(u16(32768)) == u16(32768));
        REQUIRE(Math::ValueShift<u16>(u16(65535)) == u16(65535));
        REQUIRE(Math::ValueShift<u16>(u16::Max()) == u16::Max());
    }
}

TEST_CASE("Test ValueShift functions with same size types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8/u8")
    {
        using i8 = Math::i8;
        using u8 = Math::u8;

        REQUIRE(Math::ValueShift<u8>(i8::Min()) == u8::Min());
        REQUIRE(Math::ValueShift<u8>(i8(-127 )) == u8(1));
        REQUIRE(Math::ValueShift<u8>(i8(0    )) == u8(128));
        REQUIRE(Math::ValueShift<u8>(i8(126  )) == u8(254));
        REQUIRE(Math::ValueShift<u8>(i8::Max()) == u8::Max());

        REQUIRE(Math::ValueShift<i8>(u8::Min()) == i8::Min());
        REQUIRE(Math::ValueShift<i8>(u8(1    )) == i8(-127));
        REQUIRE(Math::ValueShift<i8>(u8(128  )) == i8(0));
        REQUIRE(Math::ValueShift<i8>(u8(254  )) == i8(126));
        REQUIRE(Math::ValueShift<i8>(u8::Max()) == i8::Max());
    }

    SECTION("Test ValueShift with i16/u16")
    {
        using i16 = Math::i16;
        using u16 = Math::u16;

        REQUIRE(Math::ValueShift<u16>(i16::Min( )) == u16::Min());
        REQUIRE(Math::ValueShift<u16>(i16(-32767)) == u16(1));
        REQUIRE(Math::ValueShift<u16>(i16(0     )) == u16(32768));
        REQUIRE(Math::ValueShift<u16>(i16(32766 )) == u16(65534));
        REQUIRE(Math::ValueShift<u16>(i16::Max( )) == u16::Max());

        REQUIRE(Math::ValueShift<i16>(u16::Min()) == i16::Min());
        REQUIRE(Math::ValueShift<i16>(u16(1    )) == i16(-32767));
        REQUIRE(Math::ValueShift<i16>(u16(32768)) == i16(0));
        REQUIRE(Math::ValueShift<i16>(u16(65534)) == i16(32766));
        REQUIRE(Math::ValueShift<i16>(u16::Max()) == i16::Max());
    }

    SECTION("Test ValueShift with i32/u32")
    {
        using i32 = Math::i32;
        using u32 = Math::u32;

        REQUIRE(Math::ValueShift<u32>(i32::Min()      ) == u32::Min());
        REQUIRE(Math::ValueShift<u32>(i32(-2147483647)) == u32(1));
        REQUIRE(Math::ValueShift<u32>(i32(0          )) == u32(2147483648));
        REQUIRE(Math::ValueShift<u32>(i32(2147483646 )) == u32(4294967294));
        REQUIRE(Math::ValueShift<u32>(i32::Max()      ) == u32::Max());

        REQUIRE(Math::ValueShift<i32>(u32::Min()     ) == i32::Min());
        REQUIRE(Math::ValueShift<i32>(u32(1         )) == i32(-2147483647));
        REQUIRE(Math::ValueShift<i32>(u32(2147483648)) == i32(0));
        REQUIRE(Math::ValueShift<i32>(u32(4294967294)) == i32(2147483646));
        REQUIRE(Math::ValueShift<i32>(u32::Max()     ) == i32::Max());
    }

    SECTION("Test ValueShift with i64/u64")
    {
        using i64 = Math::i64;
        using u64 = Math::u64;

        REQUIRE(Math::ValueShift<u64>(i64::Min()                 ) == u64::Min());
        REQUIRE(Math::ValueShift<u64>(i64(-9223372036854775807ll)) == u64(1));
        REQUIRE(Math::ValueShift<u64>(i64(0                     )) == u64(9223372036854775808ull));
        REQUIRE(Math::ValueShift<u64>(i64(9223372036854775806ll )) == u64(18446744073709551614ull));
        REQUIRE(Math::ValueShift<u64>(i64::Max()                 ) == u64::Max());

        REQUIRE(Math::ValueShift<i64>(u64::Min()                  ) == i64::Min());
        REQUIRE(Math::ValueShift<i64>(u64(1                      )) == i64(-9223372036854775807ll));
        REQUIRE(Math::ValueShift<i64>(u64(9223372036854775808ull )) == i64(0));
        REQUIRE(Math::ValueShift<i64>(u64(18446744073709551614ull)) == i64(9223372036854775806ll));
        REQUIRE(Math::ValueShift<i64>(u64::Max()                  ) == i64::Max());
    }
}

TEST_CASE("Test widening ValueShift functions (from smaller size to larger)", "[Math][Functions]")
{
    // TODO(3011): Implement as test case name suggests.
}

TEST_CASE("Test narrowing ValueShift functions (from larger size to smaller)", "[Math][Functions]")
{
    // TODO(3011): Implement as test case name suggests.
}
