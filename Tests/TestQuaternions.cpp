#include <catch2/catch_test_macros.hpp>
#include <Math/Quaternion.hpp>
#include <Math/Utils/Transform.hpp>
#include <Math/Debug/StreamOperators.hpp>

TEST_CASE("Quaternion and Transform similarity", "[Math][Quaternion]")
{
    SECTION("Check a basic case")
    {
        cc::Matrix4f m1 = cc::Transform::RotateByX(cc::ToRadians(12.f));
        cc::Matrix4f m2 = cc::Quaternionf::MakeRotation(cc::ToRadians(12.f), {1.0f, 0.0f, 0.0f}).ToMatrix4();

        REQUIRE(cc::Equal(m1, m2));
    }

    SECTION("Trivial Slerp check")
    {
        cc::Matrix4f m1 = cc::Transform::RotateByY(cc::ToRadians(15.f));
        cc::Quaternionf q1 = cc::Quaternionf::MakeRotation(cc::ToRadians(0.f), {0.0f, 1.0f, 0.0f});
        cc::Quaternionf q2 = cc::Quaternionf::MakeRotation(cc::ToRadians(60.f), {0.0f, 1.0f, 0.0f});
        cc::Matrix4f m2 = cc::Slerp(0.25f, q1, q2).ToMatrix4();

        REQUIRE(cc::Equal(m1, m2));
    }
}

TEST_CASE("Check MakeFromYawPitchRoll static member function", "[Math][Quaternion]")
{
    SECTION("Trivial parameters")
    {
        cc::Quaternionf q1 = cc::Quaternionf::MakeFromYawPitchRoll(0.0f, 0.0f, 0.0f);
        cc::Quaternionf q2 = cc::Quaternionf({0.0f, 0.0f, 0.0f}, 1.0f);

        REQUIRE(cc::Equal(q1, q2));
    }

    SECTION("Yaw check")
    {
        cc::Quaternionf q1 = cc::Quaternionf::MakeFromYawPitchRoll(cc::ToRadians(30.0f), 0.0f, 0.0f);
        cc::Quaternionf q2 = cc::Quaternionf::MakeRotation(cc::ToRadians(30.0f), {0.0f, 1.0f, 0.0f});

        REQUIRE(cc::Equal(q1, q2));
    }

    SECTION("Pitch check")
    {
        cc::Quaternionf q1 = cc::Quaternionf::MakeFromYawPitchRoll(0.0f, cc::ToRadians(45.0f), 0.0f);
        cc::Quaternionf q2 = cc::Quaternionf::MakeRotation(cc::ToRadians(45.0f), {1.0f, 0.0f, 0.0f});

        REQUIRE(cc::Equal(q1, q2));
    }

    SECTION("Roll check")
    {
        cc::Quaternionf q1 = cc::Quaternionf::MakeFromYawPitchRoll(0.0f, 0.0f, cc::ToRadians(56.0f));
        cc::Quaternionf q2 = cc::Quaternionf::MakeRotation(cc::ToRadians(56.0f), {0.0f, 0.0f, 1.0f});

        std::cout << q1 << "\n" << q2 << "\n";

        REQUIRE(cc::Equal(q1, q2));
    }
}
