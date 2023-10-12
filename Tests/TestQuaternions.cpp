#include <catch2/catch_test_macros.hpp>
#include <Math/Quaternion.hpp>
#include <Math/Utils/Transform.hpp>
#include <Math/Debug/StreamOperators.hpp>

TEST_CASE("Quaternion and Transform similarity", "[Math][Quaternion]")
{
    SECTION("Check a basic case")
    {
        Math::Matrix4f m1 = Math::Transform::RotateByX(Math::ToRadians(12.f));
        Math::Matrix4f m2 = Math::Quaternionf::MakeRotation(Math::ToRadians(12.f), {1.0f, 0.0f, 0.0f}).ToMatrix4();

        REQUIRE(Math::Equal(m1, m2));
    }

    SECTION("Trivial Slerp check")
    {
        Math::Matrix4f m1 = Math::Transform::RotateByY(Math::ToRadians(15.f));
        Math::Quaternionf q1 = Math::Quaternionf::MakeRotation(Math::ToRadians(0.f), {0.0f, 1.0f, 0.0f});
        Math::Quaternionf q2 = Math::Quaternionf::MakeRotation(Math::ToRadians(60.f), {0.0f, 1.0f, 0.0f});
        Math::Matrix4f m2 = Math::Slerp(Math::f32(0.25f), q1, q2).ToMatrix4();

        REQUIRE(Math::Equal(m1, m2));
    }
}

TEST_CASE("Check MakeFromYawPitchRoll static member function", "[Math][Quaternion]")
{
    SECTION("Trivial parameters")
    {
        Math::Quaternionf q1 = Math::Quaternionf::MakeFromYawPitchRoll(0.0f, 0.0f, 0.0f);
        Math::Quaternionf q2 = Math::Quaternionf({0.0f, 0.0f, 0.0f}, 1.0f);

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Yaw check")
    {
        Math::Quaternionf q1 = Math::Quaternionf::MakeFromYawPitchRoll(Math::ToRadians(30.0f), 0.0f, 0.0f);
        Math::Quaternionf q2 = Math::Quaternionf::MakeRotation(Math::ToRadians(30.0f), {0.0f, 1.0f, 0.0f});

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Pitch check")
    {
        Math::Quaternionf q1 = Math::Quaternionf::MakeFromYawPitchRoll(0.0f, Math::ToRadians(45.0f), 0.0f);
        Math::Quaternionf q2 = Math::Quaternionf::MakeRotation(Math::ToRadians(45.0f), {1.0f, 0.0f, 0.0f});

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Roll check")
    {
        Math::Quaternionf q1 = Math::Quaternionf::MakeFromYawPitchRoll(0.0f, 0.0f, Math::ToRadians(56.0f));
        Math::Quaternionf q2 = Math::Quaternionf::MakeRotation(Math::ToRadians(56.0f), {0.0f, 0.0f, 1.0f});

        REQUIRE(Math::Equal(q1, q2));
    }
}
