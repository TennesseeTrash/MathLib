#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP

#include "../../Common/Types.hpp"

namespace Math
{
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
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP
