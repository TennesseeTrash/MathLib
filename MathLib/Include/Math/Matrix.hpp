#ifndef MATHLIB_MATRIX_HPP
#define MATHLIB_MATRIX_HPP

#include "Common/Types.hpp"
#include "Common/Concepts.hpp"
#include "Functions.hpp"

#include "Vector.hpp"
#include "Point.hpp"

#include "Implementation/Matrix2.hpp"
#include "Implementation/Matrix3.hpp"
#include "Implementation/Matrix4.hpp"
#include "Implementation/MatrixOperators.hpp"

#include <array>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Matrix2f = Matrix2T<f32>;
    using Matrix3f = Matrix3T<f32>;
    using Matrix4f = Matrix4T<f32>;

    using Matrix2d = Matrix2T<f64>;
    using Matrix3d = Matrix3T<f64>;
    using Matrix4d = Matrix4T<f64>;

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Matrix2T<T>& m, const Point2T<T>& p) noexcept
    {
        constexpr size_t dim = 2;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Matrix3T<T>& m, const Point2T<T>& p) noexcept
    {
        constexpr size_t dim = 2;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
            result[i] += m[i][dim];
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Matrix3T<T>& m, const Point3T<T>& p) noexcept
    {
        constexpr size_t dim = 3;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Matrix4T<T>& m, const Point3T<T>& p) noexcept
    {
        constexpr size_t dim = 3;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
            result[i] += m[i][dim];
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Point2T<T>& p, const Matrix2T<T>& m) noexcept
    {
        constexpr size_t dim = 2;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point2T<T> operator* (const Point2T<T>& p, const Matrix3T<T>& m) noexcept
    {
        constexpr size_t dim = 2;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
            result[i] += m[dim][i];
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Point3T<T>& p, const Matrix3T<T>& m) noexcept
    {
        constexpr size_t dim = 3;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
        }
        return result;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Point3T<T> operator* (const Point3T<T>& p, const Matrix4T<T>& m) noexcept
    {
        constexpr size_t dim = 3;
        Point2T<T> result;
        for (size_t i = 0; i < dim; ++i)
        {
            for (size_t j = 0; j < dim; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
            result[i] += m[dim][i];
        }
        return result;
    }

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(ConceptMatrix2<Matrix2f>);
    static_assert(ConceptMatrix3<Matrix3f>);
    static_assert(ConceptMatrix4<Matrix4f>);

    static_assert(ConceptMatrix2<Matrix2d>);
    static_assert(ConceptMatrix3<Matrix3d>);
    static_assert(ConceptMatrix4<Matrix4d>);
}

#endif //MATHLIB_MATRIX_HPP
