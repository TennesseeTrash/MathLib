#ifndef MATHLIB_IMPLEMENTATION_VECTOR_HPP
#define MATHLIB_IMPLEMENTATION_VECTOR_HPP

#include "Base/Concepts.hpp"
#include "Functions/BasicFunctions.hpp"
#include "Functions/Trigonometric.hpp"

namespace Math
{
    template <Concept::StrongType T>
    struct Vector2T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 2;

        T x = T(0);
        T y = T(0);

        constexpr          Vector2T()           noexcept = default;
        constexpr explicit Vector2T(T val)      noexcept : x(val ), y(val ) {}
        constexpr          Vector2T(T xv, T yv) noexcept : x(xv  ), y(yv  ) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return Math::Max(x, y); }
        constexpr T Min()    const noexcept { return Math::Min(x, y); }

        static constexpr Vector2T<T> UnitX() noexcept { return Vector2T<T>(Cast<T>(1), Cast<T>(0)); }
        static constexpr Vector2T<T> UnitY() noexcept { return Vector2T<T>(Cast<T>(0), Cast<T>(1)); }
    };

    template <Concept::StrongType T>
    struct Vector3T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 3;

        T x = T(0);
        T y = T(0);
        T z = T(0);

        constexpr          Vector3T()                           noexcept = default;
        constexpr explicit Vector3T(T val)                      noexcept : x(val ), y(val ), z(val ) {}
        constexpr          Vector3T(T xv, T yv, T zv)           noexcept : x(xv  ), y(yv  ), z(zv  ) {}
        constexpr explicit Vector3T(const Vector2T<T>& u)       noexcept : x(u.x ), y(u.y ), z(T(0)) {}
        constexpr explicit Vector3T(const Vector2T<T>& u, T zv) noexcept : x(u.x ), y(u.y ), z(zv  ) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return Math::Max(x, y, z); }
        constexpr T Min()    const noexcept { return Math::Min(x, y, z); }

        static constexpr Vector3T<T> UnitX() noexcept { return Vector3T<T>(Cast<T>(1), Cast<T>(0), Cast<T>(0)); }
        static constexpr Vector3T<T> UnitY() noexcept { return Vector3T<T>(Cast<T>(0), Cast<T>(1), Cast<T>(0)); }
        static constexpr Vector3T<T> UnitZ() noexcept { return Vector3T<T>(Cast<T>(0), Cast<T>(0), Cast<T>(1)); }
    };

    template <Concept::StrongType T>
    struct Vector4T final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = 4;

        T x = T(0);
        T y = T(0);
        T z = T(0);
        T w = T(0);

        constexpr          Vector4T()                                 noexcept = default;
        constexpr explicit Vector4T(T val)                            noexcept : x(val ), y(val ), z(val ), w(val ) {}
        constexpr          Vector4T(T xv, T yv, T zv, T wv)           noexcept : x(xv  ), y(yv  ), z(zv  ), w(wv  ) {}
        constexpr explicit Vector4T(const Vector2T<T>& u)             noexcept : x(u.x ), y(u.y ), z(T(0)), w(T(0)) {}
        constexpr explicit Vector4T(const Vector2T<T>& u, T zv, T wv) noexcept : x(u.x ), y(u.y ), z(zv  ), w(wv  ) {}
        constexpr explicit Vector4T(const Vector3T<T>& u)             noexcept : x(u.x ), y(u.y ), z(u.z ), w(T(0)) {}
        constexpr explicit Vector4T(const Vector3T<T>& u, T wv)       noexcept : x(u.x ), y(u.y ), z(u.z ), w(wv  ) {}

        constexpr       T& operator[] (SizeType idx)       { return reinterpret_cast<      T *>(this)[ToUnderlying(idx)]; }
        constexpr const T& operator[] (SizeType idx) const { return reinterpret_cast<const T *>(this)[ToUnderlying(idx)]; }

        constexpr T LenSqr() const noexcept { return x * x + y * y + z * z + w * w; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return Math::Max(x, y, z, w); }
        constexpr T Min()    const noexcept { return Math::Min(x, y, z, w); }

        static constexpr Vector4T<T> UnitX() noexcept { return Vector4T<T>(Cast<T>(1), Cast<T>(0), Cast<T>(0), Cast<T>(0)); }
        static constexpr Vector4T<T> UnitY() noexcept { return Vector4T<T>(Cast<T>(0), Cast<T>(1), Cast<T>(0), Cast<T>(0)); }
        static constexpr Vector4T<T> UnitZ() noexcept { return Vector4T<T>(Cast<T>(0), Cast<T>(0), Cast<T>(1), Cast<T>(0)); }
        static constexpr Vector4T<T> UnitW() noexcept { return Vector4T<T>(Cast<T>(0), Cast<T>(0), Cast<T>(0), Cast<T>(1)); }
    };

    template <SizeType N, Concept::StrongType T>
    struct VectorNT final
    {
        using ScalarType = T;
        static constexpr SizeType Dimension = N;

        Array<ScalarType, Dimension> Data;

        constexpr          VectorNT()      noexcept = default;
        constexpr explicit VectorNT(T val) noexcept { Data.Fill(val); }

        template <Concept::BasicVector OtherVec>
            requires (OtherVec::Dimension <= Dimension)
        constexpr explicit VectorNT(const OtherVec& other) noexcept
        {
            for (SizeType i = 0; i < other.Dimension; ++i)
            {
                Data[i] = other[i];
            }
        }

        template <typename... ValueTypes>
            requires (sizeof...(ValueTypes) == Dimension)
        constexpr VectorNT(ValueTypes... values) noexcept
            : Data{MakeStrongType<ValueTypes>(values)...}
        {}

        constexpr       T& operator[] (SizeType idx)       { return Data[idx]; }
        constexpr const T& operator[] (SizeType idx) const { return Data[idx]; }

        constexpr T LenSqr() const noexcept { T result; Data.ForEach([&result](T val) { result += val * val; }); return result; }
        constexpr T Length() const noexcept { return Sqrt(LenSqr()); }
        constexpr T Max()    const noexcept { return Data.Max(); }
        constexpr T Min()    const noexcept { return Data.Min(); }

        static constexpr VectorNT<Dimension, ScalarType> Unit(SizeType axisIndex) noexcept
        {
            VectorNT<Dimension, ScalarType> result;
            result[axisIndex] = Cast<ScalarType>(1);
            return result;
        }
    };

    namespace Implementation
    {
        template <SizeType Dimension, Concept::StrongType ScalarType>
        struct VectorSelector
        {
            using Type = VectorNT<Dimension, ScalarType>;
        };

        template <Concept::StrongType ScalarType>
        struct VectorSelector<2, ScalarType>
        {
            using Type = Vector2T<ScalarType>;
        };

        template <Concept::StrongType ScalarType>
        struct VectorSelector<3, ScalarType>
        {
            using Type = Vector3T<ScalarType>;
        };

        template <Concept::StrongType ScalarType>
        struct VectorSelector<4, ScalarType>
        {
            using Type = Vector4T<ScalarType>;
        };
    }

    template <SizeType Dimension, Concept::StrongType ScalarType>
    using VectorSelector = typename Implementation::VectorSelector<Dimension, ScalarType>::Type;
}

#endif //MATHLIB_IMPLEMENTATION_VECTOR_HPP
