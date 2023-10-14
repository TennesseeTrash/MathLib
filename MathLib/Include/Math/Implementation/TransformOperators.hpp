#ifndef MATHLIB_IMPL_TRANSFORM_OPERATORS_HPP
#define MATHLIB_IMPL_TRANSFORM_OPERATORS_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Transform-Transform operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicTransform Transform>
    [[nodiscard]] constexpr
    Transform operator* (const Transform& t1, const Transform& t2) noexcept
    {
        Transform result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension + 1; ++j)
            {
                for (SizeType k = 0; k < Transform::Dimension; ++k)
                {
                    result[i][j] += t1[i][k] * t2[k][j];
                }

                if constexpr (j == Transform::Dimension)
                {
                    result[i][j] += t1[i][j];
                }
            }
        }
        return result;
    }

    template <ConceptBasicTransform Transform>
    [[nodiscard]] constexpr
    Transform& operator*= (Transform& t1, const Transform& t2) noexcept
    {
        t1 = t1 * t2;
        return t1;
    }

    //////////////////////////////////////////////////////////////////////////
    // Transform-Vector operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicTransform Transform, ConceptBasicVector Vec>
        requires (Transform::Dimension == Vec::Dimension)
    [[nodiscard]] constexpr
    Vec operator* (const Transform& t, const Vec& v) noexcept
    {
        Vec result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += t[i][j] * v[j];
            }
        }
        return result;
    }

    //////////////////////////////////////////////////////////////////////////
    // Transform-Point operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicTransform Transform, ConceptBasicPoint Pnt>
        requires (Transform::Dimension == Pnt::Dimension)
    [[nodiscard]] constexpr
    Pnt operator* (const Transform& t, const Pnt& p) noexcept
    {
        Pnt result;
        for (SizeType i = 0; i < Transform::Dimension; ++i)
        {
            for (SizeType j = 0; j < Transform::Dimension; ++j)
            {
                result[i] += t[i][j] * p[j];
            }
            result[i] += t[i][Transform::Dimension];
        }
        return result;
    }
}

#endif //MATHLIB_IMPL_TRANSFORM_OPERATORS_HPP
