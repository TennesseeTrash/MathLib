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
    Matrix4T<T> LookAt(const Vector3T<T>& position, const Vector3T<T>& direction, const Vector3T<T>& up) noexcept
    {
        Vector4T<T> w = Vector4T<T>(-Normalize(direction));
        Vector4T<T> u = Vector4T<T>(Normalize(Cross(up, w)));
        Vector4T<T> v = Vector4T<T>(Cross(w, u));
        Vector4T<T> o = Vector4T<T>(T(0), T(0), T(0), T(1));
        return Matrix4T<T>(u, v, w, o) * Translate(-position);
    }

    enum class Handedness
    {
        LeftHanded,
        RightHanded,
    };

    template <Handedness handedness = Handedness::LeftHanded, typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> PerspectiveProjection(T fov, T aspectRatio, T near, T far) noexcept
    {
		T tanFovOver2 = std::tan(fov / T(2));

		Matrix4T<T> result(T(0));
		result[0][0] = T(1) / (aspectRatio * tanFovOver2);
		result[1][1] = T(1) / tanFovOver2;
		result[2][2] = far / (far - near);
		result[3][2] = -(far * near) / (far - near);

        if constexpr (handedness == Handedness::LeftHanded)
        {
            result[2][3] = T(1);
        }
        if constexpr (handedness == Handedness::RightHanded)
        {
            result[2][3] = T(-1);
        }

		return result;
    }

    template <Handedness handedness = Handedness::LeftHanded, typename T>
    [[nodiscard]] inline constexpr
    Matrix4T<T> OrthographicProjection(T left, T right, T bottom, T top, T near, T far) noexcept
    {
        Matrix4T<T> result(T(1));
		result[0][0] = T(2) / (right - left);
		result[1][1] = T(2) / (top - bottom);
		result[2][2] = T(1) / (far - near);
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -near / (far - near);

        if constexpr (handedness == Handedness::RightHanded)
        {
            result[2][2] = -result[2][2];
        }

		return result;
    }
}

#endif //_MATH_UTILS_TRANSFORM_HPP
