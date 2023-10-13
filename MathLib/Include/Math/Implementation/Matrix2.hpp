#ifndef MATHLIB_IMPL_MATRIX2_HPP
#define MATHLIB_IMPL_MATRIX2_HPP

#include "Vector2.hpp"

#include "../Common/Array.hpp"

namespace Math
{
    template <typename T>
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
            for (SizeType i = 0; i < 2; ++i) { rows[ToUnderlying(i)][ToUnderlying(i)] = diag; }
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

        constexpr       Vector2T<T>& operator[] (SizeType index)       { return rows[ToUnderlying(index)]; }
        constexpr const Vector2T<T>& operator[] (SizeType index) const { return rows[ToUnderlying(index)]; }

        constexpr T Min() const { return ::Math::Min(rows[0].Min(), rows[1].Min()); }
        constexpr T Max() const { return ::Math::Max(rows[0].Max(), rows[1].Max()); }
    private:
        Array<Vector2T<T>, 2> rows;
    };
}

#endif //MATHLIB_IMPL_MATRIX2_HPP
