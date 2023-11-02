#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>

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
