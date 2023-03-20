#ifndef _MATH_UTILS_TRANSFORM_HPP
#define _MATH_UTILS_TRANSFORM_HPP

#include "../Matrix.hpp"

namespace cc::Transform
{
    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> Identity() noexcept
    {
        return Matrix4T<T>(1.0f);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> RotateByX(T angle) noexcept
    {
        return Matrix4T<T>(
            T(1),            T(0),             T(0), T(0),
            T(0), std::cos(angle), -std::sin(angle), T(0),
            T(0), std::sin(angle),  std::cos(angle), T(0),
            T(0),            T(0),             T(0), T(1)
        );
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> RotateByY(T angle) noexcept
    {
        return Matrix4T<T>(
             std::cos(angle), T(0), std::sin(angle), T(0),
                        T(0), T(1),            T(0), T(0),
            -std::sin(angle), T(0), std::cos(angle), T(0),
                        T(0), T(0),            T(0), T(1)
        );
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> RotateByZ(T angle) noexcept
    {
        return Matrix4T<T>(
            std::cos(angle), T(0), -std::sin(angle), T(0),
            std::sin(angle), T(0),  std::cos(angle), T(0),
                       T(0), T(0),             T(1), T(0),
                       T(0), T(0),             T(0), T(1)
        );
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> Translate(const Vector3T<T>& direction) noexcept
    {
        Matrix4T<T> result;
        result[0][3] = direction[0];
        result[1][3] = direction[1];
        result[2][3] = direction[2];
        return result;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> Scale(const Vector3T<T>& scales) noexcept
    {
        Matrix4T<T> result;
        result[0][0] = scales[0];
        result[1][1] = scales[1];
        result[2][2] = scales[2];
        return result;
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> LookAt(const Vector3T<T>& position, const Vector3T<T>& direction, const Vector3T<T>& up)
    {
        Vector4T<T> w = Vector4T<T>(-Normalize(direction));
        Vector4T<T> u = Vector4T<T>(Normalize(Cross(up, w)));
        Vector4T<T> v = Vector4T<T>(Cross(w, u));
        Vector4T<T> o = Vector4T<T>(T(0), T(0), T(0), T(1));
        return Matrix4T<T>(u, v, w, o) * Translate(-position);
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> PerspectiveProjection(T fov, T aspectRatio, T near, T far)
    {
        // TODO
    }

    template <typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> OrthographicProjection()
    {
        // TODO
    }
}

#endif //_MATH_UTILS_TRANSFORM_HPP
