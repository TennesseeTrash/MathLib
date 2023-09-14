#ifndef MATHLIB_COMMON_CONCEPTS_HPP
#define MATHLIB_COMMON_CONCEPTS_HPP

#include <concepts>

namespace Math
{
    namespace Detail
    {
        auto prvalue(auto&& arg)
        {
            return arg;
        }
    }

    template <typename T>
    concept IntegralType = std::is_integral_v<T>;

    template <typename T>
    concept ArithmeticType = requires (T a, T b)
    {
        { a + b } -> std::same_as<T>;
        { a - b } -> std::same_as<T>;
        { a * b } -> std::same_as<T>;
        { a / b } -> std::same_as<T>;
        { -a    } -> std::same_as<T>;

        { a += b } -> std::same_as<T>;
        { a -= b } -> std::same_as<T>;
        { a *= b } -> std::same_as<T>;
        { a /= b } -> std::same_as<T>;
    };

    template <typename T>
    concept ConceptVectorN = requires (T u, T v)
    {
        typename T::ScalarType;
        { T::Dimension } -> std::same_as<size_t>;

        ArithmeticType<typename T::ScalarType>;
        ArithmeticType<T>;

        requires requires (size_t i)
        {
            { u[i] } -> std::same_as<typename T::ScalarType>;
        };

        { u.LenSqr() } -> std::same_as<typename T::ScalarType>;
        { u.Length() } -> std::same_as<typename T::ScalarType>;

        { u.Max() } -> std::same_as<T>;
        { u.Min() } -> std::same_as<T>;

        requires requires (typename T::ScalarType s)
        {
            { u + s } -> std::same_as<T>;
            { s + u } -> std::same_as<T>;
            { u - s } -> std::same_as<T>;
            { u * s } -> std::same_as<T>;
            { s * u } -> std::same_as<T>;
            { u / s } -> std::same_as<T>;

            { u += s } -> std::same_as<T>;
            { u -= s } -> std::same_as<T>;
            { u *= s } -> std::same_as<T>;
            { u /= s } -> std::same_as<T>;
        };
    };

    template <typename T>
    concept ConceptVector2 = requires (T u)
    {
        ConceptVectorN<T>;
        { Detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptVector3 = requires (T u)
    {
        ConceptVectorN<T>;
        { Detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.y) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.z) } -> std::same_as<typename T::ScalarType>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptVector4 = requires (T u)
    {
        ConceptVectorN<T>;
        { Detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.y) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.z) } -> std::same_as<typename T::ScalarType>;
        { Detail::prvalue(u.w) } -> std::same_as<typename T::ScalarType>;
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
    concept ConceptMatrixN = requires (T m)
    {
        typename T::ScalarType;
        typename T::VectorType;
        { T::Dimension } -> std::same_as<size_t>;

        T::VectorType::Dimension == T::Dimension;

        ArithmeticType<typename T::ScalarType>;
        ArithmeticType<typename T::VectorType>;

        requires requires (size_t i)
        {
            { m[i]    } -> std::same_as<typename T::VectorType>;
            { m[i][i] } -> std::same_as<typename T::ScalarType>;
        };

        requires requires (T n)
        {
            { m + n } -> std::same_as<T>;
            { m - n } -> std::same_as<T>;
            { m * n } -> std::same_as<T>;
        };

        requires requires (typename T::ScalarType s)
        {
            { m + s } -> std::same_as<T>;
            { s + m } -> std::same_as<T>;
            { m - s } -> std::same_as<T>;
            { s - m } -> std::same_as<T>;
            { m * s } -> std::same_as<T>;
            { s * m } -> std::same_as<T>;
            { m / s } -> std::same_as<T>;
        };

        requires requires (typename T::VectorType u)
        {
            { m * u } -> std::same_as<typename T::VectorType>;
            { u * m } -> std::same_as<typename T::VectorType>;
        };
    };

    template <typename T>
    concept ConceptMatrix2 = requires (T m)
    {
        ConceptMatrixN<T>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptMatrix3 = requires (T m)
    {
        ConceptMatrixN<T>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptMatrix4 = requires (T m)
    {
        ConceptMatrixN<T>;
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
    concept ConceptLibType = requires
    {
        requires ConceptVector<T>
              || ConceptMatrix<T>;
    };
}

#endif //MATHLIB_COMMON_CONCEPTS_HPP
