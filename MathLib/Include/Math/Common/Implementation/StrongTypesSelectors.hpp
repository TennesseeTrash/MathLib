#ifndef MATHLIB_COMMON_IMPL_TYPES_SELECTORS_HPP
#define MATHLIB_COMMON_IMPL_TYPES_SELECTORS_HPP

#include "StrongTypes.hpp"

namespace Math::Implementation
{
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
    template <StaticSizeType Size>
    using SignedIntegerSelector = typename Implementation::SignedIntegerSelector<Size>::Type;

    template <StaticSizeType Size>
    using UnsignedIntegerSelector = typename Implementation::UnsignedIntegerSelector<Size>::Type;

    template <StaticSizeType Size>
    using FloatingPointSelector = typename Implementation::FloatingPointSelector<Size>::Type;
}

#endif //MATHLIB_COMMON_IMPL_TYPES_SELECTORS_HPP
