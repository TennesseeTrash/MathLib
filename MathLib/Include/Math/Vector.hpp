#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include "Implementation/Base/Types.hpp"
#include "Implementation/Vector.hpp"
#include "Implementation/VectorOperators.hpp"
#include "Implementation/VectorUtilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Vector2f = Vector2T<f32>;
    using Vector3f = Vector3T<f32>;
    using Vector4f = Vector4T<f32>;

    using Vector2d = Vector2T<f64>;
    using Vector3d = Vector3T<f64>;
    using Vector4d = Vector4T<f64>;

    using Vector2c = Vector2T< i8>;
    using Vector3c = Vector3T< i8>;
    using Vector4c = Vector4T< i8>;

    using Vector2s = Vector2T<i16>;
    using Vector3s = Vector3T<i16>;
    using Vector4s = Vector4T<i16>;

    using Vector2i = Vector2T<i32>;
    using Vector3i = Vector3T<i32>;
    using Vector4i = Vector4T<i32>;

    using Vector2l = Vector2T<i64>;
    using Vector3l = Vector3T<i64>;
    using Vector4l = Vector4T<i64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(Concept::Vector2<Vector2f>);
    static_assert(Concept::Vector3<Vector3f>);
    static_assert(Concept::Vector4<Vector4f>);

    static_assert(Concept::Vector2<Vector2d>);
    static_assert(Concept::Vector3<Vector3d>);
    static_assert(Concept::Vector4<Vector4d>);

    static_assert(Concept::Vector2<Vector2i>);
    static_assert(Concept::Vector3<Vector3i>);
    static_assert(Concept::Vector4<Vector4i>);

    static_assert(Concept::Vector2<Vector2l>);
    static_assert(Concept::Vector3<Vector3l>);
    static_assert(Concept::Vector4<Vector4l>);
}

#endif //MATHLIB_VECTOR_HPP
