#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_HAS_NAN_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_HAS_NAN_HPP

#include "../Base/Concepts.hpp"

namespace Math
{
    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    bool HasNaN(T val) noexcept
    {
        return val != val;
    }

    template <Concept::MathType T>
    [[nodiscard]] constexpr
    bool HasNaN(const T& t) noexcept
    {
        for (SizeType i = 0; i < T::Dimension; ++i)
        {
            if (HasNaN(t[i]))
            {
                return true;
            }
        }

        return false;
    }

    template <Concept::BasicQuaternion Quat>
    [[nodiscard]] constexpr
    bool HasNaN(const Quat& q) noexcept
    {
        return HasNaN(q.Vector()) || HasNaN(q.Scalar());
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_HAS_NAN_HPP
