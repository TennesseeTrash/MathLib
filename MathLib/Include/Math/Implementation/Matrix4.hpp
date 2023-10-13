#ifndef MATHLIB_IMPL_MATRIX4_HPP
#define MATHLIB_IMPL_MATRIX4_HPP

#include "Vector4.hpp"

#include "../Common/Array.hpp"

namespace Math
{
    template <typename T>
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
            for (SizeType i = 0; i < 4; ++i) { rows[ToUnderlying(i)][ToUnderlying(i)] = diag; }
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

        constexpr       Vector4T<T>& operator[] (SizeType index)       { return rows[ToUnderlying(index)]; }
        constexpr const Vector4T<T>& operator[] (SizeType index) const { return rows[ToUnderlying(index)]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min(), rows[3].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max(), rows[3].Max()); }
    private:
        Array<Vector4T<T>, 4> rows;
    };
}

#endif //MATHLIB_IMPL_MATRIX4_HPP
