#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_UTILITY_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_UTILITY_FUNCTIONS_HPP

#include "ElementaryFunctions.hpp"
#include "CompositionFunctions.hpp"
#include "PiecewiseFunctions.hpp"

namespace Math::Function
{
    template <typename T, MakeStrongType<T> Begin, MakeStrongType<T> End>
    struct Lerp final
    {
    public:
        using ValueType = MakeStrongType<T>;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return (1 - x) * Begin + x * End;
        }

        using DerivativeType = Constant<T, Cast<ValueType>(1)>;
    };

    template <typename T, MakeStrongType<T> Begin, MakeStrongType<T> End>
    struct InverseLerp final
    {
    public:
        using ValueType = MakeStrongType<T>;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return (x - Begin) / (End - Begin);
        }

        using DerivativeType = Constant<T, Cast<ValueType>(1)>;
    };

    template <typename T, MakeStrongType<T> TBegin = Cast<T>(0), MakeStrongType<T> TEnd = Cast<T>(1)>
    using Smoothstep = GeneralPiecewise<
        TypePack<
            Constant<T, Cast<T>(0)>,
            Compose<
                Polynomial<T, Cast<T>(-2), Cast<T>(3), Cast<T>(0), Cast<T>(0)>,
                InverseLerp<T, TBegin, TEnd>
            >,
            Constant<T, Cast<T>(1)>
        >,
        ValuePack<
            ControlPoint<T>,
            ControlPoint<T>{ TBegin, Orientation::Right },
            ControlPoint<T>{ TEnd, Orientation::Left }
        >
    >;

    template <typename T, MakeStrongType<T> TBegin = Cast<T>(0), MakeStrongType<T> TEnd = Cast<T>(1)>
    using Smootherstep = GeneralPiecewise<
        TypePack<
            Constant<T, Cast<T>(0)>,
            Compose<
                Polynomial<T, Cast<T>(6), Cast<T>(-15), Cast<T>(10), Cast<T>(0), Cast<T>(0), Cast<T>(0)>,
                InverseLerp<T, TBegin, TEnd>
            >,
            Constant<T, Cast<T>(1)>
        >,
        ValuePack<
            ControlPoint<T>,
            ControlPoint<T>{ TBegin, Orientation::Right },
            ControlPoint<T>{ TEnd, Orientation::Left }
        >
    >;
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_UTILITY_FUNCTIONS_HPP
