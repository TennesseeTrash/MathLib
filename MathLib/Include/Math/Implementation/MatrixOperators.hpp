#ifndef MATHLIB_IMPL_MATRIX_OPERATORS_HPP
#define MATHLIB_IMPL_MATRIX_OPERATORS_HPP

#include "../Common/Concepts.hpp"
#include "VectorOperators.hpp"
#include "Utilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Matrix-Matrix operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (const Mat& a, const Mat& b) noexcept
    {
        Mat c;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                for (SizeType k = 0; k < Mat::Dimension; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    //////////////////////////////////////////////////////////////////////////
    // Matrix-Scalar operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] += s;
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator+ (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] += s;
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] -= s;
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator- (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] = s - m[i][j];
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator* (typename Mat::ScalarType s, const Mat& m) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    Mat operator/ (const Mat& m, typename Mat::ScalarType s) noexcept
    {
        Mat scaled = m;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                scaled[i][j] /= s;
            }
        }
        return scaled;
    }

    //////////////////////////////////////////////////////////////////////////
    // Matrix-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    typename Mat::VectorType operator* (const Mat& m, const typename Mat::VectorType& u) noexcept
    {
        typename Mat::VectorType result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            result[i] = Dot(m[i], u);
        }
        return result;
    }

    template <ConceptBasicMatrix Mat>
    [[nodiscard]] constexpr
    typename Mat::VectorType operator* (const typename Mat::VectorType& u, const Mat& m) noexcept
    {
        typename Mat::VectorType result;
        for (SizeType i = 0; i < Mat::Dimension; ++i)
        {
            for (SizeType j = 0; j < Mat::Dimension; ++j)
            {
                result[i] += u[j] * m[j][i];
            }
        }
        return result;
    }
}

#endif //MATHLIB_IMPL_MATRIX_OPERATORS_HPP
