#ifndef MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP

#include "../Base/Concepts.hpp"
#include "../../Functions.hpp"

namespace Math
{
    template <Concept::StrongType T>
        requires Concept::IntegralType<T>
    class UniformDistribution
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        UniformDistribution(ValueType begin = ValueType::Min(), ValueType end = ValueType::Max()) noexcept
            : mBegin(begin), mEnd(end)
        {}

        template <Concept::RandomNumberGenerator RNG>
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            using RNGVT = typename RNG::ValueType;
            RNGVT begin = ValueShift<RNGVT>(mBegin);
            RNGVT range = ValueShift<RNGVT>(mEnd) - begin;
            if (range == RNGVT::Max())
            {
                return ValueShift<ValueType>(rng());
            }

            ++range;
            RNGVT repeat = RNGVT::Max() - (RNGVT::Max() % range);
            RNGVT result = rng();
            while (result > repeat)
            {
                result = rng();
            }

            return ValueShift<ValueType>(begin + (result % range));
        }
    private:
        ValueType mBegin;
        ValueType mEnd;
    };

    // TODO(3011):
    // Add uniform float distribution.
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
