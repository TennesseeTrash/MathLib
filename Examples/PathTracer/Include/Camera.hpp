#ifndef MATHLIB_EXAMPLES_PATHTRACER_CAMERA_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_CAMERA_HPP

#include "Base.hpp"

namespace PathTracer
{
    class Camera
    {
    public:
        Camera(const Point3f& position, const Vector3f& direction, const Vector2sz& resolution, f32 fov);

        Ray GenerateRay(const Vector2f& screenSample) const;
    private:
        Point3f   mPosition;
        Matrix4f  mScreenToWorld;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_CAMERA_HPP
