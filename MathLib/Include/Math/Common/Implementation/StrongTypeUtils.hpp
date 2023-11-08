#ifndef MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP
#define MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP

#include "StrongType.hpp"

namespace Math::Implementation
{
    template <typename T>
    struct UnderlyingType
    {
        using Type = T;
    };

    template <typename T>
    struct UnderlyingType<StrongType<T>>
    {
        using Type = T;
    };

    template <typename T>
    struct UnderlyingType<StaticStrongType<T>>
    {
        using Type = T;
    };

    template <typename T>
    struct MakeStrongType
    {
        using Type = StrongType<T>;
    };

    template <typename T>
    struct MakeStrongType<StrongType<T>>
    {
        using Type = StrongType<T>;
    };

    template <typename T>
    struct MakeStrongType<StaticStrongType<T>>
    {
        using Type = StrongType<T>;
    };

    template <typename T>
    struct MakeStaticStrongType
    {
        using Type = StaticStrongType<T>;
    };

    template <typename T>
    struct MakeStaticStrongType<StrongType<T>>
    {
        using Type = StaticStrongType<T>;
    };

    template <typename T>
    struct MakeStaticStrongType<StaticStrongType<T>>
    {
        using Type = StaticStrongType<T>;
    };
}

namespace Math
{
    template <typename T>
    using UnderlyingType = typename Implementation::UnderlyingType<T>::Type;

    template <typename T>
    using MakeStrongType = typename Implementation::MakeStrongType<T>::Type;

    template <typename T>
    using MakeStaticStrongType = typename Implementation::MakeStaticStrongType<T>::Type;

    template <typename U>
    [[nodiscard]] constexpr
    U ToUnderlying(StrongType<U> value) noexcept
    {
        return value.mValue;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(StaticStrongType<T> value) noexcept
    {
        return value.Value;
    }

    template <typename T>
        requires (!Implementation::IsSpecialization<T, StrongType>::Value
              &&  !Implementation::IsSpecialization<T, StaticStrongType>::Value)
    [[nodiscard]] constexpr
    T ToUnderlying(T value) noexcept
    {
        return value;
    }

    template <typename To, typename From>
    [[nodiscard]] constexpr
    To Convert(From value) noexcept
    {
        return To(static_cast<typename Implementation::UnderlyingType<To>::Type>(ToUnderlying(value)));
    }
}

#endif //MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP
