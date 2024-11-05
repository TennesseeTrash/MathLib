#ifndef MATHLIB_EXAMPLES_PATHTRACER_SAMPLING_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_SAMPLING_HPP

#include "Base.hpp"

// TODO(3011): These functions are prime candidates for addition in the main library.
// However, the interface should include the PDFs as well to make life simpler for
// users.

namespace PathTracer
{
    Vector2f SampleTriangle(RNG& rng);
    Point3f SampleTriangle(RNG& rng, Triangle& triangle);
    Point3f SampleSphere(RNG& rng);
    Point3f SampleSphere(RNG& rng, const Sphere& sphere);
    Point3f SampleHemisphere(RNG& rng);
    Point3f SampleHemisphereCosWeighted(RNG& rng);
    Point3f SampleLobe(RNG& rng, f32 exp);
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_SAMPLING_HPP
