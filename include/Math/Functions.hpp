#ifndef _CC_MATH_FUNCTIONS_HPP
#define _CC_MATH_FUNCTIONS_HPP

namespace cc
{
    //////////////////////////////////////////////////////////////////////////
    // Min, Max functions
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename... Pack>
    inline constexpr T Min(const Pack&... values)
    {
        return Min(values);
    }

    template <typename T, typename... Pack>
    inline constexpr T Min(const T& a, const Pack&... values)
    {
        return Min(a, Min(values));
    }

    template <typename T>
    inline constexpr T Min(const T& a, const T& b)
    {
        return a > b ? b : a;
    }

    template <typename T, typename... Pack>
    inline constexpr T Max(const Pack&... values)
    {
        return Max(values);
    }

    template <typename T, typename... Pack>
    inline constexpr T Max(const T& a, const Pack&... values)
    {
        return Max(a, Max(values));
    }

    template <typename T>
    inline constexpr T Max(const T& a, const T& b)
    {
        return a > b ? a : b;
    }

    //////////////////////////////////////////////////////////////////////////
    // Clamp, Lerp
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    inline constexpr T Clamp(T val, T min = T(0), T max = T(1))
    {
        return val > max ? max : val < min ? min : val;
    }

    template <typename T, typename U>
    inline constexpr U Lerp(T val, const U& begin, const U& end)
    {
        return ((1 - val) * begin) + (val * end);
    }

    //////////////////////////////////////////////////////////////////////////
    // Floor, Ceil
    //////////////////////////////////////////////////////////////////////////

    template <typename Int, typename Float>
    inline constexpr Int Floor(Float val)
    {
        return static_cast<Int>(val - (val < static_cast<Int>(val)));
    }

    template <typename Int, typename Float>
    inline constexpr Int Ceil(Float val)
    {
        return static_cast<Int>(val - (val > static_cast<Int>(val)));
    }
}

#endif //_CC_MATH_FUNCTIONS_HPP
