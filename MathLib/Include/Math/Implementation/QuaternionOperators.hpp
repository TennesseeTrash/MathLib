#ifndef MATHLIB_IMPLEMENTATION_QUATERNION_OPERATORS_HPP
#define MATHLIB_IMPLEMENTATION_QUATERNION_OPERATORS_HPP

#include "../Common/Concepts.hpp"
#include "VectorOperators.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Quaternion-Quaternion operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicQuaternion Quat>
    [[nodiscard]] constexpr
    Quat operator+ (const Quat& p, const Quat& q) noexcept
    {
        return Quat(p.Vector() + q.Vector(), p.Scalar() + q.Scalar());
    }

    template <ConceptBasicQuaternion Quat>
    [[nodiscard]] constexpr
    Quat operator- (const Quat& p, const Quat& q) noexcept
    {
        return Quat(p.Vector() - q.Vector(), p.Scalar() - q.Scalar());
    }

    template <ConceptBasicQuaternion Quat>
    [[nodiscard]] constexpr
    Quat operator* (const Quat& p, const Quat& q) noexcept
    {
        return Quat(
            p.Scalar() * q.Vector() + q.Scalar() * p.Vector() + Cross(p.Vector(), q.Vector()),
            p.Scalar() * q.Scalar() - Dot(p.Vector(), q.Vector())
        );
    }

    //////////////////////////////////////////////////////////////////////////
    // Quaternion-Scalar operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicQuaternion Quat>
    [[nodiscard]] constexpr
    Quat operator* (const Quat& q, typename Quat::ScalarType s) noexcept
    {
        return Quat(q.Vector() * s, q.Scalar() * s);
    }

    template <ConceptBasicQuaternion Quat>
    [[nodiscard]] constexpr
    Quat operator* (typename Quat::ScalarType s, const Quat& q) noexcept
    {
        return Quat(s * q.Vector(), s * q.Scalar());
    }
}

#endif //MATHLIB_IMPLEMENTATION_QUATERNION_OPERATORS_HPP
