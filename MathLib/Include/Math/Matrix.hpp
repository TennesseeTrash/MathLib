#ifndef MATHLIB_MATRIX_HPP
#define MATHLIB_MATRIX_HPP

#include "Common/Types.hpp"
#include "Implementation/Matrix2.hpp"
#include "Implementation/Matrix3.hpp"
#include "Implementation/Matrix4.hpp"
#include "Implementation/MatrixOperators.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Matrix2f = Matrix2T<f32>;
    using Matrix3f = Matrix3T<f32>;
    using Matrix4f = Matrix4T<f32>;

    using Matrix2d = Matrix2T<f64>;
    using Matrix3d = Matrix3T<f64>;
    using Matrix4d = Matrix4T<f64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(ConceptMatrix2<Matrix2f>);
    static_assert(ConceptMatrix3<Matrix3f>);
    static_assert(ConceptMatrix4<Matrix4f>);

    static_assert(ConceptMatrix2<Matrix2d>);
    static_assert(ConceptMatrix3<Matrix3d>);
    static_assert(ConceptMatrix4<Matrix4d>);
}

#endif //MATHLIB_MATRIX_HPP
