#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_FUNCTION_DERIVATIVES_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_FUNCTION_DERIVATIVES_HPP

#include "../../Base/Types.hpp"

namespace Math::Function
{
    namespace Implementation
    {
        template <typename T, SizeType Order>
        struct Derivative final
        {
            using Type = typename Derivative<typename Derivative<T, 1>::Type, Cast<SizeType>(Order) - 1>::Type;
        };

        template <typename T>
        struct Derivative<T, 0> final
        {
            using Type = T;
        };

        template <typename T>
        struct Derivative<T, 1> final
        {
            using Type = typename T::DerivativeType;
        };
    }

    template <typename T, SizeType Order = 1>
    using Derivative = typename Implementation::Derivative<T, Order>::Type;
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_FUNCTION_DERIVATIVES_HPP
