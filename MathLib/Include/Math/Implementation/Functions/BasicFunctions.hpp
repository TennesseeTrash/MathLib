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

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Smoothstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return (static_cast<T>(3) - static_cast<T>(2) * val) * Squared(val);
    }

    template <FloatingPointType T>
    [[nodiscard]] constexpr
    T Smootherstep(T val, T begin, T end) noexcept
    {
        val = Clamp(InvLerp(val, begin, end));
        return ((static_cast<T>(6) * val - static_cast<T>(15)) * val + static_cast<T>(10)) * Cubed(val);
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

    template <ConceptMathTypeUtil T>
        requires requires (T t) { { t.Min() } -> IsSame<typename T::ScalarType>; }
    [[nodiscard]] constexpr
    typename T::ScalarType Min(const T& val) noexcept
    {
        return val.Min();
    }

    template <typename T, typename... Ts>
    [[nodiscard]] constexpr
    T Max(T v1, Ts... values) noexcept
    {
        // TODO(3011): This needs a refactor, making an array is unnecessary.
        static_assert(sizeof...(Ts) == 0 || (IsSame<T, Ts> || ...));
        return Array<T, sizeof...(Ts) + 1>(v1, values...).Max();
    }

    template <ConceptMathTypeUtil T>
        requires requires (T t) { { t.Max() } -> IsSame<typename T::ScalarType>; }
    [[nodiscard]] constexpr
    typename T::ScalarType Max(const T& val) noexcept
    {
        return val.Max();
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_BASIC_FUNCTIONS_HPP
