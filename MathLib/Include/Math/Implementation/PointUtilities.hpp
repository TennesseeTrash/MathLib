#ifndef MATHLIB_IMPL_POINT_UTILITIES_HPP
#define MATHLIB_IMPL_POINT_UTILITIES_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    template <ConceptBasicPoint Pnt>
    [[nodiscard]] constexpr
    bool HasNaN(const Pnt& p) noexcept
    {
        for (SizeType i = 0; i < Pnt::Dimension; ++i)
        {
            if (p[i] != p[i])
            {
                return true;
            }
        }

        return false;
    }
}

#endif //MATHLIB_IMPL_POINT_UTILITIES_HPP
