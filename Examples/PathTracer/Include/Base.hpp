#ifndef MATHLIB_EXAMPLES_PATHTRACER_BASE_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_BASE_HPP

#include <Math/Base.hpp>
#include <Math/Vector.hpp>
#include <Math/Point.hpp>
#include <Math/Matrix.hpp>
#include <Math/Transform.hpp>
#include <Math/Geometry.hpp>
#include <Math/Random.hpp>

namespace PathTracer
{
    using namespace Math::Types;

    using Math::Vector2ul;
    using Math::Vector2f;
    using Math::Vector3f;
    using Math::Point3f;

    using Math::Matrix4f;
    using Math::Transform3f;

    using RNG = Math::Random64;

    using Ray = Math::Geometry::Ray<f32>;
    using Sphere = Math::Geometry::Sphere<f32>;
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_BASE_HPP
