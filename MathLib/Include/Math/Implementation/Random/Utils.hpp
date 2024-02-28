#ifndef MATHLIB_IMPLEMENTATION_RANDOM_UTILS_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_UTILS_HPP

#include "../Base/Concepts.hpp"
#include "../Functions/ValueShift.hpp"

namespace Math
{
    template <Concept::StrongType T, Concept::RandomNumberGenerator RNG>
        requires Concept::UnsignedIntegralType<T>
    [[nodiscard]] constexpr
    T GetRandomBits(RNG& rng) noexcept
    {
        using RNGVT = typename RNG::ValueType;

        if constexpr (sizeof(T) <= sizeof(RNGVT))
        {
            // Note(3011): Use the full range or discard the lower bits.
            return ValueShift<T>(rng());
        }
        else
        {
            T result = 0;
            for (SizeType i = 0; i < (sizeof(T) / sizeof(RNGVT)); ++i)
            {
                result |= Cast<T>(rng()) << (i * sizeof(RNGVT) * 8);
            }
            return result;
        }
    }
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_UTILS_HPP
