#ifndef _MATH_UTILS_CAMERA_HPP
#define _MATH_UTILS_CAMERA_HPP

#include "Transform.hpp"

namespace cc
{
    using MovementDirection = uint8_t;
    namespace MovementDirections
    {
        enum Direction : MovementDirection
        {
            None     = 0x00,
            Up       = 0x01,
            Down     = 0x02,
            Left     = 0x04,
            Right    = 0x08,
            Forward  = 0x10,
            Backward = 0x20
        };
    }

    class Camera
    {
    public:
        Camera()
        {}

        Camera(const Vector3f& position, const Vector3f& direction, const Vector3f& up)
        {}

        void Update(float deltaTime, MovementDirection movementDirection, const Vector3f& deltaViewDirection) {}

        void SetView(const Vector3f& position, const Vector3f& direction, const Vector3f& up) {}
        void SetPosition(const Vector3f& newPosition) {}
        void SetMovementSpeed(float movementSpeed) {}
        void SetSensitivity(float lookSensitivity) {}

        const Matrix4f& GetViewMatrix() const {}
        const Vector4f& GetPosition() const {}
        const Vector4f& GetViewDirection() const {}
    private:
    };
}

#endif // _MATH_UTILS_CAMERA_HPP
