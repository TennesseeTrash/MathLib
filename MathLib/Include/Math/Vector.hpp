#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include "Common/Types.hpp"
#include "Common/Concepts.hpp"
#include "Functions.hpp"

#include "Implementation/Vector2.hpp"
#include "Implementation/Vector3.hpp"
#include "Implementation/Vector4.hpp"
#include "Implementation/Utilities.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Useful type aliases
    //////////////////////////////////////////////////////////////////////////

    using Vector2f = Vector2T<f32>;
    using Vector3f = Vector3T<f32>;
    using Vector4f = Vector4T<f32>;

    using Vector2d = Vector2T<f64>;
    using Vector3d = Vector3T<f64>;
    using Vector4d = Vector4T<f64>;

    using Vector2i = Vector2T<i32>;
    using Vector3i = Vector3T<i32>;
    using Vector4i = Vector4T<i32>;

    using Vector2l = Vector2T<i64>;
    using Vector3l = Vector3T<i64>;
    using Vector4l = Vector4T<i64>;

    //////////////////////////////////////////////////////////////////////////
    // Operators
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] + v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] - v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] * v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator/ (const Vec& u, const Vec& v) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] / v[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = - u[i];
        }
        return result;
    }



    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, const Vec& v) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, const Vec& v) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, const Vec& v) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= v[i];
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator/= (Vec& u, const Vec& v) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] /= v[i];
        }
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Scalar arithmetic
    //////////////////////////////////////////////////////////////////////////

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] + s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator+ (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s + u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] - s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator- (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s - u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] * s;
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator* (typename Vec::ScalarType s, const Vec& u) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = s * u[i];
        }
        return result;
    }

    template <ConceptBasicVector Vec>
    [[nodiscard]] constexpr
    Vec operator/ (const Vec& u, typename Vec::ScalarType s) noexcept
    {
        Vec result;
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            result[i] = u[i] / s;
        }
        return result;
    }



    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator+= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] += s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator-= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] -= s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator*= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] *= s;
        }
        return u;
    }

    template <ConceptBasicVector Vec>
    [[maybe_unused]] constexpr
    Vec& operator/= (Vec& u, typename Vec::ScalarType s) noexcept
    {
        for (size_t i = 0; i < Vec::Dimension; ++i)
        {
            u[i] /= s;
        }
        return u;
    }

    //////////////////////////////////////////////////////////////////////////
    // Enforce concepts on provided types
    //////////////////////////////////////////////////////////////////////////

    static_assert(ConceptVector2<Vector2f>);
    static_assert(ConceptVector3<Vector3f>);
    static_assert(ConceptVector4<Vector4f>);

    static_assert(ConceptVector2<Vector2d>);
    static_assert(ConceptVector3<Vector3d>);
    static_assert(ConceptVector4<Vector4d>);

    static_assert(ConceptVector2<Vector2i>);
    static_assert(ConceptVector3<Vector3i>);
    static_assert(ConceptVector4<Vector4i>);

    static_assert(ConceptVector2<Vector2l>);
    static_assert(ConceptVector3<Vector3l>);
    static_assert(ConceptVector4<Vector4l>);
}

#endif //MATHLIB_VECTOR_HPP
