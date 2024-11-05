#include "Sampling.hpp"

namespace PathTracer
{
    Vector2f SampleTriangle(RNG& rng)
    {
        Uniform dist;
        f32 u = Math::Sqrt(dist(rng));
        f32 v = dist(rng) * u;
        return {1.0f - u, v};
    }

    Point3f SampleTriangle(RNG& rng, Triangle& triangle)
    {
        Vector2f barycentric = SampleTriangle(rng);
        Vector3f a = Vector3f(triangle.A) * barycentric.x;
        Vector3f b = Vector3f(triangle.B) * barycentric.y;
        Vector3f c = Vector3f(triangle.C) * (1 - barycentric.x - barycentric.y);
        return Point3f(a + b + c);
    }

    Point3f SampleSphere(RNG& rng)
    {
        Uniform dist;
        f32 z = 1.0f - (2.0f * dist(rng));
        f32 r = Math::Sqrt(Math::Max(f32(0.0f), 1.0f - Math::Squared(z)));
        f32 phi = Math::Constant::Tau<f32> * dist(rng);

        Point3f position;
        position.x = Math::Cos(phi) * r;
        position.y = Math::Sin(phi) * r;
        position.z = z;
        return position;
    }

    Point3f SampleSphere(RNG& rng, const Sphere& sphere)
    {
        Point3f unitSphere = SampleSphere(rng);

        Point3f position(sphere.Center);
        position.x += sphere.Radius * unitSphere.x;
        position.y += sphere.Radius * unitSphere.y;
        position.z += sphere.Radius * unitSphere.z;
        return position;
    }

    Point3f SampleHemisphere(RNG& rng)
    {
        Uniform dist;
        f32 z = dist(rng);
        f32 r = Math::Sqrt(Math::Max(f32(0.0f), 1.0f - Math::Squared(z)));
        f32 phi = Math::Constant::Tau<f32> * dist(rng);

        Point3f position;
        position.x = Math::Cos(phi) * r;
        position.y = Math::Sin(phi) * r;
        position.z = z;
        return position;
    }

    Point3f SampleHemisphereCosWeighted(RNG &rng)
    {
        Uniform dist;
        f32 r1 = dist(rng);
        f32 r2 = dist(rng);

        f32 r = Math::Sqrt(1.0f - r2);
        f32 phi = Math::Constant::Tau<f32> * r1;

        Point3f position;
        position.x = Math::Cos(phi) * r;
        position.y = Math::Sin(phi) * r;
        position.z = Math::Sqrt(r2);
        return position;
    }

    Point3f SampleLobe(RNG &rng, f32 exp)
    {
        Uniform dist;
        f32 r1 = dist(rng);
        f32 r2 = dist(rng);

        f32 r = Math::Sqrt(1.0f - Math::Pow(r2, 2.0f / (exp + 1.0f)));
        f32 phi = Math::Constant::Tau<f32> * r1;

        Point3f position;
        position.x = Math::Cos(phi) * r;
        position.y = Math::Sin(phi) * r;
        position.z = Math::Pow(r2, 1.0f / (exp + 1.0f));
        return position;
    }
}
