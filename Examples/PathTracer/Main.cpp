#include "Base.hpp"
#include "Camera.hpp"
#include "Framebuffer.hpp"
#include "Light.hpp"
#include "Material.hpp"
#include "Scene.hpp"

#include <iostream>
#include <mutex>
#include <thread>

int main(int argc, char **argv)
{
    std::cout << "Hello, world!" << std::endl;

    using namespace Math::Types;

    Math::Vector2sz resolution(1920, 1080);

    PathTracer::RNG commonRng(15);
    Math::UniformUnitDistribution<f32> dist;

    // "Scene"
    PathTracer::Scene scene(resolution);

    PathTracer::Framebuffer fb(resolution.x, resolution.y);
    std::mutex fbMutex;

    std::vector<std::thread> threads;
    SizeType hwThreads = std::thread::hardware_concurrency();
    SizeType totalSamples = 4;
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
        threads.push_back(std::thread([samples, rng, resolution, &scene, &fb, &fbMutex]() mutable {
            PathTracer::Uniform dist;
            PathTracer::Framebuffer localFramebuffer(fb.Size());
            for (SizeType sample = 0; sample < samples; ++sample)
            {
                for (SizeType y = 0; y < resolution.y; ++y)
                {
                    for (SizeType x = 0; x < resolution.x; ++x)
                    {
                        f32 xf = Math::Cast<f32>(x) + dist(rng);
                        f32 yf = Math::Cast<f32>(y) + dist(rng);
                        PathTracer::Ray ray = scene.GetCamera().GenerateRay({xf, yf});

                        using Intersection = PathTracer::Scene::Intersection;
                        Intersection intersection = scene.Intersect(ray, {});

                        PathTracer::Vector3f accumulator(0.0f);
                        PathTracer::Vector3f throughput(1.0f);
                        SizeType bounce = 0;
                        while (true)
                        {
                            if (!intersection.IsValid())
                            {
                                // HDRI handling goes here.
                                break;
                            }

                            PathTracer::Point3f intersectedPoint = ray.Project(intersection.Distance);
                            PathTracer::Transform3f intersectedBase = Math::OrthonormalBaseFromZ(intersection.Normal);
                            PathTracer::Vector3f incomingDirection = intersectedBase * -ray.Direction;

                            if (intersection.Light)
                            {
                                PathTracer::Vector3f intensity = intersection.Light->Sample(rng, ray.Origin).Intensity;
                                if (bounce == 0 && intensity.Max() > 0.0f)
                                {
                                    accumulator += intensity;
                                }
                                break;
                            }

                            PathTracer::Vector3f mis(0.0f);
                            {   // Explicit lightsource sampling
                                for (const auto& light : scene.GetLights())
                                {
                                    PathTracer::LightSample sample = light.Sample(rng, intersectedPoint);
                                    PathTracer::Ray lightRay(intersectedPoint, sample.OutgoingDirection);
                                    PathTracer::Vector3f outgoingDirection = intersectedBase * sample.OutgoingDirection;
                                    f32 cosTheta = Math::Dot(intersection.Normal, lightRay.Direction);
                                    f32 brdfPdf = Math::Equal(sample.PDF, 1.0f) ? 0.0f : intersection.Material->PDF(incomingDirection, outgoingDirection);
                                    if (cosTheta > 0.0f && sample.Intensity.Max() > 0.0f && !scene.HasIntersection(lightRay, {Math::Constant::GeometryEpsilon<f32>, sample.Distance - 2.0f * Math::Constant::GeometryEpsilon<f32>}))
                                    {
                                        mis += (intersection.Material->BRDF(incomingDirection, outgoingDirection) * sample.Intensity * cosTheta) / (sample.PDF + brdfPdf);
                                    }
                                }
                            }
                            {   // BRDF sampling
                                PathTracer::MaterialSample sample = intersection.Material->Sample(rng, incomingDirection);
                                PathTracer::Vector3f outgoingDirection = sample.OutgoingDirection * intersectedBase;
                                f32 cosTheta = Math::Dot(intersection.Normal, outgoingDirection);

                                ray = PathTracer::Ray(intersectedPoint, outgoingDirection);
                                intersection = scene.Intersect(ray, {Math::Constant::GeometryEpsilon<f32>});

                                if (intersection.Light && cosTheta > 0.0f && sample.Intensity.Max() > 0.0f)
                                {
                                    PathTracer::Point3f lightPoint = ray.Project(intersection.Distance);
                                    mis += sample.Intensity * intersection.Light->Evaluate(intersectedPoint, lightPoint) * cosTheta / (sample.PDF + intersection.Light->PDF(intersectedPoint, lightPoint));
                                }

                                accumulator += throughput * mis;
                                throughput *= sample.Intensity * cosTheta / sample.PDF;
                            }


                            // Russian roulette
                            f32 survive = Math::Min(throughput.Max(), f32(1.0f));
                            if (dist(rng) < survive)
                            {
                                throughput /= survive;
                            }
                            else
                            {
                                break;
                            }

                            ++bounce;
                        }

                        localFramebuffer(x, y) += accumulator;
                    }
                }
            }

            {
                std::lock_guard lock(fbMutex);
                fb.Add(localFramebuffer);
            }
        }));
    }

    // We need to wait for the computation in all threads to finish.
    for (SizeType i = 0; i < threads.size(); ++i)
    {
        threads[Math::ToUnderlying(i)].join();
    }

    fb.Scale(1.0f / Math::Cast<f32>(totalSamples));
    // Note(3011): Flipping the Y axis description in the image file would be
    // better, but tev (the viewer) unfortunately does not support this.
    // We do this to make it more obvious that we follow the right hand rule.
    fb.Flip();
    fb.Save("test.hdr");
    return 0;
}
