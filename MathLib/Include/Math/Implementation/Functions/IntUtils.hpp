#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INT_UTILS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INT_UTILS_HPP

#include "../Base/Concepts.hpp"

#include <bit>

namespace Math
{
    template <Concept::UnsignedIntegralType ValueType, Concept::UnsignedIntegralType ShiftType>
    [[nodiscard]] constexpr
    ValueType RotateLeft(ValueType val, ShiftType shift) noexcept
    {
        return (val << shift) | (val >> ((sizeof(ValueType) * 8) - shift));
    }

    template <Concept::UnsignedIntegralType ValueType, Concept::UnsignedIntegralType ShiftType>
    [[nodiscard]] constexpr
    ValueType RotateRight(ValueType val, ShiftType shift) noexcept
    {
        return (val >> shift) | (val << ((sizeof(ValueType) * 8) - shift));
    }

    template <Concept::UnsignedIntegralType Int>
    [[nodiscard]] constexpr
    Int CountLeadingZeros(Int val) noexcept
    {
        return std::countl_zero(val);
    }

    template <Concept::UnsignedIntegralType Int>
    [[nodiscard]] constexpr
    Int CountTrailingZeros(Int val) noexcept
    {
        return std::countr_zero(val);
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INT_UTILS_HPP
