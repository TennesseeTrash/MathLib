#ifndef MATHLIB_TRANSFORM_HPP
#define MATHLIB_TRANSFORM_HPP

#include "Implementation/Transform.hpp"
#include "Implementation/TransformOperators.hpp"
#include "Implementation/Utilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Transform2f = Transform2T<f32>;
    using Transform3f = Transform3T<f32>;

    using Transform2d = Transform2T<f64>;
    using Transform3d = Transform3T<f64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(ConceptTransform2<Transform2f>);
    static_assert(ConceptTransform3<Transform3f>);

    static_assert(ConceptTransform2<Transform2d>);
    static_assert(ConceptTransform3<Transform3d>);
}

#endif //MATHLIB_TRANSFORM_HPP
