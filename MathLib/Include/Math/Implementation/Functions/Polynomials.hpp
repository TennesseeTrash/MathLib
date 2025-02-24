#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP

#include "../../Base.hpp"

// TODO(3011): Yeet this header after cleaning up the cubic roots mess
#include <complex>

namespace Math
{
    template <typename T, SizeType N>
    struct Roots
    {
        SizeType Count;
        Array<T, N> Roots;
    };

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Roots<T, 2> QuadraticRoots(T a, T b, T c) noexcept
    {
        T discriminant = Squared(b) - Cast<T>(4) * a * c;

        if (Equal(discriminant, Cast<T>(0)))
        {
            return {
                .Count = 1,
                .Roots = { -b / (Cast<T>(2) * a), T::NaN() },
            };
        }
        if (discriminant < Cast<T>(0))
        {
            return {
                .Count = 0,
                .Roots = { T::NaN(), T::NaN() },
            };
        }

        T root1 = (-b + Sqrt(discriminant)) / (Cast<T>(2) * a);
        T root2 = (-b - Sqrt(discriminant)) / (Cast<T>(2) * a);
        return {
            .Count = 2,
            .Roots = { Min(root1, root2), Max(root1, root2) },
        };
    }

    template <Concept::StrongFloatType T>
    [[nodiscard]] constexpr
    Roots<T, 3> CubicRoots(T a, T b, T c, T d) noexcept
    {
        T delta = Cast<T>(-27) * Squared(a) * Squared(d) + Cast<T>(18) * a * b * c * d
                - Cast<T>(4) * a * Cubed(c) - Cast<T>(4) * Cubed(b) * d + Squared(b) * Squared(c);
        T delta0 = Squared(b) - Cast<T>(3) * a * c;
        T delta1 = Cast<T>(2) * Cubed(b) - Cast<T>(9) * a * b * c + Cast<T>(27) * Squared(a) * d;

        T coeff;
        if (Equal(delta0, Cast<T>(0)))
        {
            coeff = Cbrt(delta1);
        }
        else
        {
            coeff = Cbrt((delta1 + Sqrt(Squared(delta1) - Cast<T>(4) * Cubed(delta0))) / Cast<T>(2));
        }

        if (Equal(delta, Cast<T>(0)))
        {
            if (Equal(delta0, Cast<T>(0)))
            {
                return {
                    .Count = 1,
                    .Roots = { b / (Cast<T>(-3) * a), T::NaN(), T::NaN() },
                };
            }
            else
            {
                T root1 = (Cast<T>(9) * a * d - b * c) / (Cast<T>(2) * delta0);
                T root2 = (Cast<T>(4) * a * b * c - Cast<T>(9) * Squared(a) * d - Cubed(b)) / (a * delta0);
                return {
                    .Count = 2,
                    .Roots = { Min(root1, root2), Max(root1, root2), T::NaN() },
                };
            }
        }
        else if (delta < Cast<T>(0))
        {
            T root = (Cast<T>(-1) / (Cast<T>(3) * a)) * (b + coeff + delta0 / coeff);
            return {
                .Count = 1,
                .Roots = { root, T::NaN(), T::NaN() },
            };
        }
        else
        {
            // TODO(3011): Clean up this horrible mess ...
            using Float = decltype(ToUnderlying(a));
            using Complex = std::complex<Float>;
            Complex u1 = (-1.0f + Complex(0, 1) * std::sqrt(3.0f)) / 2.0f;
            Complex u2 = (-1.0f - Complex(0, 1) * std::sqrt(3.0f)) / 2.0f;
            Complex coeff1 = std::pow((ToUnderlying(delta1) + std::sqrt(Squared(ToUnderlying(delta1)) - Complex(4) * Cubed(ToUnderlying(delta0)))) / 2.0f, 1.0f / 3.0f);
            T root1 = (-1 / (3 * ToUnderlying(a))) * (ToUnderlying(b) + coeff1 + ToUnderlying(delta0) / coeff1).real();
            T root2 = ((-1 / (3 * ToUnderlying(a))) * (ToUnderlying(b) + u1 * ToUnderlying(coeff1) + ToUnderlying(delta0) / (u1 * ToUnderlying(coeff1)))).real();
            T root3 = ((-1 / (3 * ToUnderlying(a))) * (ToUnderlying(b) + u2 * ToUnderlying(coeff1) + ToUnderlying(delta0) / (u2 * ToUnderlying(coeff1)))).real();

            // TODO(3011): This is unnecessarily inefficient ...
            T min = Min(root1, root2, root3);
            T mid = Mid(root1, root2, root3);
            T max = Max(root1, root2, root3);

            return {
                .Count = 3,
                .Roots = { min, mid, max },
            };
        }
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP
