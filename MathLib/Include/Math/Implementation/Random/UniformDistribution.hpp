#ifndef MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP

#include "../Base/Concepts.hpp"
#include "../Functions/ValueShift.hpp"
#include "../Functions/IntUtils.hpp"
#include "Utils.hpp"

namespace Math
{
    template <Concept::StrongType T>
    class UniformDistribution;

    template <Concept::StrongType T>
        requires Concept::FloatingPointType<T> && (sizeof(T) == 4 || sizeof(T) == 8)
    class UniformUnitDistribution
    {
    public:
        using ValueType = T;

        template <Concept::RandomNumberGenerator RNG>
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            using Uint = UnsignedIntegerSelector<sizeof(ValueType)>;
            Uint randomBits = GetRandomBits<Uint>(rng);

            if constexpr (sizeof(ValueType) == 4)
            {
                return Cast<ValueType>(randomBits >> 8) * 0x1.0p-24f;
            }
            else if constexpr (sizeof(ValueType) == 8)
            {
                return Cast<ValueType>(randomBits >> 11) * 0x1.0p-53;
            }
        }
    };

    template <Concept::StrongType T>
        requires Concept::IntegralType<T>
    class UniformDistribution<T>
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        UniformDistribution(ValueType begin = ValueType::Min(), ValueType end = ValueType::Max()) noexcept
            : mBegin(begin), mEnd(end)
        {}

        // TODO(3011): (The implementation has been disabled for getting larger types from smaller types.)
        // Using just the ValueShift function is imperfect in the case where we're
        // trying to generate a value with a larger size than the RNG's value type.
        // Some values cannot be generated. It would be better to use the RNG as
        // a source of random bits that get shifted into the larger type.
        template <Concept::RandomNumberGenerator RNG>
            requires (sizeof(typename RNG::ValueType) >= sizeof(ValueType))
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

    template <Concept::StrongType T>
        requires Concept::FloatingPointType<T>
    class UniformDistribution<T>
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        UniformDistribution(ValueType begin = Cast<ValueType>(0), ValueType end = Cast<ValueType>(1)) noexcept
            : mBegin(begin), mEnd(end)
        {}

        // TODO(3011):
        // For now, the implementation is very naive. It should be correct for
        // the [0,1] range. However, the result values get scaled and shifted
        // with other ranges, which loses information.
        template <Concept::RandomNumberGenerator RNG>
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            // TODO(3011): Not sure if this is the best we can do, but it's a start.
            ValueType result = UniformUnitDistribution<ValueType>()(rng);
            return mBegin + (mEnd - mBegin) * result;
        }
    private:
        ValueType mBegin;
        ValueType mEnd;
    };
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
