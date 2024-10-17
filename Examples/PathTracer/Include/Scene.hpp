#ifndef MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP

#include "Base.hpp"
#include "Light.hpp"
#include "Material.hpp"

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
            const Material& Material;
        };

        Scene();

        Intersection Intersect(const Ray& ray, const Interval& interval) const;
        bool HasIntersection(const Ray& ray, const Interval& interval) const;

        std::span<const PointLight> GetLights() const;
    private:
        Plane mPlane;
        std::vector<Sphere> mObjects;
        std::vector<PointLight> mLights;
        std::vector<Material> mMaterials;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_SCENE_HPP
