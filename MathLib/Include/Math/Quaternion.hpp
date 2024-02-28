#ifndef MATHLIB_QUATERNION_HPP
#define MATHLIB_QUATERNION_HPP

#include "Implementation/Quaternion.hpp"
#include "Implementation/QuaternionOperators.hpp"
#include "Implementation/QuaternionUtilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Quaternionf = QuaternionT<f32>;
    using Quaterniond = QuaternionT<f64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(Concept::Quaternion<Quaternionf>);
    static_assert(Concept::Quaternion<Quaterniond>);
}

#endif //MATHLIB_QUATERNION_HPP
