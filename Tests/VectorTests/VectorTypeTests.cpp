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
