#ifndef MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP
#define MATHLIB_IMPL_TRANSFORM_UTILITIES_HPP

#include "../Common/Concepts.hpp"
#include "../Functions.hpp"

// TODO(3011): I'm not very happy with the shear transforms. I'm not sure if
// is any reason to split them up into multiple different functions.

namespace Math
{
    template <ConceptTransform Transform>
    [[nodiscard]] constexpr
    Transform Translate(const typename Transform::VectorType& v) noexcept
    {
        Transform result(typename Transform::ScalarType(1));
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i][Transform::Dimension] = v[i];
        }
        return result;
    }

    template <ConceptTransform Transform>
    [[nodiscard]] constexpr
    Transform Scale(const typename Transform::VectorType& v) noexcept
    {
        Transform result(typename Transform::ScalarType(1));
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            result[i][i] = v[i];
        }
        return result;
    }

    template <ConceptTransform2 Transform>
    [[nodiscard]] constexpr
    Transform Rotate(typename Transform::ScalarType angle) noexcept
    {
        return Transform(
            Cos(angle), -Sin(angle), 0,
            Sin(angle),  Cos(angle), 0
        );
    }

    template <Handedness Hand = Handedness::Right, ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform RotateX(typename Transform::ScalarType angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform(
                1,          0,           0, 0,
                0, Cos(angle), -Sin(angle), 0,
                0, Sin(angle),  Cos(angle), 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform(
                1,           0,          0, 0,
                0,  Cos(angle), Sin(angle), 0,
                0, -Sin(angle), Cos(angle), 0
            );
        }
    }

    template <Handedness Hand = Handedness::Right, ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform RotateY(typename Transform::ScalarType angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform(
                 Cos(angle), 0, Sin(angle), 0,
                          0, 1,          0, 0,
                -Sin(angle), 0, Cos(angle), 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform(
                 Cos(angle), 0, -Sin(angle), 0,
                          0, 1,           0, 0,
                 Sin(angle), 0,  Cos(angle), 0
            );
        }
    }

    template <Handedness Hand = Handedness::Right, ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform RotateZ(typename Transform::ScalarType angle) noexcept
    {
        if constexpr (Hand == Handedness::Right)
        {
            return Transform(
                Cos(angle), -Sin(angle), 0, 0,
                Sin(angle),  Cos(angle), 0, 0,
                         0,           0, 1, 0
            );
        }
        else if constexpr (Hand == Handedness::Left)
        {
            return Transform(
                 Cos(angle), Sin(angle), 0, 0,
                -Sin(angle), Cos(angle), 0, 0,
                          0,          0, 1, 0
            );
        }
    }

    template <ConceptTransform2 Transform>
    [[nodiscard]] constexpr
    Transform ShearX(typename Transform::ScalarType s) noexcept
    {
        return Transform(
            1, s, 0,
            0, 1, 0
        );
    }

    template <ConceptTransform2 Transform>
    [[nodiscard]] constexpr
    Transform ShearY(typename Transform::ScalarType s) noexcept
    {
        return Transform(
            1, 0, 0,
            s, 1, 0
        );
    }

    template <ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform ShearX(typename Transform::ScalarType s, typename Transform::ScalarType t) noexcept
    {
        return Transform(
            1, s, t, 0,
            0, 1, 0, 0,
            0, 0, 1, 0
        );
    }

    template <ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform ShearY(typename Transform::ScalarType s, typename Transform::ScalarType t) noexcept
    {
        return Transform(
            1, 0, 0, 0,
            s, 1, t, 0,
            0, 0, 1, 0
        );
    }

    template <ConceptTransform3 Transform>
    [[nodiscard]] constexpr
    Transform ShearZ(typename Transform::ScalarType s, typename Transform::ScalarType t) noexcept
    {
        return Transform(
            1, 0, 0, 0,
            0, 1, 0, 0,
            s, t, 1, 0
        );
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
