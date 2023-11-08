#ifndef MATHLIB_IMPL_MATRIX_HPP
#define MATHLIB_IMPL_MATRIX_HPP

#include "../Common/Array.hpp"
#include "Vector.hpp"

// TODO(3011): Add a generic, n-dimensional matrix implementation.

namespace Math
{
    template <ConceptStrongType T>
    class Matrix2T final
    {
    public:
        using ScalarType = T;
        static constexpr SizeType Dimension = 2;

        constexpr explicit Matrix2T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix2T(T diag) noexcept
            : rows({})
        {
            for (SizeType i = 0; i < 2; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix2T(const Vector2T<T>& row0,
                                    const Vector2T<T>& row1)
        noexcept
            : rows({ row0,
                     row1 })
        {}

        constexpr explicit Matrix2T(T m00, T m01,
                                    T m10, T m11)
        noexcept
            : rows(Vector2T<T>(m00, m01),
                   Vector2T<T>(m10, m11))
        {}

        constexpr       Vector2T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector2T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max()); }

        static constexpr Matrix2T<T> Identity() noexcept { return Matrix2T<T>(Convert<T>(1)); }
    private:
        Array<Vector2T<T>, 2> rows;
    };

    template <ConceptStrongType T>
    class Matrix3T final
    {
    public:
        using ScalarType = T;
        static constexpr SizeType Dimension = 3;

        constexpr explicit Matrix3T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix3T(T diag) noexcept
            : rows({})
        {
            for (SizeType i = 0; i < 3; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix3T(const Vector3T<T>& row0,
                                    const Vector3T<T>& row1,
                                    const Vector3T<T>& row2)
        noexcept
            : rows({ row0,
                     row1,
                     row2 })
        {}

        constexpr explicit Matrix3T(T m00, T m01, T m02,
                                    T m10, T m11, T m12,
                                    T m20, T m21, T m22)
        noexcept
            : rows(Vector3T<T>(m00, m01, m02),
                   Vector3T<T>(m10, m11, m12),
                   Vector3T<T>(m20, m21, m22))
        {}

        constexpr explicit Matrix3T(const Matrix2T<T>& m) noexcept
            : rows(Vector3T<T>(m[0][0], m[0][1], 0),
                   Vector3T<T>(m[1][0], m[1][1], 0),
                   Vector3T<T>(      0,       0, 1))
        {}

        constexpr       Vector3T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector3T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max()); }

        static constexpr Matrix3T<T> Identity() noexcept { return Matrix3T<T>(Convert<T>(1)); }
    private:
        Array<Vector3T<T>, 3> rows;
    };

    template <ConceptStrongType T>
    class Matrix4T final
    {
    public:
        using ScalarType = T;
        static constexpr SizeType Dimension = 4;

        constexpr explicit Matrix4T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix4T(T diag) noexcept
            : rows({})
        {
            for (SizeType i = 0; i < 4; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix4T(const Vector4T<T>& row0,
                                    const Vector4T<T>& row1,
                                    const Vector4T<T>& row2,
                                    const Vector4T<T>& row3)
        noexcept
            : rows({ row0,
                     row1,
                     row2,
                     row3 })
        {}

        constexpr explicit Matrix4T(T m00, T m01, T m02, T m03,
                                    T m10, T m11, T m12, T m13,
                                    T m20, T m21, T m22, T m23,
                                    T m30, T m31, T m32, T m33)
        noexcept
            : rows(Vector4T<T>(m00, m01, m02, m03),
                   Vector4T<T>(m10, m11, m12, m13),
                   Vector4T<T>(m20, m21, m22, m23),
                   Vector4T<T>(m30, m31, m32, m33))
        {}

        constexpr explicit Matrix4T(const Matrix2T<T>& m) noexcept
            : rows(Vector4T<T>(m[0][0], m[0][1], 0, 0),
                   Vector4T<T>(m[1][0], m[1][1], 0, 0),
                   Vector4T<T>(      0,       0, 1, 0),
                   Vector4T<T>(      0,       0, 0, 1))
        {}

        constexpr explicit Matrix4T(const Matrix3T<T>& m) noexcept
            : rows(Vector4T<T>(m[0][0], m[0][1], m[0][2], 0),
                   Vector4T<T>(m[1][0], m[1][1], m[1][2], 0),
                   Vector4T<T>(m[2][0], m[2][1], m[2][2], 0),
                   Vector4T<T>(      0,       0,       0, 1))
        {}

        constexpr       Vector4T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector4T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min(), rows[3].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max(), rows[3].Max()); }

        static constexpr Matrix4T<T> Identity() noexcept { return Matrix4T<T>(Convert<T>(1)); }
    private:
        Array<Vector4T<T>, 4> rows;
    };
}

#endif //MATHLIB_IMPL_MATRIX_HPP
