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
}

#endif //_MATH_UTILS_TRANSFORM_HPP
