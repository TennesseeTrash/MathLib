#ifndef MATHLIB_IMPLEMENTATION_POINT_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_POINT_UTILITIES_HPP

#include "Base/Concepts.hpp"

namespace Math
{
    template <Concept::BasicPoint Pnt>
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

#endif //MATHLIB_IMPLEMENTATION_POINT_UTILITIES_HPP
