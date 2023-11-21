#ifndef MATHLIB_RANDOM_HPP
#define MATHLIB_RANDOM_HPP

#include "Implementation/Random/Xoshiro.hpp"
#include "Implementation/Random/UniformDistribution.hpp"

namespace Math
{
    using Random32 = Xoshiro128StarStar;
    using Random64 = Xoshiro256StarStar;

    static_assert(ConceptRandomNumberGenerator<Random32>);
    static_assert(ConceptRandomNumberGenerator<Random64>);

    static_assert(ConceptDistribution<UniformIntegerDistribution<u32>, Random32>);
    static_assert(ConceptDistribution<UniformIntegerDistribution<u64>, Random64>);
}

#endif //MATHLIB_RANDOM_HPP
