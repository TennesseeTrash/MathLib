#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::i8;
using Math::i16;
using Math::i32;
using Math::i64;

using Math::u8;
using Math::u16;
using Math::u32;
using Math::u64;

using Math::ValueShift;

// TODO(3011): Make the more anaemic tests more robust

TEST_CASE("Test ValueShift function with identical types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8")
    {
        REQUIRE(ValueShift<i8>(i8::Min()) == i8::Min());
        REQUIRE(ValueShift<i8>(i8(-64  )) == i8(-64));
        REQUIRE(ValueShift<i8>(i8(0    )) == i8(0));
        REQUIRE(ValueShift<i8>(i8(64   )) == i8(64));
        REQUIRE(ValueShift<i8>(i8::Max()) == i8::Max());
    }

    SECTION("Test ValueShift with u8")
    {
        REQUIRE(ValueShift<u8>(u8::Min()) == u8::Min());
        REQUIRE(ValueShift<u8>(u8(32   )) == u8(32));
        REQUIRE(ValueShift<u8>(u8(64   )) == u8(64));
        REQUIRE(ValueShift<u8>(u8(128  )) == u8(128));
        REQUIRE(ValueShift<u8>(u8::Max()) == u8::Max());
    }

    SECTION("Test ValueShift with i16")
    {
        REQUIRE(ValueShift<i16>(i16::Min() )  == i16::Min());
        REQUIRE(ValueShift<i16>(i16(-16384)) == i16(-16384));
        REQUIRE(ValueShift<i16>(i16(0     )) == i16(0));
        REQUIRE(ValueShift<i16>(i16(16384 )) == i16(16384));
        REQUIRE(ValueShift<i16>(i16::Max() )  == i16::Max());
    }

    SECTION("Test ValueShift with u16")
    {
        REQUIRE(ValueShift<u16>(u16::Min()) == u16::Min());
        REQUIRE(ValueShift<u16>(u16(8192 )) == u16(8192));
        REQUIRE(ValueShift<u16>(u16(16384)) == u16(16384));
        REQUIRE(ValueShift<u16>(u16(32768)) == u16(32768));
        REQUIRE(ValueShift<u16>(u16::Max()) == u16::Max());
    }
}

TEST_CASE("Test ValueShift function for widening with signed types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8/i16")
    {
        REQUIRE(ValueShift<i16>(i8::Min()) == i16::Min());
        REQUIRE(ValueShift<i16>(i8::Max()) == i16::Max());
    }

    SECTION("Test ValueShift with i8/i32")
    {
        REQUIRE(ValueShift<i32>(i8::Min()) == i32::Min());
        REQUIRE(ValueShift<i32>(i8::Max()) == i32::Max());
    }

    SECTION("Test ValueShift with i16/i32")
    {
        REQUIRE(ValueShift<i32>(i16::Min()) == i32::Min());
        REQUIRE(ValueShift<i32>(i16::Max()) == i32::Max());
    }

    SECTION("Test ValueShift with i32/i64")
    {
        REQUIRE(ValueShift<i64>(i32::Min()) == i64::Min());
        REQUIRE(ValueShift<i64>(i32::Max()) == i64::Max());
    }
}

TEST_CASE("Test ValueShift function for narrowing with signed types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8/i16")
    {
        REQUIRE(ValueShift<i8>(i16::Min() ) == i8::Min());
        REQUIRE(ValueShift<i8>(i16(-16384)) == i8(-64));
        REQUIRE(ValueShift<i8>(i16(0     )) == i8(0));
        REQUIRE(ValueShift<i8>(i16(16384 )) == i8(64));
        REQUIRE(ValueShift<i8>(i16::Max() ) == i8::Max());
    }

    SECTION("Test ValueShift with i8/i32")
    {
        REQUIRE(ValueShift<i8>(i32::Min()      ) == i8::Min());
        REQUIRE(ValueShift<i8>(i32(-1073741824)) == i8(-64));
        REQUIRE(ValueShift<i8>(i32(0          )) == i8(0));
        REQUIRE(ValueShift<i8>(i32(1073741824 )) == i8(64));
        REQUIRE(ValueShift<i8>(i32::Max()      ) == i8::Max());
    }

    SECTION("Test ValueShift with i16/i32")
    {
        REQUIRE(ValueShift<i16>(i32::Min()      ) == i16::Min());
        REQUIRE(ValueShift<i16>(i32(-1073741824)) == i16(-16384));
        REQUIRE(ValueShift<i16>(i32(0          )) == i16(0));
        REQUIRE(ValueShift<i16>(i32(1073741824 )) == i16(16384));
        REQUIRE(ValueShift<i16>(i32::Max()      ) == i16::Max());
    }

    SECTION("Test ValueShift with i32/i64")
    {
        REQUIRE(ValueShift<i32>(i64::Min()               ) == i32::Min());
        REQUIRE(ValueShift<i32>(i64(-4611686018427387904)) == i32(-1073741824));
        REQUIRE(ValueShift<i32>(i64(0                   )) == i32(0));
        REQUIRE(ValueShift<i32>(i64(4611686018427387904 )) == i32(1073741824));
        REQUIRE(ValueShift<i32>(i64::Max()               ) == i32::Max());
    }
}

TEST_CASE("Test ValueShift function for widening with unsigned types", "[Math][Functions]")
{
    SECTION("Test ValueShift with u8/u16")
    {
        REQUIRE(ValueShift<u16>(u8::Min()) == u16::Min());
        REQUIRE(ValueShift<u16>(u8(1    )) == u16(257));
        REQUIRE(ValueShift<u16>(u8::Max()) == u16::Max());
    }

    SECTION("Test ValueShift with u8/u32")
    {
        REQUIRE(ValueShift<u32>(u8::Min()) == u32::Min());
        REQUIRE(ValueShift<u32>(u8(1    )) == u32(16843009));
        REQUIRE(ValueShift<u32>(u8::Max()) == u32::Max());
    }

    SECTION("Test ValueShift with u16/u32")
    {
        REQUIRE(ValueShift<u32>(u16::Min()) == u32::Min());
        REQUIRE(ValueShift<u32>(u16(1    )) == u32(65537));
        REQUIRE(ValueShift<u32>(u16::Max()) == u32::Max());
    }

    SECTION("Test ValueShift with u32/u64")
    {
        REQUIRE(ValueShift<u64>(u32::Min()) == u64::Min());
        REQUIRE(ValueShift<u64>(u32(1    )) == u64(4294967297));
        REQUIRE(ValueShift<u64>(u32::Max()) == u64::Max());
    }
}

TEST_CASE("Test ValueShift function for narrowing with unsigned types", "[Math][Functions]")
{
    SECTION("Test ValueShift with u8/u16")
    {
        REQUIRE(ValueShift<u8>(u16::Min()) == u8::Min());
        REQUIRE(ValueShift<u8>(u16(8192 )) == u8(32));
        REQUIRE(ValueShift<u8>(u16(16384)) == u8(64));
        REQUIRE(ValueShift<u8>(u16(32768)) == u8(128));
        REQUIRE(ValueShift<u8>(u16::Max()) == u8::Max());
    }

    SECTION("Test ValueShift with u16/u32")
    {
        REQUIRE(ValueShift<u16>(u32::Min()     ) == u16::Min());
        REQUIRE(ValueShift<u16>(u32(536870912 )) == u16(8192));
        REQUIRE(ValueShift<u16>(u32(1073741824)) == u16(16384));
        REQUIRE(ValueShift<u16>(u32(2147483648)) == u16(32768));
        REQUIRE(ValueShift<u16>(u32::Max()     ) == u16::Max());
    }

    SECTION("Test ValueShift with u32/u64")
    {
        REQUIRE(ValueShift<u32>(u64::Min()                 ) == u32::Min());
        REQUIRE(ValueShift<u32>(u64(2305843009213693952   )) == u32(536870912));
        REQUIRE(ValueShift<u32>(u64(4611686018427387904   )) == u32(1073741824));
        REQUIRE(ValueShift<u32>(u64(9223372036854775808ull)) == u32(2147483648));
        REQUIRE(ValueShift<u32>(u64::Max()                 ) == u32::Max());
    }
}

TEST_CASE("Test ValueShift function with same size signed/unsigned types", "[Math][Functions]")
{
    SECTION("Test ValueShift with i8/u8")
    {
        REQUIRE(ValueShift<u8>(i8::Min()) == u8::Min());
        REQUIRE(ValueShift<u8>(i8(-127 )) == u8(1));
        REQUIRE(ValueShift<u8>(i8(0    )) == u8(128));
        REQUIRE(ValueShift<u8>(i8(126  )) == u8(254));
        REQUIRE(ValueShift<u8>(i8::Max()) == u8::Max());

        REQUIRE(ValueShift<i8>(u8::Min()) == i8::Min());
        REQUIRE(ValueShift<i8>(u8(1    )) == i8(-127));
        REQUIRE(ValueShift<i8>(u8(128  )) == i8(0));
        REQUIRE(ValueShift<i8>(u8(254  )) == i8(126));
        REQUIRE(ValueShift<i8>(u8::Max()) == i8::Max());
    }

    SECTION("Test ValueShift with i16/u16")
    {
        REQUIRE(ValueShift<u16>(i16::Min( )) == u16::Min());
        REQUIRE(ValueShift<u16>(i16(-32767)) == u16(1));
        REQUIRE(ValueShift<u16>(i16(0     )) == u16(32768));
        REQUIRE(ValueShift<u16>(i16(32766 )) == u16(65534));
        REQUIRE(ValueShift<u16>(i16::Max( )) == u16::Max());

        REQUIRE(ValueShift<i16>(u16::Min()) == i16::Min());
        REQUIRE(ValueShift<i16>(u16(1    )) == i16(-32767));
        REQUIRE(ValueShift<i16>(u16(32768)) == i16(0));
        REQUIRE(ValueShift<i16>(u16(65534)) == i16(32766));
        REQUIRE(ValueShift<i16>(u16::Max()) == i16::Max());
    }

    SECTION("Test ValueShift with i32/u32")
    {
        REQUIRE(ValueShift<u32>(i32::Min()      ) == u32::Min());
        REQUIRE(ValueShift<u32>(i32(-2147483647)) == u32(1));
        REQUIRE(ValueShift<u32>(i32(0          )) == u32(2147483648));
        REQUIRE(ValueShift<u32>(i32(2147483646 )) == u32(4294967294));
        REQUIRE(ValueShift<u32>(i32::Max()      ) == u32::Max());

        REQUIRE(ValueShift<i32>(u32::Min()     ) == i32::Min());
        REQUIRE(ValueShift<i32>(u32(1         )) == i32(-2147483647));
        REQUIRE(ValueShift<i32>(u32(2147483648)) == i32(0));
        REQUIRE(ValueShift<i32>(u32(4294967294)) == i32(2147483646));
        REQUIRE(ValueShift<i32>(u32::Max()     ) == i32::Max());
    }

    SECTION("Test ValueShift with i64/u64")
    {
        REQUIRE(ValueShift<u64>(i64::Min()                 ) == u64::Min());
        REQUIRE(ValueShift<u64>(i64(-9223372036854775807ll)) == u64(1));
        REQUIRE(ValueShift<u64>(i64(0                     )) == u64(9223372036854775808ull));
        REQUIRE(ValueShift<u64>(i64(9223372036854775806ll )) == u64(18446744073709551614ull));
        REQUIRE(ValueShift<u64>(i64::Max()                 ) == u64::Max());

        REQUIRE(ValueShift<i64>(u64::Min()                  ) == i64::Min());
        REQUIRE(ValueShift<i64>(u64(1                      )) == i64(-9223372036854775807ll));
        REQUIRE(ValueShift<i64>(u64(9223372036854775808ull )) == i64(0));
        REQUIRE(ValueShift<i64>(u64(18446744073709551614ull)) == i64(9223372036854775806ll));
        REQUIRE(ValueShift<i64>(u64::Max()                  ) == i64::Max());
    }
}

TEST_CASE("Test ValueShift function for widening conversion from signed to unsigned types", "[Math][Function]")
{
    SECTION("Test ValueShift with i8/u16")
    {
        REQUIRE(ValueShift<u16>(i8::Min()) == u16::Min());
        REQUIRE(ValueShift<u16>(i8::Max()) == u16::Max());
    }

    SECTION("Test ValueShift with i8/u32")
    {
        REQUIRE(ValueShift<u32>(i8::Min()) == u32::Min());
        REQUIRE(ValueShift<u32>(i8::Max()) == u32::Max());
    }

    SECTION("Test ValueShift with i8/u64")
    {
        REQUIRE(ValueShift<u64>(i8::Min()) == u64::Min());
        REQUIRE(ValueShift<u64>(i8::Max()) == u64::Max());
    }

    SECTION("Test ValueShift with i16/u32")
    {
        REQUIRE(ValueShift<u32>(i16::Min()) == u32::Min());
        REQUIRE(ValueShift<u32>(i16::Max()) == u32::Max());
    }

    SECTION("Test ValueShift with i16/u64")
    {
        REQUIRE(ValueShift<u64>(i16::Min()) == u64::Min());
        REQUIRE(ValueShift<u64>(i16::Max()) == u64::Max());
    }

    SECTION("Test ValueShift with i32/u64")
    {
        REQUIRE(ValueShift<u64>(i32::Min()) == u64::Min());
        REQUIRE(ValueShift<u64>(i32::Max()) == u64::Max());
    }
}

TEST_CASE("Test ValueShift function for widening conversion from unsigned to signed types")
{
    SECTION("Test ValueShift with u8/i16")
    {
        REQUIRE(ValueShift<i16>(u8::Min()) == i16::Min());
        REQUIRE(ValueShift<i16>(u8::Max()) == i16::Max());
    }

    SECTION("Test ValueShift with u8/i32")
    {
        REQUIRE(ValueShift<i32>(u8::Min()) == i32::Min());
        REQUIRE(ValueShift<i32>(u8::Max()) == i32::Max());
    }

    SECTION("Test ValueShift with u8/i64")
    {
        REQUIRE(ValueShift<i64>(u8::Min()) == i64::Min());
        REQUIRE(ValueShift<i64>(u8::Max()) == i64::Max());
    }

    SECTION("Test ValueShift with u16/i32")
    {
        REQUIRE(ValueShift<i32>(u16::Min()) == i32::Min());
        REQUIRE(ValueShift<i32>(u16::Max()) == i32::Max());
    }

    SECTION("Test ValueShift with u16/i64")
    {
        REQUIRE(ValueShift<i64>(u16::Min()) == i64::Min());
        REQUIRE(ValueShift<i64>(u16::Max()) == i64::Max());
    }

    SECTION("Test ValueShift with u32/i64")
    {
        REQUIRE(ValueShift<i64>(u32::Min()) == i64::Min());
        REQUIRE(ValueShift<i64>(u32::Max()) == i64::Max());
    }
}
