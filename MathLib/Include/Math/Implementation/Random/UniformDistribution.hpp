#ifndef MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP

#include "../Base/Concepts.hpp"
#include "../Functions/BasicFunctions.hpp"
#include "../Functions/ValueShift.hpp"
#include "../Functions/IntUtils.hpp"
#include "Utils.hpp"

namespace Math
{
    // Note(3011): This forward decl should accept only Concept::StrongType,
    // but Clang does not like that, despite the specializations being stricter.
    template <typename T>
    class UniformDistribution;

    template <Concept::StrongFloatType T>
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

    template <Concept::StrongIntegerType T>
    class UniformDistribution<T>
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
            using RandomBitsType = UnsignedIntegerSelector<sizeof(ValueType)>;

            RandomBitsType begin = ValueShift<RandomBitsType>(mBegin);
            RandomBitsType range = ValueShift<RandomBitsType>(mEnd) - begin;

            if constexpr (sizeof(RNGVT) < sizeof(ValueType))
            {
                // Note(3011): I don't really like this duplication, but I don't see a more
                // elegant way to do this currently. The usage where this becomes useful is
                // generally not a great idea anyway, so I might still remove this at some
                // point.

                if (range == Cast<RandomBitsType>(RNGVT::Max()))
                {
                    return ValueShift<ValueType>(rng());
                }
                else if (range <= Cast<RandomBitsType>(RNGVT::Max()))
                {
                    ++range;
                    RNGVT repeat = RNGVT::Max() - (RNGVT::Max() % Cast<RNGVT>(range));
                    RNGVT result = rng();
                    while (result > repeat)
                    {
                        result = rng();
                    }

                    return ValueShift<ValueType>(begin + (Cast<RandomBitsType>(result) % range));
                }
            }

            if (range == RandomBitsType::Max())
            {
                return ValueShift<ValueType>(GetRandomBits<RandomBitsType>(rng));
            }

            ++range;
            RandomBitsType repeat = RandomBitsType::Max() - (RandomBitsType::Max() % range);
            RandomBitsType result = GetRandomBits<RandomBitsType>(rng);
            while (result > repeat)
            {
                result = GetRandomBits<RandomBitsType>(rng);
            }

            return ValueShift<ValueType>(begin + (result % range));
        }
    private:
        ValueType mBegin;
        ValueType mEnd;
    };

    template <Concept::StrongFloatType T>
    class UniformDistribution<T>
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        UniformDistribution(ValueType begin = Cast<ValueType>(0), ValueType end = Cast<ValueType>(1)) noexcept
            : mBegin(begin), mEnd(end.Next())
        {}

        template <Concept::RandomNumberGenerator RNG>
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            ValueType result = UniformUnitDistribution<ValueType>()(rng);
            return Lerp(result, mBegin, mEnd);
        }
    private:
        ValueType mBegin;
        ValueType mEnd;
    };
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_UNIFORM_DISTRIBUTION_HPP
