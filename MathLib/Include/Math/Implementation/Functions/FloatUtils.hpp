#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_FLOAT_UTILS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_FLOAT_UTILS_HPP

#include "../Base/Types.hpp"
#include "../Base/Concepts.hpp"

namespace Math
{
    template <Concept::SignedIntegralType Int, Concept::FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Trunc(Float val) noexcept
    {
        return Cast<Int>(val);
    }

    template <Concept::FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Trunc(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Trunc<Int, Float>(val));
    }

    template <Concept::SignedIntegralType Int, Concept::FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Floor(Float val) noexcept
    {
        return Cast<Int>(val - (val < Trunc<Float>(val)));
    }

    template <Concept::FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Floor(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Floor<Int, Float>(val));
    }

    template <Concept::SignedIntegralType Int, Concept::FloatingPointType Float>
        requires (sizeof(Int) >= sizeof(Float))
    [[nodiscard]] constexpr
    Int Ceil(Float val) noexcept
    {
        return Cast<Int>(val + (val > Trunc<Float>(val)));
    }

    template <Concept::FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Ceil(Float val) noexcept
    {
        using Int = SignedIntegerSelector<sizeof(UnderlyingType<Float>)>;
        return Cast<Float>(Ceil<Int, Float>(val));
    }

    template <Concept::FloatingPointType Float>
    [[nodiscard]] constexpr
    Float Frac(Float val) noexcept
    {
        return val - Trunc<Float>(val);
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_FLOAT_UTILS_HPP
