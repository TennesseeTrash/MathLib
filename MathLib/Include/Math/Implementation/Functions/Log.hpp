#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_LOG_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_LOG_HPP

#include "../Base/Concepts.hpp"

#include <cmath>

namespace Math
{
    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Log(T val) noexcept
    {
        return std::log(ToUnderlying(val));
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_LOG_HPP
