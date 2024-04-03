#ifndef MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_UTILS_HPP
#define MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_UTILS_HPP

#include "StrongTypes.hpp"

namespace Math::Implementation
{
    template <typename T>
    struct UnderlyingType
    {
        using Type = T;
    };

    template <typename T>
    struct UnderlyingType<StrongIntegerType<T>>
    {
        using Type = T;
    };

    template <typename T>
    struct UnderlyingType<StrongFloatType<T>>
    {
        using Type = T;
    };

    template <SizeType>
    struct SignedIntegerSelector
    {
        using Type = void;
    };

    template <> struct SignedIntegerSelector<1> { using Type = i8;  };
    template <> struct SignedIntegerSelector<2> { using Type = i16; };
    template <> struct SignedIntegerSelector<4> { using Type = i32; };
    template <> struct SignedIntegerSelector<8> { using Type = i64; };

    template <SizeType>
    struct UnsignedIntegerSelector
    {
        using Type = void;
    };

    template <> struct UnsignedIntegerSelector<1> { using Type = u8;  };
    template <> struct UnsignedIntegerSelector<2> { using Type = u16; };
    template <> struct UnsignedIntegerSelector<4> { using Type = u32; };
    template <> struct UnsignedIntegerSelector<8> { using Type = u64; };

    template <SizeType>
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

    template <SizeType Size>
    using SignedIntegerSelector = typename Implementation::SignedIntegerSelector<Size>::Type;

    template <SizeType Size>
    using UnsignedIntegerSelector = typename Implementation::UnsignedIntegerSelector<Size>::Type;

    template <SizeType Size>
    using FloatingPointSelector = typename Implementation::FloatingPointSelector<Size>::Type;

    template <typename To, typename From>
    [[nodiscard]] constexpr
    To Cast(From value) noexcept
    {
        return To(static_cast<typename Implementation::UnderlyingType<To>::Type>(ToUnderlying(value)));
    }


    template <typename T>
    [[nodiscard]] constexpr
    Implementation::StrongIntegerType<T> operator<< (const Implementation::StrongIntegerType<T>& u, const SizeType& v) noexcept
    {
        return ToUnderlying(u) << ToUnderlying(v);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Implementation::StrongIntegerType<T> operator>> (const Implementation::StrongIntegerType<T>& u, const SizeType& v) noexcept
    {
        return ToUnderlying(u) >> ToUnderlying(v);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Implementation::StrongIntegerType<T> operator<<= (Implementation::StrongIntegerType<T>& u, const SizeType& v) noexcept
    {
        return u = u << v;
    }

    template <typename T>
    [[nodiscard]] constexpr
    Implementation::StrongIntegerType<T> operator>>= (Implementation::StrongIntegerType<T>& u, const SizeType& v) noexcept
    {
        return u = u >> v;
    }
}

#endif //MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_UTILS_HPP
