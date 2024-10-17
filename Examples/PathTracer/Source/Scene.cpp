#include "Scene.hpp"

namespace PathTracer
{
    bool Scene::Intersection::IsValid()
    {
        return Distance == Distance;
    }

    Scene::Scene()
        : mPlane({0.0f, 4.0f, 0.0f}, {0.0f, -1.0f, 0.0f}),
          mObjects{{{0.0f, 0.0f, 0.0f}, 1.0f}, {{2.0f, 1.0f, 5.0f}, 2.5f}, {{-1.0f, -1.0f, 10.0f}, 5.0f}},
          mLights{{{0.0f, -4.0f, -5.0f}, {1.0f, 1.0f, 1.0f}},},// {{-8.0f, -5.0f, 0.0f}, {0.1f, 1.0f, 1.0f}}},
          mMaterials{Material({0.5f, 0.8f, 0.1f})}
    {}

    Scene::Intersection Scene::Intersect(const Ray& ray, const Interval& interval) const
    {
        using BasicIntersection = Math::Geometry::Intersection<f32>;
        BasicIntersection nearest = Math::Geometry::NearestIntersection(ray, interval, mPlane);
        SizeType nearestIndex = SizeType::Max();

        for (SizeType i = 0; i < mObjects.size(); ++i)
        {
            BasicIntersection candidate = Math::Geometry::NearestIntersection(ray, interval, mObjects[Math::ToUnderlying(i)]);
            if (!nearest.IsValid() || nearest.Distance > candidate.Distance)
            {
                nearest = candidate;
                nearestIndex = i;
            }
        }

        if (nearest.IsValid())
        {
            if (nearestIndex == SizeType::Max())
            {
                return {
                    .Distance = nearest.Distance,
                    .Normal = mPlane.SurfaceNormal(ray.Project(nearest.Distance)),
                    .Material = mMaterials[0]
                };
            }

            return {
                .Distance = nearest.Distance,
                .Normal = mObjects[Math::ToUnderlying(nearestIndex)].SurfaceNormal(ray.Project(nearest.Distance)),
                .Material = mMaterials[0]
            };
        }

        return {
            .Distance = f32::NaN(),
            .Normal = Vector3f(0.0f),
            .Material = mMaterials[0]
        };
    }

    bool Scene::HasIntersection(const Ray& ray, const Interval& interval) const
    {
        if (Math::Geometry::NearestIntersection(ray, interval, mPlane))
        {
            return true;
        }

        for (SizeType i = 0; i < mObjects.size(); ++i)
        {
            if (Math::Geometry::NearestIntersection(ray, interval, mObjects[Math::ToUnderlying(i)]))
            {
                return true;
            }
        }

        return false;
    }

    std::span<const PointLight> Scene::GetLights() const
    {
        return mLights;
    }
}
