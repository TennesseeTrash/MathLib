#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP

#include "../../Common/Concepts.hpp"
#include "../../Common/Array.hpp"
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
        return (val > Cast<T>(0)) ? val : -val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Equal function for fundamental types
    //////////////////////////////////////////////////////////////////////////

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, T val2, T epsilon = Constant::Epsilon<T>) noexcept
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
    bool Equal(StrongType<T> val1, StrongType<T> val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, T val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), val2, ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, StrongType<T> val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(val1, ToUnderlying(val2), ToUnderlying(epsilon));
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

    template <typename T>
    [[nodiscard]] constexpr
    T Pow(T val, T exponent) noexcept
    {
        return std::pow(ToUnderlying(val), ToUnderlying(exponent));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Sqrt(T val) noexcept
    {
        return std::sqrt(ToUnderlying(val));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Log(T val) noexcept
    {
        return std::log(ToUnderlying(val));
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
    // Trunc, Floor, Ceil, Frac
    //////////////////////////////////////////////////////////////////////////

    template <SignedIntegralType Int, FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Trunc(Float val) noexcept
    {
        return Cast<Int>(val);
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Trunc(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Trunc<Int, Float>(val));
    }

    template <SignedIntegralType Int, FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Floor(Float val) noexcept
    {
        return Cast<Int>(val - (val < Trunc<Float>(val)));
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Floor(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Floor<Int, Float>(val));
    }

    template <SignedIntegralType Int, FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Ceil(Float val) noexcept
    {
        return Cast<Int>(val + (val > Trunc<Float>(val)));
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Ceil(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Ceil<Int, Float>(val));
    }

    template <FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Frac(Float val) noexcept
    {
        return val - Trunc<Float>(val);
    }

    //////////////////////////////////////////////////////////////////////////
    // Smoothstep, Smootherstep
    //////////////////////////////////////////////////////////////////////////

    // OBSOLETE - All these functions are obsolete and will be removed once
    // the Function API is implemented.

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
        return Constant::Pi<T> * (degrees / Cast<T>(180));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T ToDegrees(T radians) noexcept
    {
        return Cast<T>(180) * (radians / Constant::Pi<T>);
    }

    //////////////////////////////////////////////////////////////////////////
    // Min/Max
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Min(T v1, Ts... values) noexcept
    {
        // TODO(3011): This needs a refactor, making an array is unnecessary.
        static_assert(sizeof...(Ts) == 0 || (IsSame<T, Ts> || ...));
        return Array<T, sizeof...(Ts) + 1>(v1, values...).Min();
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Max(T v1, Ts... values) noexcept
    {
        // TODO(3011): This needs a refactor, making an array is unnecessary.
        static_assert(sizeof...(Ts) == 0 || (IsSame<T, Ts> || ...));
        return Array<T, sizeof...(Ts) + 1>(v1, values...).Max();
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP
