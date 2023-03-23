#ifndef MATHLIB_QUATERNION_HPP
#define MATHLIB_QUATERNION_HPP

#include "Matrix.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Assumptions for correct behavior
    //////////////////////////////////////////////////////////////////////////

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    //////////////////////////////////////////////////////////////////////////
    // Basic Definition
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct QuaternionT final
    {
        Vector3T<T> mV;
        T mS;

        QuaternionT() noexcept
            : mV(), mS()
        {}

        explicit QuaternionT(const Vector3T<T>& vec, T s) noexcept
            : mV(vec), mS(s)
        {}

        explicit QuaternionT(T i, T j, T k, T s) noexcept
            : mV(i, j, k), mS(s)
        {}

        const Vector3T<T>& GetVector() const
        {
            return mV;
        }

        Matrix3T<T> ToMatrix3() const
        {
            Matrix3T<T> result;

            result[0][0] = Sq(mS) + Sq(mV.x) - Sq(mV.y) - Sq(mV.z);
            result[0][1] = 2 * (mV.x * mV.y - mS * mV.z);
            result[0][2] = 2 * (mV.x * mV.z + mS * mV.y);
            result[1][0] = 2 * (mV.x * mV.y + mS * mV.z);
            result[1][1] = Sq(mS) - Sq(mV.x) + Sq(mV.y) - Sq(mV.z);
            result[1][2] = 2 * (mV.y * mV.z - mS * mV.x);
            result[2][0] = 2 * (mV.x * mV.z - mS * mV.y);
            result[2][1] = 2 * (mV.y * mV.z + mS * mV.x);
            result[2][2] = Sq(mS) - Sq(mV.x) - Sq(mV.y) + Sq(mV.z);

            return result;
        }

        Matrix4T<T> ToMatrix4() const
        {
            Matrix4T<T> result(T(1));

            result[0][0] = Sq(mS) + Sq(mV.x) - Sq(mV.y) - Sq(mV.z);
            result[0][1] = 2 * (mV.x * mV.y - mS * mV.z);
            result[0][2] = 2 * (mV.x * mV.z + mS * mV.y);
            result[1][0] = 2 * (mV.x * mV.y + mS * mV.z);
            result[1][1] = Sq(mS) - Sq(mV.x) + Sq(mV.y) - Sq(mV.z);
            result[1][2] = 2 * (mV.y * mV.z - mS * mV.x);
            result[2][0] = 2 * (mV.x * mV.z - mS * mV.y);
            result[2][1] = 2 * (mV.y * mV.z + mS * mV.x);
            result[2][2] = Sq(mS) - Sq(mV.x) - Sq(mV.y) + Sq(mV.z);

            return result;
        }

        static QuaternionT<T> MakeRotation(T angle, const Vector3T<T>& axis) noexcept
        {
            return QuaternionT(std::sin(angle / 2) * axis, std::cos(angle / 2));
        }

        static QuaternionT<T> MakeFromYawPitchRoll(T yaw, T pitch, T roll) noexcept
        {
            T cosRoll  = std::cos(roll  / T(2));
            T sinRoll  = std::sin(roll  / T(2));
            T cosPitch = std::cos(pitch / T(2));
            T sinPitch = std::sin(pitch / T(2));
            T cosYaw   = std::cos(yaw   / T(2));
            T sinYaw   = std::sin(yaw   / T(2));
            return QuaternionT<T>({
                cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw,
                cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw,
                sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw},
                cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw
            );
        }
    };

    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Quaternionf = QuaternionT<float>;
    using Quaterniond = QuaternionT<double>;

    //////////////////////////////////////////////////////////////////////////
    // Operators
    //////////////////////////////////////////////////////////////////////////

    // Basic arithmetic operators

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator+ (const QuaternionT<T>& q1, const QuaternionT<T>& q2) noexcept
    {
        return QuaternionT<T>(q1.mV + q2.mV, q1.mS + q2.mS);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator- (const QuaternionT<T>& q1, const QuaternionT<T>& q2) noexcept
    {
        return QuaternionT<T>(q1.mV - q2.mV, q1.mS - q2.mS);
    }

    // Hamilton product

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator* (const QuaternionT<T>& q1, const QuaternionT<T>& q2) noexcept
    {
        QuaternionT<T> result;
        result.mV = (q1.mV * q2.mS) + (q1.mS * q2.mV) + Cross(q1.mV, q2.mV);
        result.mS = q1.mS * q2.mS - Dot(q1.mV, q2.mV);
        return result;
    }

    /* Alternative implementation taken from
     * Foundations of Game Engine Development, Volume 1 Mathematics by E. Lengyel
    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator* (const QuaternionT<T>& q1, const QuaternionT<T>& q2) noexcept
    {
        return QuaternionT(
            q1.mS * q2.mV.x + q1.mV.x * q2.mS   + q1.mV.y * q2.mV.z - q1.mV.z * q2.mV.y,
            q1.mS * q2.mV.y - q1.mV.x * q2.mV.z + q1.mV.y * q2.mS   + q1.mV.z * q2.mV.x,
            q1.mS * q2.mV.z + q1.mV.x * q2.mV.y - q1.mV.y * q2.mV.x + q1.mV.z * q2.mS  ,
            q1.mS * q2.mS   - q1.mV.x * q2.mV.x - q1.mV.y * q2.mV.y - q1.mV.z * q2.mV.z
        );
    }
    */

    // Scalar multiplication, division by scalar

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator* (const QuaternionT<T>& q, T s) noexcept
    {
        return QuaternionT<T>(q.mV * s, q.mS * s);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator* (T s, const QuaternionT<T>& q) noexcept
    {
        return QuaternionT<T>(s * q.mV, s * q.mS);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> operator/ (const QuaternionT<T>& q, T s) noexcept
    {
        return QuaternionT<T>(q.mV / s, q.mS / s);
    }

    //////////////////////////////////////////////////////////////////////////
    // Utilities
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    [[nodiscard]] constexpr
    bool Equal(const QuaternionT<T>& q1, const QuaternionT<T>& q2, T epsilon = Constants::FloatEps<T>) noexcept
    {
        return Equal(q1.mV, q2.mV, epsilon)
            && Equal(q1.mS, q2.mS, epsilon);
    }

    template <typename T>
    [[nodiscard]] constexpr
    T NormSqr(const QuaternionT<T>& q) noexcept
    {
        return q.mV.LenSqr() + Sq(q.mS);
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Norm(const QuaternionT<T>& q) noexcept
    {
        return std::sqrt(NormSqr(q));
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> Normalize(const QuaternionT<T>& q) noexcept
    {
        return q / Norm(q);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> Conjugate(const QuaternionT<T>& q) noexcept
    {
        return QuaternionT(-q.mV, q.mS);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> Inverse(const QuaternionT<T>& q) noexcept
    {
        return  Conjugate(q) / NormSqr(q);
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Dot(const QuaternionT<T>& q1, const QuaternionT<T>& q2) noexcept
    {
        return (q1.mS * q2.mS) + Dot(q1.mV, q2.mV);
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> Lerp(T value, const QuaternionT<T>& begin, const QuaternionT<T>& end) noexcept
    {
        value = Clamp(value);
        if (Dot(begin, end) >= T(0))
        {
            return Normalize(begin * (1 - value) + end * (value));
        }
        else
        {
            return Normalize(begin * (1 - value) - end * (value));
        }
    }

    template <bool Long = false, typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> Slerp(T value, const QuaternionT<T>& begin, const QuaternionT<T>& end) noexcept
    {
        value = Clamp(value);
        T cosAngle = Dot(begin, end);
        if (Equal(cosAngle, T(1)))
        {
            return Lerp(value, begin, end);
        }
        T mult = T(1);
        if (cosAngle < T(0))
        {
            cosAngle = -cosAngle;
            mult = T(-1);
        }
        T angle = std::acos(cosAngle);
        T sinAngle = std::sin(angle);
        return ((begin * std::sin((T(1) - value) * angle) + end * std::sin(value * angle) * mult)) / sinAngle;
    }

    template <typename T>
    [[nodiscard]] constexpr
    QuaternionT<T> LongSlerp(T value, const QuaternionT<T>& begin, const QuaternionT<T>& end) noexcept
    {
        value = Clamp(value);
        T cosAngle = Dot(begin, end);
        if (Equal(cosAngle, T(1)))
        {
            return Lerp(value, begin, end);
        }
        T mult = T(1);
        if (cosAngle > T(0))
        {
            cosAngle = -cosAngle;
            mult = T(-1);
        }
        T angle = std::acos(cosAngle);
        T sinAngle = std::sin(angle);
        return (begin * std::sin((1 - value) * angle) + end * std::sin(value * angle) * mult) / sinAngle;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Vector3T<T> Transform(const Vector3T<T>& v, const QuaternionT<T>& q) noexcept
    {
        return (v * (Sq(q.mS) - Dot(q.mV, q.mV))) + (q.mV * (T(2) * Dot(v, q.mV))) + (Cross(q.mV, v) * q.mS * T(2));
    }
}

#endif //MATHLIB_QUATERNION_HPP
