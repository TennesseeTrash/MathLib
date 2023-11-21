#ifndef MATHLIB_IMPL_RANDOM_UNIFORM_DISTRIBUTION_HPP
#define MATHLIB_IMPL_RANDOM_UNIFORM_DISTRIBUTION_HPP

#include "../../Common/Concepts.hpp"
#include "../../Functions.hpp"

namespace Math
{
    template <ConceptStrongType T>
        requires IntegralType<T>
    class UniformIntegerDistribution
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        UniformIntegerDistribution(ValueType begin = ValueType::Min, ValueType end = ValueType::Max) noexcept
            : mBegin(begin), mEnd(end)
        {}

        // TODO(3011):
        // Relax the equality requirement once ValueShift is implemented
        // for unequal sizes.
        template <ConceptRandomNumberGenerator RNG>
            requires (sizeof(typename RNG::ValueType) == sizeof(ValueType))
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            using RNGVT = typename RNG::ValueType;
            RNGVT range = ValueShift<RNGVT>(mEnd) - ValueShift<RNGVT>(mBegin);
            if (range == RNGVT::Max)
            {
                return ValueShift<ValueType>(rng());
            }

            RNGVT repeat = RNGVT::Max - (RNGVT::Max % range) + 1;
            RNGVT result = rng();
            while (result >= repeat)
            {
                result = rng();
            }

            return mBegin + ValueShift<ValueType>(result % range);
        }
    private:
        ValueType mBegin;
        ValueType mEnd;
    };

    // TODO(3011):
    // Add uniform float distribution.
}

#endif //MATHLIB_IMPL_RANDOM_UNIFORM_DISTRIBUTION_HPP
