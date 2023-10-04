#ifndef MATHLIB_IMPL_MATRIX3_HPP
#define MATHLIB_IMPL_MATRIX3_HPP

#include "Vector3.hpp"

#include <array>

namespace Math
{
    template <typename T>
    class Matrix3T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;
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
            : rows({{ {m00, m01, m02},
                      {m10, m11, m12},
                      {m20, m21, m22} }})
        {}

        constexpr       Vector3T<T>& operator[] (SizeType index)       { return rows[index]; }
        constexpr const Vector3T<T>& operator[] (SizeType index) const { return rows[index]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min(), rows[2].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max(), rows[2].Max()); }
    private:
        std::array<Vector3T<T>, 3> rows;
    };
}

#endif //MATHLIB_IMPL_MATRIX3_HPP
