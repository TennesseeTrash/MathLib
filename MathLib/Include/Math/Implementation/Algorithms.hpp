#ifndef MATHLIB_IMPL_ALGORITHMS_HPP
#define MATHLIB_IMPL_ALGORITHMS_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    template <ConceptArray Arr>
    [[nodiscard]] constexpr
    typename Arr::ValueType Min(Arr values) noexcept
    {
        if constexpr (Arr::Size == 0)
        {
            return typename Arr::ValueType();
        }

        typename Arr::ValueType min = values[0];
        for (SizeType i = 1; i < values.Size; ++i)
        {
            if (values[i] < min)
            {
                min = values[i];
            }
        }
        return min;
    }

    template <ConceptArray Arr>
    [[nodiscard]] constexpr
    typename Arr::ValueType Max(Arr values) noexcept
    {
        if constexpr (Arr::Size == 0)
        {
            return typename Arr::ValueType();
        }

        typename Arr::ValueType max = values[0];
        for (SizeType i = 1; i < values.Size; ++i)
        {
            if (values[i] > max)
            {
                max = values[i];
            }
        }
        return max;
    }
}

#endif //MATHLIB_IMPL_ALGORITHMS_HPP
