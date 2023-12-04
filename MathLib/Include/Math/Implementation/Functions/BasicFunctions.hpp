#ifndef MATHLIB_IMPL_FUNCTIONS_BASIC_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_BASIC_FUNCTIONS_HPP

#include "../../Common/Concepts.hpp"
#include "../../Common/Array.hpp"
#include "../../Constants.hpp"

// Note(3011): Currently used for std::pow and trig functions.
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
        return val > Cast<T>(0) ? val : -val;
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
    // Trig functions
    //////////////////////////////////////////////////////////////////////////

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Sin(T val) noexcept
    {
        return std::sin(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Cos(T val) noexcept
    {
        return std::cos(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Tan(T val) noexcept
    {
        return std::tan(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Asin(T val) noexcept
    {
        return std::asin(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Acos(T val) noexcept
    {
        return std::acos(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Atan(T val) noexcept
    {
        return std::atan(ToUnderlying(val));
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Atan2(T y, T x) noexcept
    {
        return std::atan2(ToUnderlying(y), ToUnderlying(x));
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
    // ValueShift
    //////////////////////////////////////////////////////////////////////////

    // TODO(3011):
    // - Add overloads for unequal sizes.

    template <SignedIntegralType To, SignedIntegralType From>
        requires (sizeof(To) >= sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <UnsignedIntegralType To, UnsignedIntegralType From>
        requires (sizeof(To) >= sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <SignedIntegralType To, UnsignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        // TODO(3011): Make the variables static constexpr
        // once it's feasible to move to C++23.

        if (value >= (From(1) << ((sizeof(To) * 8) - 1)))
        {
            constexpr From sub = Cast<From>(1) << ((sizeof(From) * 8) - 1);
            return Cast<To>(value - sub);
        }
        else
        {
            // ((sizeof(To) * 8) - 1) is not representable by To
            constexpr To sub = Cast<To>(1) << ((sizeof(To) * 8) - 2);
            return Cast<To>(value) - sub - sub;
        }
    }

    template <UnsignedIntegralType To, SignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        // TODO(3011): Make the variables static constexpr
        // once it's feasible to move to C++23.

        if (value >= 0)
        {
            constexpr To add = Cast<To>(1) << ((sizeof(To) * 8) - 1);
            return Cast<To>(value) + add;
        }
        else
        {
            // ((sizeof(From) * 8) - 1) is not representable by From
            constexpr From add = Cast<From>(1) << ((sizeof(From) * 8) - 2);
            return Cast<To>(value + add + add);
        }
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
        static_assert(sizeof...(Ts) == 0 || (IsSame<T, Ts> || ...));
        return Array<T, sizeof...(Ts) + 1>(v1, values...).Min();
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Max(T v1, Ts... values) noexcept
    {
        static_assert(sizeof...(Ts) == 0 || (IsSame<T, Ts> || ...));
        return Array<T, sizeof...(Ts) + 1>(v1, values...).Max();
    }
}

#endif //MATHLIB_IMPL_FUNCTION_BASIC_FUNCTIONS_HPP
