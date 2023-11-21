#ifndef MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP
#define MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP

#include "StrongTypes.hpp"
#include "../Traits.hpp"

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
    To Cast(From value) noexcept
    {
        return To(static_cast<typename Implementation::UnderlyingType<To>::Type>(ToUnderlying(value)));
    }

    // TODO(3011):
    // - Add overloads for unequal sizes.
    // - Move somewhere else, it doesn't really fit here.

    template <SignedIntegralType To, SignedIntegralType From>
        requires (sizeof(To) >= sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <UnsignedIntegralType To, UnsignedIntegralType From>
        requires (sizeof(To) >= sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        return Cast<To>(value);
    }

    template <SignedIntegralType To, UnsignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        if (value >= (1 << ((sizeof(To) * 8) - 1)))
        {
            static constexpr From sub = 1 << ((sizeof(From) * 8) - 1);
            return Cast<To>(value - sub);
        }
        else
        {
            // ((sizeof(To) * 8) - 1) is not representable by To
            static constexpr To sub = 1 << ((sizeof(To) * 8) - 2);
            return Cast<To>(value) - sub - sub;
        }
    }

    template <UnsignedIntegralType To, SignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        if (value >= 0)
        {
            static constexpr To add = 1 << ((sizeof(To) * 8) - 1);
            return Cast<To>(value) + add;
        }
        else
        {
            // ((sizeof(From) * 8) - 1) is not representable by From
            static constexpr From add = 1 << ((sizeof(From) * 8) - 2);
            return Cast<To>(value + add + add);
        }
    }
}

#endif //MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP
