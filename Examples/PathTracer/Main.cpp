#include "Base.hpp"
#include "Camera.hpp"
#include "Framebuffer.hpp"
#include "Light.hpp"
#include "Scene.hpp"

#include <iostream>
#include <thread>
#include <mutex>

int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    using namespace Math::Types;

    Math::Vector2ul resolution(512, 512);

    PathTracer::RNG commonRng(15);
    Math::UniformUnitDistribution<f32> dist;

    // "Scene"
    PathTracer::Scene scene;

    PathTracer::Camera cam({0.0f, 0.0f, -3.0f}, {0.0f, 0.0f, 1.0f}, resolution, Math::ToRadians<f32>(90.0f));
    PathTracer::Framebuffer fb(resolution.x, resolution.y);
    std::mutex fbMutex;

    std::vector<std::thread> threads;
    SizeType hwThreads = std::thread::hardware_concurrency();
    SizeType totalSamples = 500;
    SizeType samplesRemainder = totalSamples % hwThreads;
    for (SizeType i = 0; i < hwThreads; ++i)
    {
        SizeType samples = totalSamples / hwThreads + ((samplesRemainder > 0) ? 1 : 0);
        if (samplesRemainder > 0)
        {
            --samplesRemainder;
        }
        if (samples == 0)
        {
            continue;
        }
        PathTracer::RNG rng = commonRng.Jump();
        threads.push_back(std::thread([samples, rng, resolution, &scene, &cam, &fb, &fbMutex]() mutable {
            Math::UniformUnitDistribution<f32> dist;
            PathTracer::Framebuffer localFramebuffer(fb.Size());
            for (SizeType sample = 0; sample < samples; ++sample)
            {
                for (SizeType y = 0; y < resolution.y; ++y)
                {
                    for (SizeType x = 0; x < resolution.x; ++x)
                    {
                        f32 xf = Math::Cast<f32>(x) + dist(rng);
                        f32 yf = Math::Cast<f32>(y) + dist(rng);
                        PathTracer::Ray ray = cam.GenerateRay({xf, yf});

                        using Intersection = PathTracer::Scene::Intersection;
                        if (Intersection i = scene.Intersect(ray, {}); i.IsValid())
                        {
                            f32 cosTheta = Math::Dot(i.Normal, -ray.Direction);
                            if (cosTheta <= Math::Cast<f32>(0))
                            {
                                continue;
                            }

                            PathTracer::Point3f intersectedPoint = ray.Project(i.Distance);
                            PathTracer::Transform3f intersectedBase = Math::OrthonormalBaseFromZ(i.Normal);
                            PathTracer::Vector3f incomingDirection = intersectedBase * -ray.Direction;
                            for (const auto& light : scene.GetLights())
                            {
                                PathTracer::Ray lightRay(intersectedPoint, Normalize(light.SamplePoint(rng) - intersectedPoint));
                                PathTracer::Vector3f outgoingDirection = intersectedBase * lightRay.Direction;
                                PathTracer::Vector3f lightIntensity = light.Evaluate(intersectedPoint);
                                if (lightIntensity.Max() > 0.0f && !scene.HasIntersection(lightRay, {Math::Constant::GeometryEpsilon<f32>, i.Distance}))
                                {
                                    localFramebuffer(x, y) += i.Material->BRDF(incomingDirection, outgoingDirection) * lightIntensity * cosTheta;
                                }
                            }
                        }
                    }
                }
            }

            {
                std::lock_guard lock(fbMutex);
                fb.Add(localFramebuffer);
            }
        }));
    }

    // We need to wait for the computation in all the threads to finish.
    for (SizeType i = 0; i < threads.size(); ++i)
    {
        threads[Math::ToUnderlying(i)].join();
    }

    fb.Scale(1.0f / Math::Cast<f32>(totalSamples));
    fb.Save("test.hdr");
    return 0;
}
