#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP

#include "../Base/Types.hpp"

namespace Math
{
    template <Concept::SignedIntegralType To, Concept::SignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <Concept::SignedIntegralType To, Concept::SignedIntegralType From>
        requires (sizeof(To) < sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        From shiftAmount = Cast<From>(sizeof(From) - sizeof(To)) * 8;
        return Cast<To>(value >> shiftAmount);
    }

    template <Concept::SignedIntegralType To, Concept::SignedIntegralType From>
        requires (sizeof(To) > sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        using UnsignedFrom = UnsignedIntegerSelector<sizeof(From)>;
        using UnsignedTo = UnsignedIntegerSelector<sizeof(To)>;
        return ValueShift<To>(ValueShift<UnsignedTo>(ValueShift<UnsignedFrom>(value)));
    }

    template <Concept::UnsignedIntegralType To, Concept::UnsignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <Concept::UnsignedIntegralType To, Concept::UnsignedIntegralType From>
        requires (sizeof(To) < sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        From shiftAmount = Cast<From>(sizeof(From) - sizeof(To)) * 8;
        return Cast<To>(value >> shiftAmount);
    }

    template <Concept::UnsignedIntegralType To, Concept::UnsignedIntegralType From>
        requires (sizeof(To) > sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        // TODO(3011): Make this static constexpr in C++23 (and see if there's a way to make it nicer)
        constexpr To increment = []() constexpr
        {
            To result = 0;
            for (SizeType i = 0; i < sizeof(To); i += sizeof(From))
            {
                result += (1 << (Cast<To>(i) * 8));
            }
            return result;
        }();
        To multiplier = Cast<To>(value);
        return increment * multiplier;
    }

    template <Concept::SignedIntegralType To, Concept::UnsignedIntegralType From>
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

    template <Concept::SignedIntegralType To, Concept::UnsignedIntegralType From>
        requires (sizeof(To) != sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        using UnsignedTo = UnsignedIntegerSelector<sizeof(To)>;
        return ValueShift<To>(ValueShift<UnsignedTo>(value));
    }

    template <Concept::UnsignedIntegralType To, Concept::SignedIntegralType From>
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

    template <Concept::UnsignedIntegralType To, Concept::SignedIntegralType From>
        requires (sizeof(To) != sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        using UnsignedFrom = UnsignedIntegerSelector<sizeof(From)>;
        return ValueShift<To>(ValueShift<UnsignedFrom>(value));
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_VALUE_SHIFT_HPP
