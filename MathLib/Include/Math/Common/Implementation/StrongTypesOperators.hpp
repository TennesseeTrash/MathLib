#ifndef MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_OPERATORS_HPP
#define MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_OPERATORS_HPP

#include "StrongTypes.hpp"

namespace Math
{
    template <typename T>
    [[nodiscard]] constexpr
    StrongType<T> operator<< (const StrongType<T>& u, const SizeType& v) noexcept
    {
        return StrongType<T>(ToUnderlying(u) << ToUnderlying(v));
    }

    template <typename T>
    [[nodiscard]] constexpr
    StrongType<T> operator>> (const StrongType<T>& u, const SizeType& v) noexcept
    {
        return StrongType<T>(ToUnderlying(u) >> ToUnderlying(v));
    }

    template <typename T>
    [[nodiscard]] constexpr
    StrongType<T> operator <<= (StrongType<T>& u, const SizeType& v) noexcept
    {
        return u = u << v;
    }

    template <typename T>
    [[nodiscard]] constexpr
    StrongType<T> operator >>= (StrongType<T>& u, const SizeType& v) noexcept
    {
        return u = u >> v;
    }
}

#endif //MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_OPERATORS_HPP
