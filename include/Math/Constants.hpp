#ifndef _MATH_CONSTANTS_HPP
#define _MATH_CONSTANTS_HPP

namespace cc
{
    namespace Constants
    {
        template <typename T>
        inline static constexpr T Pi    = T(3.1415926535897932384626433832795028841971693993751058209749445923);
        template <typename T>
        inline static constexpr T E     = T(2.7182818284590452353602874713526624977572470936999595749669676277);
        template <typename T>
        inline static constexpr T Phi   = T(1.6180339887498948482045868343656381177203091798057628621354486227);
        template <typename T>
        inline static constexpr T Sqrt2 = T(1.4142135623730950488016887242096980785696718753769480731766797379);
        template <typename T>
        inline static constexpr T Sqrt3 = T(1.7320508075688772935274463415058723669428052538103806280558069794);
        template <typename T>
        inline static constexpr T Sqrt5 = T(2.2360679774997896964091736687312762354406183596115257242708972454);

        inline static constexpr float Pi_f    = Pi   <float>;
        inline static constexpr float E_f     = E    <float>;
        inline static constexpr float Phi_f   = Phi  <float>;
        inline static constexpr float Sqrt2_f = Sqrt2<float>;
        inline static constexpr float Sqrt3_f = Sqrt3<float>;
        inline static constexpr float Sqrt5_f = Sqrt5<float>;

        inline static constexpr double Pi_d    = Pi   <double>;
        inline static constexpr double E_d     = E    <double>;
        inline static constexpr double Phi_d   = Phi  <double>;
        inline static constexpr double Sqrt2_d = Sqrt2<double>;
        inline static constexpr double Sqrt3_d = Sqrt3<double>;
        inline static constexpr double Sqrt5_d = Sqrt5<double>;
    }
}

#endif //_MATH_CONSTANTS_HPP
