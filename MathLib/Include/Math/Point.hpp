#ifndef MATHLIB_POINT_HPP
#define MATHLIB_POINT_HPP

#include "Implementation/Point.hpp"
#include "Implementation/PointOperators.hpp"
#include "Implementation/PointUtilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Point2f = Point2T<f32>;
    using Point3f = Point3T<f32>;

    using Point2d = Point2T<f64>;
    using Point3d = Point3T<f64>;

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(ConceptPoint2<Point2f>);
    static_assert(ConceptPoint3<Point3f>);

    static_assert(ConceptPoint2<Point2d>);
    static_assert(ConceptPoint3<Point3d>);
}

#endif //MATHLIB_POINT_HPP
