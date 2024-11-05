#ifndef MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP

#include "Base.hpp"

namespace PathTracer
{
    struct MaterialSample
    {
        Vector3f OutgoingDirection;
        Vector3f Intensity;
        f32 PDF;
    };

    class Material
    {
    public:
        Material(const Vector3f& reflectance);

        MaterialSample Sample(RNG& rng, const Vector3f& incomingDirection) const;

        Vector3f BRDF(const Vector3f& incomingDirection, const Vector3f& outgoingDirection) const;
        f32 PDF(const Vector3f& incomingDirection, const Vector3f& outgoingDirection) const;
    private:
        Vector3f mReflectance;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP
