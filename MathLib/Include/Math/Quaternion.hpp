#ifndef MATHLIB_QUATERNION_HPP
#define MATHLIB_QUATERNION_HPP

#include "Implementation/Quaternion.hpp"
#include "Implementation/QuaternionOperators.hpp"
#include "Implementation/QuaternionUtilities.hpp"

#include "Matrix.hpp"

// TODO(3011): Reimplement this class to follow the same conventions
// as other classes in MathLib.

// TODO(3011): It might be nicer for the quaternion to return a transform
// instead of a matrix.

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

    static_assert(ConceptQuaternion<Quaternionf>);
    static_assert(ConceptQuaternion<Quaterniond>);
}

#endif //MATHLIB_QUATERNION_HPP
