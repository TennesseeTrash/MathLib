#ifndef MATHLIB_UTILS_COORDINATE_FRAME_HPP
#define MATHLIB_UTILS_COORDINATE_FRAME_HPP

#include "../Vector.hpp"
#include "../Matrix.hpp"

namespace Math
{
    class CoordinateFrame final
    {
    public:
        [[nodiscard]] constexpr
        CoordinateFrame() noexcept
            : mFrame(1.0f)
        {}

        [[nodiscard]] constexpr
        CoordinateFrame(const Vector3f& x, const Vector3f& y, const Vector3f& z) noexcept
            : mFrame(x, y, z)
        {}

        [[nodiscard]] constexpr
        static CoordinateFrame MakeFromNormal(const Vector3f& normal) noexcept
        {
            CoordinateFrame result;
            result.mFrame[2] = Normalize(normal);
            result.mFrame[1] =
                Normalize(Cross(result.mFrame[2],
                                (Abs(result.mFrame[2].x) > 0.99f)
                                    ? Vector3f(0.0f, 1.0f, 0.0f)
                                    : Vector3f(1.0f, 0.0f, 0.0f)));
            result.mFrame[0] = Cross(result.mFrame[1], result.mFrame[2]);
            return result;
        }

        [[nodiscard]] constexpr
        Vector3f ToWorld(const Vector3f& vec) const noexcept
        {
            return vec.x * mFrame[0] + vec.y * mFrame[1] + vec.z * mFrame[2];
        }

        [[nodiscard]] constexpr
        Vector3f ToLocal(const Vector3f& vec) const noexcept
        {
            return mFrame * vec;
        }

        [[nodiscard]] constexpr const Vector3f& Binormal() const { return mFrame[0]; }
        [[nodiscard]] constexpr const Vector3f& Tangent () const { return mFrame[1]; }
        [[nodiscard]] constexpr const Vector3f& Normal  () const { return mFrame[2]; }
    private:
        Matrix3f mFrame;
    };
}

#endif // MATHLIB_UTILS_COORDINATE_FRAME_HPP
