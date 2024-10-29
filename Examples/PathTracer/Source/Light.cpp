#include "Light.hpp"

namespace PathTracer
{
    PointLight::PointLight(const Point3f& position, const Vector3f& intensity)
        : mPosition(position), mIntensity(intensity)
    {}

    Point3f PointLight::SamplePoint(RNG& rng) const
    {
        return mPosition;
    }

    Vector3f PointLight::Evaluate(const Point3f& distantPoint) const
    {
        Vector3f direction = distantPoint - mPosition;
        Vector3f intensity = (mIntensity / (4.0f * Math::Constant::Pi<f32>)) / direction.LenSqr();
        return intensity;
    }
}
