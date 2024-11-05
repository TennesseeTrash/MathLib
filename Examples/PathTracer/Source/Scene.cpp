#include "Scene.hpp"
#include "Light.hpp"

namespace PathTracer
{
    bool Scene::Intersection::IsValid() const
    {
        return Distance == Distance;
    }

    bool Scene::Object::Intersection::IsValid() const
    {
        return Distance == Distance;
    }

    Scene::Object::Intersection Scene::Object::Intersect(const Ray& ray, const Interval& interval) const noexcept
    {
        Object::Intersection intersection = mObject->Intersect(ray, interval);
        if (intersection.IsValid())
        {
            intersection.MaterialIndex = mMaterialIndex;
        }
        return intersection;
    }

    bool Scene::Object::HasIntersection(const Ray& ray, const Interval& interval) const noexcept
    {
        return mObject->HasIntersection(ray, interval);
    }

    Scene::Scene(const Vector2sz& resolution)
        : mCamera({0.0f, 0.5f, -2.0f}, {0.0f, 0.0f, 1.0f}, resolution, Math::ToRadians<f32>(90.0f)),
          mObjects{},
          mLights{},
          mMaterials{Material({0.99f, 0.1f, 0.1f}), Material({0.1f, 0.1f, 0.99f}), Material({0.99f, 0.99f, 0.99f}), Material({0.1f, 0.89f, 0.1f})}
    {
        // Note(3011): I really don't like this but it doesn't matter much because it's just init code anyway.
        mObjects.push_back({Sphere({0.0f, 0.0f, 0.0f}, 0.2f), 0});
        mObjects.push_back({Sphere({0.8f, -0.2f, 0.6f}, 0.50f), 0});
        mObjects.push_back({Sphere({-0.5f, 0.2f, 1.0f}, 0.75f), 3});
        mObjects.push_back({Plane({0.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}), 2});
        mObjects.push_back({Plane({0.0f, 0.0f,2.0f}, {0.0f, 0.0f, -1.0f}), 2});
        mObjects.push_back({Plane({-1.5f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}), 2});
        mObjects.push_back({Triangle({1.5f, 0.0f, 0.0f}, {1.5f, 0.0f, 1.0f}, {1.5f, 2.0f, 1.0f}), 1});

        // Point light
        // mLights.push_back({PointLight({0.8f, 0.8f, 0.0f}, Vector3f(15.0f))});

        // (Spherical) Area light.
        mObjects.push_back({Sphere({{0.8f, 0.8f, 0.0f}, 0.2f}), 1000});
        mLights.push_back({SphericalLight({{0.8f, 0.8f, 0.0f}, 0.2f}, Vector3f(15.0f))});
    }

    Scene::Intersection Scene::Intersect(const Ray& ray, const Interval& interval) const
    {
        Object::Intersection nearest = mObjects[0].Intersect(ray, interval);
        SizeType nearestIndex = 0;

        for (SizeType i = 1; i < mObjects.size(); ++i)
        {
            Object::Intersection candidate = mObjects[Math::ToUnderlying(i)].Intersect(ray, interval);
            if (!nearest.IsValid() || nearest.Distance > candidate.Distance)
            {
                nearest = candidate;
                nearestIndex = i;
            }
        }

        return {
            .Distance = nearest.Distance,
            .Normal = nearest.Normal,
            .Material = nearest.MaterialIndex != 1000 ? &mMaterials[Math::ToUnderlying(nearest.MaterialIndex)] : nullptr,
            .Light = nearest.MaterialIndex != 1000 ? nullptr : &mLights[0],
        };
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

    std::span<const Light> Scene::GetLights() const
    {
        return mLights;
    }
}
