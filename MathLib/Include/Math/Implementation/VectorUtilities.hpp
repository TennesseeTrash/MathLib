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

    template <Handedness Hand = Handedness::Right, ConceptVector3 Vec>
    [[nodiscard]] constexpr
    Vec Cross(const Vec& u, const Vec& v) noexcept
    {
        Vec w;
        if constexpr (Hand == Handedness::Right)
        {
            w.x = u.y * v.z - u.z * v.y;
            w.y = u.z * v.x - u.x * v.z;
            w.z = u.x * v.y - u.y * v.x;
        }
        else if constexpr (Hand == Handedness::Left)
        {
            w.x = u.z * v.y - u.y * v.z;
            w.y = u.x * v.z - u.z * v.x;
            w.z = u.y * v.x - u.x * v.y;
        }
        return w;
    }
}

#endif //MATHLIB_IMPL_VECTOR_UTILITIES_HPP
