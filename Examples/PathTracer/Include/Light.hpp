#ifndef MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP

#include "Base.hpp"

#include <memory>

namespace PathTracer
{
    struct LightSample
    {
        Vector3f OutgoingDirection;
        Vector3f Intensity;
        f32 Distance;
        f32 PDF;
    };

    class Light
    {
    public:
        struct GenericLight
        {
        public:
            virtual LightSample Sample(RNG& rng, const Point3f& distantPoint) const = 0;
            virtual Vector3f Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const = 0;
            virtual f32 PDF(const Point3f& distantPoint, const Point3f& lightPoint) const = 0;
            virtual ~GenericLight() {}
        };

        template <typename LightType>
        struct LightContainer : public GenericLight
        {
        public:
            LightContainer(const LightType& light)
                : mLight(light)
            {}

            LightSample Sample(RNG& rng, const Point3f& distantPoint) const override
            {
                return mLight.Sample(rng, distantPoint);
            }

            Vector3f Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const override
            {
                return mLight.Evaluate(distantPoint, lightPoint);
            }

            f32 PDF(const Point3f& distantPoint, const Point3f& lightPoint) const override
            {
                return mLight.PDF(distantPoint, lightPoint);
            }
        private:
            LightType mLight;
        };

        template <typename LightType>
        Light(const LightType& light)
            : mLight(std::make_unique<LightContainer<LightType>>(light))
        {}

        LightSample Sample(RNG& rng, const Point3f& distantPoint) const
        {
            return mLight->Sample(rng, distantPoint);
        }

        Vector3f Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const
        {
            return mLight->Evaluate(distantPoint, lightPoint);
        }

        f32 PDF(const Point3f& distantPoint, const Point3f& lightPoint) const
        {
            return mLight->PDF(distantPoint, lightPoint);
        }
    private:
        std::unique_ptr<GenericLight> mLight;
    };

    class PointLight
    {
    public:
        PointLight(const Point3f& position, const Vector3f& emission);

        LightSample Sample(RNG& rng, const Point3f& distantPoint) const;

        Vector3f Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const;
        f32 PDF(const Point3f& distantPoint, const Point3f& lightPoint) const;
    private:
        Point3f  mPosition;
        Vector3f mEmission;
    };

    class SphericalLight
    {
    public:
        SphericalLight(const Sphere& sphere, const Vector3f& emission);

        LightSample Sample(RNG& rng, const Point3f& distantPoint) const;

        Vector3f Evaluate(const Point3f& distantPoint, const Point3f& lightPoint) const;
        f32 PDF(const Point3f& distantPoint, const Point3f& lightPoint) const;
    private:
        Sphere mSphere;
        Vector3f mEmission;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_LIGHT_HPP
