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

    using Vector2uc = Vector2T< u8>;
    using Vector3uc = Vector3T< u8>;
    using Vector4uc = Vector4T< u8>;

    using Vector2us = Vector2T<u16>;
    using Vector3us = Vector3T<u16>;
    using Vector4us = Vector4T<u16>;

    using Vector2u = Vector2T<u32>;
    using Vector3u = Vector3T<u32>;
    using Vector4u = Vector4T<u32>;

    using Vector2ul = Vector2T<u64>;
    using Vector3ul = Vector3T<u64>;
    using Vector4ul = Vector4T<u64>;

    using Vector2sz = Vector2T<SizeType>;
    using Vector3sz = Vector3T<SizeType>;
    using Vector4sz = Vector4T<SizeType>;

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

    static_assert(Concept::Vector2<Vector2uc>);
    static_assert(Concept::Vector3<Vector3uc>);
    static_assert(Concept::Vector4<Vector4uc>);

    static_assert(Concept::Vector2<Vector2us>);
    static_assert(Concept::Vector3<Vector3us>);
    static_assert(Concept::Vector4<Vector4us>);

    static_assert(Concept::Vector2<Vector2u>);
    static_assert(Concept::Vector3<Vector3u>);
    static_assert(Concept::Vector4<Vector4u>);

    static_assert(Concept::Vector2<Vector2ul>);
    static_assert(Concept::Vector3<Vector3ul>);
    static_assert(Concept::Vector4<Vector4ul>);
}

#endif //MATHLIB_VECTOR_HPP
