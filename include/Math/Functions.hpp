#ifndef _CC_MATH_FUNCTIONS_HPP
#define _CC_MATH_FUNCTIONS_HPP


namespace cc
{
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

    //////////////////////////////////////////////////////////////////////////
    // Sign, Abs
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] inline constexpr
    T Sign(T val) noexcept
    {
        return (T(0) < val) - (val < T(0));
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    T Abs(T val) noexcept
    {
        return val > T(0) ? val : -val;
    }

    //////////////////////////////////////////////////////////////////////////
    // Equal function for floating point comparisons
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] inline constexpr
    bool Equal(T val1, T val2, T epsilon = T(0.000001)) noexcept
    {
        return Abs(val1 - val2) < epsilon;
    }
}

#endif //_CC_MATH_FUNCTIONS_HPP
