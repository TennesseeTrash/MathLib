#include <catch2/catch_test_macros.hpp>
#include <Math/Base.hpp>
#include <Math/Functions.hpp>
#include <Math/Random.hpp>

using Math::f32;

using Math::Equal;

TEST_CASE("Test Array basics", "[Math][Common]")
{
    SECTION("Array size")
    {
        using Array = Math::Array<f32, 4>;
        STATIC_REQUIRE(Array::Size == 4);
    }

    SECTION("Default constructor (zero initialization)")
    {
        Math::Array<f32, 4> array;
        REQUIRE(Equal(array[0], 0.0f));
        REQUIRE(Equal(array[1], 0.0f));
        REQUIRE(Equal(array[2], 0.0f));
        REQUIRE(Equal(array[3], 0.0f));
    }

    SECTION("Normal constructor")
    {
        Math::Array<f32, 4> array(f32(1.0f), f32(2.0f), f32(3.0f), f32(4.0f));
        REQUIRE(Equal(array[0], 1.0f));
        REQUIRE(Equal(array[1], 2.0f));
        REQUIRE(Equal(array[2], 3.0f));
        REQUIRE(Equal(array[3], 4.0f));
    }

    SECTION("ForEach")
    {
        Math::Array<f32, 4> array(f32(1.0f), f32(2.0f), f32(3.0f), f32(4.0f));
        array.ForEach([](f32& value) { value *= 2.0f; });
        REQUIRE(Equal(array[0], 2.0f));
        REQUIRE(Equal(array[1], 4.0f));
        REQUIRE(Equal(array[2], 6.0f));
        REQUIRE(Equal(array[3], 8.0f));
    }

    SECTION("ForEach with index")
    {
        Math::Array<f32, 4> array(f32(1.0f), f32(2.0f), f32(3.0f), f32(4.0f));
        array.ForEach([](Math::SizeType index, f32& value) { value *= Cast<f32>(index); });
        REQUIRE(Equal(array[0], 0.0f));
        REQUIRE(Equal(array[1], 2.0f));
        REQUIRE(Equal(array[2], 6.0f));
        REQUIRE(Equal(array[3], 12.0f));
    }

    SECTION("Fill")
    {
        Math::Array<f32, 4> array;
        array.Fill(f32(1.0f));
        REQUIRE(Equal(array[0], 1.0f));
        REQUIRE(Equal(array[1], 1.0f));
        REQUIRE(Equal(array[2], 1.0f));
        REQUIRE(Equal(array[3], 1.0f));
    }

    SECTION("Shuffle")
    {
        Math::Random64 random;
        Math::Array<f32, 4> array(f32(1.0f), f32(2.0f), f32(3.0f), f32(4.0f));
        array.Shuffle<Math::Random64, Math::UniformDistribution>(random);
        REQUIRE(Equal(array[0], 4.0f));
        REQUIRE(Equal(array[1], 3.0f));
        REQUIRE(Equal(array[2], 1.0f));
        REQUIRE(Equal(array[3], 2.0f));
    }

    SECTION("Min and Max")
    {
        Math::Array<f32, 4> array(f32(1.0f), f32(2.0f), f32(3.0f), f32(4.0f));
        REQUIRE(Equal(array.Min(), 1.0f));
        REQUIRE(Equal(array.Max(), 4.0f));
    }
}

TEST_CASE("Array creation utilities")
{
    SECTION("MakeArray with a list of values")
    {
        auto array = Math::MakeArray<f32, 4>(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(Equal(array[0], 1.0f));
        REQUIRE(Equal(array[1], 2.0f));
        REQUIRE(Equal(array[2], 3.0f));
        REQUIRE(Equal(array[3], 4.0f));
    }

    SECTION("MakeArray with a function")
    {
        f32 temp = 1.0f;
        auto array = Math::MakeArray<f32, 4>([&temp](f32& value) { value = Math::Cast<f32>(temp); temp += 1.0f; });
        REQUIRE(Equal(array[0], 1.0f));
        REQUIRE(Equal(array[1], 2.0f));
        REQUIRE(Equal(array[2], 3.0f));
        REQUIRE(Equal(array[3], 4.0f));
    }

    SECTION("MakeArray with a function (index)")
    {
        auto array = Math::MakeArray<f32, 4>([](Math::SizeType index, f32& value) { value = Math::Cast<f32>(index); });
        REQUIRE(Equal(array[0], 0.0f));
        REQUIRE(Equal(array[1], 1.0f));
        REQUIRE(Equal(array[2], 2.0f));
        REQUIRE(Equal(array[3], 3.0f));
    }

    SECTION("MakeArray from ValuePack")
    {
        using Pack = Math::ValuePack<f32, 1.0f, 2.0f, 3.0f, 4.0f>;
        auto array = Math::MakeArray<f32, Pack>();
        REQUIRE(Equal(array[0], 1.0f));
        REQUIRE(Equal(array[1], 2.0f));
        REQUIRE(Equal(array[2], 3.0f));
        REQUIRE(Equal(array[3], 4.0f));
    }
}
