#ifndef MATHLIB_IMPL_VECTOR_UTILITIES_HPP
#define MATHLIB_IMPL_VECTOR_UTILITIES_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    template <ConceptVector Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType Dot(const Vec& u, const Vec& v) noexcept
    {
        typename Vec::ScalarType dot{};
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            dot += (u[i] * v[i]);
        }
        return dot;
    }

    template <ConceptVector Vec>
    [[nodiscard]] constexpr
    Vec Normalize(const Vec& u) noexcept
    {
        auto len = u.Length();
        return u / len;
    }

    template <ConceptVector2 Vec>
    [[nodiscard]] constexpr
    Vec Perp(const Vec& u) noexcept
    {
        return Vec(-u.y, u.x);
    }

    template <ConceptVector3 Vec>
    [[nodiscard]] constexpr
    Vec Cross(const Vec& u, const Vec& v) noexcept
    {
        Vec w;
        w.x = u.y * v.z - u.z * v.y;
        w.y = u.z * v.x - u.x * v.z;
        w.z = u.x * v.y - u.y * v.x;
        return w;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    bool HasNaN(const Vec& u) noexcept
    {
        for (SizeType i = 0; i < Vec::Dimension; ++i)
        {
            if (u[i] != u[i])
            {
                return true;
            }
        }

        return false;
    }
}

#endif //MATHLIB_IMPL_VECTOR_UTILITIES_HPP
