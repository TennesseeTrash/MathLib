#ifndef MATHLIB_CONSTANTS_HPP
#define MATHLIB_CONSTANTS_HPP

#include "Common/Types.hpp"
#include "Common/Concepts.hpp"

namespace Math
{
    namespace Constants
    {
        template <typename T>
        static constexpr T FloatEps = T(0.000001);
        template <typename T>
        static constexpr T Pi       = T(3.1415926535897932384626433832795028841971693993751058209749445923);
        template <typename T>
        static constexpr T E        = T(2.7182818284590452353602874713526624977572470936999595749669676277);
        template <typename T>
        static constexpr T Phi      = T(1.6180339887498948482045868343656381177203091798057628621354486227);
        template <typename T>
        static constexpr T Sqrt2    = T(1.4142135623730950488016887242096980785696718753769480731766797379);
        template <typename T>
        static constexpr T Sqrt3    = T(1.7320508075688772935274463415058723669428052538103806280558069794);
        template <typename T>
        static constexpr T Sqrt5    = T(2.2360679774997896964091736687312762354406183596115257242708972454);

        static constexpr f32 Pi_f    = Pi   <f32>;
        static constexpr f32 E_f     = E    <f32>;
        static constexpr f32 Phi_f   = Phi  <f32>;
        static constexpr f32 Sqrt2_f = Sqrt2<f32>;
        static constexpr f32 Sqrt3_f = Sqrt3<f32>;
        static constexpr f32 Sqrt5_f = Sqrt5<f32>;

        static constexpr f64 Pi_d    = Pi   <f64>;
        static constexpr f64 E_d     = E    <f64>;
        static constexpr f64 Phi_d   = Phi  <f64>;
        static constexpr f64 Sqrt2_d = Sqrt2<f64>;
        static constexpr f64 Sqrt3_d = Sqrt3<f64>;
        static constexpr f64 Sqrt5_d = Sqrt5<f64>;

        template <typename T>
        struct Epsilon final
        {};

        template <IntegralType T>
        struct Epsilon<T> final
        {
            static constexpr T Value = 0;
        };

        template <>
        struct Epsilon<f32> final
        {
            static constexpr f32 Value = 1.0e-6f;
        };

        template <>
        struct Epsilon<f64> final
        {
            static constexpr f64 Value = 1.0e-10;
        };
    }
}

#endif //MATHLIB_CONSTANTS_HPP
