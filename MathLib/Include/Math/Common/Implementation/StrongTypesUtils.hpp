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

    template <StaticSizeType>
    struct SignedIntegerSelector
    {
        using Type = void;
    };

    template <> struct SignedIntegerSelector<1> { using Type = i8;  };
    template <> struct SignedIntegerSelector<2> { using Type = i16; };
    template <> struct SignedIntegerSelector<4> { using Type = i32; };
    template <> struct SignedIntegerSelector<8> { using Type = i64; };

    template <StaticSizeType>
    struct UnsignedIntegerSelector
    {
        using Type = void;
    };

    template <> struct UnsignedIntegerSelector<1> { using Type = u8;  };
    template <> struct UnsignedIntegerSelector<2> { using Type = u16; };
    template <> struct UnsignedIntegerSelector<4> { using Type = u32; };
    template <> struct UnsignedIntegerSelector<8> { using Type = u64; };

    template <StaticSizeType>
    struct FloatingPointSelector
    {
        using Type = void;
    };

    template <> struct FloatingPointSelector<4> { using Type = f32; };
    template <> struct FloatingPointSelector<8> { using Type = f64; };
}

namespace Math
{
    template <typename T>
    using UnderlyingType = typename Implementation::UnderlyingType<T>::Type;

    template <typename T>
    using MakeStrongType = typename Implementation::MakeStrongType<T>::Type;

    template <typename T>
    using MakeStaticStrongType = typename Implementation::MakeStaticStrongType<T>::Type;

    template <StaticSizeType Size>
    using SignedIntegerSelector = typename Implementation::SignedIntegerSelector<Size>::Type;

    template <StaticSizeType Size>
    using UnsignedIntegerSelector = typename Implementation::UnsignedIntegerSelector<Size>::Type;

    template <StaticSizeType Size>
    using FloatingPointSelector = typename Implementation::FloatingPointSelector<Size>::Type;

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
        // TODO(3011): Make the variables static constexpr
        // once it's feasible to move to C++23.

        if (value >= (1 << ((sizeof(To) * 8) - 1)))
        {
            constexpr From sub = 1 << ((sizeof(From) * 8) - 1);
            return Cast<To>(value - sub);
        }
        else
        {
            // ((sizeof(To) * 8) - 1) is not representable by To
            constexpr To sub = 1 << ((sizeof(To) * 8) - 2);
            return Cast<To>(value) - sub - sub;
        }
    }

    template <UnsignedIntegralType To, SignedIntegralType From>
        requires (sizeof(To) == sizeof(From))
    [[nodiscard]] constexpr
    To ValueShift(From value) noexcept
    {
        // TODO(3011): Make the variables static constexpr
        // once it's feasible to move to C++23.

        if (value >= 0)
        {
            constexpr To add = 1 << ((sizeof(To) * 8) - 1);
            return Cast<To>(value) + add;
        }
        else
        {
            // ((sizeof(From) * 8) - 1) is not representable by From
            constexpr From add = 1 << ((sizeof(From) * 8) - 2);
            return Cast<To>(value + add + add);
        }
    }
}

#endif //MATHLIB_COMMON_IMPL_STRONG_TYPES_UTILS_HPP
