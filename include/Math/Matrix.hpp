#ifndef _MATH_MATRIX_HPP
#define _MATH_MATRIX_HPP

#include "Vector.hpp"
#include <array>
#include <limits>

namespace cc
{
    //////////////////////////////////////////////////////////////////////////
    // Assumptions for correct behavior
    //////////////////////////////////////////////////////////////////////////

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    //////////////////////////////////////////////////////////////////////////
    // Basic Definitions
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    class Matrix2T
    {
    public:
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
            : rows({ {m00, m01},
                     {m10, m11} })
        {}

        constexpr       Vector2T<T>& operator[] (int32_t index)       { return rows[index]; }
        constexpr const Vector2T<T>& operator[] (int32_t index) const { return rows[index]; }
    private:
        std::array<Vector2T<T>, 2> rows;
    };

    template <typename T>
    class Matrix3T
    {
    public:
        constexpr explicit Matrix3T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix3T(T diag) noexcept
            : rows({})
        {
            for (size_t i = 0; i < 3; ++i) { rows[i][i] = diag; }
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
            : rows({ {m00, m01, m02},
                     {m10, m11, m12},
                     {m20, m21, m22} })
        {}

        constexpr       Vector3T<T>& operator[] (int32_t index)       { return rows[index]; }
        constexpr const Vector3T<T>& operator[] (int32_t index) const { return rows[index]; }
    private:
        std::array<Vector3T<T>, 3> rows;
    };

    template <typename T>
    class Matrix4T
    {
    public:
        constexpr explicit Matrix4T() noexcept
            : rows({})
        {}

        constexpr explicit Matrix4T(T diag) noexcept
            : rows({})
        {
            for (size_t i = 0; i < 4; ++i) { rows[i][i] = diag; }
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
            : rows({ {m00, m01, m02, m03},
                     {m10, m11, m12, m13},
                     {m20, m21, m22, m23},
                     {m30, m31, m32, m33} })
        {}

        constexpr       Vector4T<T>& operator[] (int32_t index)       { return rows[index]; }
        constexpr const Vector4T<T>& operator[] (int32_t index) const { return rows[index]; }
    private:
        std::array<Vector4T<T>, 4> rows;
    };

    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Matrix2f = Matrix2T<float>;
    using Matrix3f = Matrix3T<float>;
    using Matrix4f = Matrix4T<float>;

    using Matrix2d = Matrix2T<double>;
    using Matrix3d = Matrix3T<double>;
    using Matrix4d = Matrix4T<double>;

    //////////////////////////////////////////////////////////////////////////
    // Operators
    //////////////////////////////////////////////////////////////////////////

    // Basic matrix arithmetic

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> operator+ (const Matrix2T<T>& a, const Matrix2T<T>& b) noexcept
    {
        constexpr int32_t dim = 2;
        Matrix2T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> operator+ (const Matrix3T<T>& a, const Matrix3T<T>& b) noexcept
    {
        constexpr int32_t dim = 3;
        Matrix3T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> operator+ (const Matrix4T<T>& a, const Matrix4T<T>& b) noexcept
    {
        constexpr int32_t dim = 4;
        Matrix4T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> operator- (const Matrix2T<T>& a, const Matrix2T<T>& b) noexcept
    {
        constexpr int32_t dim = 2;
        Matrix2T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> operator- (const Matrix3T<T>& a, const Matrix3T<T>& b) noexcept
    {
        constexpr int32_t dim = 3;
        Matrix3T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> operator- (const Matrix4T<T>& a, const Matrix4T<T>& b) noexcept
    {
        constexpr int32_t dim = 4;
        Matrix4T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> operator* (const Matrix2T<T>& a, const Matrix2T<T>& b) noexcept
    {
        constexpr int32_t dim = 2;
        Matrix2T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                for (int32_t k = 0; k < dim; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> operator* (const Matrix3T<T>& a, const Matrix3T<T>& b) noexcept
    {
        constexpr int32_t dim = 3;
        Matrix3T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                for (int32_t k = 0; k < dim; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> operator* (const Matrix4T<T>& a, const Matrix4T<T>& b) noexcept
    {
        constexpr int32_t dim = 4;
        Matrix4T<T> c;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++i)
            {
                for (int32_t k = 0; k < dim; ++k)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }


    // Matrix-scalar multiplication

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> operator* (const Matrix2T<T>& m, T s) noexcept
    {
        constexpr int32_t dim = 2;
        Matrix2T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> operator* (const Matrix3T<T>& m, T s) noexcept
    {
        constexpr int32_t dim = 3;
        Matrix3T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> operator* (const Matrix4T<T>& m, T s) noexcept
    {
        constexpr int32_t dim = 4;
        Matrix4T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> operator* (T s, const Matrix2T<T>& m) noexcept
    {
        constexpr int32_t dim = 2;
        Matrix2T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> operator* (T s, const Matrix3T<T>& m) noexcept
    {
        constexpr int32_t dim = 3;
        Matrix3T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> operator* (T s, const Matrix4T<T>& m) noexcept
    {
        constexpr int32_t dim = 4;
        Matrix4T<T> scaled = m;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                scaled[i][j] *= s;
            }
        }
        return scaled;
    }

    // Matrix-vector multiplication

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator* (const Matrix2T<T>& m, Vector2T<T>& u) noexcept
    {
        constexpr int32_t dim = 2;
        Vector2T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            mult[i] = Dot(m[i], u);
        }
        return mult;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator* (const Matrix3T<T>& m, Vector3T<T>& u) noexcept
    {
        constexpr int32_t dim = 3;
        Vector3T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            mult[i] = Dot(m[i], u);
        }
        return mult;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator* (const Matrix4T<T>& m, Vector4T<T>& u) noexcept
    {
        constexpr int32_t dim = 4;
        Vector4T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            mult[i] = Dot(m[i], u);
        }
        return mult;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector2T<T> operator* (Vector2T<T>& u, const Matrix2T<T>& m) noexcept
    {
        constexpr int32_t dim = 2;
        Vector2T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                mult[i] += u[j] * m[j][i];
            }
        }
        return mult;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector3T<T> operator* (Vector3T<T>& u, const Matrix3T<T>& m) noexcept
    {
        constexpr int32_t dim = 3;
        Vector3T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                mult[i] += u[j] * m[j][i];
            }
        }
        return mult;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Vector4T<T> operator* (Vector4T<T>& u, const Matrix4T<T>& m) noexcept
    {
        constexpr int32_t dim = 4;
        Vector4T<T> mult;
        for (int32_t i = 0; i < dim; ++i)
        {
            for (int32_t j = 0; j < dim; ++j)
            {
                mult[i] += u[j] * m[j][i];
            }
        }
        return mult;
    }

    //////////////////////////////////////////////////////////////////////////
    // Utilities
    //////////////////////////////////////////////////////////////////////////

    // Transpose

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> Transpose(const Matrix2T<T>& m) noexcept
    {
        Matrix2T<T> result = m;
        std::swap(result[1][0], result[0][1]);
        return result;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> Transpose(const Matrix3T<T>& m) noexcept
    {
        Matrix3T<T> result = m;
        std::swap(result[1][0], result[0][1]);
		std::swap(result[2][0], result[0][2]);
		std::swap(result[2][1], result[1][2]);
		return result;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> Transpose(const Matrix4T<T>& m) noexcept
    {
        Matrix4T<T> result = m;
        std::swap(result[1][0], result[0][1]);
		std::swap(result[2][0], result[0][2]);
		std::swap(result[2][1], result[1][2]);
		std::swap(result[3][0], result[0][3]);
		std::swap(result[3][1], result[1][3]);
		std::swap(result[3][2], result[2][3]);
        return result;
    }

    // Determinants

    template <typename T>
    [[nodiscard]] inline constexpr
    T Determinant(const Matrix2T<T>& m) noexcept
    {
        return (m[0][0] * m[1][1])
             - (m[0][1] * m[1][0]);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Determinant(const Matrix3T<T>& m) noexcept
    {
        return (m[0][0] * m[1][1] * m[2][2])
			 + (m[0][1] * m[1][2] * m[2][0])
			 + (m[0][2] * m[1][0] * m[2][1])
			 - (m[0][2] * m[1][1] * m[2][0])
			 - (m[0][1] * m[1][0] * m[2][2])
			 - (m[0][0] * m[1][2] * m[2][1]);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Determinant(const Matrix4T<T>& m) noexcept
    {
        return (m[0][0] * m[1][1] * m[2][2] * m[3][3])
			 + (m[0][0] * m[1][2] * m[2][3] * m[3][2])
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
			 - (m[0][2] * m[2][3] * m[2][1] * m[3][0])
			 - (m[0][3] * m[1][1] * m[2][2] * m[3][0])
			 + (m[0][3] * m[1][2] * m[2][1] * m[3][0])
			 + (m[0][2] * m[1][1] * m[2][3] * m[3][0])
			 + (m[0][1] * m[1][3] * m[2][2] * m[3][0]);
    }

    // Matrix inverse

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix2T<T> Invert(const Matrix2T<T>& m) noexcept
    {

    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix3T<T> Invert(const Matrix3T<T>& m) noexcept
    {

    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> Invert(const Matrix4T<T>& m) noexcept
    {

    }
}

#endif //_MATH_MATRIX_HPP
