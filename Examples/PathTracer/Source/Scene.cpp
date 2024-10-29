#include "Scene.hpp"
#include "Material.hpp"

namespace PathTracer
{
    bool Scene::Intersection::IsValid()
    {
        return Distance == Distance;
    }

    Scene::Intersection Scene::Object::Intersect(const Ray& ray, const Interval& interval) const noexcept
    {
        return mObject->Intersect(ray, interval);
    }

    bool Scene::Object::HasIntersection(const Ray& ray, const Interval& interval) const noexcept
    {
        return mObject->HasIntersection(ray, interval);
    }

    Scene::Scene(const Vector2sz& resolution)
        : mCamera({0.0f, 0.5f, -2.0f}, {0.0f, 0.0f, 1.0f}, resolution, Math::ToRadians<f32>(90.0f)),
          mObjects{},
          mLights{{{0.8f, 0.8f, 0.0f}, Vector3f(10.0f)}},
          mMaterials{Material({0.8f, 0.8f, 0.5f})}
    {
        // Note(3011): I really don't like this but it doesn't matter much because it's just init code anyway.
        mObjects.push_back(Sphere({0.0f, 0.0f, 0.0f}, 0.2f));
        mObjects.push_back(Sphere({0.8f, -0.2f, 0.6f}, 0.50f));
        mObjects.push_back(Sphere({-0.5f, 0.2f, 1.0f}, 0.75f));
        mObjects.push_back(Plane({0.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}));
        mObjects.push_back(Plane({0.0f, 0.0f,2.0f}, {0.0f, 0.0f, -1.0f}));
        mObjects.push_back(Plane({-1.5f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}));
        mObjects.push_back(Triangle({1.5f, 0.0f, 0.0f}, {1.5f, 0.0f, 1.0f}, {1.5f, 2.0f, 1.0f}));
    }

    Scene::Intersection Scene::Intersect(const Ray& ray, const Interval& interval) const
    {
        Intersection nearest = mObjects[0].Intersect(ray, interval);
        SizeType nearestIndex = 0;

        for (SizeType i = 1; i < mObjects.size(); ++i)
        {
            Intersection candidate = mObjects[Math::ToUnderlying(i)].Intersect(ray, interval);
            if (!nearest.IsValid() || nearest.Distance > candidate.Distance)
            {
                nearest = candidate;
                nearestIndex = i;
            }
        }

        nearest.Material = &mMaterials[0];
        return nearest;
    }

    bool Scene::HasIntersection(const Ray& ray, const Interval& interval) const
    {
        for (const auto& object : mObjects)
        {
            if (object.HasIntersection(ray, interval))
            {
                return true;
            }
        }

        return false;
    }

    const Camera& Scene::GetCamera() const
    {
        return mCamera;
    }

    std::span<const PointLight> Scene::GetLights() const
    {
        return mLights;
    }
}
