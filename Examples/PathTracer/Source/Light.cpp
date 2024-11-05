#include "Light.hpp"
#include "Sampling.hpp"

namespace PathTracer
{
    PointLight::PointLight(const Point3f& position, const Vector3f& emission)
        : mPosition(position), mEmission(emission)
    {}

    LightSample PointLight::Sample(RNG& rng, const Point3f& distantPoint) const
    {
        Vector3f direction = mPosition - distantPoint;
        return {
            .OutgoingDirection = Math::Normalize(direction),
            .Intensity = (mEmission / (4.0f * Math::Constant::Pi<f32>)) / direction.LenSqr(),
            .Distance = direction.Length(),
            .PDF = 1.0f
        };
    }

    Vector3f PointLight::Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const
    {
        return mEmission;
    }

    f32 PointLight::PDF([[maybe_unused]] const Point3f& distantPoint, [[maybe_unused]] const Point3f& lightPoint) const
    {
        return 1.0f;
    }


    SphericalLight::SphericalLight(const Sphere& sphere, const Vector3f& emission)
        : mSphere(sphere), mEmission(emission)
    {}

    LightSample SphericalLight::Sample(RNG& rng, const Point3f& distantPoint) const
    {
        // Note(3011): This is the most naive sampling, it's incredibly ineffective, should be replaced later.
        Point3f lightPoint = SampleSphere(rng, mSphere);
        Vector3f direction = lightPoint - distantPoint;
        Vector3f normal = mSphere.SurfaceNormal(lightPoint);
        f32 lambert = Math::Dot(normal, Math::Normalize(direction));
        return {
            .OutgoingDirection = Math::Normalize(direction),
            .Intensity = mEmission / direction.LenSqr() * lambert,
            .Distance = direction.Length(),
            .PDF = PDF(distantPoint, lightPoint),
        };
    }

    Vector3f SphericalLight::Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const
    {
        return mEmission;
    }

    f32 SphericalLight::PDF(const Point3f& distantPoint, const Point3f& lightPoint) const
    {
        return 1.0f / (4.0f * Math::Constant::Pi<f32> * Math::Squared(mSphere.Radius));
    }
}
