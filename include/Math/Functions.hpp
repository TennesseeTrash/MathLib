#ifndef MATHLIB_FUNCTIONS_HPP
#define MATHLIB_FUNCTIONS_HPP

#include "Constants.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Square function
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Sq(T val) noexcept
    {
        return val * val;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Cube(T val) noexcept
    {
        return val * val * val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Clamp, Lerp
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Clamp(T val, T min = T(0), T max = T(1)) noexcept
    {
        return val > max ? max : val < min ? min : val;
    }

    template <typename T, typename U>
    [[nodiscard]] constexpr
    U Lerp(T val, const U& begin, const U& end) noexcept
    {
        return ((1 - val) * begin) + (val * end);
    }

    //////////////////////////////////////////////////////////////////////////
    // Floor, Ceil
    //////////////////////////////////////////////////////////////////////////

    template <typename Int, typename Float>
    [[nodiscard]] constexpr
    Int Floor(Float val) noexcept
    {
        return static_cast<Int>(val - (val < static_cast<Int>(val)));
    }

    template <typename Int, typename Float>
    [[nodiscard]] constexpr
    Int Ceil(Float val) noexcept
    {
        return static_cast<Int>(val - (val > static_cast<Int>(val)));
    }

    //////////////////////////////////////////////////////////////////////////
    // Sign, Abs
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Sign(T val) noexcept
    {
        return (T(0) < val) - (val < T(0));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Abs(T val) noexcept
    {
        return val > T(0) ? val : -val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Angle unit conversion functions
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T ToRadians(T val) noexcept
    {
        return (Constants::Pi<T> * val) / T(180);
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToDegrees(T val) noexcept
    {
        return (180 * val) / Constants::Pi<T>;
    }

    //////////////////////////////////////////////////////////////////////////
    // Equal function for floating point comparisons
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    bool Equal(T val1, T val2, T epsilon = Constants::FloatEps<T>) noexcept
    {
        return Abs(val1 - val2) < epsilon;
    }
}

#endif //MATHLIB_FUNCTIONS_HPP
