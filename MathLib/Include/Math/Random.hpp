#ifndef MATHLIB_RANDOM_HPP
#define MATHLIB_RANDOM_HPP

#include "Implementation/Random/Xoshiro.hpp"
#include "Implementation/Random/UniformDistribution.hpp"
#include "Implementation/Random/PoissonDistribution.hpp"

namespace Math
{
    using Random32 = Xoshiro128StarStar;
    using Random64 = Xoshiro256StarStar;

    static_assert(Concept::RandomNumberGenerator<Random32>);
    static_assert(Concept::RandomNumberGenerator<Random64>);

    static_assert(Concept::Distribution<UniformDistribution<u32>, Random32>);
    static_assert(Concept::Distribution<UniformDistribution<u64>, Random64>);
}

#endif //MATHLIB_RANDOM_HPP
