#include "Camera.hpp"
#include "Framebuffer.hpp"

#include <Math/Geometry.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    using namespace Math::Types;
    using Intersection = Math::Geometry::Intersection<f32>;

    PathTracer::RNG rng(12);
    Math::UniformUnitDistribution<f32> dist;

    // "Scene"
    PathTracer::Sphere s({0.0f, 0.0f, 0.0f}, 1.0f);

    PathTracer::Camera cam({0.0f, 0.0f, -3.0f}, {0.0f, 0.0f, 1.0f}, {512, 512}, Math::ToRadians<f32>(90.0f));
    PathTracer::Framebuffer fb(512, 512);

    // This is the stand-in for an actual light for now.
    Math::Vector3f light = Math::Normalize(Math::Vector3f(0.5f, -1.0f, -0.8f));

    using PathTracer::SizeType;
    for (SizeType samples = 0; samples <= 1000; ++samples)
    {
        std::cout << Math::ToUnderlying(samples) << "\n";

        for (SizeType y = 0; y < 512; ++y)
        {
            for (SizeType x = 0; x < 512; ++x)
            {
                f32 xf = Math::Cast<f32>(x) + dist(rng);
                f32 yf = Math::Cast<f32>(y) + dist(rng);
                PathTracer::Ray ray = cam.GenerateRay({xf, yf});
                Intersection i = Math::Geometry::NearestIntersection(ray, {}, s);

                if (i)
                {
                    fb(x, y) = Math::Vector3f(0.0f, 1.0f, 0.0f) * Math::Dot(light, i.Normal);
                }
                else
                {
                    fb(x, y) = {0.1f, 0.3f, 0.7f};
                }
            }
        }
    }

    fb.Save("test.hdr");
    return 0;
}
