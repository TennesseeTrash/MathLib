#ifndef MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP
#define MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP

#include "../Common/Concepts.hpp"
#include "../Functions.hpp"
#include "Point.hpp"

// TODO(3011): This implementation is still not final.
// Ideally, the overloads to enable TAD should not be necessary.

namespace Math
{
    template <ConceptTransform Transform, ConceptVector Vec>
        requires (Transform::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Transform Translate(const Vec& v) noexcept
    {
        using Scalar = typename Transform::ScalarType;

        Transform result(Convert<Scalar>(1));
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i][Transform::Dimension] = v[i];
        }
        return result;
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> Translate(const Vector2T<Scalar>& v) noexcept
    {
        return Translate<Transform2T<Scalar>, Vector2T<Scalar>>(v);
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> Translate(const Vector3T<Scalar>& v) noexcept
    {
        return Translate<Transform3T<Scalar>, Vector3T<Scalar>>(v);
    }

    template <ConceptTransform Transform, ConceptVector Vec>
        requires (Transform::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Transform Scale(const Vec& v) noexcept
    {
        using Scalar = typename Transform::ScalarType;

        Transform result(Convert<Scalar>(1));
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i][i] = v[i];
        }
        return result;
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> Scale(const Vector2T<Scalar>& v) noexcept
    {
        return Scale<Transform2T<Scalar>, Vector2T<Scalar>>(v);
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> Scale(const Vector3T<Scalar>& v) noexcept
    {
        return Scale<Transform3T<Scalar>, Vector3T<Scalar>>(v);
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> Rotate(Scalar angle) noexcept
    {
        return Transform2T<Scalar>(
            Cos(angle), -Sin(angle), 0,
            Sin(angle),  Cos(angle), 0
        );
    }

    template <Handedness Hand = Handedness::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateX(Scalar angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform3T<Scalar>(
                1,          0,           0, 0,
                0, Cos(angle), -Sin(angle), 0,
                0, Sin(angle),  Cos(angle), 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform3T<Scalar>(
                1,           0,          0, 0,
                0,  Cos(angle), Sin(angle), 0,
                0, -Sin(angle), Cos(angle), 0
            );
        }
    }

    template <Handedness Hand = Handedness::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateY(Scalar angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform3T<Scalar>(
                 Cos(angle), 0, Sin(angle), 0,
                          0, 1,          0, 0,
                -Sin(angle), 0, Cos(angle), 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform3T<Scalar>(
                 Cos(angle), 0, -Sin(angle), 0,
                          0, 1,           0, 0,
                 Sin(angle), 0,  Cos(angle), 0
            );
        }
    }

    template <Handedness Hand = Handedness::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateZ(Scalar angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform3T<Scalar>(
                Cos(angle), -Sin(angle), 0, 0,
                Sin(angle),  Cos(angle), 0, 0,
                         0,           0, 1, 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform3T<Scalar>(
                 Cos(angle), Sin(angle), 0, 0,
                -Sin(angle), Cos(angle), 0, 0,
                          0,          0, 1, 0
            );
        }
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> ShearX(Scalar s) noexcept
    {
        return Transform2T<Scalar>(
            1, s, 0,
            0, 1, 0
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> ShearY(Scalar s) noexcept
    {
        return Transform2T<Scalar>(
            1, 0, 0,
            s, 1, 0
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> ShearX(Scalar s, Scalar t) noexcept
    {
        return Transform3T<Scalar>(
            1, s, t, 0,
            0, 1, 0, 0,
            0, 0, 1, 0
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> ShearY(Scalar s, Scalar t) noexcept
    {
        return Transform3T<Scalar>(
            1, 0, 0, 0,
            s, 1, t, 0,
            0, 0, 1, 0
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> ShearZ(Scalar s, Scalar t) noexcept
    {
        return Transform3T<Scalar>(
            1, 0, 0, 0,
            0, 1, 0, 0,
            s, t, 1, 0
        );
    }

    template <ConceptTransform3 Transform, ConceptPoint3 Pnt, ConceptVector3 Vec>
    [[nodiscard]] constexpr
    Transform LookAt(const Pnt& pos, const Vec& dir, const Vec& up = {0, 1, 0}) noexcept
    {
        Vec w = -Normalize(dir);
        Vec u = Normalize(Cross(Normalize(up), w));
        Vec v = Normalize(Cross(w, u));
        return Transform(
            u.x, u.y, u.z, -pos.x,
            v.x, v.y, v.z, -pos.y,
            w.x, w.y, w.z, -pos.z
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> LookAt(const Point3T<Scalar>& pos, const Vector3T<Scalar>& dir, const Vector3T<Scalar>& up = {0, 1, 0}) noexcept
    {
        return LookAt<Transform3T<Scalar>, Point3T<Scalar>, Vector3T<Scalar>>(pos, dir, up);
    }

    template <Handedness Hand = Handedness::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    auto PerspectiveProjection(Scalar fov, Scalar aspectRatio, Scalar near, Scalar far) noexcept
    {
        Scalar tanFovOver2 = Tan(fov / Scalar(2));
        if constexpr (Hand == Handedness::Right)
        {
            Transform3T<Scalar, Vector3T<Scalar>(0, 0, -1, 0)> result;
            result[0][0] = Convert<Scalar>(1) / (aspectRatio * tanFovOver2);
            result[1][1] = Convert<Scalar>(1) / tanFovOver2;
            result[2][2] = far / (near - far);
            result[2][3] = -(far * near) / (far - near);
            return result;
        }
        else if constexpr (Hand == Handedness::Left)
        {
            Transform3T<Scalar, Vector3T<Scalar>(0, 0, 1, 0)> result;
            result[0][0] = Convert<Scalar>(1) / (aspectRatio * tanFovOver2);
            result[1][1] = Convert<Scalar>(1) / tanFovOver2;
            result[2][2] = far / (far - near);
            result[2][3] = -(far * near) / (far - near);
            return result;
        }
    }

    template <Handedness Hand = Handedness::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> OrthographicProjection(Scalar left, Scalar right, Scalar bottom, Scalar top, Scalar near, Scalar far) noexcept
    {
        Transform3T<Scalar> result;
        if constexpr (Hand == Handedness::Right)
        {
            result[0][0] = Convert<Scalar>(2) / (right - left);
            result[1][1] = Convert<Scalar>(2) / (top - bottom);
            result[2][2] = Convert<Scalar>(1) / (far - near);
            result[0][3] = -(right + left) / (right - left);
            result[1][3] = -(top + bottom) / (top - bottom);
            result[2][3] = -near / (far - near);
        }
        else if constexpr (Hand == Handedness::Left)
        {
            result[0][0] = Convert<Scalar>(2) / (right - left);
            result[1][1] = Convert<Scalar>(2) / (top - bottom);
            result[2][2] = -Convert<Scalar>(1) / (far - near);
            result[0][3] = -(right + left) / (right - left);
            result[1][3] = -(top + bottom) / (top - bottom);
            result[2][3] = -near / (far - near);
        }
        return result;
    }

    template <ConceptBasicTransform Transform>
    [[nodiscard]] constexpr
    bool HasNaN(const Transform& t)
    {
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            if (HasNaN(t[i]))
            {
                return true;
            }
        }

        return false;
    }
}

#endif //MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP
