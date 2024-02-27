#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Implementation/Functions/Equal.hpp>

// TODO(3011): Add tests for
//   - Area
//   - TriangleArea
//   - Volume
//   - TetrahedronVolume
//   - Reflect
//   - ReflectLocalZ
//   - Refract

TEST_CASE("Dot helper functions", "[Math][Vector]")
{
    SECTION("Dot function for Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        REQUIRE(Math::Equal(11.0f, Math::Dot(vec1, vec2)));
    }

    SECTION("Dot function for Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        REQUIRE(Math::Equal(32.0f, Math::Dot(vec1, vec2)));
    }

    SECTION("Dot function for Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        REQUIRE(Math::Equal(70.0f, Math::Dot(vec1, vec2)));
    }
}

TEST_CASE("Normalize helper functions", "[Math][Vector]")
{
    SECTION("Normalize function for Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        REQUIRE(Math::Equal(1.0f, Math::Normalize(vec).Length()));
    }

    SECTION("Normalize function for Vector3")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(Math::Equal(1.0f, Math::Normalize(vec).Length()));
    }

    SECTION("Normalize function for Vector4")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(Math::Equal(1.0f, Math::Normalize(vec).Length()));
    }
}

TEST_CASE("Perp and Cross helper functions", "[Math][Vector]")
{
    SECTION("Perp function for Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        REQUIRE(Math::Equal(0.0f, Math::Dot(vec, Math::Perp(vec))));
    }

    SECTION("Cross function for Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        REQUIRE(Math::Equal(0.0f, Math::Dot(vec1, Math::Cross(vec1, vec2))));
        REQUIRE(Math::Equal(0.0f, Math::Dot(vec2, Math::Cross(vec2, vec1))));

        REQUIRE(Math::Equal(Math::Cross(vec1, vec2), Math::Cross<Math::Orientation::Left>(vec2, vec1)));
        REQUIRE(Math::Equal(Math::Cross(vec1, vec2), -Math::Cross<Math::Orientation::Left>(vec1, vec2)));
    }
}
