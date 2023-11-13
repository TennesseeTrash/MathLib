#ifndef MATHLIB_COMMON_BOOL_TOOLS_HPP
#define MATHLIB_COMMON_BOOL_TOOLS_HPP

#include "Implementation/BoolTools.hpp"

namespace Math
{
    template <StaticSizeType CheckValue, StaticSizeType... TrueValues>
    static constexpr bool TrueFor = Implementation::TrueFor<CheckValue, TrueValues...>::Value;

    template <StaticSizeType CheckValue, StaticSizeType... FalseValues>
    static constexpr bool FalseFor = Implementation::FalseFor<CheckValue, FalseValues...>::Value;
}

#endif //MATHLIB_COMMON_BOOL_TOOLS_HPP
