#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_TRIGONOMETRIC_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_TRIGONOMETRIC_FUNCTIONS_HPP

#include "../Base/Concepts.hpp"
#include "../Base/Types.hpp"

// TODO(3011): Add custom implementation and remove this include later.
#include <cmath>

namespace Math
{
    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Sin(T val) noexcept
    {
        return std::sin(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Cos(T val) noexcept
    {
        return std::cos(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Tan(T val) noexcept
    {
        return std::tan(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Asin(T val) noexcept
    {
        return std::asin(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Acos(T val) noexcept
    {
        return std::acos(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Atan(T val) noexcept
    {
        return std::atan(ToUnderlying(val));
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Atan2(T y, T x) noexcept
    {
        return std::atan2(ToUnderlying(y), ToUnderlying(x));
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_TRIGONOMETRIC_FUNCTIONS_HPP
