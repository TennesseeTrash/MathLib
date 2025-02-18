#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP

#include "../../Base.hpp"

namespace Math
{
    template <typename T, SizeType N>
    struct Roots
    {
        SizeType Count;
        Array<T, N> Roots;
    };

    template <Concept::StrongFloatType T>
    Roots<T, 2> QuadraticRoots(T a, T b, T c)
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
            .Roots = { root1, root2 },
        };
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_POLYNOMIALS_HPP
