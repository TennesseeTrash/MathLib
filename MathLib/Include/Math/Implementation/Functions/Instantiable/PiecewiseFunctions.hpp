#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP

#include "../../Base/Types.hpp"

namespace Math::Function
{
    template <typename T>
    struct ControlPoint final
    {
        MakeStrongType<T> Value;
        Orientation Side;
    };

    template <typename FuncPack, typename BoundaryPack>
    struct GeneralPiecewise;

    template <typename... Funcs, ControlPoint<GetValueType<Funcs...>>... Boundaries>
        requires ((sizeof...(Funcs) == sizeof...(Boundaries) + 1))
    struct GeneralPiecewise<TypePack<Funcs...>, ValuePack<ControlPoint<GetValueType<Funcs...>>, Boundaries...>> final
    {
    private:
        using NextPiecewise = GeneralPiecewise<RemoveFirst<TypePack<Funcs...>>, RemoveFirst<ValuePack<ControlPoint<GetValueType<Funcs...>>, Boundaries...>>>;
    public:
        using ValueType = GetValueType<Funcs...>;
        static constexpr ControlPoint<ValueType> FirstBoundary = ValuePack<ControlPoint<ValueType>, Boundaries...>::template At<0>;
        static constexpr typename TypePack<Funcs...>::First FirstFuncInstance;
        static constexpr ConditionalType<(TypePack<Funcs...>::Size > 2), NextPiecewise, typename TypePack<Funcs...>::Last> RemainingFuncsInstance;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            if constexpr (FirstBoundary.Side == Orientation::Left)
            {
                return (x <= FirstBoundary.Value) ? FirstFuncInstance(x) : RemainingFuncsInstance(x);
            }
            else if constexpr (FirstBoundary.Side == Orientation::Right)
            {
                return (x >= FirstBoundary.Value) ? RemainingFuncsInstance(x) : FirstFuncInstance(x);
            }
        }

        using DerivativeType = GeneralPiecewise<TypePack<typename Funcs::DerivativeType...>, ValuePack<ControlPoint<ValueType>, Boundaries...>>;

        template <typename NextFunc, ControlPoint<GetValueType<Funcs..., NextFunc>> NextBoundary>
            requires (Cast<ValueType>(ValuePack<ControlPoint<ValueType>, Boundaries...>::Last.Value) < Cast<ValueType>(NextBoundary.Value))
        using AddSegment = GeneralPiecewise<TypePack<Funcs..., NextFunc>, ValuePack<ControlPoint<ValueType>, Boundaries..., NextBoundary>>;
    };

    template <typename LeftFunc, typename RightFunc, ControlPoint<GetValueType<LeftFunc, RightFunc>> Boundary>
    struct Piecewise
    {
    public:
        using ValueType = GetValueType<LeftFunc, RightFunc>;
        static constexpr LeftFunc  LeftFuncInstance;
        static constexpr RightFunc RightFuncInstance;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            if constexpr (Boundary.Side == Orientation::Left)
            {
                return (x <= Boundary.Value) ? LeftFuncInstance(x) : RightFuncInstance(x);
            }
            else if constexpr (Boundary.Side == Orientation::Right)
            {
                return (x >= Boundary.Value) ? RightFuncInstance(x) : LeftFuncInstance(x);
            }
        }

        using DerivativeType = Piecewise<typename LeftFunc::DerivativeType, typename RightFunc::DerivativeType, Boundary>;

        template <typename NextFunc, ControlPoint<GetValueType<LeftFunc, RightFunc, NextFunc>> NextBoundary>
            requires (Cast<ValueType>(Boundary.Value) < Cast<ValueType>(NextBoundary.Value))
        using AddSegment = GeneralPiecewise<TypePack<LeftFunc, RightFunc, NextFunc>, ValuePack<ControlPoint<ValueType>, Boundary, NextBoundary>>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP
