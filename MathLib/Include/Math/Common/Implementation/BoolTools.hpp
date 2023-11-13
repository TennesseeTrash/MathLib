#ifndef MATHLIB_COMMON_IMPL_BOOL_TOOLS_HPP
#define MATHLIB_COMMON_IMPL_BOOL_TOOLS_HPP

#include "StrongTypes.hpp"

namespace Math::Implementation
{
    template <StaticSizeType CheckValue, StaticSizeType... TrueValues>
    struct TrueFor
    {
        static constexpr bool Value = ((SizeType(TrueValues) == SizeType(CheckValue)) || ...);
    };

    template <StaticSizeType CheckValue, StaticSizeType... FalseValues>
    struct FalseFor
    {
        static constexpr bool Value = !TrueFor<CheckValue, FalseValues...>::Value;
    };
}

#endif //MATHLIB_COMMON_IMPL_BOOL_TOOLS_HPP
