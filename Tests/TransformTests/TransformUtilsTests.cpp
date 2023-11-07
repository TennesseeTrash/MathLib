#include <catch2/catch_test_macros.hpp>

#include "TransformTestsCommon.hpp"
#include <Math/Vector.hpp>
#include <Math/Point.hpp>

// TODO(3011): Complete tests for 3D projections

TEST_CASE("Test 2D transform helpers", "[Math][Transform]")
{
    SECTION("Scale")
    {
        Math::Transform2f scale1 = Math::Scale(Math::Vector2f(2.0f, 3.0f));
        REQUIRE(Math::Equal(scale1 * Math::Vector2f(1.0f, 1.0f), Math::Vector2f(2.0f, 3.0f)));
        REQUIRE(Math::Equal(scale1 * Math::Point2f(1.0f, 1.0f), Math::Point2f(2.0f, 3.0f)));
    }

    SECTION("Translation")
    {
        Math::Transform2f translation1 = Math::Translate(Math::Vector2f(1.0f, 2.0f));
        REQUIRE(Math::Equal(translation1 * Math::Vector2f(0.0f, 0.0f), Math::Vector2f(0.0f, 0.0f)));
        REQUIRE(Math::Equal(translation1 * Math::Point2f(0.0f, 0.0f), Math::Point2f(1.0f, 2.0f)));
    }

    SECTION("Rotation")
    {
        Math::Transform2f rotation1 = Math::Rotate(Math::Constants::Pi<Math::f32> / 4.0f);
        Math::Vector2f check = Math::Normalize(Math::Vector2f(1.0f, 1.0f));
        REQUIRE(Math::Equal(rotation1 * Math::Vector2f(1.0f, 0.0f), check));
        REQUIRE(Math::Equal(rotation1 * Math::Point2f(1.0f, 0.0f), Math::Point2f(check)));
    }

    SECTION("Shear")
    {
        Math::Transform2f shear1 = Math::ShearX(Math::f32(2.0f));
        REQUIRE(Math::Equal(shear1 * Math::Vector2f(1.0f, 1.0f), Math::Vector2f(3.0f, 1.0f)));
        REQUIRE(Math::Equal(shear1 * Math::Point2f(1.0f, 1.0f), Math::Point2f(3.0f, 1.0f)));

        Math::Transform2f shear2 = Math::ShearY(Math::f32(2.0f));
        REQUIRE(Math::Equal(shear2 * Math::Vector2f(1.0f, 1.0f), Math::Vector2f(1.0f, 3.0f)));
        REQUIRE(Math::Equal(shear2 * Math::Point2f(1.0f, 1.0f), Math::Point2f(1.0f, 3.0f)));
    }
}

TEST_CASE("Test 3D transform helpers")
{
    SECTION("Scale")
    {
        Math::Transform3f scale1 = Math::Scale(Math::Vector3f(2.0f, 3.0f, 4.0f));
        REQUIRE(Math::Equal(scale1 * Math::Vector3f(1.0f, 1.0f, 1.0f), Math::Vector3f(2.0f, 3.0f, 4.0f)));
        REQUIRE(Math::Equal(scale1 * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(2.0f, 3.0f, 4.0f)));
    }

    SECTION("Translation")
    {
        Math::Transform3f translation1 = Math::Translate(Math::Vector3f(1.0f, 2.0f, 3.0f));
        REQUIRE(Math::Equal(translation1 * Math::Vector3f(0.0f, 0.0f, 0.0f), Math::Vector3f(0.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(translation1 * Math::Point3f(0.0f, 0.0f, 0.0f), Math::Point3f(1.0f, 2.0f, 3.0f)));
    }

    SECTION("Rotation")
    {
        auto sq2div2 = Math::Constants::Sqrt2<Math::f32> / 2.0f;

        Math::Transform3f rotation1 = Math::RotateX(Math::Constants::Pi<Math::f32> / 4.0f);
        Math::Vector3f check = Math::Vector3f(1.0f, sq2div2, sq2div2);
        REQUIRE(Math::Equal(rotation1 * Math::Vector3f(1.0f, 1.0f, 0.0f), check));
        REQUIRE(Math::Equal(rotation1 * Math::Point3f(1.0f, 1.0f, 0.0f), Math::Point3f(check)));

        Math::Transform3f rotation2 = Math::RotateY(Math::Constants::Pi<Math::f32> / 4.0f);
        check = Math::Vector3f(sq2div2, 1.0f, sq2div2);
        REQUIRE(Math::Equal(rotation2 * Math::Vector3f(0.0f, 1.0f, 1.0f), check));
        REQUIRE(Math::Equal(rotation2 * Math::Point3f(0.0f, 1.0f, 1.0f), Math::Point3f(check)));

        Math::Transform3f rotation3 = Math::RotateZ(Math::Constants::Pi<Math::f32> / 4.0f);
        check = Math::Vector3f(sq2div2, sq2div2, 1.0f);
        REQUIRE(Math::Equal(rotation3 * Math::Vector3f(1.0f, 0.0f, 1.0f), check));
        REQUIRE(Math::Equal(rotation3 * Math::Point3f(1.0f, 0.0f, 1.0f), Math::Point3f(check)));
    }

    SECTION("Shear")
    {
        Math::Transform3f shear1 = Math::ShearX(Math::f32(2.0f), Math::f32(3.0f));
        REQUIRE(Math::Equal(shear1 * Math::Vector3f(1.0f, 1.0f, 1.0f), Math::Vector3f(6.0f, 1.0f, 1.0f)));
        REQUIRE(Math::Equal(shear1 * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(6.0f, 1.0f, 1.0f)));

        Math::Transform3f shear2 = Math::ShearY(Math::f32(2.0f), Math::f32(3.0f));
        REQUIRE(Math::Equal(shear2 * Math::Vector3f(1.0f, 1.0f, 1.0f), Math::Vector3f(1.0f, 6.0f, 1.0f)));
        REQUIRE(Math::Equal(shear2 * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(1.0f, 6.0f, 1.0f)));

        Math::Transform3f shear3 = Math::ShearZ(Math::f32(2.0f), Math::f32(3.0f));
        REQUIRE(Math::Equal(shear3 * Math::Vector3f(1.0f, 1.0f, 1.0f), Math::Vector3f(1.0f, 1.0f, 6.0f)));
        REQUIRE(Math::Equal(shear3 * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(1.0f, 1.0f, 6.0f)));
    }
}

TEST_CASE("Test 3D LookAt transform")
{
    SECTION("Basic parameters")
    {
        Math::Transform3f lookAt = Math::LookAt(Math::Point3f(0.0f, 0.0f, 0.0f), Math::Vector3f(0.0f, 0.0f, 1.0f));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 0.0f), Math::Point3f(0.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 0.0f, 0.0f), Math::Point3f(-1.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 1.0f, 0.0f), Math::Point3f(0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 1.0f), Math::Point3f(0.0f, 0.0f, -1.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(-1.0f, 1.0f, -1.0f)));
    }

    SECTION("Non-zero position")
    {
        Math::Transform3f lookAt = Math::LookAt(Math::Point3f(1.0f, 2.0f, 3.0f), Math::Vector3f(0.0f, 0.0f, 1.0f));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 0.0f), Math::Point3f(-1.0f, -2.0f, -3.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 0.0f, 0.0f), Math::Point3f(-2.0f, -2.0f, -3.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 1.0f, 0.0f), Math::Point3f(-1.0f, -1.0f, -3.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 1.0f), Math::Point3f(-1.0f, -2.0f, -4.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(-2.0f, -1.0f, -4.0f)));
    }

    SECTION("Non-trivial view direction")
    {
        Math::Transform3f lookAt = Math::LookAt(Math::Point3f(0.0f, 0.0f, 0.0f), Math::Vector3f(1.0f, 0.0f, 1.0f));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 0.0f), Math::Point3f(0.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 0.0f, 0.0f), Math::Point3f(Math::Normalize(Math::Vector3f(-1.0f, 0.0f, -1.0f)))));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 1.0f, 0.0f), Math::Point3f(0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(0.0f, 0.0f, 1.0f), Math::Point3f(Math::Normalize(Math::Vector3f(1.0f, 0.0f, -1.0f)))));
        REQUIRE(Math::Equal(lookAt * Math::Point3f(1.0f, 1.0f, 1.0f), Math::Point3f(0.0f, 1.0f, -Math::Constants::Sqrt2<Math::f32>)));
    }
}

TEST_CASE("Test 3D projections")
{

}
