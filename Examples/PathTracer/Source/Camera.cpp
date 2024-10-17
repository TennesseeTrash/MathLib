#include "Camera.hpp"

namespace PathTracer
{
    Camera::Camera(const Point3f& position, const Vector3f& direction, const Vector2ul& resolution, f32 fov)
        : mPosition(position), mScreenToWorld{}
    {
        Vector2f fres = Vector2f(Math::Cast<f32>(resolution.x), Math::Cast<f32>(resolution.y));

        f32 aspectRatio = fres.x / fres.y;
        Matrix4f perspectiveTransform = Math::PerspectiveProjection(fov, aspectRatio, f32(0.1f), f32(10000.0f)).ToMatrix();
        Matrix4f worldToCamera = perspectiveTransform * Math::LookAt(position, direction).ToMatrix();

        Matrix4f toWorldAdjust = (
            Math::Translate(Vector3f(-1.0f, -1.0f, 0.0f)) *
            Math::Scale(Vector3f(2.0f / fres.x, 2.0f / fres.y, 0.0f))).ToMatrix();

        mScreenToWorld = Math::Invert(worldToCamera) * toWorldAdjust;
    }

    Ray Camera::GenerateRay(const Vector2f& screenSample) const
    {
        Point3f worldScreen = mScreenToWorld * Point3f(screenSample);
        return Ray(mPosition, Math::Normalize(worldScreen - mPosition));
    }
}
