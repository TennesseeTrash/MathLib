#include <catch2/catch_test_macros.hpp>
#include <Math/Quaternion.hpp>
#include <Math/Transform.hpp>

using Math::f32;

// TODO(3011): Complete these tests and refactor them into the new format.

TEST_CASE("Quaternion and Transform similarity", "[Math][Quaternion]")
{
    SECTION("Check a basic case")
    {
        Math::Transform3f t1 = Math::RotateX(Math::ToRadians(f32(12.0f)));
        Math::Transform3f t2 = Math::ToTransform(Math::FromAxisAngle({1.0f, 0.0f, 0.0f}, Math::ToRadians(f32(12.0f))));

        REQUIRE(Math::Equal(t1, t2));
    }

    SECTION("Trivial Slerp check")
    {
        Math::Transform3f t1 = Math::RotateY(Math::ToRadians(Math::f32(15.0f)));
        Math::Quaternionf q1 = Math::FromAxisAngle({0.0f, 1.0f, 0.0f}, Math::ToRadians(Math::f32(0.0f )));
        Math::Quaternionf q2 = Math::FromAxisAngle({0.0f, 1.0f, 0.0f}, Math::ToRadians(Math::f32(60.0f)));
        Math::Transform3f t2 = Math::ToTransform(Math::Slerp(0.25f, q1, q2));

        REQUIRE(Math::Equal(t1, t2));
    }
}

TEST_CASE("Check FromYawPitchRoll static member function", "[Math][Quaternion]")
{
    SECTION("Trivial parameters")
    {
        Math::Quaternionf q1 = Math::FromYawPitchRoll(f32(0.0f), f32(0.0f), f32(0.0f));
        Math::Quaternionf q2 = Math::Quaternionf::Identity();

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Yaw check")
    {
        Math::Quaternionf q1 = Math::FromYawPitchRoll(Math::ToRadians(f32(30.0f)), f32(0.0f), f32(0.0f));
        Math::Quaternionf q2 = Math::FromAxisAngle({0.0f, 0.0f, 1.0f}, Math::ToRadians(f32(30.0f)));

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Pitch check")
    {
        Math::Quaternionf q1 = Math::FromYawPitchRoll(f32(0.0f), Math::ToRadians(f32(45.0f)), f32(0.0f));
        Math::Quaternionf q2 = Math::FromAxisAngle({0.0f, 1.0f, 0.0f}, Math::ToRadians(f32(45.0f)));

        REQUIRE(Math::Equal(q1, q2));
    }

    SECTION("Roll check")
    {
        Math::Quaternionf q1 = Math::FromYawPitchRoll(f32(0.0f), f32(0.0f), Math::ToRadians(f32(56.0f)));
        Math::Quaternionf q2 = Math::FromAxisAngle({1.0f, 0.0f, 0.0f}, Math::ToRadians(f32(56.0f)));

        REQUIRE(Math::Equal(q1, q2));
    }
}
