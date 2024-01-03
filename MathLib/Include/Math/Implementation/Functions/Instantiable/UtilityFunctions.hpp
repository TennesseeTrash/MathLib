#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_UTILITY_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_UTILITY_FUNCTIONS_HPP

#include "ElementaryFunctions.hpp"
#include "CompositionFunctions.hpp"
#include "PiecewiseFunctions.hpp"

namespace Math::Function
{
    template <typename T, MakeStaticStrongType<T> TBegin, MakeStaticStrongType<T> TEnd>
    struct Lerp final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Begin = Cast<ValueType>(TBegin);
        static constexpr ValueType End = Cast<ValueType>(TEnd);

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return (1 - x) * Begin + x * End;
        }

        using DerivativeType = Constant<T, Cast<MakeStaticStrongType<T>>(1)>;
    };

    template <typename T, MakeStaticStrongType<T> TBegin, MakeStaticStrongType<T> TEnd>
    struct InverseLerp final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Begin = Cast<ValueType>(TBegin);
        static constexpr ValueType End = Cast<ValueType>(TEnd);

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return (x - Begin) / (End - Begin);
        }

        using DerivativeType = Constant<T, Cast<MakeStaticStrongType<T>>(1)>;
    };

    template <typename T, MakeStaticStrongType<T> TBegin = Cast<T>(0), MakeStaticStrongType<T> TEnd = Cast<T>(1)>
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

    template <typename T, MakeStaticStrongType<T> TBegin = Cast<T>(0), MakeStaticStrongType<T> TEnd = Cast<T>(1)>
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
