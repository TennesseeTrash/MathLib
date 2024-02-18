#ifndef MATHLIB_IMPLEMENTATION_MATRIX_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_MATRIX_UTILITIES_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    template <Concept::Matrix Mat>
    [[nodiscard]] constexpr
    Mat Transpose(const Mat& m) noexcept
    {
        Mat result = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = i + 1; j < Mat::Dimension; ++j)
            {
                std::swap(result[i][j], result[j][i]);
            }
        }
        return result;
    }

    template <Concept::Matrix2 Mat>
    [[nodiscard]] constexpr
    typename Mat::ScalarType Determinant(const Mat& m) noexcept
    {
        return (m[0][0] * m[1][1])
             - (m[0][1] * m[1][0]);
    }

    template <Concept::Matrix3 Mat>
    [[nodiscard]] constexpr
    typename Mat::ScalarType Determinant(const Mat& m) noexcept
    {
        return (m[0][0] * m[1][1] * m[2][2])
             + (m[0][1] * m[1][2] * m[2][0])
             + (m[0][2] * m[1][0] * m[2][1])
             - (m[0][2] * m[1][1] * m[2][0])
             - (m[0][1] * m[1][0] * m[2][2])
             - (m[0][0] * m[1][2] * m[2][1]);
    }

    template <Concept::Matrix4 Mat>
    [[nodiscard]] constexpr
    typename Mat::ScalarType Determinant(const Mat& m) noexcept
    {
        return (m[0][0] * m[1][1] * m[2][2] * m[3][3])
             + (m[0][0] * m[1][2] * m[2][3] * m[3][1])
             + (m[0][0] * m[1][3] * m[2][1] * m[3][2])
             - (m[0][0] * m[1][3] * m[2][2] * m[3][1])
             - (m[0][0] * m[1][2] * m[2][1] * m[3][3])
             - (m[0][0] * m[1][1] * m[2][3] * m[3][2])
             - (m[0][1] * m[1][0] * m[2][2] * m[3][3])
             - (m[0][2] * m[1][0] * m[2][3] * m[3][1])
             - (m[0][3] * m[1][0] * m[2][1] * m[3][2])
             + (m[0][3] * m[1][0] * m[2][2] * m[3][1])
             + (m[0][2] * m[1][0] * m[2][1] * m[3][3])
             + (m[0][1] * m[1][0] * m[2][3] * m[3][2])
             + (m[0][1] * m[1][2] * m[2][0] * m[3][3])
             + (m[0][2] * m[1][3] * m[2][0] * m[3][1])
             + (m[0][3] * m[1][1] * m[2][0] * m[3][2])
             - (m[0][3] * m[1][2] * m[2][0] * m[3][1])
             - (m[0][2] * m[1][1] * m[2][0] * m[3][3])
             - (m[0][1] * m[1][3] * m[2][0] * m[3][2])
             - (m[0][1] * m[1][2] * m[2][3] * m[3][0])
             - (m[0][2] * m[1][3] * m[2][1] * m[3][0])
             - (m[0][3] * m[1][1] * m[2][2] * m[3][0])
             + (m[0][3] * m[1][2] * m[2][1] * m[3][0])
             + (m[0][2] * m[1][1] * m[2][3] * m[3][0])
             + (m[0][1] * m[1][3] * m[2][2] * m[3][0]);
    }

    template <Concept::Matrix2 Mat>
    [[nodiscard]] constexpr
    Mat Adjugate(const Mat& m) noexcept
    {
        return Mat(
             m[1][1], -m[0][1],
            -m[1][0],  m[0][0]
        );
    }

    template <Concept::Matrix3 Mat>
    [[nodiscard]] constexpr
    Mat Adjugate(const Mat& m) noexcept
    {
        Mat result;
        result[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
        result[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]);
        result[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]);
        result[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]);
        result[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]);
        result[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]);
        result[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
        result[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]);
        result[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
        return result;
    }

    template <Concept::Matrix4 Mat>
    [[nodiscard]] constexpr
    Mat Adjugate(const Mat& m) noexcept
    {
        Mat result;
        result[0][0] =  (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]));
        result[0][1] = -(m[0][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[0][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[0][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]));
        result[0][2] =  (m[0][1] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) - m[0][2] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) + m[0][3] * (m[1][1] * m[3][2] - m[1][2] * m[3][1]));
        result[0][3] = -(m[0][1] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) - m[0][2] * (m[1][1] * m[2][3] - m[1][3] * m[2][1]) + m[0][3] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]));
        result[1][0] = -(m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]));
        result[1][1] =  (m[0][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[0][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[0][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]));
        result[1][2] = -(m[0][0] * (m[1][2] * m[3][3] - m[1][3] * m[3][2]) - m[0][2] * (m[1][0] * m[3][3] - m[1][3] * m[3][0]) + m[0][3] * (m[1][0] * m[3][2] - m[1][2] * m[3][0]));
        result[1][3] =  (m[0][0] * (m[1][2] * m[2][3] - m[1][3] * m[2][2]) - m[0][2] * (m[1][0] * m[2][3] - m[1][3] * m[2][0]) + m[0][3] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]));
        result[2][0] =  (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
        result[2][1] = -(m[0][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[0][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[0][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
        result[2][2] =  (m[0][0] * (m[1][1] * m[3][3] - m[1][3] * m[3][1]) - m[0][1] * (m[1][0] * m[3][3] - m[1][3] * m[3][0]) + m[0][3] * (m[1][0] * m[3][1] - m[1][1] * m[3][0]));
        result[2][3] = -(m[0][0] * (m[1][1] * m[2][3] - m[1][3] * m[2][1]) - m[0][1] * (m[1][0] * m[2][3] - m[1][3] * m[2][0]) + m[0][3] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]));
        result[3][0] = -(m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
        result[3][1] =  (m[0][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[0][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[0][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
        result[3][2] = -(m[0][0] * (m[1][1] * m[3][2] - m[1][2] * m[3][1]) - m[0][1] * (m[1][0] * m[3][2] - m[1][2] * m[3][0]) + m[0][2] * (m[1][0] * m[3][1] - m[1][1] * m[3][0]));
        result[3][3] =  (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]));
        return result;
    }

    template <Concept::Matrix Mat>
    [[nodiscard]] constexpr
    Mat Invert(const Mat& m) noexcept
    {
        return Adjugate(m) / Determinant(m);
    }

    template <Concept::BasicMatrix Mat>
    [[nodiscard]] constexpr
    bool HasNaN(const Mat& m)
    {
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            if (HasNaN(m[i]))
            {
                return true;
            }
        }

        return false;
    }
}

#endif //MATHLIB_IMPLEMENTATION_MATRIX_UTILITIES_HPP
