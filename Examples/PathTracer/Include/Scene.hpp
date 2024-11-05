#ifndef MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP

#include "Base.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Material.hpp"

#include <memory>
#include <span>

namespace PathTracer
{
    class Scene
    {
    public:
        using Interval = Math::Geometry::Interval<f32>;
        struct Intersection
        {
            bool IsValid() const;

            f32 Distance;
            Vector3f Normal;
            const Material* Material;
            const Light* Light;
        };

        class Object
        {
        public:
            struct Intersection
            {
                bool IsValid() const;

                f32 Distance;
                Vector3f Normal;
                SizeType MaterialIndex;
            };

            struct GenericObject
            {
            public:
                virtual Intersection Intersect(const Ray& ray, const Interval& interval) const noexcept = 0;
                virtual bool HasIntersection(const Ray& ray, const Interval& interval) const noexcept = 0;
                virtual ~GenericObject() noexcept {}
            };

            template <typename ObjectType>
            struct ObjectContainer : public GenericObject
            {
            public:
                ObjectContainer(const ObjectType& object)
                    : mObject(object)
                {}

                Intersection Intersect(const Ray& ray, const Interval& interval) const noexcept override
                {
                    using BasicIntersection = Math::Geometry::Intersection<f32>;
                    BasicIntersection nearest = Math::Geometry::NearestIntersection(ray, interval, mObject);
                    return {
                        .Distance = nearest.Distance,
                        .Normal = mObject.SurfaceNormal(ray.Project(nearest.Distance)),
                        .MaterialIndex = 0,
                    };
                }

                bool HasIntersection(const Ray& ray, const Interval& interval) const noexcept override
                {
                    return Math::Geometry::NearestIntersection(ray, interval, mObject).IsValid();
                }
            private:
                ObjectType mObject;
            };

            template <typename ObjectType>
            Object(const ObjectType& object, SizeType materialIndex)
                : mObject(std::make_unique<ObjectContainer<ObjectType>>(object)), mMaterialIndex(materialIndex)
            {}

            Intersection Intersect(const Ray& ray, const Interval& interval) const noexcept;
            bool HasIntersection(const Ray& ray, const Interval& interval) const noexcept;
        private:
            // Note(3011): It might make sense to replace this
            // with a small buffer that can store the objects directly
            // in case they fit, and only use allocations when the object
            // is too large. About 64B should be enough, since that's the
            // size of a cache line, and we don't want to waste too much
            // memory purely on alignment. (8B for vtable (64bit) ptr overhead,
            // 56B of useable space (14 floats ~ 3 points + change).)
            std::unique_ptr<GenericObject> mObject;
            SizeType mMaterialIndex;
        };

        Scene(const Vector2sz& resolution);

        Intersection Intersect(const Ray& ray, const Interval& interval) const;
        bool HasIntersection(const Ray& ray, const Interval& interval) const;

        const Camera& GetCamera() const;
        std::span<const Light> GetLights() const;
    private:
        Camera mCamera;
        std::vector<Object> mObjects;
        std::vector<Light> mLights;
        std::vector<Material> mMaterials;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
