#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>
#include <Math/Point.hpp>
#include <Math/Matrix.hpp>
#include <Math/Transform.hpp>

TEST_CASE("Test basic concepts", "[Math][Concepts]")
{
    SECTION("Test Vector concepts")
    {
        REQUIRE(Math::ConceptBasicVector<Math::Vector2f>);
        REQUIRE(Math::ConceptBasicVector<Math::Vector3f>);
        REQUIRE(Math::ConceptBasicVector<Math::Vector4f>);

        REQUIRE(!Math::ConceptBasicVector<Math::Matrix2f>);
        REQUIRE(!Math::ConceptBasicVector<Math::Matrix3f>);
        REQUIRE(!Math::ConceptBasicVector<Math::Matrix4f>);

        REQUIRE(!Math::BinaryArithmetic<Math::Vector2f, Math::Vector2d>);
        REQUIRE(!Math::BinaryArithmetic<Math::Vector3f, Math::Vector3d>);
        REQUIRE(!Math::BinaryArithmetic<Math::Vector4f, Math::Vector4d>);

        REQUIRE(!Math::BinaryArithmetic<Math::Vector2f, Math::Vector3f>);
        REQUIRE(!Math::BinaryArithmetic<Math::Vector2f, Math::Vector4f>);
        REQUIRE(!Math::BinaryArithmetic<Math::Vector3f, Math::Vector4f>);

        REQUIRE(Math::ConceptVector2<Math::Vector2f>);
        REQUIRE(Math::ConceptVector3<Math::Vector3f>);
        REQUIRE(Math::ConceptVector4<Math::Vector4f>);

        REQUIRE(Math::ConceptVector<Math::Vector2f>);
        REQUIRE(Math::ConceptVector<Math::Vector3f>);
        REQUIRE(Math::ConceptVector<Math::Vector4f>);
    }

    SECTION("Test Point concepts")
    {
        REQUIRE(Math::ConceptBasicPoint<Math::Point2f>);
        REQUIRE(Math::ConceptBasicPoint<Math::Point3f>);

        REQUIRE(!Math::ConceptBasicPoint<Math::Matrix2f>);
        REQUIRE(!Math::ConceptBasicPoint<Math::Matrix3f>);
        REQUIRE(!Math::ConceptBasicPoint<Math::Matrix4f>);

        REQUIRE(!Math::BinaryArithmetic<Math::Point2f, Math::Point2d>);
        REQUIRE(!Math::BinaryArithmetic<Math::Point3f, Math::Point3d>);

        REQUIRE(!Math::BinaryArithmetic<Math::Point2f, Math::Point3f>);

        REQUIRE(Math::ConceptPoint2<Math::Point2f>);
        REQUIRE(Math::ConceptPoint3<Math::Point3f>);

        REQUIRE(Math::ConceptPoint<Math::Point2f>);
        REQUIRE(Math::ConceptPoint<Math::Point3f>);
    }

    SECTION("Test Matrix concepts")
    {
        REQUIRE(Math::ConceptBasicMatrix<Math::Matrix2f>);
        REQUIRE(Math::ConceptBasicMatrix<Math::Matrix3f>);
        REQUIRE(Math::ConceptBasicMatrix<Math::Matrix4f>);

        REQUIRE(!Math::ConceptBasicMatrix<Math::Vector2f>);
        REQUIRE(!Math::ConceptBasicMatrix<Math::Vector3f>);
        REQUIRE(!Math::ConceptBasicMatrix<Math::Vector4f>);

        REQUIRE(!Math::ConceptBasicMatrix<Math::Point2f>);
        REQUIRE(!Math::ConceptBasicMatrix<Math::Point3f>);

        REQUIRE(Math::ConceptMatrix2<Math::Matrix2f>);
        REQUIRE(Math::ConceptMatrix3<Math::Matrix3f>);
        REQUIRE(Math::ConceptMatrix4<Math::Matrix4f>);

        REQUIRE(Math::ConceptMatrix<Math::Matrix2f>);
        REQUIRE(Math::ConceptMatrix<Math::Matrix3f>);
        REQUIRE(Math::ConceptMatrix<Math::Matrix4f>);
    }

    SECTION("Test Transform concepts")
    {
        REQUIRE(Math::ConceptBasicTransform<Math::Transform2f>);
        REQUIRE(Math::ConceptBasicTransform<Math::Transform3f>);

        REQUIRE(Math::ConceptTransform2<Math::Transform2f>);
        REQUIRE(Math::ConceptTransform3<Math::Transform3f>);

        REQUIRE(!Math::ConceptTransform2<Math::Matrix2f>);
        REQUIRE(!Math::ConceptTransform3<Math::Matrix3f>);

        REQUIRE(!Math::ConceptTransform2<Math::Transform3f>);
        REQUIRE(!Math::ConceptTransform3<Math::Transform2f>);

        REQUIRE(Math::ConceptTransform<Math::Transform2f>);
        REQUIRE(Math::ConceptTransform<Math::Transform3f>);
    }
}
