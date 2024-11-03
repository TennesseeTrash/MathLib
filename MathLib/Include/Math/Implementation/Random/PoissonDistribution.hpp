#ifndef MATHLIB_IMPLEMENTATION_RANDOM_POISSON_DISTRIBUTION_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_POISSON_DISTRIBUTION_HPP

#include "UniformDistribution.hpp"

namespace Math
{
    // Note(3011):
    // Works fine for mean values up to ~700 (doubles/f64) or ~100 (floats/f32).
    // This is not ideal, but it should work fine for most purposes.

    template <Concept::StrongIntegerType T>
    class PoissonDistribution
    {
    public:
        using ValueType = T;
        using MeanType = FloatingPointSelector<sizeof(ValueType)>;

        [[nodiscard]] constexpr
        PoissonDistribution(MeanType mean = Cast<MeanType>(0))
            : mUniform(Cast<MeanType>(0), Cast<MeanType>(1)), mMean(mean)
        {}

        template <Concept::RandomNumberGenerator RNG>
        [[nodiscard]] constexpr
        ValueType operator()(RNG& rng) const noexcept
        {
            MeanType uniformSample = mUniform(rng);

            ValueType i = 0;
            MeanType p = Exp(-mMean);
            MeanType cdf = p;
            while (uniformSample >= cdf)
            {
                p = (mMean * p) / Cast<MeanType>(i + 1);
                cdf += p;
                i++;
            }

            return i;
        }
    private:
        UniformDistribution<MeanType> mUniform;
        MeanType mMean;
    };
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_POISSON_DISTRIBUTION_HPP
