#ifndef MATHLIB_IMPLEMENTATION_POINT_OPERATORS_HPP
#define MATHLIB_IMPLEMENTATION_POINT_OPERATORS_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Point-Point operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicPoint Pnt>
    [[nodiscard]] constexpr
    typename Pnt::VectorType operator- (const Pnt& p1, const Pnt& p2) noexcept
    {
        typename Pnt::VectorType u;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            u[i] = p1[i] - p2[i];
        }
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Point-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Pnt operator+ (const Pnt& p, const Vec& v) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] + v[i];
        }
        return result;
    }

    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Pnt operator+ (const Vec& v, const Pnt& p) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = v[i] + p[i];
        }
        return result;
    }

    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Pnt operator- (const Pnt& p, const Vec& v) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = p[i] - v[i];
        }
        return result;
    }

    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Pnt operator- (const Vec& v, const Pnt& p) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            result[i] = v[i] - p[i];
        }
        return result;
    }



    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[maybe_unused]] constexpr
    Pnt& operator+= (Pnt& p, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] += v[i];
        }
        return p;
    }

    template <Concept::BasicPoint Pnt, Concept::BasicVector Vec>
        requires (Pnt::Dimension == Vec::Dimension)
    [[maybe_unused]] constexpr
    Pnt& operator-= (Pnt& p, const Vec& v) noexcept
    {
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            p[i] -= v[i];
        }
        return p;
    }
}

#endif //MATHLIB_IMPLEMENTATION_POINT_OPERATORS_HPP
