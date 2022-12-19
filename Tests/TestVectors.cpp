#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>

#include <iostream>

TEST_CASE("Check Vector2f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        cc::Vector2f vec;
        REQUIRE(vec.x == 0.0f);
        REQUIRE(vec.y == 0.0f);
    }

    SECTION("Single-value constructor")
    {
        cc::Vector2f vec(1.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 1.0f);
    }

    SECTION("Full constructor")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
    }
}

TEST_CASE("Check Vector3f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        cc::Vector3f vec;
        REQUIRE(vec.x == 0.0f);
        REQUIRE(vec.y == 0.0f);
        REQUIRE(vec.z == 0.0f);
    }

    SECTION("Single-value constructor")
    {
        cc::Vector3f vec(1.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 1.0f);
        REQUIRE(vec.z == 1.0f);
    }

    SECTION("Full constructor")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
        REQUIRE(vec.z == 3.0f);
    }

    SECTION("Extension constructor from Vector2f with implicit z")
    {
        cc::Vector2f vec2(1.0f, 2.0f);
        cc::Vector3f vec3(vec2);
        REQUIRE(vec3.x == 1.0f);
        REQUIRE(vec3.y == 2.0f);
        REQUIRE(vec3.z == 0.0f);
    }

    SECTION("Extension constructor from Vector2f with explicit z")
    {
        cc::Vector2f vec2(1.0f, 2.0f);
        cc::Vector3f vec3(vec2, 3.0f);
        REQUIRE(vec3.x == 1.0f);
        REQUIRE(vec3.y == 2.0f);
        REQUIRE(vec3.z == 3.0f);
    }
}

TEST_CASE("Check Vector4f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        cc::Vector4f vec;
        REQUIRE(vec.x == 0.0f);
        REQUIRE(vec.y == 0.0f);
        REQUIRE(vec.z == 0.0f);
        REQUIRE(vec.w == 0.0f);
    }

    SECTION("Single-value constructor")
    {
        cc::Vector4f vec(1.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 1.0f);
        REQUIRE(vec.z == 1.0f);
        REQUIRE(vec.w == 1.0f);
    }

    SECTION("Full constructor")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
        REQUIRE(vec.z == 3.0f);
        REQUIRE(vec.w == 4.0f);
    }

    SECTION("Extension constructor from Vector2f with implicit z and w")
    {
        cc::Vector2f vec2(1.0f, 2.0f);
        cc::Vector4f vec4(vec2);
        REQUIRE(vec4.x == 1.0f);
        REQUIRE(vec4.y == 2.0f);
        REQUIRE(vec4.z == 0.0f);
        REQUIRE(vec4.w == 0.0f);
    }

    SECTION("Extension constructor from Vector2f with explicit z and w")
    {
        cc::Vector2f vec2(1.0f, 2.0f);
        cc::Vector4f vec4(vec2, 3.0f, 4.0f);
        REQUIRE(vec4.x == 1.0f);
        REQUIRE(vec4.y == 2.0f);
        REQUIRE(vec4.z == 3.0f);
        REQUIRE(vec4.w == 4.0f);
    }

    SECTION("Extension constructor from Vector3f with implicit w")
    {
        cc::Vector3f vec3(1.0f, 2.0f, 3.0f);
        cc::Vector4f vec4(vec3);
        REQUIRE(vec4.x == 1.0f);
        REQUIRE(vec4.y == 2.0f);
        REQUIRE(vec4.z == 3.0f);
        REQUIRE(vec4.w == 0.0f);
    }

    SECTION("Extension constructor from Vector3f with explicit w")
    {
        cc::Vector3f vec3(1.0f, 2.0f, 3.0f);
        cc::Vector4f vec4(vec3, 4.0f);
        REQUIRE(vec4.x == 1.0f);
        REQUIRE(vec4.y == 2.0f);
        REQUIRE(vec4.z == 3.0f);
        REQUIRE(vec4.w == 4.0f);
    }
}

TEST_CASE("operator[] tests", "[Math][Vector]")
{
    SECTION("Vector2f operator[]")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
    }

    SECTION("Vector3f operator[]")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
        REQUIRE(vec.z == 3.0f);
    }

    SECTION("Vector4f operator[]")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(vec.x == 1.0f);
        REQUIRE(vec.y == 2.0f);
        REQUIRE(vec.z == 3.0f);
        REQUIRE(vec.w == 4.0f);
    }
}

TEST_CASE("LenSqr and Length member func tests", "[Math][Vector]")
{
    SECTION("LenSqr member")
    {
        REQUIRE(cc::Equal(cc::Vector2f(1.0f, 2.0f).LenSqr(), 5.0f));
        REQUIRE(cc::Equal(cc::Vector3f(1.0f, 2.0f, 3.0f).LenSqr(), 14.0f));
        REQUIRE(cc::Equal(cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).LenSqr(), 30.0f));
    }

    SECTION("Length member")
    {
        REQUIRE(cc::Equal(cc::Vector2f(1.0f, 2.0f).Length(), std::sqrt(5.0f)));
        REQUIRE(cc::Equal(cc::Vector3f(1.0f, 2.0f, 3.0f).Length(), std::sqrt(14.0f)));
        REQUIRE(cc::Equal(cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Length(), std::sqrt(30.0f)));
    }
}

TEST_CASE("Min and Max member func tests", "[Math][Vector]")
{
    SECTION("Min member")
    {
        REQUIRE(1.0f == cc::Vector2f(1.0f, 2.0f).Min());
        REQUIRE(1.0f == cc::Vector3f(1.0f, 2.0f, 3.0f).Min());
        REQUIRE(1.0f == cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Min());
    }

    SECTION("Max member")
    {
        REQUIRE(2.0f == cc::Vector2f(1.0f, 2.0f).Max());
        REQUIRE(3.0f == cc::Vector3f(1.0f, 2.0f, 3.0f).Max());
        REQUIRE(4.0f == cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Max());
    }
}

TEST_CASE("Equal utility func tests", "[Math][Vector]")
{
    SECTION("Equal function for Vector2f")
    {
        REQUIRE( cc::Equal(cc::Vector2f(1.0f, 2.0f), cc::Vector2f(1.0f, 2.0f)));
        REQUIRE(!cc::Equal(cc::Vector2f(1.0f, 2.0f), cc::Vector2f(1.1f, 2.1f)));
        REQUIRE(!cc::Equal(cc::Vector2f(1.0f, 2.0f), cc::Vector2f(3.0f, 4.0f)));
    }

    SECTION("Equal function for Vector3f")
    {
        REQUIRE( cc::Equal(cc::Vector3f(1.0f, 2.0f, 3.0f), cc::Vector3f(1.0f, 2.0f, 3.0f)));
        REQUIRE(!cc::Equal(cc::Vector3f(1.0f, 2.0f, 3.0f), cc::Vector3f(1.1f, 2.1f, 3.1f)));
        REQUIRE(!cc::Equal(cc::Vector3f(1.0f, 2.0f, 3.0f), cc::Vector3f(4.0f, 5.0f, 6.0f)));
    }

    SECTION("Equal function for Vector2f")
    {
        REQUIRE( cc::Equal(cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f), cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f)));
        REQUIRE(!cc::Equal(cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f), cc::Vector4f(1.1f, 2.1f, 3.1f, 4.1f)));
        REQUIRE(!cc::Equal(cc::Vector4f(1.0f, 2.0f, 3.0f, 4.0f), cc::Vector4f(5.0f, 6.0f, 7.0f, 8.0f)));
    }
}

TEST_CASE("Vector operator+", "[Math][Vector]")
{
    SECTION("Vector2 + Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(4.0f, 6.0f);
        REQUIRE(cc::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector3 + Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(5.0f, 7.0f, 9.0f);
        REQUIRE(cc::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector4 + Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(6.0f, 8.0f, 10.0f, 12.0f);
        REQUIRE(cc::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector2 + Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(4.0f, 5.0f);
        REQUIRE(cc::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector2")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(4.0f, 5.0f);
        REQUIRE(cc::Equal(3.0f + vec, expect));
    }

    SECTION("Vector3 + Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(cc::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector3")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(cc::Equal(3.0f + vec, expect));
    }

    SECTION("Vector4 + Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(cc::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector4")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(cc::Equal(3.0f + vec, expect));
    }
}

TEST_CASE("Vector operator-", "[Math][Vector]")
{
    SECTION("Vector2 - Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(-2.0f, -2.0f);
        REQUIRE(cc::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector3 - Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(-3.0f, -3.0f, -3.0f);
        REQUIRE(cc::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector4 - Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(-4.0f, -4.0f, -4.0f, -4.0f);
        REQUIRE(cc::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector2 - Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(-2.0f, -1.0f);
        REQUIRE(cc::Equal(vec - 3.0f, expect));
    }

    SECTION("Vector3 - Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(-2.0f, -1.0f, 0.0f);
        REQUIRE(cc::Equal(vec - 3.0f, expect));
    }

    SECTION("Vector4 - Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(-2.0f, -1.0f, 0.0f, 1.0f);
        REQUIRE(cc::Equal(vec - 3.0f, expect));
    }
}

TEST_CASE("Vector operator*", "[Math][Vector]")
{
    SECTION("Vector2 * Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(3.0f, 8.0f);
        REQUIRE(cc::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector3 * Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(4.0f, 10.0f, 18.0f);
        REQUIRE(cc::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector4 * Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(5.0f, 12.0f, 21.0f, 32.0f);
        REQUIRE(cc::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector2 * Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(3.0f, 6.0f);
        REQUIRE(cc::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector2")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(3.0f, 6.0f);
        REQUIRE(cc::Equal(3.0f * vec, expect));
    }

    SECTION("Vector3 * Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(cc::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector3")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(cc::Equal(3.0f * vec, expect));
    }

    SECTION("Vector4 * Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(cc::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector4")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(cc::Equal(3.0f * vec, expect));
    }
}

TEST_CASE("Vector operator/", "[Math][Vector]")
{
    SECTION("Vector2 / Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(1.0f / 3.0f, 0.5f);
        REQUIRE(cc::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector3 / Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(0.25f, 0.4f, 0.5f);
        REQUIRE(cc::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector4 / Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(0.2f, 1.0f / 3.0f, 3.0f / 7.0f, 0.5f);
        REQUIRE(cc::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector2 / Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(1.0f / 3.0f, 2.0f / 3.0f);
        REQUIRE(cc::Equal(vec / 3.0f, expect));
    }

    SECTION("Vector3 / Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f);
        REQUIRE(cc::Equal(vec / 3.0f, expect));
    }

    SECTION("Vector4 / Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f, 4.0f / 3.0f);
        REQUIRE(cc::Equal(vec / 3.0f, expect));
    }
}

TEST_CASE("Vector operator+=", "[Math][Vector]")
{
    SECTION("Vector2 += Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(4.0f, 6.0f);
        REQUIRE(cc::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector3 += Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(5.0f, 7.0f, 9.0f);
        REQUIRE(cc::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector4 += Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(6.0f, 8.0f, 10.0f, 12.0f);
        REQUIRE(cc::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector2 += Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(4.0f, 5.0f);
        REQUIRE(cc::Equal(vec += 3.0f, expect));
    }

    SECTION("Vector3 += Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(cc::Equal(vec += 3.0f, expect));
    }

    SECTION("Vector4 += Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(cc::Equal(vec += 3.0f, expect));
    }
}

TEST_CASE("Vector operator-=", "[Math][Vector]")
{
    SECTION("Vector2 -= Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(-2.0f, -2.0f);
        REQUIRE(cc::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector3 -= Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(-3.0f, -3.0f, -3.0f);
        REQUIRE(cc::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector4 -= Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(-4.0f, -4.0f, -4.0f, -4.0f);
        REQUIRE(cc::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector2 -= Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(-2.0f, -1.0f);
        REQUIRE(cc::Equal(vec -= 3.0f, expect));
    }

    SECTION("Vector3 -= Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(-2.0f, -1.0f, 0.0f);
        REQUIRE(cc::Equal(vec -= 3.0f, expect));
    }

    SECTION("Vector4 -= Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(-2.0f, -1.0f, 0.0f, 1.0f);
        REQUIRE(cc::Equal(vec -= 3.0f, expect));
    }
}

TEST_CASE("Vector operator*=", "[Math][Vector]")
{
    SECTION("Vector2 *= Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(3.0f, 8.0f);
        REQUIRE(cc::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector3 *= Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(4.0f, 10.0f, 18.0f);
        REQUIRE(cc::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector4 *= Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(5.0f, 12.0f, 21.0f, 32.0f);
        REQUIRE(cc::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector2 *= Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(3.0f, 6.0f);
        REQUIRE(cc::Equal(vec *= 3.0f, expect));
    }

    SECTION("Vector3 *= Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(cc::Equal(vec *= 3.0f, expect));
    }

    SECTION("Vector4 *= Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(cc::Equal(vec *= 3.0f, expect));
    }
}

TEST_CASE("Vector operator/=", "[Math][Vector]")
{
    SECTION("Vector2 /= Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        cc::Vector2f expect(1.0f / 3.0f, 0.5f);
        REQUIRE(cc::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector3 /= Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        cc::Vector3f expect(0.25f, 0.4f, 0.5f);
        REQUIRE(cc::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector4 /= Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        cc::Vector4f expect(0.2f, 1.0f / 3.0f, 3.0f / 7.0f, 0.5f);
        REQUIRE(cc::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector2 /= Scalar")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        cc::Vector2f expect(1.0f / 3.0f, 2.0f / 3.0f);
        REQUIRE(cc::Equal(vec /= 3.0f, expect));
    }

    SECTION("Vector3 /= Scalar")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        cc::Vector3f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f);
        REQUIRE(cc::Equal(vec /= 3.0f, expect));
    }

    SECTION("Vector4 /= Scalar")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f, 4.0f / 3.0f);
        REQUIRE(cc::Equal(vec /= 3.0f, expect));
    }
}

TEST_CASE("Dot helper functions", "[Math][Vector]")
{
    SECTION("Dot function for Vector2")
    {
        cc::Vector2f vec1(1.0f, 2.0f);
        cc::Vector2f vec2(3.0f, 4.0f);
        REQUIRE(cc::Equal(11.0f, cc::Dot(vec1, vec2)));
    }

    SECTION("Dot function for Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        REQUIRE(cc::Equal(32.0f, cc::Dot(vec1, vec2)));
    }

    SECTION("Dot function for Vector4")
    {
        cc::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        cc::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        REQUIRE(cc::Equal(70.0f, cc::Dot(vec1, vec2)));
    }
}

TEST_CASE("Normalize helper functions", "[Math][Vector]")
{
    SECTION("Normalize function for Vector2")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        REQUIRE(cc::Equal(1.0f, cc::Normalize(vec).Length()));
    }

    SECTION("Normalize function for Vector3")
    {
        cc::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(cc::Equal(1.0f, cc::Normalize(vec).Length()));
    }

    SECTION("Normalize function for Vector4")
    {
        cc::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(cc::Equal(1.0f, cc::Normalize(vec).Length()));
    }
}

TEST_CASE("Perp and Cross helper functions", "[Math][Vector]")
{
    SECTION("Perp function for Vector2")
    {
        cc::Vector2f vec(1.0f, 2.0f);
        REQUIRE(cc::Equal(0.0f, cc::Dot(vec, cc::Perp(vec))));
    }

    SECTION("Cross function for Vector3")
    {
        cc::Vector3f vec1(1.0f, 2.0f, 3.0f);
        cc::Vector3f vec2(4.0f, 5.0f, 6.0f);
        REQUIRE(cc::Equal(0.0f, cc::Dot(vec1, cc::Cross(vec1, vec2))));
        REQUIRE(cc::Equal(0.0f, cc::Dot(vec2, cc::Cross(vec2, vec1))));
    }
}
