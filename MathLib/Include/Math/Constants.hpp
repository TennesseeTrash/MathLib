#ifndef MATHLIB_CONSTANTS_HPP
#define MATHLIB_CONSTANTS_HPP

#include "Implementation/Constants.hpp"

namespace Math
{
    namespace Constants
    {
        template <typename T>
        static constexpr T Pi       = Math::Implementation::Pi<T>::Value;

        template <typename T>
        static constexpr T PiDiv2   = Pi<T> / static_cast<T>(2);

        template <typename T>
        static constexpr T Tau      = Pi<T> * static_cast<T>(2);

        template <typename T>
        static constexpr T E        = Math::Implementation::E<T>::Value;

        template <typename T>
        static constexpr T Phi      = Math::Implementation::Phi<T>::Value;

        template <typename T>
        static constexpr T Sqrt2    = Math::Implementation::Sqrt2<T>::Value;

        template <typename T>
        static constexpr T InvSqrt2 = static_cast<T>(1) / Sqrt2<T>;

        template <typename T>
        static constexpr T Sqrt3    = Math::Implementation::Sqrt3<T>::Value;

        template <typename T>
        static constexpr T InvSqrt3 = static_cast<T>(1) / Sqrt3<T>;

        template <typename T>
        static constexpr T Sqrt5    = Math::Implementation::Sqrt5<T>::Value;

        template <typename T>
        static constexpr T InvSqrt5 = static_cast<T>(1) / Sqrt5<T>;

        template <typename T>
        static constexpr T Epsilon  = Math::Implementation::Epsilon<T>::Value;
    }
}

#endif //MATHLIB_CONSTANTS_HPP
