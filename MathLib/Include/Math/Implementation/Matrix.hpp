#ifndef MATHLIB_IMPLEMENTATION_MATRIX_HPP
#define MATHLIB_IMPLEMENTATION_MATRIX_HPP

#include "Base/Concepts.hpp"
#include "Base/Array.hpp"
#include "Vector.hpp"

namespace Math
{
    template <Concept::StrongType T>
    class Matrix2T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector2T<T>;
        static constexpr SizeType Dimension = 2;

        constexpr explicit Matrix2T() noexcept
            : rows()
        {}

        constexpr explicit Matrix2T(T diag) noexcept
            : rows()
        {
            for (SizeType i = 0; i < 2; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix2T(const VectorType& row0,
                                    const VectorType& row1)
        noexcept
            : rows({ row0,
                     row1 })
        {}

        constexpr explicit Matrix2T(T m00, T m01,
                                    T m10, T m11)
        noexcept
            : rows(VectorType(m00, m01),
                   VectorType(m10, m11))
        {}

        constexpr       VectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const VectorType& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return Math::Min(rows[0].Min(), rows[1].Min()); }
        constexpr T Max() const { return Math::Max(rows[0].Max(), rows[1].Max()); }

        static constexpr Matrix2T<T> Identity() noexcept { return Matrix2T<T>(Cast<T>(1)); }
    private:
        Array<VectorType, 2> rows;
    };

    template <Concept::StrongType T>
    class Matrix3T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        static constexpr SizeType Dimension = 3;

        constexpr explicit Matrix3T() noexcept
            : rows{}
        {}

        constexpr explicit Matrix3T(T diag) noexcept
            : rows{}
        {
            for (SizeType i = 0; i < 3; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix3T(const VectorType& row0,
                                    const VectorType& row1,
                                    const VectorType& row2)
        noexcept
            : rows({ row0,
                     row1,
                     row2 })
        {}

        constexpr explicit Matrix3T(T m00, T m01, T m02,
                                    T m10, T m11, T m12,
                                    T m20, T m21, T m22)
        noexcept
            : rows(VectorType(m00, m01, m02),
                   VectorType(m10, m11, m12),
                   VectorType(m20, m21, m22))
        {}

        constexpr explicit Matrix3T(const Matrix2T<T>& m) noexcept
            : rows(VectorType(m[0][0], m[0][1], 0),
                   VectorType(m[1][0], m[1][1], 0),
                   VectorType(      0,       0, 1))
        {}

        constexpr       VectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const VectorType& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min()); }
        constexpr T Max() const { return Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max()); }

        static constexpr Matrix3T<T> Identity() noexcept { return Matrix3T<T>(Cast<T>(1)); }
    private:
        Array<VectorType, 3> rows;
    };

    template <Concept::StrongType T>
    class Matrix4T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector4T<T>;
        static constexpr SizeType Dimension = 4;

        constexpr explicit Matrix4T() noexcept
            : rows{}
        {}

        constexpr explicit Matrix4T(T diag) noexcept
            : rows{}
        {
            for (SizeType i = 0; i < 4; ++i) { rows[i][i] = diag; }
        }

        constexpr explicit Matrix4T(const VectorType& row0,
                                    const VectorType& row1,
                                    const VectorType& row2,
                                    const VectorType& row3)
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
            : rows(VectorType(m00, m01, m02, m03),
                   VectorType(m10, m11, m12, m13),
                   VectorType(m20, m21, m22, m23),
                   VectorType(m30, m31, m32, m33))
        {}

        constexpr explicit Matrix4T(const Matrix2T<T>& m) noexcept
            : rows(VectorType(m[0][0], m[0][1], 0, 0),
                   VectorType(m[1][0], m[1][1], 0, 0),
                   VectorType(      0,       0, 1, 0),
                   VectorType(      0,       0, 0, 1))
        {}

        constexpr explicit Matrix4T(const Matrix3T<T>& m) noexcept
            : rows(VectorType(m[0][0], m[0][1], m[0][2], 0),
                   VectorType(m[1][0], m[1][1], m[1][2], 0),
                   VectorType(m[2][0], m[2][1], m[2][2], 0),
                   VectorType(      0,       0,       0, 1))
        {}

        constexpr       VectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const VectorType& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min(), rows[3].Min()); }
        constexpr T Max() const { return Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max(), rows[3].Max()); }

        static constexpr Matrix4T<T> Identity() noexcept { return Matrix4T<T>(Cast<T>(1)); }
    private:
        Array<VectorType, 4> rows;
    };

    template <SizeType N, Concept::StrongType T>
    class MatrixNT final
    {
    public:
        using ScalarType = T;
        using VectorType = VectorNT<N, T>;
        static constexpr SizeType Dimension = N;

        constexpr explicit MatrixNT() noexcept
            : rows{}
        {}

        constexpr explicit MatrixNT(T diag) noexcept
            : rows{}
        {
            rows.ForEach([diag](SizeType i, ScalarType& row){ row[i] = diag; });
        }

        constexpr       VectorType& operator[] (SizeType index)       { return rows[index]; }
        constexpr const VectorType& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { T min = T::Max(); rows.ForEach([&min](T& row){ if (row.Min() < min) { min = row.Min(); } }); return min; }
        constexpr T Max() const { T max = T::Min(); rows.ForEach([&max](T& row){ if (row.Max() > max) { max = row.Max(); } }); return max; }

        static constexpr MatrixNT<N, T> Identity() noexcept { return MatrixNT<N, T>(Cast<T>(1)); }
    private:
        Array<VectorType, Dimension> rows;
    };
}

#endif //MATHLIB_IMPLEMENTATION_MATRIX_HPP
