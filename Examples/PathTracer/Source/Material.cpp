#include "Material.hpp"
#include "Sampling.hpp"

namespace PathTracer
{
    Material::Material(const Vector3f& reflectance)
        : mReflectance(reflectance)
    {}

    MaterialSample Material::Sample(RNG& rng, const Vector3f& incomingDirection) const
    {
        Vector3f outgoingDirection = Vector3f(SampleHemisphereCosWeighted(rng));
        return {
            .OutgoingDirection = outgoingDirection,
            .Intensity = BRDF(incomingDirection, outgoingDirection),
            .PDF = PDF(incomingDirection, outgoingDirection)
        };
    }

    Vector3f Material::BRDF([[maybe_unused]] const Vector3f& incomingDirection, [[maybe_unused]] const Vector3f& outgoingDirection) const
    {
        return mReflectance / Math::Constant::Pi<f32>;
    }

    f32 Material::PDF(const Vector3f& incomingDirection, const Vector3f& outgingDirection) const
    {
        // TODO(3011): Not sure if this is completely correct.
        return 1.0f / Math::Constant::Pi<f32>;
    }
}
