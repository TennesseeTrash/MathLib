#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include "Common/Types.hpp"
#include "Common/Concepts.hpp"
#include "Functions.hpp"

#include "Implementation/Vector2.hpp"
#include "Implementation/Vector3.hpp"
#include "Implementation/Vector4.hpp"
#include "Implementation/Utilities.hpp"

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

    using Vector2i = Vector2T<i32>;
    using Vector3i = Vector3T<i32>;
    using Vector4i = Vector4T<i32>;

    using Vector2l = Vector2T<i64>;
    using Vector3l = Vector3T<i64>;
    using Vector4l = Vector4T<i64>;
}

#endif //MATHLIB_VECTOR_HPP
