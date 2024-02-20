#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Point.hpp>
#include <Math/Matrix.hpp>
#include <Math/Transform.hpp>

TEST_CASE("Test basic concepts", "[Math][Concepts]")
{
    SECTION("Test Vector concepts")
    {
        STATIC_REQUIRE(Math::Concept::BasicVector<Math::Vector2f>);
        STATIC_REQUIRE(Math::Concept::BasicVector<Math::Vector3f>);
        STATIC_REQUIRE(Math::Concept::BasicVector<Math::Vector4f>);

        STATIC_REQUIRE(!Math::Concept::BasicVector<Math::Matrix2f>);
        STATIC_REQUIRE(!Math::Concept::BasicVector<Math::Matrix3f>);
        STATIC_REQUIRE(!Math::Concept::BasicVector<Math::Matrix4f>);

        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector2d>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector3f, Math::Vector3d>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector4f, Math::Vector4d>);

        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector3f>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector4f>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector3f, Math::Vector4f>);

        STATIC_REQUIRE(Math::Concept::Vector2<Math::Vector2f>);
        STATIC_REQUIRE(Math::Concept::Vector3<Math::Vector3f>);
        STATIC_REQUIRE(Math::Concept::Vector4<Math::Vector4f>);

        STATIC_REQUIRE(Math::Concept::Vector<Math::Vector2f>);
        STATIC_REQUIRE(Math::Concept::Vector<Math::Vector3f>);
        STATIC_REQUIRE(Math::Concept::Vector<Math::Vector4f>);
    }

    SECTION("Test Point concepts")
    {
        STATIC_REQUIRE(Math::Concept::BasicPoint<Math::Point2f>);
        STATIC_REQUIRE(Math::Concept::BasicPoint<Math::Point3f>);

        STATIC_REQUIRE(!Math::Concept::BasicPoint<Math::Matrix2f>);
        STATIC_REQUIRE(!Math::Concept::BasicPoint<Math::Matrix3f>);
        STATIC_REQUIRE(!Math::Concept::BasicPoint<Math::Matrix4f>);

        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point2f, Math::Point2d>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point3f, Math::Point3d>);
        STATIC_REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point2f, Math::Point3f>);

        STATIC_REQUIRE(Math::Concept::Point2<Math::Point2f>);
        STATIC_REQUIRE(Math::Concept::Point3<Math::Point3f>);

        STATIC_REQUIRE(Math::Concept::Point<Math::Point2f>);
        STATIC_REQUIRE(Math::Concept::Point<Math::Point3f>);
    }

    SECTION("Test Matrix concepts")
    {
        STATIC_REQUIRE(Math::Concept::BasicMatrix<Math::Matrix2f>);
        STATIC_REQUIRE(Math::Concept::BasicMatrix<Math::Matrix3f>);
        STATIC_REQUIRE(Math::Concept::BasicMatrix<Math::Matrix4f>);

        STATIC_REQUIRE(!Math::Concept::BasicMatrix<Math::Vector2f>);
        STATIC_REQUIRE(!Math::Concept::BasicMatrix<Math::Vector3f>);
        STATIC_REQUIRE(!Math::Concept::BasicMatrix<Math::Vector4f>);

        STATIC_REQUIRE(!Math::Concept::BasicMatrix<Math::Point2f>);
        STATIC_REQUIRE(!Math::Concept::BasicMatrix<Math::Point3f>);

        STATIC_REQUIRE(Math::Concept::Matrix2<Math::Matrix2f>);
        STATIC_REQUIRE(Math::Concept::Matrix3<Math::Matrix3f>);
        STATIC_REQUIRE(Math::Concept::Matrix4<Math::Matrix4f>);

        STATIC_REQUIRE(Math::Concept::Matrix<Math::Matrix2f>);
        STATIC_REQUIRE(Math::Concept::Matrix<Math::Matrix3f>);
        STATIC_REQUIRE(Math::Concept::Matrix<Math::Matrix4f>);
    }

    SECTION("Test Transform concepts")
    {
        STATIC_REQUIRE(Math::Concept::BasicTransform<Math::Transform2f>);
        STATIC_REQUIRE(Math::Concept::BasicTransform<Math::Transform3f>);

        STATIC_REQUIRE(Math::Concept::Transform2<Math::Transform2f>);
        STATIC_REQUIRE(Math::Concept::Transform3<Math::Transform3f>);

        STATIC_REQUIRE(!Math::Concept::Transform2<Math::Matrix2f>);
        STATIC_REQUIRE(!Math::Concept::Transform3<Math::Matrix3f>);

        STATIC_REQUIRE(!Math::Concept::Transform2<Math::Transform3f>);
        STATIC_REQUIRE(!Math::Concept::Transform3<Math::Transform2f>);

        STATIC_REQUIRE(Math::Concept::Transform<Math::Transform2f>);
        STATIC_REQUIRE(Math::Concept::Transform<Math::Transform3f>);
    }
}
