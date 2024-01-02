#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP

#include "../../../Common/Types.hpp"

namespace Math::Function
{
    template <typename T>
    struct ControlPoint final
    {
        MakeStaticStrongType<T> Value;
        Orientation Side;
    };

    //template <typename LeftFunc, typename RightFunc, ControlPoint<GetValueType<LeftFunc, RightFunc>> Boundary>
    //struct Piecewise final
    //{
    //public:
    //    using ValueType = GetValueType<LeftFunc, RightFunc>;
    //    static constexpr LeftFunc  LeftFuncInstance;
    //    static constexpr RightFunc RightFuncInstance;
    //
    //    [[nodiscard]] constexpr
    //    ValueType operator()(ValueType x) const noexcept
    //    {
    //        if constexpr (Boundary.Side == Orientation::Left)
    //        {
    //            return (x <= Boundary.Value) ? LeftFuncInstance(x) : RightFuncInstance(x);
    //        }
    //        else if constexpr (Boundary.Side == Orientation::Right)
    //        {
    //            return (x >= Boundary.Value) ? RightFuncInstance(x) : LeftFuncInstance(x);
    //        }
    //    }
    //
    //    using DerivativeType = Piecewise<typename LeftFunc::DerivativeType, typename RightFunc::DerivativeType, Boundary, BoundarySide>;
    //};

    template <typename FuncPack, typename BoundaryPack>
    struct Piecewise;

    template <typename... Funcs, ControlPoint<GetValueType<Funcs...>>... Boundaries>
        requires ((sizeof...(Funcs) == sizeof...(Boundaries) + 1) && (sizeof...(Funcs) > 2))
    struct Piecewise<TypePack<Funcs...>, ValuePack<ControlPoint<GetValueType<Funcs...>>, Boundaries...>> final
    {
    public:
        using ValueType = GetValueType<Funcs...>;
        static constexpr ControlPoint<ValueType> FirstBoundary = ValuePack<ControlPoint<ValueType>, Boundaries...>::template At<0>;
        static constexpr typename TypePack<Funcs...>::template At<0> FirstFuncInstance;
        static constexpr Piecewise<RemoveFirst<TypePack<Funcs...>>, RemoveFirst<ValuePack<ControlPoint<ValueType>, Boundaries...>>> RemainingFuncsInstance;

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

        using DerivativeType = Piecewise<TypePack<typename Funcs::DerivativeType...>, ValuePack<ControlPoint<ValueType>, Boundaries...>>;
    };

    template <typename LeftFunc, typename RightFunc, ControlPoint<GetValueType<LeftFunc, RightFunc>> Boundary>
    struct Piecewise<TypePack<LeftFunc, RightFunc>, ValuePack<ControlPoint<GetValueType<LeftFunc, RightFunc>>, Boundary>> final
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

        using DerivativeType = Piecewise<TypePack<typename LeftFunc::DerivativeType, typename RightFunc::DerivativeType>, ValuePack<ControlPoint<ValueType>, Boundary>>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_PIECEWISE_FUNCTIONS_HPP
