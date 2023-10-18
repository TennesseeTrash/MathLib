#ifndef MATHLIB_IMPL_ALGORITHMS_HPP
#define MATHLIB_IMPL_ALGORITHMS_HPP

#include "../Common/Concepts.hpp"

// TODO(3011): Check if it would make sense to replace this
// with a custom implementation. (To shorten compile times.)
#include <utility>
#include <random>

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

    template <ConceptArray Arr>
    constexpr
    void FillAscending(Arr& a)
    {
        for (SizeType i = 0; i < Arr::Size; ++i)
        {
            a[i] = Convert<typename Arr::ValueType>(i + 1);
        }
    }

    template <ConceptArray Arr>
    constexpr
    void Shuffle(Arr& a, u64 seed) noexcept
    {
        std::mt19937_64 rng(ToUnderlying(seed));
        std::uniform_int_distribution<std::size_t> dist(0, ToUnderlying(Arr::Size - 1));
        for (SizeType i = 0; i < Arr::Size; ++i)
        {
            SizeType j = dist(rng);
            std::swap(a[i], a[j]);
        }
    }

    template <ConceptArray Arr>
    constexpr
    void PoissonFill(Arr& a, u64 seed, f64 mean) noexcept
    {
        std::mt19937_64 rng(ToUnderlying(seed));
        std::poisson_distribution<std::size_t> dist(ToUnderlying(mean));
        for (SizeType i = 0; i < Arr::Size; ++i)
        {
            a[i] = dist(rng);
        }
    }
}

#endif //MATHLIB_IMPL_ALGORITHMS_HPP
