#include "Light.hpp"

namespace PathTracer
{
    PointLight::PointLight(const Point3f& position, const Vector3f& colour)
        : mPosition(position), mColour(colour)
    {}

    Point3f PointLight::SamplePoint(RNG& rng) const
    {
        return mPosition;
    }

    Vector3f PointLight::Evaluate(const Point3f& distantPoint) const
    {
        Vector3f direction = distantPoint - mPosition;
        Vector3f intensity = mColour / direction.LenSqr();
        return intensity;
    }
}
