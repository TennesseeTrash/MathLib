#ifndef MATHLIB_IMPLEMENTATION_QUATERNION_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_QUATERNION_UTILITIES_HPP

#include "../Common/Concepts.hpp"
#include "VectorUtilities.hpp"

namespace Math
{
    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    typename Quat::ScalarType Dot(const Quat& p, const Quat& q) noexcept
    {
        return Dot(p.Vector(), q.Vector()) + p.Scalar() * q.Scalar();
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    Quat Conjugate(const Quat& q) noexcept
    {
        return Quat(-q.Vector(), q.Scalar());
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    Quat Normalize(const Quat& q) noexcept
    {
        auto norm = q.Norm();
        return Quat(q.Vector() / norm, q.Scalar() / norm);
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    Quat Inverse(const Quat& q) noexcept
    {
        auto normSqr = q.NormSqr();
        return Quat(-q.Vector() / normSqr, q.Scalar() / normSqr);
    }

    template <ConceptQuaternion Quat, ConceptVector3 Vec>
    [[nodiscard]] constexpr
    Vec Transform(const Quat& q, const Vec& v) noexcept
    {
        return (q * Quat(v, 0) * Inverse(q)).Vector();
    }

    template <ConceptQuaternion Quat, ConceptPoint3 Pnt>
    [[nodiscard]] constexpr
    Pnt Transform(const Quat& q, const Pnt& p) noexcept
    {
        return Pnt((q * Quat(Vec(p), 0) * Inverse(q)).Vector());
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    Quat Lerp(typename Quat::ScalarType val, const Quat& p, const Quat& q) noexcept
    {
        val = Clamp(val);
        if (Dot(p, q) >= typename Quat::ScalarType(0))
        {
            return Normalize(p * (1 - val) + q * (val));
        }
        else
        {
            return Normalize(p * (1 - val) - q * (val));
        }
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    Quat Slerp(typename Quat::ScalarType val, const Quat& p, const Quat& q) noexcept
    {
        using Scalar = typename Quat::ScalarType;
        val = Clamp(val);
        Scalar cosAngle = Dot(p, q);
        Scalar sinAngle = Sqrt(1 - Squared(cosAngle));
        Scalar angle = Acos(cosAngle);
        return (p * Sin((1 - val) * angle) + q * Sin(val * angle)) * (1 / sinAngle);
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    typename Quat::MatrixType ToMatrix(const Quat& q) noexcept
    {
        using Scalar = typename Quat::ScalarType;
        Quat qNorm = Normalize(q);
        Scalar x2 = Squared(qNorm.Vector().x);
        Scalar y2 = Squared(qNorm.Vector().y);
        Scalar z2 = Squared(qNorm.Vector().z);
        Scalar xy = qNorm.Vector().x * qNorm.Vector().y;
        Scalar xz = qNorm.Vector().x * qNorm.Vector().z;
        Scalar yz = qNorm.Vector().y * qNorm.Vector().z;
        Scalar wx = qNorm.Scalar() * qNorm.Vector().x;
        Scalar wy = qNorm.Scalar() * qNorm.Vector().y;
        Scalar wz = qNorm.Scalar() * qNorm.Vector().z;

        return typename Quat::MatrixType(
            1 - 2 * (y2 + z2),     2 * (xy - wz),     2 * (xz + wy),
                2 * (xy + wz), 1 - 2 * (x2 + z2),     2 * (yz - wx),
                2 * (xz - wy),     2 * (yz + wx), 1 - 2 * (x2 + y2)
        );
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    typename Quat::TransformType ToTransform(const Quat& q) noexcept
    {
        return typename Quat::TransformType(ToMatrix(q), {});
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    QuaternionT<Scalar> FromAxisAngle(const Vector3T<Scalar>& axis, Scalar angle) noexcept
    {
        Scalar halfAngle = angle / 2;
        return QuaternionT<Scalar>(
            Normalize(axis) * Sin(halfAngle),
            Cos(halfAngle)
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    QuaternionT<Scalar> FromYawPitchRoll(Scalar yaw, Scalar pitch, Scalar roll) noexcept
    {
        Scalar cy = Cos(yaw / 2);
        Scalar cp = Cos(pitch / 2);
        Scalar cr = Cos(roll / 2);
        Scalar sy = Sin(yaw / 2);
        Scalar sp = Sin(pitch / 2);
        Scalar sr = Sin(roll / 2);

        return QuaternionT<Scalar>(
            {cy * cp * sr - sy * sp * cr,
             cy * sp * cr + sy * cp * sr,
             sy * cp * cr - cy * sp * sr},
             cy * cp * cr + sy * sp * sr);
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    bool Equal(const Quat& p, const Quat& q) noexcept
    {
        return Equal(p.Vector(), q.Vector()) && Equal(p.Scalar(), q.Scalar());
    }

    template <ConceptQuaternion Quat>
    [[nodiscard]] constexpr
    bool HasNaN(const Quat& q) noexcept
    {
        return HasNaN(q.Vector()) || HasNaN(q.Scalar());
    }
}

#endif //MATHLIB_IMPLEMENTATION_QUATERNION_UTILITIES_HPP
