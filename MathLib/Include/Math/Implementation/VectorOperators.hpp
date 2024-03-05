#ifndef MATHLIB_IMPLEMENTATION_VECTOR_OPERATORS_HPP
#define MATHLIB_IMPLEMENTATION_VECTOR_OPERATORS_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Vector-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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



    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += v[i];
        }
        return u;
    }

    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= v[i];
        }
        return u;
    }

    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= v[i];
        }
        return u;
    }

    template <Concept::BasicVector Vec>
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
    // Bitwise Vector-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::IntegerVector Vec>
    [[nodiscard]] constexpr
    Vec operator& (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] & v[i];
        }
        return result;
    }

    template <Concept::IntegerVector Vec>
    [[nodiscard]] constexpr
    Vec operator| (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] | v[i];
        }
        return result;
    }

    template <Concept::IntegerVector Vec>
    [[nodiscard]] constexpr
    Vec operator^ (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] ^ v[i];
        }
        return result;
    }

    template <Concept::IntegerVector Vec>
    [[nodiscard]] constexpr
    Vec operator~ (const Vec& u) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = ~u[i];
        }
        return result;
    }

    //////////////////////////////////////////////////////////////////////////
    // Vector-Scalar operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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

    template <Concept::BasicVector Vec>
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



    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += s;
        }
        return u;
    }

    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= s;
        }
        return u;
    }

    template <Concept::BasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= s;
        }
        return u;
    }

    template <Concept::BasicVector Vec>
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

#endif //MATHLIB_IMPLEMENTATION_VECTOR_OPERATORS_HPP
