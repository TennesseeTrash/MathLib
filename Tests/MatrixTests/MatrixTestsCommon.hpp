#ifndef MATHLIB_TESTS_MATRIX_TESTS_COMMON_HPP
#define MATHLIB_TESTS_MATRIX_TESTS_COMMON_HPP

#include <Math/Matrix.hpp>

constexpr Math::Matrix2f MakeTestingMatrix2f()
{
    return Math::Matrix2f(1.0f, 2.0f,
                            3.0f, 4.0f);
}

constexpr Math::Matrix2f MakeTestingMatrix2f2()
{
    return Math::Matrix2f(5.0f, 6.0f,
                            7.0f, 8.0f);
}

constexpr Math::Matrix3f MakeTestingMatrix3f()
{
    return Math::Matrix3f( 1.0f,  2.0f,  3.0f,
                            4.0f,  5.0f,  6.0f,
                            7.0f,  8.0f,  9.0f);
}

constexpr Math::Matrix3f MakeTestingMatrix3f2()
{
    return Math::Matrix3f(10.0f, 11.0f, 12.0f,
                            13.0f, 14.0f, 15.0f,
                            16.0f, 17.0f, 18.0f);
}

constexpr Math::Matrix4f MakeTestingMatrix4f()
{
    return Math::Matrix4f( 1.0f,  2.0f,  3.0f,  4.0f,
                            5.0f,  6.0f,  7.0f,  8.0f,
                            9.0f, 10.0f, 11.0f, 12.0f,
                            13.0f, 14.0f, 15.0f, 16.0f);
}

constexpr Math::Matrix4f MakeTestingMatrix4f2()
{
    return Math::Matrix4f(17.0f, 18.0f, 19.0f, 20.0f,
                            21.0f, 22.0f, 23.0f, 24.0f,
                            25.0f, 26.0f, 27.0f, 28.0f,
                            29.0f, 30.0f, 31.0f, 32.0f);
}

#endif //MATRIX_TESTS_MATRIX_TESTS_COMMON_HPP
