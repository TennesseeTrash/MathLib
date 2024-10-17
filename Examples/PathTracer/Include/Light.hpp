#ifndef MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP

#include "Base.hpp"

namespace PathTracer
{
    class PointLight
    {
    public:
        PointLight(const Point3f& position, const Vector3f& colour);

        Point3f SamplePoint(RNG& rng) const;

        Vector3f Evaluate(const Point3f& distantPoint) const;
    private:
        Point3f  mPosition;
        Vector3f mColour;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP
