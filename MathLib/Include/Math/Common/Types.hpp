#ifndef MATHLIB_COMMON_TYPES_HPP
#define MATHLIB_COMMON_TYPES_HPP

#include "Implementation/Types.hpp"
#include "Implementation/StrongTypes.hpp"
#include "Implementation/StrongTypesUtils.hpp"
#include "Implementation/StrongTypesSelectors.hpp"

#include <limits>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Assumptions
    //////////////////////////////////////////////////////////////////////////

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    //////////////////////////////////////////////////////////////////////////
    // Types
    //////////////////////////////////////////////////////////////////////////

    enum class Orientation
    {
        Left,
        Right
    };

    template <bool Condition, typename TrueType, typename FalseType>
    using ConditionalType = typename Implementation::ConditionalType<Condition, TrueType, FalseType>::Type;

    template <typename T>
    using GetValueType = typename Implementation::GetValueType<T>::Type;
}

#endif //MATHLIB_COMMON_TYPES_HPP
