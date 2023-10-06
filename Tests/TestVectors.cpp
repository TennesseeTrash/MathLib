#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>

TEST_CASE("Check Vector2f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        Math::Vector2f vec;
        REQUIRE(Math::Equal(vec.x, 0.0f));
        REQUIRE(Math::Equal(vec.y, 0.0f));
    }

    SECTION("Single-value constructor")
    {
        Math::Vector2f vec(1.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 1.0f));
    }

    SECTION("Full constructor")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
    }
}

TEST_CASE("Check Vector3f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        Math::Vector3f vec;
        REQUIRE(Math::Equal(vec.x, 0.0f));
        REQUIRE(Math::Equal(vec.y, 0.0f));
        REQUIRE(Math::Equal(vec.z, 0.0f));
    }

    SECTION("Single-value constructor")
    {
        Math::Vector3f vec(1.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 1.0f));
        REQUIRE(Math::Equal(vec.z, 1.0f));
    }

    SECTION("Full constructor")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
        REQUIRE(Math::Equal(vec.z, 3.0f));
    }

    SECTION("Extension constructor from Vector2f with implicit z")
    {
        Math::Vector2f vec2(1.0f, 2.0f);
        Math::Vector3f vec3(vec2);
        REQUIRE(Math::Equal(vec3.x, 1.0f));
        REQUIRE(Math::Equal(vec3.y, 2.0f));
        REQUIRE(Math::Equal(vec3.z, 0.0f));
    }

    SECTION("Extension constructor from Vector2f with explicit z")
    {
        Math::Vector2f vec2(1.0f, 2.0f);
        Math::Vector3f vec3(vec2, 3.0f);
        REQUIRE(Math::Equal(vec3.x, 1.0f));
        REQUIRE(Math::Equal(vec3.y, 2.0f));
        REQUIRE(Math::Equal(vec3.z, 3.0f));
    }
}

TEST_CASE("Check Vector4f constructors", "[Math][Vector]")
{
    SECTION("Default constructor")
    {
        Math::Vector4f vec;
        REQUIRE(Math::Equal(vec.x, 0.0f));
        REQUIRE(Math::Equal(vec.y, 0.0f));
        REQUIRE(Math::Equal(vec.z, 0.0f));
        REQUIRE(Math::Equal(vec.w, 0.0f));
    }

    SECTION("Single-value constructor")
    {
        Math::Vector4f vec(1.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 1.0f));
        REQUIRE(Math::Equal(vec.z, 1.0f));
        REQUIRE(Math::Equal(vec.w, 1.0f));
    }

    SECTION("Full constructor")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
        REQUIRE(Math::Equal(vec.z, 3.0f));
        REQUIRE(Math::Equal(vec.w, 4.0f));
    }

    SECTION("Extension constructor from Vector2f with implicit z and w")
    {
        Math::Vector2f vec2(1.0f, 2.0f);
        Math::Vector4f vec4(vec2);
        REQUIRE(Math::Equal(vec4.x, 1.0f));
        REQUIRE(Math::Equal(vec4.y, 2.0f));
        REQUIRE(Math::Equal(vec4.z, 0.0f));
        REQUIRE(Math::Equal(vec4.w, 0.0f));
    }

    SECTION("Extension constructor from Vector2f with explicit z and w")
    {
        Math::Vector2f vec2(1.0f, 2.0f);
        Math::Vector4f vec4(vec2, 3.0f, 4.0f);
        REQUIRE(Math::Equal(vec4.x, 1.0f));
        REQUIRE(Math::Equal(vec4.y, 2.0f));
        REQUIRE(Math::Equal(vec4.z, 3.0f));
        REQUIRE(Math::Equal(vec4.w, 4.0f));
    }

    SECTION("Extension constructor from Vector3f with implicit w")
    {
        Math::Vector3f vec3(1.0f, 2.0f, 3.0f);
        Math::Vector4f vec4(vec3);
        REQUIRE(Math::Equal(vec4.x, 1.0f));
        REQUIRE(Math::Equal(vec4.y, 2.0f));
        REQUIRE(Math::Equal(vec4.z, 3.0f));
        REQUIRE(Math::Equal(vec4.w, 0.0f));
    }

    SECTION("Extension constructor from Vector3f with explicit w")
    {
        Math::Vector3f vec3(1.0f, 2.0f, 3.0f);
        Math::Vector4f vec4(vec3, 4.0f);
        REQUIRE(Math::Equal(vec4.x, 1.0f));
        REQUIRE(Math::Equal(vec4.y, 2.0f));
        REQUIRE(Math::Equal(vec4.z, 3.0f));
        REQUIRE(Math::Equal(vec4.w, 4.0f));
    }
}

TEST_CASE("operator[] tests", "[Math][Vector]")
{
    SECTION("Vector2f operator[]")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
    }

    SECTION("Vector3f operator[]")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
        REQUIRE(Math::Equal(vec.z, 3.0f));
    }

    SECTION("Vector4f operator[]")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        REQUIRE(Math::Equal(vec.x, 1.0f));
        REQUIRE(Math::Equal(vec.y, 2.0f));
        REQUIRE(Math::Equal(vec.z, 3.0f));
        REQUIRE(Math::Equal(vec.w, 4.0f));
    }
}

TEST_CASE("LenSqr and Length member func tests", "[Math][Vector]")
{
    SECTION("LenSqr member")
    {
        REQUIRE(Math::Equal(Math::Vector2f(1.0f, 2.0f).LenSqr(), 5.0f));
        REQUIRE(Math::Equal(Math::Vector3f(1.0f, 2.0f, 3.0f).LenSqr(), 14.0f));
        REQUIRE(Math::Equal(Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).LenSqr(), 30.0f));
    }

    SECTION("Length member")
    {
        REQUIRE(Math::Equal(Math::Vector2f(1.0f, 2.0f).Length(), std::sqrt(5.0f)));
        REQUIRE(Math::Equal(Math::Vector3f(1.0f, 2.0f, 3.0f).Length(), std::sqrt(14.0f)));
        REQUIRE(Math::Equal(Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Length(), std::sqrt(30.0f)));
    }
}

TEST_CASE("Min and Max member func tests", "[Math][Vector]")
{
    SECTION("Min member")
    {
        REQUIRE(Math::Equal(1.0f, Math::Vector2f(1.0f, 2.0f).Min()));
        REQUIRE(Math::Equal(1.0f, Math::Vector3f(1.0f, 2.0f, 3.0f).Min()));
        REQUIRE(Math::Equal(1.0f, Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Min()));
    }

    SECTION("Max member")
    {
        REQUIRE(Math::Equal(2.0f, Math::Vector2f(1.0f, 2.0f).Max()));
        REQUIRE(Math::Equal(3.0f, Math::Vector3f(1.0f, 2.0f, 3.0f).Max()));
        REQUIRE(Math::Equal(4.0f, Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f).Max()));
    }
}

TEST_CASE("Vector operator+", "[Math][Vector]")
{
    SECTION("Vector2 + Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(4.0f, 6.0f);
        REQUIRE(Math::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector3 + Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(5.0f, 7.0f, 9.0f);
        REQUIRE(Math::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector4 + Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(6.0f, 8.0f, 10.0f, 12.0f);
        REQUIRE(Math::Equal(vec1 + vec2, expect));
    }

    SECTION("Vector2 + Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(4.0f, 5.0f);
        REQUIRE(Math::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(4.0f, 5.0f);
        REQUIRE(Math::Equal(3.0f + vec, expect));
    }

    SECTION("Vector3 + Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(Math::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector3")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(Math::Equal(3.0f + vec, expect));
    }

    SECTION("Vector4 + Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(Math::Equal(vec + 3.0f, expect));
    }

    SECTION("Scalar + Vector4")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(Math::Equal(3.0f + vec, expect));
    }
}

TEST_CASE("Vector operator-", "[Math][Vector]")
{
    SECTION("Vector2 - Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(-2.0f, -2.0f);
        REQUIRE(Math::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector3 - Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(-3.0f, -3.0f, -3.0f);
        REQUIRE(Math::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector4 - Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(-4.0f, -4.0f, -4.0f, -4.0f);
        REQUIRE(Math::Equal(vec1 - vec2, expect));
    }

    SECTION("Vector2 - Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(-2.0f, -1.0f);
        REQUIRE(Math::Equal(vec - 3.0f, expect));
    }

    SECTION("Scalar - Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(2.0f, 1.0f);
        REQUIRE(Math::Equal(3.0f - vec, expect));
    }

    SECTION("Vector3 - Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(-2.0f, -1.0f, 0.0f);
        REQUIRE(Math::Equal(vec - 3.0f, expect));
    }

    SECTION("Scalar - Vector3")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(2.0f, 1.0f, 0.0f);
        REQUIRE(Math::Equal(3.0f - vec, expect));
    }

    SECTION("Vector4 - Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(-2.0f, -1.0f, 0.0f, 1.0f);
        REQUIRE(Math::Equal(vec - 3.0f, expect));
    }

    SECTION("Scalar - Vector4")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(2.0f, 1.0f, 0.0f, -1.0f);
        REQUIRE(Math::Equal(3.0f - vec, expect));
    }
}

TEST_CASE("Vector operator*", "[Math][Vector]")
{
    SECTION("Vector2 * Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(3.0f, 8.0f);
        REQUIRE(Math::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector3 * Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(4.0f, 10.0f, 18.0f);
        REQUIRE(Math::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector4 * Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(5.0f, 12.0f, 21.0f, 32.0f);
        REQUIRE(Math::Equal(vec1 * vec2, expect));
    }

    SECTION("Vector2 * Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(3.0f, 6.0f);
        REQUIRE(Math::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(3.0f, 6.0f);
        REQUIRE(Math::Equal(3.0f * vec, expect));
    }

    SECTION("Vector3 * Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(Math::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector3")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(Math::Equal(3.0f * vec, expect));
    }

    SECTION("Vector4 * Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(Math::Equal(vec * 3.0f, expect));
    }

    SECTION("Scalar * Vector4")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(Math::Equal(3.0f * vec, expect));
    }
}

TEST_CASE("Vector operator/", "[Math][Vector]")
{
    SECTION("Vector2 / Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(1.0f / 3.0f, 0.5f);
        REQUIRE(Math::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector3 / Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(0.25f, 0.4f, 0.5f);
        REQUIRE(Math::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector4 / Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(0.2f, 1.0f / 3.0f, 3.0f / 7.0f, 0.5f);
        REQUIRE(Math::Equal(vec1 / vec2, expect));
    }

    SECTION("Vector2 / Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(1.0f / 3.0f, 2.0f / 3.0f);
        REQUIRE(Math::Equal(vec / 3.0f, expect));
    }

    SECTION("Vector3 / Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f);
        REQUIRE(Math::Equal(vec / 3.0f, expect));
    }

    SECTION("Vector4 / Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f, 4.0f / 3.0f);
        REQUIRE(Math::Equal(vec / 3.0f, expect));
    }

    SECTION("Scalar / Vector2")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(3.0f, 1.5f);
        REQUIRE(Math::Equal(3.0f / vec, expect));
    }

    SECTION("Scalar / Vector3")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(3.0f, 1.5f, 1.0f);
        REQUIRE(Math::Equal(3.0f / vec, expect));
    }

    SECTION("Scalar / Vector4")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(3.0f, 1.5f, 1.0f, 0.75f);
        REQUIRE(Math::Equal(3.0f / vec, expect));
    }
}

TEST_CASE("Vector operator+=", "[Math][Vector]")
{
    SECTION("Vector2 += Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(4.0f, 6.0f);
        REQUIRE(Math::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector3 += Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(5.0f, 7.0f, 9.0f);
        REQUIRE(Math::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector4 += Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(6.0f, 8.0f, 10.0f, 12.0f);
        REQUIRE(Math::Equal(vec1 += vec2, expect));
    }

    SECTION("Vector2 += Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(4.0f, 5.0f);
        REQUIRE(Math::Equal(vec += 3.0f, expect));
    }

    SECTION("Vector3 += Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(4.0f, 5.0f, 6.0f);
        REQUIRE(Math::Equal(vec += 3.0f, expect));
    }

    SECTION("Vector4 += Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(4.0f, 5.0f, 6.0f, 7.0f);
        REQUIRE(Math::Equal(vec += 3.0f, expect));
    }
}

TEST_CASE("Vector operator-=", "[Math][Vector]")
{
    SECTION("Vector2 -= Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(-2.0f, -2.0f);
        REQUIRE(Math::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector3 -= Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(-3.0f, -3.0f, -3.0f);
        REQUIRE(Math::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector4 -= Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(-4.0f, -4.0f, -4.0f, -4.0f);
        REQUIRE(Math::Equal(vec1 -= vec2, expect));
    }

    SECTION("Vector2 -= Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(-2.0f, -1.0f);
        REQUIRE(Math::Equal(vec -= 3.0f, expect));
    }

    SECTION("Vector3 -= Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(-2.0f, -1.0f, 0.0f);
        REQUIRE(Math::Equal(vec -= 3.0f, expect));
    }

    SECTION("Vector4 -= Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(-2.0f, -1.0f, 0.0f, 1.0f);
        REQUIRE(Math::Equal(vec -= 3.0f, expect));
    }
}

TEST_CASE("Vector operator*=", "[Math][Vector]")
{
    SECTION("Vector2 *= Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(3.0f, 8.0f);
        REQUIRE(Math::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector3 *= Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(4.0f, 10.0f, 18.0f);
        REQUIRE(Math::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector4 *= Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(5.0f, 12.0f, 21.0f, 32.0f);
        REQUIRE(Math::Equal(vec1 *= vec2, expect));
    }

    SECTION("Vector2 *= Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(3.0f, 6.0f);
        REQUIRE(Math::Equal(vec *= 3.0f, expect));
    }

    SECTION("Vector3 *= Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(3.0f, 6.0f, 9.0f);
        REQUIRE(Math::Equal(vec *= 3.0f, expect));
    }

    SECTION("Vector4 *= Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(3.0f, 6.0f, 9.0f, 12.0f);
        REQUIRE(Math::Equal(vec *= 3.0f, expect));
    }
}

TEST_CASE("Vector operator/=", "[Math][Vector]")
{
    SECTION("Vector2 /= Vector2")
    {
        Math::Vector2f vec1(1.0f, 2.0f);
        Math::Vector2f vec2(3.0f, 4.0f);
        Math::Vector2f expect(1.0f / 3.0f, 0.5f);
        REQUIRE(Math::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector3 /= Vector3")
    {
        Math::Vector3f vec1(1.0f, 2.0f, 3.0f);
        Math::Vector3f vec2(4.0f, 5.0f, 6.0f);
        Math::Vector3f expect(0.25f, 0.4f, 0.5f);
        REQUIRE(Math::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector4 /= Vector4")
    {
        Math::Vector4f vec1(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f vec2(5.0f, 6.0f, 7.0f, 8.0f);
        Math::Vector4f expect(0.2f, 1.0f / 3.0f, 3.0f / 7.0f, 0.5f);
        REQUIRE(Math::Equal(vec1 /= vec2, expect));
    }

    SECTION("Vector2 /= Scalar")
    {
        Math::Vector2f vec(1.0f, 2.0f);
        Math::Vector2f expect(1.0f / 3.0f, 2.0f / 3.0f);
        REQUIRE(Math::Equal(vec /= 3.0f, expect));
    }

    SECTION("Vector3 /= Scalar")
    {
        Math::Vector3f vec(1.0f, 2.0f, 3.0f);
        Math::Vector3f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f);
        REQUIRE(Math::Equal(vec /= 3.0f, expect));
    }

    SECTION("Vector4 /= Scalar")
    {
        Math::Vector4f vec(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f expect(1.0f / 3.0f, 2.0f / 3.0f, 1.0f, 4.0f / 3.0f);
        REQUIRE(Math::Equal(vec /= 3.0f, expect));
    }
}

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
    }
}
