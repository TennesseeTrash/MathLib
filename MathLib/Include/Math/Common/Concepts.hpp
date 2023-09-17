#ifndef MATHLIB_COMMON_CONCEPTS_HPP
#define MATHLIB_COMMON_CONCEPTS_HPP

#include <concepts>

namespace Math
{
    namespace Detail
    {
        auto Prvalue(auto&& arg)
        {
            return arg;
        }
    }

    template <typename T, typename U>
    concept SameBaseType = std::is_same_v<std::remove_cvref_t<U>, std::remove_cvref_t<T>>;

    template <typename T>
    concept FundamentalType = std::is_fundamental_v<T>;

    template <typename T>
    concept IntegralType = std::is_integral_v<T>;

    template <typename T>
    concept FloatingPointType = std::is_floating_point_v<T>;

    template <typename T>
    concept ArithmeticType = requires (T a, T b)
    {
        { a + b } -> std::same_as<T>;
        { a - b } -> std::same_as<T>;
        { a * b } -> std::same_as<T>;
        { a / b } -> std::same_as<T>;
        { -a    } -> std::same_as<T>;

        { a += b } -> SameBaseType<T>;
        { a -= b } -> SameBaseType<T>;
        { a *= b } -> SameBaseType<T>;
        { a /= b } -> SameBaseType<T>;
    };

    template <typename T>
    concept ConceptBasicVector = requires (T u)
    {
        typename T::ScalarType;
        { T::Dimension } -> SameBaseType<size_t>;

        requires ArithmeticType<typename T::ScalarType>;

        requires requires (size_t i)
        {
            { u[i] } -> SameBaseType<typename T::ScalarType>;
        };

        { u.LenSqr() } -> SameBaseType<typename T::ScalarType>;
        { u.Length() } -> SameBaseType<typename T::ScalarType>;

        { u.Max() } -> SameBaseType<typename T::ScalarType>;
        { u.Min() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptVectorN = requires (T u, T v)
    {
        requires ConceptBasicVector<T>;

        requires ArithmeticType<T>;

        requires requires (typename T::ScalarType s)
        {
            { u + s } -> std::same_as<T>;
            { s + u } -> std::same_as<T>;
            { u - s } -> std::same_as<T>;
            { s - u } -> std::same_as<T>;
            { u * s } -> std::same_as<T>;
            { s * u } -> std::same_as<T>;
            { u / s } -> std::same_as<T>;

            { u += s } -> SameBaseType<T>;
            { u -= s } -> SameBaseType<T>;
            { u *= s } -> SameBaseType<T>;
            { u /= s } -> SameBaseType<T>;
        };
    };

    template <typename T>
    concept ConceptVector2 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptVector3 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.y) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.z) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptVector4 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.y) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.z) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.w) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 4;
    };

    template <typename T>
    concept ConceptVector = requires
    {
        requires ConceptVector2<T>
              || ConceptVector3<T>
              || ConceptVector4<T>;
    };

    template <typename T>
    concept ConceptBasicPoint = requires (T p)
    {
        typename T::ScalarType;
        { T::Dimension } -> SameBaseType<size_t>;

        requires ArithmeticType<typename T::ScalarType>;

        requires requires (size_t i)
        {
            { p[i] } -> SameBaseType<typename T::ScalarType>;
        };

        { p.Max() } -> SameBaseType<typename T::ScalarType>;
        { p.Min() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T, typename Vec>
    concept ConceptPointN = requires (T p)
    {
        requires ConceptBasicPoint<T>;

        requires requires (T q)
        {
            { p - q } -> std::convertible_to<Vec>;
        };
    };

    template <typename T, typename Vec>
    concept ConceptPoint2 = requires (T p)
    {
        requires ConceptPointN<T, Vec>;
        requires T::Dimension == 2;
    };

    template <typename T, typename Vec>
    concept ConceptPoint3 = requires (T p)
    {
        requires ConceptPointN<T, Vec>;
        requires T::Dimension == 3;
    };

    template <typename T, typename Vec>
    concept ConceptPoint = requires
    {
        requires ConceptPoint2<T, Vec>
              || ConceptPoint3<T, Vec>;
    };

    template <typename T>
    concept ConceptBasicMatrix = requires (T m)
    {
        typename T::ScalarType;
        typename T::VectorType;
        { T::Dimension } -> SameBaseType<size_t>;

        requires T::VectorType::Dimension == T::Dimension;

        requires ArithmeticType<typename T::ScalarType>;
        requires ArithmeticType<typename T::VectorType>;

        requires requires (size_t i)
        {
            { m[i]    } -> SameBaseType<typename T::VectorType>;
            { m[i][i] } -> SameBaseType<typename T::ScalarType>;
        };
    };

    template <typename T>
    concept ConceptMatrixN = requires (T m)
    {
        requires ConceptBasicMatrix<T>;

        requires requires (T n)
        {
            { m + n } -> SameBaseType<T>;
            { m - n } -> SameBaseType<T>;
            { m * n } -> SameBaseType<T>;
        };

        requires requires (typename T::ScalarType s)
        {
            { m + s } -> SameBaseType<T>;
            { s + m } -> SameBaseType<T>;
            { m - s } -> SameBaseType<T>;
            { s - m } -> SameBaseType<T>;
            { m * s } -> SameBaseType<T>;
            { s * m } -> SameBaseType<T>;
            { m / s } -> SameBaseType<T>;
        };

        requires requires (typename T::VectorType u)
        {
            { m * u } -> SameBaseType<typename T::VectorType>;
            { u * m } -> SameBaseType<typename T::VectorType>;
        };
    };

    template <typename T>
    concept ConceptMatrix2 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptMatrix3 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptMatrix4 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 4;
    };

    template <typename T>
    concept ConceptMatrix = requires
    {
        requires ConceptMatrix2<T>
              || ConceptMatrix3<T>
              || ConceptMatrix4<T>;
    };

    template <typename T>
    concept ConceptUtilType = requires
    {
        requires ConceptBasicVector<T>
              || ConceptBasicPoint<T>
              || ConceptBasicMatrix<T>;
    };
}

#endif //MATHLIB_COMMON_CONCEPTS_HPP
