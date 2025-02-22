#ifndef MATHLIB_IMPLEMENTATION_BASE_COMPLEX_HPP
#define MATHLIB_IMPLEMENTATION_BASE_COMPLEX_HPP

#include "Concepts.hpp"

namespace Math
{
    template <Concept::StrongFloatType T>
    struct Complex final
    {
        using ValueType = T;

        [[nodiscard]] constexpr
        Complex(T real, T imag = Cast<T>(0))
            : Real(real), Imag(imag)
        {}

        [[nodiscard]] friend constexpr Complex<T> operator+(Complex<T> a, Complex<T> b) noexcept { return { a.Real + b.Real, a.Imag + b.Imag }; }
        [[nodiscard]] friend constexpr Complex<T> operator+(Complex<T> a, Complex<T> b) noexcept { return { a.Real - b.Real, a.Imag - b.Imag }; }

        ValueType Real;
        ValueType Imag;
    };
}

#endif //MATHLIB_IMPLEMENTATION_BASE_COMPLEX_HPP
