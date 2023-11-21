#ifndef MATHLIB_IMPL_RANDOM_CONCEPTS_HPP
#define MATHLIB_IMPL_RANDOM_CONCEPTS_HPP

#include "../../Common/Concepts.hpp"

namespace Math
{
    template <typename T>
    concept RandomNumberGenerator = requires(T rng)
    {
        typename T::ValueType;

        requires UnsignedIntegralType<typename T::ValueType>;

        requires requires (typename T::ValueType val)
        {
            { T(val) } -> IsSame<T>;
        };

        { rng()          } -> IsSame<typename T::ValueType>;
        { rng.Jump()     } -> IsSame<T>;
        { rng.LongJump() } -> IsSame<T>;
    };
}

#endif //MATHLIB_IMPL_RANDOM_CONCEPTS_HPP
