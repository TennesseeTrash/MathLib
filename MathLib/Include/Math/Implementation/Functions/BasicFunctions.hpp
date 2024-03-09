#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP

#include "../../Base.hpp"
#include "../../Constants.hpp"

// Note(3011): Currently used for std::pow, std::log and std::sqrt.
// TODO(3011): Add custom implementation and remove this include later.
#include <cmath>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Sign, Abs
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Sign(T val) noexcept
    {
        return Cast<T>((Cast<T>(0) < val) - (val < Cast<T>(0)));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Abs(T val) noexcept
    {
        // Note(3011): This might not necessarily work, e.g. i8(-128).
        // The implementation assumes that val is never T::Min() for
        // signed integer types.
        return (val > Cast<T>(0)) ? val : -val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Power functions, logarithms
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Squared(T val) noexcept
    {
        return val * val;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Cubed(T val) noexcept
    {
        return val * val * val;
    }

    // TODO(3011): Possible implicit conversion
    template <typename T>
    [[nodiscard]] constexpr
    T Pow(T val, T exponent) noexcept
    {
        return std::pow(ToUnderlying(val), ToUnderlying(exponent));
    }

    // TODO(3011): Possible implicit conversion
    template <typename T>
    [[nodiscard]] constexpr
    T Sqrt(T val) noexcept
    {
        return std::sqrt(ToUnderlying(val));
    }

    //////////////////////////////////////////////////////////////////////////
    // Clamp, Lerp
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Clamp(T val, T min = static_cast<T>(0), T max = static_cast<T>(1)) noexcept
    {
        return (val > max) ? max : ((val < min) ? min : val);
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Lerp(T val, T begin, T end) noexcept
    {
        return ((1 - val) * begin) + (val * end);
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T InvLerp(T val, T begin, T end) noexcept
    {
        return (val - begin) / (end - begin);
    }

    //////////////////////////////////////////////////////////////////////////
    // Smoothstep, Smootherstep
    //////////////////////////////////////////////////////////////////////////

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Smoothstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return (static_cast<T>(3) - static_cast<T>(2) * val) * Squared(val);
    }

    template <Concept::FloatingPointType T>
    [[nodiscard]] constexpr
    T Smootherstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return ((static_cast<T>(6) * val - static_cast<T>(15)) * val + static_cast<T>(10)) * Cubed(val);
    }

    //////////////////////////////////////////////////////////////////////////
    // Min/Max
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    auto Min(const T& val) noexcept
    {
        if constexpr (requires (T t) { { t.Min() } -> Concept::IsSame<typename T::ScalarType>; })
        {
            return val.Min();
        }
        else
        {
            return val;
        }
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Min(T v1, T v2) noexcept
    {
        return (v1 < v2) ? v1 : v2;
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Min(T v1, T v2, Ts... values) noexcept
    {
        return Min(Min(v1, v2), values...);
    }

    template <typename T>
    [[nodiscard]] constexpr
    auto Max(const T& val) noexcept
    {
        if constexpr (requires (T t) { { t.Max() } -> Concept::IsSame<typename T::ScalarType>; })
        {
            return val.Max();
        }
        else
        {
            return val;
        }
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Max(T v1, T v2) noexcept
    {
        return (v1 > v2) ? v1 : v2;
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Max(T v1, T v2, Ts... values) noexcept
    {
        return Max(Max(v1, v2), values...);
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP
