#ifndef MATHLIB_IMPL_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_HPP

#include <initializer_list>

namespace Math::Implementation
{
    template <typename T>
    [[nodiscard]] constexpr
    T Min(std::initializer_list<T> values) noexcept
    {
        T min = *values.begin();
        for (auto val : values)
        {
            if (val < min)
            {
                min = val;
            }
        }
        return min;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Max(std::initializer_list<T> values) noexcept
    {
        T max = *values.begin();
        for (auto val : values)
        {
            if (val > max)
            {
                max = val;
            }
        }
        return max;
    }
}

#endif //MATHLIB_IMPL_FUNCTIONS_HPP
