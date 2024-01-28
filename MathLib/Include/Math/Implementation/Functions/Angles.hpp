#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_ANGLES_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_ANGLES_HPP

#include "../Base/Concepts.hpp"

namespace Math
{
    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T ToRadians(T degrees) noexcept
    {
        return Constant::Pi<T> * (degrees / Cast<T>(180));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T ToDegrees(T radians) noexcept
    {
        return Cast<T>(180) * (radians / Constant::Pi<T>);
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_ANGLES_HPP
