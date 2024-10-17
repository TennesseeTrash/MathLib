#include "Material.hpp"

namespace PathTracer
{
    Material::Material(const Vector3f& reflectance)
        : mReflectance(reflectance)
    {}

    Vector3f Material::BRDF(const Vector3f& incomingDirection, const Vector3f& outgoingDirection) const
    {
        //return mReflectance;// / Math::Constant::Pi<f32>;
        return mReflectance * Vector3f(Math::Abs(Math::Dot(Math::Reflect(incomingDirection, Vector3f::UnitZ()), outgoingDirection)));
    }
}
