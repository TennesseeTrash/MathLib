#ifndef MATHLIB_CONSTANTS_HPP
#define MATHLIB_CONSTANTS_HPP

#include "Implementation/Constants.hpp"

namespace Math::Constant
{
    template <typename T>
    static constexpr T Pi       = Implementation::Pi<T>::Value;

    template <typename T>
    static constexpr T PiDiv2   = Pi<T> / static_cast<T>(2);

    template <typename T>
    static constexpr T Tau      = Pi<T> * static_cast<T>(2);

    template <typename T>
    static constexpr T E        = Implementation::E<T>::Value;

    template <typename T>
    static constexpr T Phi      = Implementation::Phi<T>::Value;

    template <typename T>
    static constexpr T Sqrt2    = Implementation::Sqrt2<T>::Value;

    template <typename T>
    static constexpr T InvSqrt2 = Cast<T>(1) / Sqrt2<T>;

    template <typename T>
    static constexpr T Sqrt3    = Implementation::Sqrt3<T>::Value;

    template <typename T>
    static constexpr T InvSqrt3 = Cast<T>(1) / Sqrt3<T>;

    template <typename T>
    static constexpr T Sqrt5    = Implementation::Sqrt5<T>::Value;

    template <typename T>
    static constexpr T InvSqrt5 = Cast<T>(1) / Sqrt5<T>;

    template <typename T>
    static constexpr T Epsilon  = Implementation::Epsilon<T>::Value;
}

#endif //MATHLIB_CONSTANTS_HPP
