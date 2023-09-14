#ifndef MATHLIB_COMMON_CONCEPTS_HPP
#define MATHLIB_COMMON_CONCEPTS_HPP

#include <concepts>

namespace Math
{
    namespace detail
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
        { detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        T::Dimension == 2;
    };

    template <typename T>
    concept ConceptVector3 = requires (T u)
    {
        ConceptVectorN<T>;
        { detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.y) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.z) } -> std::same_as<typename T::ScalarType>;
        T::Dimension == 3;
    };

    template <typename T>
    concept ConceptVector4 = requires (T u)
    {
        ConceptVectorN<T>;
        { detail::prvalue(u.x) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.y) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.z) } -> std::same_as<typename T::ScalarType>;
        { detail::prvalue(u.w) } -> std::same_as<typename T::ScalarType>;
        T::Dimension == 4;
    };

    template <typename T>
    concept ConceptVector = requires {
        requires ConceptVector2<T>
              || ConceptVector3<T>
              || ConceptVector4<T>;
    };
}

#endif //MATHLIB_COMMON_CONCEPTS_HPP
