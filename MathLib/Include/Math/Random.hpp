#ifndef MATHLIB_RANDOM_HPP
#define MATHLIB_RANDOM_HPP

#include "Implementation/Random/Concepts.hpp"
#include "Implementation/Random/Xoshiro.hpp"
#include "Implementation/Random/UniformDistribution.hpp"

namespace Math
{
    using Random32 = Xoshiro128StarStar;
    using Random64 = Xoshiro256StarStar;

    static_assert(RandomNumberGenerator<Random32>);
    static_assert(RandomNumberGenerator<Random64>);
}

#endif //MATHLIB_RANDOM_HPP
