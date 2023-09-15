#include <catch2/catch_test_macros.hpp>
#include <Math/Matrix.hpp>
#include <Math/Debug/StreamOperators.hpp>

namespace
{
    Math::Matrix2f MakeTestingMatrix2f()
    {
        return Math::Matrix2f(1.0f, 2.0f,
                              3.0f, 4.0f);
    }

    Math::Matrix2f MakeTestingMatrix2f2()
    {
        return Math::Matrix2f(5.0f, 6.0f,
                              7.0f, 8.0f);
    }

    Math::Matrix3f MakeTestingMatrix3f()
    {
        return Math::Matrix3f( 1.0f,  2.0f,  3.0f,
                               4.0f,  5.0f,  6.0f,
                               7.0f,  8.0f,  9.0f);
    }

    Math::Matrix3f MakeTestingMatrix3f2()
    {
        return Math::Matrix3f(10.0f, 11.0f, 12.0f,
                              13.0f, 14.0f, 15.0f,
                              16.0f, 17.0f, 18.0f);
    }

    Math::Matrix4f MakeTestingMatrix4f()
    {
        return Math::Matrix4f( 1.0f,  2.0f,  3.0f,  4.0f,
                               5.0f,  6.0f,  7.0f,  8.0f,
                               9.0f, 10.0f, 11.0f, 12.0f,
                              13.0f, 14.0f, 15.0f, 16.0f);
    }

    Math::Matrix4f MakeTestingMatrix4f2()
    {
        return Math::Matrix4f(17.0f, 18.0f, 19.0f, 20.0f,
                              21.0f, 22.0f, 23.0f, 24.0f,
                              25.0f, 26.0f, 27.0f, 28.0f,
                              29.0f, 30.0f, 31.0f, 32.0f);
    }
}

TEST_CASE("Check default constructors", "[Math][Matrix]")
{
    SECTION("Matrix2f default constructor")
    {
        Math::Matrix2f m;

        REQUIRE(Math::Equal(m[0], Math::Vector2f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(0.0f)));
    }

    SECTION("Matrix3f default constructor")
    {
        Math::Matrix3f m;

        REQUIRE(Math::Equal(m[0], Math::Vector3f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(0.0f)));
    }

    SECTION("Matrix4f default constructor")
    {
        Math::Matrix4f m;

        REQUIRE(Math::Equal(m[0], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f(0.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(0.0f)));
    }
}

TEST_CASE("Check diagonal constructor", "[Math][Matrix]")
{
    SECTION("Matrix2f diagonal constructor")
    {
        Math::Matrix2f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector2f(1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(0.0f, 1.0f)));
    }

    SECTION("Matrix3f diagonal constructor")
    {
        Math::Matrix3f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector3f(1.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(0.0f, 0.0f, 1.0f)));
    }

    SECTION("Matrix4f diagonal constructor")
    {
        Math::Matrix4f m(1.0f);

        REQUIRE(Math::Equal(m[0], Math::Vector4f(1.0f, 0.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f(0.0f, 1.0f, 0.0f, 0.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f(0.0f, 0.0f, 1.0f, 0.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(0.0f, 0.0f, 0.0f, 1.0f)));
    }
}

TEST_CASE("Check full constructors", "[Math][Matrix]")
{
    SECTION("Matrix2f full constructor")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();

        REQUIRE(Math::Equal(m[0], Math::Vector2f(1.0f, 2.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector2f(3.0f, 4.0f)));
    }

    SECTION("Matrix3f full constructor")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();

        REQUIRE(Math::Equal(m[0], Math::Vector3f(1.0f, 2.0f, 3.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector3f(4.0f, 5.0f, 6.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector3f(7.0f, 8.0f, 9.0f)));
    }

    SECTION("Matrix4f full constructor")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();

        REQUIRE(Math::Equal(m[0], Math::Vector4f( 1.0f,  2.0f,  3.0f,  4.0f)));
        REQUIRE(Math::Equal(m[1], Math::Vector4f( 5.0f,  6.0f,  7.0f,  8.0f)));
        REQUIRE(Math::Equal(m[2], Math::Vector4f( 9.0f, 10.0f, 11.0f, 12.0f)));
        REQUIRE(Math::Equal(m[3], Math::Vector4f(13.0f, 14.0f, 15.0f, 16.0f)));
    }
}

TEST_CASE("Test addition operators", "[Math][Matrix]")
{
    SECTION("Matrix2f addition")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
    }

    SECTION("Matrix3f addition")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] + m2[2]));
    }

    SECTION("Matrix4f addition")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 + m2;

        REQUIRE(Math::Equal(m3[0], m1[0] + m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] + m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] + m2[2]));
        REQUIRE(Math::Equal(m3[3], m1[3] + m2[3]));
    }
}

TEST_CASE("Test subtraction operators", "[Math][Matrix]")
{
    SECTION("Matrix2f subtraction")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
    }

    SECTION("Matrix3f subtraction")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] - m2[2]));
    }

    SECTION("Matrix4f subtraction")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 - m2;

        REQUIRE(Math::Equal(m3[0], m1[0] - m2[0]));
        REQUIRE(Math::Equal(m3[1], m1[1] - m2[1]));
        REQUIRE(Math::Equal(m3[2], m1[2] - m2[2]));
        REQUIRE(Math::Equal(m3[3], m1[3] - m2[3]));
    }
}

TEST_CASE("Test matrix multiplication", "[Math][Matrix]")
{
    SECTION("Matrix2f multiplication")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = MakeTestingMatrix2f2();
        Math::Matrix2f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector2f(19.0f, 22.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector2f(43.0f, 50.0f)));
    }

    SECTION("Matrix3f multiplication")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = MakeTestingMatrix3f2();
        Math::Matrix3f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector3f( 84.0f,  90.0f,  96.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector3f(201.0f, 216.0f, 231.0f)));
        REQUIRE(Math::Equal(m3[2], Math::Vector3f(318.0f, 342.0f, 366.0f)));
    }

    SECTION("Matrix4f multiplication")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = MakeTestingMatrix4f2();
        Math::Matrix4f m3 = m1 * m2;

        REQUIRE(Math::Equal(m3[0], Math::Vector4f( 250.0f,  260.0f,  270.0f,  280.0f)));
        REQUIRE(Math::Equal(m3[1], Math::Vector4f( 618.0f,  644.0f,  670.0f,  696.0f)));
        REQUIRE(Math::Equal(m3[2], Math::Vector4f( 986.0f, 1028.0f, 1070.0f, 1112.0f)));
        REQUIRE(Math::Equal(m3[3], Math::Vector4f(1354.0f, 1412.0f, 1470.0f, 1528.0f)));
    }
}

TEST_CASE("Test scalar addition operators", "[Math][Matrix]")
{
    SECTION("Scalar + Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f + m1;

        REQUIRE(Math::Equal(m2[0], 5.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f + m1[1]));
    }

    SECTION("Matrix2f + Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 + 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 5.0f));
    }

    SECTION("Scalar + Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f + m1;

        REQUIRE(Math::Equal(m2[0], 10.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f + m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f + m1[2]));
    }

    SECTION("Matrix3f + Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 + 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] + 10.0f));
    }

    SECTION("Matrix4f + Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 + 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] + 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] + 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] + 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] + 10.0f));
    }

    SECTION("Scalar + Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f + m1;

        REQUIRE(Math::Equal(m2[0], 10.0f + m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f + m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f + m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f + m1[3]));
    }
}

TEST_CASE("Test scalar subtraction operators", "[Math][Matrix]")
{
    SECTION("Scalar - Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f - m1;

        REQUIRE(Math::Equal(m2[0], 5.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f - m1[1]));
    }

    SECTION("Matrix2f - Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 - 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 5.0f));
    }

    SECTION("Scalar - Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f - m1;

        REQUIRE(Math::Equal(m2[0], 10.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f - m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f - m1[2]));
    }

    SECTION("Matrix3f - Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 - 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] - 10.0f));
    }

    SECTION("Matrix4f - Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 - 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] - 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] - 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] - 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] - 10.0f));
    }

    SECTION("Scalar - Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f - m1;

        REQUIRE(Math::Equal(m2[0], 10.0f - m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f - m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f - m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f - m1[3]));
    }
}

TEST_CASE("Test scalar multiplication operators", "[Math][Matrix]")
{
    SECTION("Scalar * Matrix2f")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = 5.0f * m1;

        REQUIRE(Math::Equal(m2[0], 5.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 5.0f * m1[1]));
    }

    SECTION("Matrix2f * Scalar")
    {
        Math::Matrix2f m1 = MakeTestingMatrix2f();
        Math::Matrix2f m2 = m1 * 5.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 5.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 5.0f));
    }

    SECTION("Scalar * Matrix3f")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = 10.0f * m1;

        REQUIRE(Math::Equal(m2[0], 10.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f * m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f * m1[2]));
    }

    SECTION("Matrix3f * Scalar")
    {
        Math::Matrix3f m1 = MakeTestingMatrix3f();
        Math::Matrix3f m2 = m1 * 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] * 10.0f));
    }

    SECTION("Matrix4f * Scalar")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = m1 * 10.0f;

        REQUIRE(Math::Equal(m2[0], m1[0] * 10.0f));
        REQUIRE(Math::Equal(m2[1], m1[1] * 10.0f));
        REQUIRE(Math::Equal(m2[2], m1[2] * 10.0f));
        REQUIRE(Math::Equal(m2[3], m1[3] * 10.0f));
    }

    SECTION("Scalar * Matrix4f")
    {
        Math::Matrix4f m1 = MakeTestingMatrix4f();
        Math::Matrix4f m2 = 10.0f * m1;

        REQUIRE(Math::Equal(m2[0], 10.0f * m1[0]));
        REQUIRE(Math::Equal(m2[1], 10.0f * m1[1]));
        REQUIRE(Math::Equal(m2[2], 10.0f * m1[2]));
        REQUIRE(Math::Equal(m2[3], 10.0f * m1[3]));
    }
}

TEST_CASE("Test matrix vector multiplication", "[Math][Matrix]")
{
    SECTION("Matrix2f * Vector2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Vector2f v(1.0f, 2.0f);
        Math::Vector2f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector2f(5.0f, 11.0f)));
    }

    SECTION("Vector2f * Matrix2f")
    {
        Math::Matrix2f m = MakeTestingMatrix2f();
        Math::Vector2f v(1.0f, 2.0f);
        Math::Vector2f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector2f(7.0f, 10.0f)));
    }

    SECTION("Matrix3f * Vector3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Vector3f v(1.0f, 2.0f, 3.0f);
        Math::Vector3f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector3f(14.0f, 32.0f, 50.0f)));
    }

    SECTION("Vector3f * Matrix3f")
    {
        Math::Matrix3f m = MakeTestingMatrix3f();
        Math::Vector3f v(1.0f, 2.0f, 3.0f);
        Math::Vector3f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector3f(30.0f, 36.0f, 42.0f)));
    }

    SECTION("Matrix4f * Vector4f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f v2 = m * v;

        REQUIRE(Math::Equal(v2, Math::Vector4f(30.0f, 70.0f, 110.0f, 150.0f)));
    }

    SECTION("Vector4f * Matrix4f")
    {
        Math::Matrix4f m = MakeTestingMatrix4f();
        Math::Vector4f v(1.0f, 2.0f, 3.0f, 4.0f);
        Math::Vector4f v2 = v * m;

        REQUIRE(Math::Equal(v2, Math::Vector4f(90.0f, 100.0f, 110.0f, 120.0f)));
    }
}

TEST_CASE("Check determinant calculations", "[Math][Matrix]")
{
    SECTION("Matrix2f determinant")
    {
        Math::Matrix2f m(48.0f, -0.34f,
                         1.05f, 12.43f);

        REQUIRE(Math::Equal(Math::Determinant(m), 591.0f));
    }

    SECTION("Matrix3f determinant")
    {
        Math::Matrix3f m(48.0f, -0.34f,   0.34f,
                         1.05f, 12.43f,   0.12f,
                         13.0f, -0.21f, -65.01f);

        REQUIRE(Math::Equal(Math::Determinant(m), 591.0f));
    }

    SECTION("Matrix4f determinant")
    {
        Math::Matrix4f m(48.0f, -0.34f,   0.34f,    0.0f,
                         1.05f, 12.43f,   0.12f,  -34.0f,
                         13.0f, -0.21f, -65.01f, -0.001f,
                         0.01f, -0.23f,  -0.11f,  -0.45f);

        REQUIRE(Math::Equal(Math::Determinant(m), 591.0f));
    }
}

TEST_CASE("Check inverse calculations", "[Math][Matrix]")
{
    SECTION("Matrix2f inverse")
    {
        Math::Matrix2f m(48.0f, -0.34f,
                         1.05f, 12.43f);

        Math::Matrix2f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix2f(1.0f)));
    }

    SECTION("Matrix3f inverse")
    {
        Math::Matrix3f m(48.0f, -0.34f, 0.34f,
                         1.05f, 12.43f, 0.12f,
                         13.0f, -0.21f, -65.01f);

        Math::Matrix3f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix3f(1.0f)));
    }

    SECTION("Matrix4f inverse")
    {
        Math::Matrix4f m(48.0f, -0.34f, 0.34f,     0.0f,
                         1.05f, 12.43f, 0.12f,   -34.0f,
                         13.0f, -0.21f, -65.01f, -0.001f,
                         0.01f, -0.23f, -0.11f,   -0.45f);

        Math::Matrix4f m_inverse = Math::Invert(m);

        REQUIRE(Math::Equal((m * m_inverse), Math::Matrix4f(1.0f), 1.0e-5f));
    }
}
