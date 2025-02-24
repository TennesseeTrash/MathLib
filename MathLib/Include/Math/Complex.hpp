#ifndef MATHLIB_COMPLEX_HPP
#define MATHLIB_COMPLEX_HPP

#include "Base.hpp"
#include "Implementation/Functions/BasicFunctions.hpp"

namespace Math
{
    template <Concept::StrongFloatType T>
    struct Complex final
    {
        using ValueType = T;

        [[nodiscard]] constexpr
        Complex(T real = Cast<T>(0), T imag = Cast<T>(0))
            : Real(real), Imag(imag)
        {}

        [[nodiscard]] friend constexpr
        Complex<T> operator+(Complex<T> a, Complex<T> b) noexcept
        {
            return { a.Real + b.Real, a.Imag + b.Imag };
        }

        [[nodiscard]] friend constexpr
        Complex<T> operator-(Complex<T> a, Complex<T> b) noexcept
        {
            return { a.Real - b.Real, a.Imag - b.Imag };
        }

        [[nodiscard]] friend constexpr
        Complex<T> operator*(Complex<T> a, Complex<T> b) noexcept
        {
            return { a.Real * b.Real - a.Imag * b.Imag,
                     a.Real * b.Imag + a.Imag * b.Real
            };
        }

        [[nodiscard]] friend constexpr
        Complex<T> operator/(Complex<T> a, Complex<T> b) noexcept
        {
            T magSquared = Squared(b.Real) + Squared(b.Imag);
            return { (a.Real * b.Real + a.Imag * b.Imag) / magSquared,
                     (a.Imag * b.Real + a.Real * b.Imag) / magSquared
            };
        }

        ValueType Real;
        ValueType Imag;
    };

    template <typename T>
    [[nodiscard]] constexpr
    T Abs(const Complex<T>& a) noexcept
    {
        return Sqrt(Squared(a.Real) + Squared(a.Imag));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Angle(const Complex<T>& a) noexcept
    {
        return Acos(a.Real / Abs(a));
    }

    template <typename T>
    [[nodiscard]] constexpr
    T Conjugate(const Complex<T>& a) noexcept
    {
        return { a.Real, -a.Imag };
    }

    template <typename T>
    [[nodiscard]] constexpr
    Complex<T> Polar(T r, T angle) noexcept
    {
        return { r * Cos(angle), r * Sin(angle) };
    }

    template <typename T>
    [[nodiscard]] constexpr
    Complex<T> Sqrt(const Complex<T>& a, SizeType i = Cast<SizeType>(0)) noexcept
    {
        T angle = (Angle(a) + Cast<T>(2) * Cast<T>(i) * Constant::Pi<T>) / Cast<T>(2);
        return Polar(Sqrt(Abs(a)), angle);
    }

    template <typename T>
    [[nodiscard]] constexpr
    Complex<T> Cbrt(const Complex<T>& a, SizeType i = 0) noexcept
    {
        T angle = (Angle(a) + Cast<T>(2) * Cast<T>(i) * Constant::Pi<T>) / Cast<T>(3);
        return Polar(Cbrt(Abs(a)), angle);
    }
}

#endif //MATHLIB_COMPLEX_HPP
