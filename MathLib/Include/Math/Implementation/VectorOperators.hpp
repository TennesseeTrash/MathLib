#ifndef MATHLIB_IMPL_VECTOR_OPERATORS_HPP
#define MATHLIB_IMPL_VECTOR_OPERATORS_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Vector-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] + v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] - v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] * v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator/ (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] / v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = - u[i];
        }
        return result;
    }



    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator/= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] /= v[i];
        }
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Vector-Scalar operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] + s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s + u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] - s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s - u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] * s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s * u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator/ (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] / s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator/ (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s / u[i];
        }
        return result;
    }



    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator/= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] /= s;
        }
        return u;
    }
}

#endif //MATHLIB_IMPL_VECTOR_OPERATORS_HPP
