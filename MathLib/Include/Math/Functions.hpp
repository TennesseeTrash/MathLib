#ifndef MATHLIB_FUNCTIONS_HPP
#define MATHLIB_FUNCTIONS_HPP

#include "Common/Concepts.hpp"
#include "Common/Array.hpp"
#include "Constants.hpp"
#include "Implementation/Algorithms.hpp"

#include <cmath>

// TODO(3011): Add Pow function
// TODO(3011): Add Sqrt function
// TODO(3011): Add Trigonometric functions (sin, cos, tan etc.)

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Sign, Abs
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Sign(T val) noexcept
    {
        return (static_cast<T>(0) < val) - (val < static_cast<T>(0));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Abs(T val) noexcept
    {
        return val > static_cast<T>(0) ? val : -val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Equal function for fundamental types
    //////////////////////////////////////////////////////////////////////////

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, T val2, T epsilon = Constants::Epsilon<T>) noexcept
    {
        if constexpr (FloatingPointType<T>)
        {
            return Abs(val1 - val2) < epsilon;
        }
        else
        {
            return val1 == val2;
        }
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, StrongType<T> val2, StrongType<T> epsilon = Constants::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, T val2, StrongType<T> epsilon = Constants::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), val2, ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, StrongType<T> val2, StrongType<T> epsilon = Constants::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(val1, ToUnderlying(val2), ToUnderlying(epsilon));
    }

    //////////////////////////////////////////////////////////////////////////
    // Square function
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

    //////////////////////////////////////////////////////////////////////////
    // Clamp, Lerp
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    T Clamp(T val, T min = static_cast<T>(0), T max = static_cast<T>(1)) noexcept
    {
        return (val > max) ? max : ((val < min) ? min : val);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Lerp(T val, T begin, T end) noexcept
    {
        return ((1 - val) * begin) + (val * end);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T InvLerp(T val, T begin, T end) noexcept
    {
        return (val - begin) / (end - begin);
    }

    //////////////////////////////////////////////////////////////////////////
    // Floor, Ceil
    //////////////////////////////////////////////////////////////////////////

    template <SignedIntegralType Int, FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Floor(Float val) noexcept
    {
        return Convert<Int>(val - (val < Convert<Float>(ToUnderlying(Convert<Int>(val)))));
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Floor(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Convert<Float>(ToUnderlying(Floor<Int, Float>(val)));
    }

    template <SignedIntegralType Int, FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Ceil(Float val) noexcept
    {
        return Convert<Int>(val + (val > Convert<Float>(ToUnderlying(Convert<Int>(val)))));
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Ceil(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Convert<Float>(ToUnderlying(Ceil<Int, Float>(val)));
    }

    //////////////////////////////////////////////////////////////////////////
    // Smoothstep, Smootherstep
    //////////////////////////////////////////////////////////////////////////

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Smoothstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return (static_cast<T>(3) - static_cast<T>(2) * val) * Squared(val);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T SmoothstepDerivative(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return static_cast<T>(6) * val * (static_cast<T>(1) - val);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Smootherstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return ((static_cast<T>(6) * val - static_cast<T>(15)) * val + static_cast<T>(10)) * Cubed(val);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T SmootherstepDerivative(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return static_cast<T>(30) * (Squared(val) - static_cast<T>(2) * val + static_cast<T>(1)) * Squared(val);
    }

    //////////////////////////////////////////////////////////////////////////
    // Angle unit conversion functions
    //////////////////////////////////////////////////////////////////////////

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T ToRadians(T degrees) noexcept
    {
        return Constants::Pi<T> * (degrees / static_cast<T>(180));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T ToDegrees(T radians) noexcept
    {
        return 180 * (radians / Constants::Pi<T>);
    }

    //////////////////////////////////////////////////////////////////////////
    // Min/Max
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Min(T v1, Ts... values) noexcept
    {
        static_assert(sizeof...(Ts) == 0 || (std::is_same_v<T, Ts> || ...));
        return Min(Array<T, sizeof...(Ts) + 1>(v1, values...));
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Max(T v1, Ts... values) noexcept
    {
        static_assert(sizeof...(Ts) == 0 || (std::is_same_v<T, Ts> || ...));
        return Max(Array<T, sizeof...(Ts) + 1>(v1, values...));
    }
}

#endif //MATHLIB_FUNCTIONS_HPP
