#ifndef MATHLIB_IMPLEMENTATION_VECTOR_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_VECTOR_UTILITIES_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    template <Concept::Vector Vec>
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

    template <Concept::Vector Vec>
    [[nodiscard]] constexpr
    Vec Normalize(const Vec& u) noexcept
    {
        auto len = u.Length();
        return u / len;
    }

    template <Concept::Vector2 Vec>
    [[nodiscard]] constexpr
    Vec Perp(const Vec& u) noexcept
    {
        return Vec(-u.y, u.x);
    }

    template <Concept::Vector2 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType Area(const Vec& u, const Vec& v) noexcept
    {
        return u.x * v.y - u.y * v.x;
    }

    template <Concept::Vector2 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType TriangleArea(const Vec& u, const Vec& v) noexcept
    {
        return Area(u, v) / 2;
    }

    template <Orientation Hand = Orientation::Right, Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    Vec Cross(const Vec& u, const Vec& v) noexcept
    {
        Vec w;
        if constexpr (Hand == Orientation::Right)
        {
            w.x = u.y * v.z - u.z * v.y;
            w.y = u.z * v.x - u.x * v.z;
            w.z = u.x * v.y - u.y * v.x;
        }
        else if constexpr (Hand == Orientation::Left)
        {
            w.x = u.z * v.y - u.y * v.z;
            w.y = u.x * v.z - u.z * v.x;
            w.z = u.y * v.x - u.x * v.y;
        }
        return w;
    }

    template <Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType Area(const Vec& u, const Vec& v) noexcept
    {
        return Cross(u, v).Length();
    }

    template <Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType TriangleArea(const Vec& u, const Vec& v) noexcept
    {
        return Area(u, v) / 2;
    }

    template <Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType Volume(const Vec& u, const Vec& v, const Vec& w) noexcept
    {
        return Dot(u, Cross(v, w));
    }

    template <Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    typename Vec::ScalarType TetrahedronVolume(const Vec& u, const Vec& v, const Vec& w) noexcept
    {
        return Volume(u, v, w) / 6;
    }

    template <Concept::Vector Vec>
    [[nodiscard]] constexpr
    Vec Reflect(const Vec& u, const Vec& n) noexcept
    {
        Vec unitN = Normalize(n);
        return u - 2 * Dot(u, unitN) * unitN;
    }

    template <Concept::Vector3 Vec>
    [[nodiscard]] constexpr
    Vec Refract(const Vec& u, const Vec& n, typename Vec::ScalarType eta) noexcept
    {
        using Scalar = typename Vec::ScalarType;

        Scalar cosTheta = Dot(n, u);
        Scalar sinThetaSquared = 1 - Squared(cosTheta);
        Scalar sinPhiSquared = Squared(eta) * sinThetaSquared;
        Scalar cosPhiSquared = 1 - sinPhiSquared;
        if (cosPhiSquared < Scalar(0))
        {
            return Vec(0);
        }
        return eta * u - (eta * cosTheta + Sqrt(cosPhiSquared)) * n;
    }
}

#endif //MATHLIB_IMPLEMENTATION_VECTOR_UTILITIES_HPP
