#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Point.hpp>
#include <Math/Matrix.hpp>
#include <Math/Transform.hpp>

TEST_CASE("Test basic concepts", "[Math][Concepts]")
{
    SECTION("Test Vector concepts")
    {
        REQUIRE(Math::Concept::BasicVector<Math::Vector2f>);
        REQUIRE(Math::Concept::BasicVector<Math::Vector3f>);
        REQUIRE(Math::Concept::BasicVector<Math::Vector4f>);

        REQUIRE(!Math::Concept::BasicVector<Math::Matrix2f>);
        REQUIRE(!Math::Concept::BasicVector<Math::Matrix3f>);
        REQUIRE(!Math::Concept::BasicVector<Math::Matrix4f>);

        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector2d>);
        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector3f, Math::Vector3d>);
        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector4f, Math::Vector4d>);

        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector3f>);
        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector2f, Math::Vector4f>);
        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Vector3f, Math::Vector4f>);

        REQUIRE(Math::Concept::Vector2<Math::Vector2f>);
        REQUIRE(Math::Concept::Vector3<Math::Vector3f>);
        REQUIRE(Math::Concept::Vector4<Math::Vector4f>);

        REQUIRE(Math::Concept::Vector<Math::Vector2f>);
        REQUIRE(Math::Concept::Vector<Math::Vector3f>);
        REQUIRE(Math::Concept::Vector<Math::Vector4f>);
    }

    SECTION("Test Point concepts")
    {
        REQUIRE(Math::Concept::BasicPoint<Math::Point2f>);
        REQUIRE(Math::Concept::BasicPoint<Math::Point3f>);

        REQUIRE(!Math::Concept::BasicPoint<Math::Matrix2f>);
        REQUIRE(!Math::Concept::BasicPoint<Math::Matrix3f>);
        REQUIRE(!Math::Concept::BasicPoint<Math::Matrix4f>);

        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point2f, Math::Point2d>);
        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point3f, Math::Point3d>);

        REQUIRE(!Math::Concept::BinaryArithmetic<Math::Point2f, Math::Point3f>);

        REQUIRE(Math::Concept::Point2<Math::Point2f>);
        REQUIRE(Math::Concept::Point3<Math::Point3f>);

        REQUIRE(Math::Concept::Point<Math::Point2f>);
        REQUIRE(Math::Concept::Point<Math::Point3f>);
    }

    SECTION("Test Matrix concepts")
    {
        REQUIRE(Math::Concept::BasicMatrix<Math::Matrix2f>);
        REQUIRE(Math::Concept::BasicMatrix<Math::Matrix3f>);
        REQUIRE(Math::Concept::BasicMatrix<Math::Matrix4f>);

        REQUIRE(!Math::Concept::BasicMatrix<Math::Vector2f>);
        REQUIRE(!Math::Concept::BasicMatrix<Math::Vector3f>);
        REQUIRE(!Math::Concept::BasicMatrix<Math::Vector4f>);

        REQUIRE(!Math::Concept::BasicMatrix<Math::Point2f>);
        REQUIRE(!Math::Concept::BasicMatrix<Math::Point3f>);

        REQUIRE(Math::Concept::Matrix2<Math::Matrix2f>);
        REQUIRE(Math::Concept::Matrix3<Math::Matrix3f>);
        REQUIRE(Math::Concept::Matrix4<Math::Matrix4f>);

        REQUIRE(Math::Concept::Matrix<Math::Matrix2f>);
        REQUIRE(Math::Concept::Matrix<Math::Matrix3f>);
        REQUIRE(Math::Concept::Matrix<Math::Matrix4f>);
    }

    SECTION("Test Transform concepts")
    {
        REQUIRE(Math::Concept::BasicTransform<Math::Transform2f>);
        REQUIRE(Math::Concept::BasicTransform<Math::Transform3f>);

        REQUIRE(Math::Concept::Transform2<Math::Transform2f>);
        REQUIRE(Math::Concept::Transform3<Math::Transform3f>);

        REQUIRE(!Math::Concept::Transform2<Math::Matrix2f>);
        REQUIRE(!Math::Concept::Transform3<Math::Matrix3f>);

        REQUIRE(!Math::Concept::Transform2<Math::Transform3f>);
        REQUIRE(!Math::Concept::Transform3<Math::Transform2f>);

        REQUIRE(Math::Concept::Transform<Math::Transform2f>);
        REQUIRE(Math::Concept::Transform<Math::Transform3f>);
    }
}
