#ifndef MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP

#include "Base.hpp"

namespace PathTracer
{
    class Material
    {
    public:
        Material(const Vector3f& reflectance);

        Vector3f BRDF(const Vector3f& incomingDirection, const Vector3f& outgoingDirection) const;
    private:
        Vector3f mReflectance;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_MATERIAL_HPP
