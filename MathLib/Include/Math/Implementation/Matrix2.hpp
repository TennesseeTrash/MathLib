#ifndef MATHLIB_IMPL_MATRIX2_HPP
#define MATHLIB_IMPL_MATRIX2_HPP

namespace Math
{
    template <typename T>
    class Matrix2T final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector2T<T>;
        static constexpr size_t Dimension = 2;

        constexpr explicit Matrix2T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix2T(T diag) noexcept
            : rows({})
        {
            for (size_t i = 0; i < 2; ++i) { rows[i][i] = diag; }
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
            : rows({{ {m00, m01},
                      {m10, m11} }})
        {}

        constexpr       Vector2T<T>& operator[] (size_t index)       { return rows[index]; }
        constexpr const Vector2T<T>& operator[] (size_t index) const { return rows[index]; }
    private:
        std::array<Vector2T<T>, 2> rows;
    };
}

#endif //MATHLIB_IMPL_MATRIX2_HPP
