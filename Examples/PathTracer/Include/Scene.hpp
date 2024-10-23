#ifndef MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP

#include "Base.hpp"
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
            bool IsValid();

            f32 Distance;
            Vector3f Normal;
            const Material* Material;
        };

        class Object
        {
        public:
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
                        .Material = nullptr
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
            Object(const ObjectType& object)
                : mObject(std::make_unique<ObjectContainer<ObjectType>>(object))
            {}

            Object(Object&& other) noexcept = default;
            Object& operator=(Object&& other) noexcept = default;
            ~Object() noexcept = default;

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
        };

        Scene();

        Intersection Intersect(const Ray& ray, const Interval& interval) const;
        bool HasIntersection(const Ray& ray, const Interval& interval) const;

        std::span<const PointLight> GetLights() const;
    private:
        std::vector<Object> mObjects;
        std::vector<PointLight> mLights;
        std::vector<Material> mMaterials;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
