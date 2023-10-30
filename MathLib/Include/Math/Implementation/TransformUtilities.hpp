#ifndef MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP
#define MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP

#include "../Common/Concepts.hpp"
#include "../Functions.hpp"
#include "Point.hpp"

namespace Math
{
    template <ConceptTransform2 Transform>
    [[nodiscard]] constexpr
    typename Transform::MatrixType ToMatrix(const Transform& t) noexcept
    {
        return typename Transform::MatrixType( t[0], t[1], Transform::BottomRow );
    }

    template <ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    typename Transform::MatrixType ToMatrix(const Transform& t) noexcept
    {
        return typename Transform::MatrixType( t[0], t[1], t[2], Transform::BottomRow );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> Translate(const Vector2T<Scalar>& v) noexcept
    {
        return Transform2T<Scalar>(
            1, 0, v.x,
            0, 1, v.y
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> Translate(const Vector3T<Scalar>& v) noexcept
    {
        return Transform3T<Scalar>(
            1, 0, 0, v.x,
            0, 1, 0, v.y,
            0, 0, 1, v.z
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform2T<Scalar> Scale(const Vector2T<Scalar>& v) noexcept
    {
        return Transform2T<Scalar>(
            v.x, 0, 0,
            0, v.y, 0
        );
    }

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> Scale(const Vector3T<Scalar>& v) noexcept
    {
        return Transform3T<Scalar>(
            v.x, 0, 0, 0,
            0, v.y, 0, 0,
            0, 0, v.z, 0
        );
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

    template <Orientation Hand = Orientation::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateX(Scalar angle) noexcept
    {
        if constexpr (Hand == Orientation::Right)
        {
            return Transform3T<Scalar>(
                1,          0,           0, 0,
                0, Cos(angle), -Sin(angle), 0,
                0, Sin(angle),  Cos(angle), 0
            );
        }
        else if constexpr (Hand == Orientation::Left)
        {
            return Transform3T<Scalar>(
                1,           0,          0, 0,
                0,  Cos(angle), Sin(angle), 0,
                0, -Sin(angle), Cos(angle), 0
            );
        }
    }

    template <Orientation Hand = Orientation::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateY(Scalar angle) noexcept
    {
        if constexpr (Hand == Orientation::Right)
        {
            return Transform3T<Scalar>(
                 Cos(angle), 0, Sin(angle), 0,
                          0, 1,          0, 0,
                -Sin(angle), 0, Cos(angle), 0
            );
        }
        else if constexpr (Hand == Orientation::Left)
        {
            return Transform3T<Scalar>(
                 Cos(angle), 0, -Sin(angle), 0,
                          0, 1,           0, 0,
                 Sin(angle), 0,  Cos(angle), 0
            );
        }
    }

    template <Orientation Hand = Orientation::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> RotateZ(Scalar angle) noexcept
    {
        if constexpr (Hand == Orientation::Right)
        {
            return Transform3T<Scalar>(
                Cos(angle), -Sin(angle), 0, 0,
                Sin(angle),  Cos(angle), 0, 0,
                         0,           0, 1, 0
            );
        }
        else if constexpr (Hand == Orientation::Left)
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

    template <ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> LookAt(const Point3T<Scalar>& pos, const Vector3T<Scalar>& dir, const Vector3T<Scalar>& up = {0, 1, 0}) noexcept
    {
        Vector3T<Scalar> w = -Normalize(dir);
        Vector3T<Scalar> u = Normalize(Cross(Normalize(up), w));
        Vector3T<Scalar> v = Normalize(Cross(w, u));
        return Transform3T<Scalar>(
            u.x, u.y, u.z, -pos.x,
            v.x, v.y, v.z, -pos.y,
            w.x, w.y, w.z, -pos.z
        );
    }

    template <Orientation Hand = Orientation::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    auto PerspectiveProjection(Scalar fov, Scalar aspectRatio, Scalar near, Scalar far) noexcept
    {
        static_assert(Hand == Orientation::Right || Hand == Orientation::Left, "Orientation must be either Right or Left.");
        using Vec = Vector4T<Scalar>;
        using TransformRight = Transform3T<Scalar, Vec(0, 0, -1, 0)>;
        using TransformLeft = Transform3T<Scalar, Vec(0, 0, 1, 0)>;

        ConditionalType<Hand == Orientation::Right, TransformRight, TransformLeft> result;
        Scalar tanFovOver2 = Tan(fov / Scalar(2));
        result[0][0] = Convert<Scalar>(1) / (aspectRatio * tanFovOver2);
        result[1][1] = Convert<Scalar>(1) / tanFovOver2;
        result[2][2] = far / (near - far);
        result[2][3] = -(far * near) / (far - near);
        return result;
    }

    template <Orientation Hand = Orientation::Right, ConceptScalar Scalar>
    [[nodiscard]] constexpr
    Transform3T<Scalar> OrthographicProjection(Scalar left, Scalar right, Scalar bottom, Scalar top, Scalar near, Scalar far) noexcept
    {
        static_assert(Hand == Orientation::Right || Hand == Orientation::Left, "Orientation must be either Right or Left.");

        Transform3T<Scalar> result;
        result[0][0] = Convert<Scalar>(2) / (right - left);
        result[1][1] = Convert<Scalar>(2) / (top - bottom);
        result[2][2] = Convert<Scalar>(1) / (far - near);
        result[0][3] = -(right + left) / (right - left);
        result[1][3] = -(top + bottom) / (top - bottom);
        result[2][3] = -near / (far - near);
        if constexpr (Hand == Orientation::Right)
        {
            result[2][2] = -result[2][2];
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
