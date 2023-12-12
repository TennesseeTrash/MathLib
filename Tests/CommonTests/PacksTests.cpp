#include <catch2/catch_test_macros.hpp>
#include <Math/Common/Packs.hpp>
#include <Math/Common/Types.hpp>

using Math::i32;
using Math::i64;
using Math::f32;
using Math::f64;
using Math::SizeType;
using Math::i32s;

namespace
{
    template <typename T1, typename T2>
    struct TypeZipperTest
    {
        using Type = Math::ConditionalType<sizeof(T1) < sizeof(T2), T1, T2>;
    };
}

TEST_CASE("TypePack creation and basic utilities", "[Math][Common]")
{
    using Pack = Math::TypePack<i32, i64, f32, f64>;

    SECTION("Test Pack::Size")
    {
        STATIC_REQUIRE(Pack::Size == 4);
    }

    SECTION("Test Pack::At")
    {
        STATIC_REQUIRE(Math::IsSame<Pack::At<0>, i32>);
        STATIC_REQUIRE(Math::IsSame<Pack::At<1>, i64>);
        STATIC_REQUIRE(Math::IsSame<Pack::At<2>, f32>);
        STATIC_REQUIRE(Math::IsSame<Pack::At<3>, f64>);
    }

    SECTION("Test Pack::Append")
    {
        using ResultPack = Pack::Append<SizeType>;
        STATIC_REQUIRE(ResultPack::Size == 5);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, f32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<3>, f64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<4>, SizeType>);
    }

    SECTION("Test Concatenate")
    {
        using ResultPack = Math::Concatenate<Pack, Math::TypePack<SizeType>>;
        STATIC_REQUIRE(ResultPack::Size == 5);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, f32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<3>, f64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<4>, SizeType>);
    }

    SECTION("Test RemoveAt")
    {
        using ResultPack = Math::RemoveAt<Pack, 2>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, f64>);
    }

    SECTION("Test RemoveFirst")
    {
        using ResultPack = Math::RemoveFirst<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, f32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, f64>);
    }

    SECTION("Test RemoveLast")
    {
        using ResultPack = Math::RemoveLast<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, f32>);
    }

    SECTION("Test SubPack")
    {
        using ResultPack = Math::SubPack<Pack, 1, 2>;
        STATIC_REQUIRE(ResultPack::Size == 2);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, f32>);
    }

    SECTION("Test Reverse")
    {
        using ResultPack = Math::Reverse<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 4);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, f64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, f32>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, i64>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<3>, i32>);
    }

    SECTION("Test Zip")
    {
        using ResultPack = Math::Zip<Pack, Math::TypePack<SizeType>>;
        STATIC_REQUIRE(ResultPack::Size == 1);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, Math::TypePack<i32, SizeType>>);
    }

    SECTION("Test ZipWith")
    {
        using ResultPack = Math::ZipWith<Math::MakeTypeZipper<TypeZipperTest>, Pack, Math::TypePack<SizeType>>;
        STATIC_REQUIRE(ResultPack::Size == 1);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, i32>);
    }
}

TEST_CASE("ValuePack creation and basic utilities", "[Math][Common]")
{
    // Won't work with StrongTypes, only StaticStrongTypes, due to class type and private value.
    using Pack = Math::ValuePack<i32s, 1, 2, 3, 4>;

    SECTION("Test Pack::Size")
    {
        STATIC_REQUIRE(Pack::Size == 4);
    }

    SECTION("Test Pack::ValueType")
    {
        STATIC_REQUIRE(Math::IsSame<Pack::ValueType, i32s>);
    }

    SECTION("Test Pack::At")
    {
        STATIC_REQUIRE(i32(Pack::At<0>) == 1);
        STATIC_REQUIRE(i32(Pack::At<1>) == 2);
        STATIC_REQUIRE(i32(Pack::At<2>) == 3);
        STATIC_REQUIRE(i32(Pack::At<3>) == 4);
    }

    SECTION("Test Pack::Append")
    {
        using ResultPack = Pack::Append<5>;
        STATIC_REQUIRE(ResultPack::Size == 5);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 1);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 3);
        STATIC_REQUIRE(i32(ResultPack::At<3>) == 4);
        STATIC_REQUIRE(i32(ResultPack::At<4>) == 5);
    }

    SECTION("Test Concatenate")
    {
        using ResultPack = Math::Concatenate<Pack, Math::ValuePack<i32s, 5>>;
        STATIC_REQUIRE(ResultPack::Size == 5);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 1);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 3);
        STATIC_REQUIRE(i32(ResultPack::At<3>) == 4);
        STATIC_REQUIRE(i32(ResultPack::At<4>) == 5);
    }

    SECTION("Test RemoveAt")
    {
        using ResultPack = Math::RemoveAt<Pack, 2>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 1);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 4);
    }

    SECTION("Test RemoveFirst")
    {
        using ResultPack = Math::RemoveFirst<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 3);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 4);
    }

    SECTION("Test RemoveLast")
    {
        using ResultPack = Math::RemoveLast<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 3);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 1);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 3);
    }

    SECTION("Test SubPack")
    {
        using ResultPack = Math::SubPack<Pack, 1, 2>;
        STATIC_REQUIRE(ResultPack::Size == 2);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 3);
    }

    SECTION("Test Reverse")
    {
        using ResultPack = Math::Reverse<Pack>;
        STATIC_REQUIRE(ResultPack::Size == 4);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 4);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 3);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 2);
        STATIC_REQUIRE(i32(ResultPack::At<3>) == 1);
    }

    SECTION("Test Zip")
    {
        using ResultPack = Math::Zip<Pack, Math::ValuePack<i32s, 5, 6, 7, 8, 9>>;
        STATIC_REQUIRE(ResultPack::Size == 4);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<0>, Math::ValuePack<i32s, 1, 5>>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<1>, Math::ValuePack<i32s, 2, 6>>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<2>, Math::ValuePack<i32s, 3, 7>>);
        STATIC_REQUIRE(Math::IsSame<ResultPack::At<3>, Math::ValuePack<i32s, 4, 8>>);
    }

    SECTION("Test ZipWith")
    {
        using ResultPack = Math::ZipWith<decltype([](i32 a, i32 b){ return a + b; }), Pack, Math::ValuePack<i32s, 5, 6, 7, 8, 9>>;
        STATIC_REQUIRE(ResultPack::Size == 4);
        STATIC_REQUIRE(i32(ResultPack::At<0>) == 6);
        STATIC_REQUIRE(i32(ResultPack::At<1>) == 8);
        STATIC_REQUIRE(i32(ResultPack::At<2>) == 10);
        STATIC_REQUIRE(i32(ResultPack::At<3>) == 12);
    }
}
