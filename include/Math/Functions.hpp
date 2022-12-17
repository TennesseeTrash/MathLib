#ifndef _CC_MATH_FUNCTIONS_HPP
#define _CC_MATH_FUNCTIONS_HPP

namespace cc
{
    //////////////////////////////////////////////////////////////////////////
    // Min, Max functions
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename... Pack>
    [[nodiscard]] inline constexpr
    T Min(const Pack&... values) noexcept
    {
        return Min(values);
    }

    template <typename T, typename... Pack>
    [[nodiscard]] inline constexpr
    T Min(const T& a, const Pack&... values) noexcept
    {
        return Min(a, Min(values));
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Min(const T& a, const T& b) noexcept
    {
        return a > b ? b : a;
    }

    template <typename T, typename... Pack>
    [[nodiscard]] inline constexpr
    T Max(const Pack&... values) noexcept
    {
        return Max(values);
    }

    template <typename T, typename... Pack>
    [[nodiscard]] inline constexpr
    T Max(const T& a, const Pack&... values) noexcept
    {
        return Max(a, Max(values));
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Max(const T& a, const T& b) noexcept
    {
        return a > b ? a : b;
    }

    //////////////////////////////////////////////////////////////////////////
    // Clamp, Lerp
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] inline constexpr
    T Clamp(T val, T min = T(0), T max = T(1)) noexcept
    {
        return val > max ? max : val < min ? min : val;
    }

    template <typename T, typename U>
    [[nodiscard]] inline constexpr
    U Lerp(T val, const U& begin, const U& end) noexcept
    {
        return ((1 - val) * begin) + (val * end);
    }

    //////////////////////////////////////////////////////////////////////////
    // Floor, Ceil
    //////////////////////////////////////////////////////////////////////////

    template <typename Int, typename Float>
    [[nodiscard]] inline constexpr
    Int Floor(Float val) noexcept
    {
        return static_cast<Int>(val - (val < static_cast<Int>(val)));
    }

    template <typename Int, typename Float>
    [[nodiscard]] inline constexpr
    Int Ceil(Float val) noexcept
    {
        return static_cast<Int>(val - (val > static_cast<Int>(val)));
    }
}

#endif //_CC_MATH_FUNCTIONS_HPP
