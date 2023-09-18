#ifndef MATHLIB_IMPL_POINT_OPERATORS_HPP
#define MATHLIB_IMPL_POINT_OPERATORS_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Point-Point operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    typename Pnt::VectorType operator- (const Pnt& p1, const Pnt& p2) noexcept
    {
        typename Pnt::VectorType u;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            u[i] = p1[i] - p2[i];
        }
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Point-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator+ (const Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] + v[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator+ (const typename Pnt::VectorType& v, const Pnt& p) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = v[i] + p[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator- (const Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] - v[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator- (const typename Pnt::VectorType& v, const Pnt& p) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = v[i] - p[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] * v[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const typename Pnt::VectorType& v, const Pnt& p) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = v[i] * p[i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator/ (const Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] / v[i];
        }
        return result;
    }



    template <ConceptBasicPoint Pnt>
    [[maybe_unused]] constexpr
    Pnt& operator+= (Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] += v[i];
        }
        return p;
    }

    template <ConceptBasicPoint Pnt>
    [[maybe_unused]] constexpr
    Pnt& operator-= (Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] -= v[i];
        }
        return p;
    }

    template <ConceptBasicPoint Pnt>
    [[maybe_unused]] constexpr
    Pnt& operator*= (Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] *= v[i];
        }
        return p;
    }

    template <ConceptBasicPoint Pnt>
    [[maybe_unused]] constexpr
    Pnt& operator/= (Pnt& p, const typename Pnt::VectorType& v) noexcept
    {
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] /= v[i];
        }
        return p;
    }

    //////////////////////////////////////////////////////////////////////////
    // Point-Matrix operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const typename Pnt::MatrixType& m) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            for (size_t j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const typename Pnt::MatrixType& m, const Pnt& p) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            for (size_t j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const Pnt& p, const typename Pnt::ProjectiveMatrixType& m) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            for (size_t j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += p[j] * m[j][i];
            }
            result[i] += m[Pnt::Dimension][i];
        }
        return result;
    }

    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    Pnt operator* (const typename Pnt::ProjectiveMatrixType& m, const Pnt& p) noexcept
    {
        Pnt result;
        for (size_t i = 0; i < Pnt::Dimension; ++i)
        {
            for (size_t j = 0; j < Pnt::Dimension; ++j)
            {
                result[i] += m[i][j] * p[j];
            }
            result[i] += m[i][Pnt::Dimension];
        }
        return result;
    }
}

#endif //MATHLIB_IMPL_POINT_OPERATORS_HPP
