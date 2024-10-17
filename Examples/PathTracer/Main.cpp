#include "Base.hpp"
#include "Camera.hpp"
#include "Framebuffer.hpp"
#include "Light.hpp"
#include "Math/Implementation/TransformUtilities.hpp"
#include "Math/Vector.hpp"
#include "Scene.hpp"

#include <iostream>
#include <thread>
#include <mutex>

int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    using namespace Math::Types;

    PathTracer::RNG commonRng(15);
    Math::UniformUnitDistribution<f32> dist;

    // "Scene"
    PathTracer::Scene scene;

    PathTracer::Camera cam({0.0f, 0.0f, -3.0f}, {0.0f, 0.0f, 1.0f}, {512, 512}, Math::ToRadians<f32>(90.0f));
    PathTracer::Framebuffer fb(512, 512);
    std::mutex fbMutex;

    std::vector<std::thread> threads;
    SizeType hwThreads = std::thread::hardware_concurrency();
    SizeType totalSamples = 1000;
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
        threads.push_back(std::thread([samples, rng, &scene, &cam, &fb, &fbMutex]() mutable {
            Math::UniformUnitDistribution<f32> dist;
            PathTracer::Framebuffer localFramebuffer(fb.Size());
            for (SizeType sample = 0; sample < samples; ++sample)
            {
                for (SizeType y = 0; y < 512; ++y)
                {
                    for (SizeType x = 0; x < 512; ++x)
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
                                PathTracer::Ray lightRay(intersectedPoint, light.SamplePoint(rng) - intersectedPoint);
                                PathTracer::Vector3f outgoingDirection = intersectedBase * lightRay.Direction;
                                if (!scene.HasIntersection(lightRay, {Math::Constant::GeometryEpsilon<f32>, i.Distance}))
                                {
                                    localFramebuffer(x, y) += i.Material.BRDF(incomingDirection, outgoingDirection) * light.Evaluate(intersectedPoint) * cosTheta;
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
