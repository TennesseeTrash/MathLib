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

    class FirstPersonCamera
    {
    public:
        FirstPersonCamera()
            : mView(1.0f), mInverseView(1.0f)
        {}

        FirstPersonCamera(const Vector3f& position, const Vector3f& direction, const Vector3f& up)
            : mView(Transform::LookAt(position, direction, up)), mInverseView(Transpose(Invert(mView)))
        {}

        void Update(float deltaTime, MovementDirection movementDirection, const Vector3f& deltaViewDirection)
        {
            auto tempView = mInverseView;
            tempView[3] = Vector4f(0.0f);
            Vector4f& aside    = tempView[0];
            Vector4f& up       = tempView[1];
            Vector4f& dir      = tempView[2];
            Vector4f& position = tempView[3];

            float pitch = std::asin(dir.y)         - deltaViewDirection.x * mSensitivity * deltaTime;
            float yaw   = std::atan2(dir.z, dir.x) - deltaViewDirection.y * mSensitivity * deltaTime;

            if (Abs(pitch) > ToRadians(89.9f))
            {
                pitch = Sign(pitch) * ToRadians(89.9f);
            }

            dir.x = std::cos(pitch) * std::cos(yaw);
            dir.y = std::sin(pitch);
            dir.z = std::cos(pitch) * std::sin(yaw);
            dir   = Vector4f(Normalize(Vector3f(dir.x, dir.y, dir.z)));

            if (movementDirection & MovementDirections::Forward)
            {
                position += dir * mMovementSpeed * deltaTime;
            }
            if (movementDirection & MovementDirections::Backward)
            {
                position -= dir * mMovementSpeed * deltaTime;
            }
            if (movementDirection & MovementDirections::Left)
            {
                position += aside * mMovementSpeed * deltaTime;
            }
            if (movementDirection & MovementDirections::Right)
            {
                position -= aside * mMovementSpeed * deltaTime;
            }
            if (movementDirection & MovementDirections::Up)
            {
                position += up * mMovementSpeed * deltaTime;
            }
            if (movementDirection & MovementDirections::Down)
            {
                position -= up * mMovementSpeed * deltaTime;
            }

            mInverseView[0] = Vector4f(Normalize(Cross(Vector3f(0.0f, 1.0f, 0.0f), Vector3f(dir.x, dir.y, dir.z))));
            mInverseView[1] = Vector4f(Normalize(Cross(Vector3f(dir.x, dir.y, dir.z), Vector3f(mInverseView[0][1], mInverseView[0][1], mInverseView[0][2]))));
            mInverseView[2] = Vector4f(Normalize(Vector3f(dir.x, dir.y, dir.z)));
            mInverseView[3] = position;
            mInverseView = mInverseView;
            mView = Transpose(Invert(mInverseView));
        }

        void SetView(const Vector3f& position, const Vector3f& direction, const Vector3f& up)
        {
            mView = Transform::LookAt(position, direction, up);
            mInverseView = Transpose(Invert(mView));
        }

        void SetPosition(const Vector3f& newPosition)
        {
            Vector4f& aside = mInverseView[0];
            Vector4f& dir   = mInverseView[2];
            mInverseView[3] = Vector4f(newPosition, 1.0f);
            mInverseView[0] = Vector4f(Normalize(Cross(Vector3f(0.0f, 1.0f, 0.0f), Vector3f(dir.x, dir.y, dir.z))));
            mInverseView[1] = Vector4f(Normalize(Cross(Vector3f(dir.x, dir.y, dir.z), Vector3f(aside.x, aside.y, aside.z))));
            mInverseView[2] = Vector4f(Normalize(Vector3f(dir.x, dir.y, dir.z)));
            mView = Transpose(Invert(mInverseView));
        }

        void SetMovementSpeed(float movementSpeed) { mMovementSpeed = movementSpeed; }
        void SetSensitivity(float lookSensitivity) { mSensitivity = lookSensitivity; }

        const Matrix4f& GetViewMatrix    () const { return mView; }
              Vector4f  GetPosition      () const { return {mView[0][3], mView[1][3], mView[2][3], 0.0f}; }
              Vector4f  GetViewDirection () const { return {mView[0][2], mView[1][2], mView[2][3], 0.0f}; }
    private:
        Matrix4f mView;
        Matrix4f mInverseView;

        float mMovementSpeed = 1.0f;
        float mSensitivity   = 1.0f;
    };
}

#endif // _MATH_UTILS_CAMERA_HPP
