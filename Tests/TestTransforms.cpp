#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Point.hpp>
#include <Math/Matrix.hpp>
#include <Math/Transform.hpp>

#include <Math/Debug/StreamOperators.hpp>
#include <iostream>

namespace
{
    Math::Transform2f MakeTransform2f1()
    {
        return Math::Transform2f(
            1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f
        );
    }

    Math::Transform2f MakeTransform2f2()
    {
        return Math::Transform2f(
            7.0f,  8.0f,  9.0f,
            10.0f, 11.0f, 12.0f
        );
    }

    Math::Transform2f MakeTransform2f3()
    {
        return Math::Transform2f(
            27.0f, 30.0f,  36.0f,
            78.0f, 87.0f, 102.0f
        );
    }

    Math::Transform3f MakeTransform3f1()
    {
        return Math::Transform3f(
            1.0f,  2.0f,  3.0f,  4.0f,
            5.0f,  6.0f,  7.0f,  8.0f,
            9.0f, 10.0f, 11.0f, 12.0f
        );
    }

    Math::Transform3f MakeTransform3f2()
    {
        return Math::Transform3f(
            13.0f, 14.0f, 15.0f, 16.0f,
            17.0f, 18.0f, 19.0f, 20.0f,
            21.0f, 22.0f, 23.0f, 24.0f
        );
    }

    Math::Transform3f MakeTransform3f3()
    {
        return Math::Transform3f(
            110.0f, 116.0f, 122.0f, 132.0f,
            314.0f, 332.0f, 350.0f, 376.0f,
            518.0f, 548.0f, 578.0f, 620.0f
        );
    }
}

TEST_CASE("Test transform multiplication", "[Math][Transform]")
{
    SECTION("Transform2f multiplication")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * MakeTransform2f2(), MakeTransform2f3()));
    }

    SECTION("Transform3f multiplication")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * MakeTransform3f2(), MakeTransform3f3()));
    }

    SECTION("Transform2f mutable multiplication")
    {
        auto t1 = MakeTransform2f1();
        t1 *= MakeTransform2f2();
        REQUIRE(Math::Equal(t1, MakeTransform2f3()));
    }

    SECTION("Transform3f mutable multiplication")
    {
        auto t1 = MakeTransform3f1();
        t1 *= MakeTransform3f2();
        REQUIRE(Math::Equal(t1, MakeTransform3f3()));
    }
}

TEST_CASE("Test ToMatrix member function", "[Math][Transform]")
{
    SECTION("Transform2f::ToMatrix")
    {
        REQUIRE(Math::Equal(MakeTransform2f1().ToMatrix(), Math::Matrix3f(
            1.0f, 2.0f, 3.0f,
            4.0f, 5.0f, 6.0f,
            0.0f, 0.0f, 1.0f
        )));
    }

    SECTION("Transform3f::ToMatrix")
    {
        REQUIRE(Math::Equal(MakeTransform3f1().ToMatrix(), Math::Matrix4f(
            1.0f,  2.0f,  3.0f,  4.0f,
            5.0f,  6.0f,  7.0f,  8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            0.0f,  0.0f,  0.0f,  1.0f
        )));
    }
}

TEST_CASE("Test transform-vector multiplication", "[Math][Transform]")
{
    SECTION("Test Transform2f with Vector2f and Vector3f")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Vector2f(1.0f, 2.0f), Math::Vector2f(5.0f, 14.0f)));
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Vector3f(1.0f, 2.0f, 3.0f), Math::Vector3f(14.0f, 32.0f, 3.0f)));
    }

    SECTION("Test Transform3f with Vector3f and Vector4f")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Vector3f(1.0f, 2.0f, 3.0f), Math::Vector3f(14.0f, 38.0f, 62.0f)));
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Vector4f(1.0f, 2.0f, 3.0f, 4.0f), Math::Vector4f(30.0f, 70.0f, 110.0f, 4.0f)));
    }
}

TEST_CASE("Test transform-point multiplication", "[Math][Transform]")
{
    SECTION("Test Transform2f * Point2f")
    {
        REQUIRE(Math::Equal(MakeTransform2f1() * Math::Point2f(1.0f, 2.0f), Math::Point2f(8.0f, 20.0f)));
    }

    SECTION("Test Transform3f * Point3f")
    {
        REQUIRE(Math::Equal(MakeTransform3f1() * Math::Point3f(1.0f, 2.0f, 3.0f), Math::Point3f(18.0f, 46.0f, 74.0f)));
    }
}

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
