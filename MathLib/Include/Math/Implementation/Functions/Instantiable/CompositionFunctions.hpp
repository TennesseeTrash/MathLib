#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_COMPOSITION_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_COMPOSITION_FUNCTIONS_HPP

#include "../../../Common/Types.hpp"

namespace Math::Function
{
    // Note(3011): Forward decl for PowerCompose.
    template <typename T>
    struct NaturalLogarithm;

    template <typename Func>
    struct Minus final
    {
    public:
        using ValueType = GetValueType<Func>;
        static constexpr Func FuncInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return -FuncInstance(args...);
        }

        using DerivativeType = Minus<typename Func::DerivativeType>;
    };

    template <typename... Funcs>
    struct Add;

    template <typename FirstFunc, typename SecondFunc>
    struct Add<FirstFunc, SecondFunc> final
    {
    public:
        using ValueType = GetValueType<FirstFunc, SecondFunc>;
        static constexpr FirstFunc  FirstFuncInstance;
        static constexpr SecondFunc SecondFuncInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return FirstFuncInstance(args...) + SecondFuncInstance(args...);
        }

        using DerivativeType = Add<typename FirstFunc::DerivativeType, typename SecondFunc::DerivativeType>;
    };

    template <typename Func, typename... RemainingFuncs>
    struct Add<Func, RemainingFuncs...> final
    {
    public:
        using ValueType = GetValueType<Func, RemainingFuncs...>;
        static constexpr Func                   FuncInstance;
        static constexpr Add<RemainingFuncs...> RemainingFuncsInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return FuncInstance(args...) + RemainingFuncsInstance(args...);
        }

        using DerivativeType = Add<typename Func::DerivativeType, typename Add<RemainingFuncs...>::DerivativeType>;
    };

    template <typename Subtrahend, typename Subtractor>
    struct Subtract final
    {
    public:
        using ValueType = GetValueType<Subtrahend, Subtractor>;
        static constexpr Subtrahend SubtrahendInstance;
        static constexpr Subtractor SubtractorInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return SubtrahendInstance(args...) - SubtractorInstance(args...);
        }

        using DerivativeType = Subtract<typename Subtrahend::DerivativeType, typename Subtractor::DerivativeType>;
    };

    template <typename... Funcs>
    struct Multiply;

    template <typename FirstFunc, typename SecondFunc>
    struct Multiply<FirstFunc, SecondFunc> final
    {
    public:
        using ValueType = GetValueType<FirstFunc, SecondFunc>;
        static constexpr FirstFunc  FirstFuncInstance;
        static constexpr SecondFunc SecondFuncInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return FirstFuncInstance(args...) * SecondFuncInstance(args...);
        }

        using DerivativeType = Add<Multiply<typename FirstFunc::DerivativeType, SecondFunc>, Multiply<FirstFunc, typename SecondFunc::DerivativeType>>;
    };

    template <typename Func, typename... RemainingFuncs>
    struct Multiply<Func, RemainingFuncs...> final
    {
    public:
        using ValueType = GetValueType<Func, RemainingFuncs...>;
        static constexpr Func                        FuncInstance;
        static constexpr Multiply<RemainingFuncs...> RemainingFuncsInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return FuncInstance(args...) * RemainingFuncsInstance(args...);
        }

        using DerivativeType = Add<Multiply<typename Func::DerivativeType, Multiply<RemainingFuncs...>>, Multiply<Func, typename Multiply<RemainingFuncs...>::DerivativeType>>;
    };

    template <typename Dividend, typename Divisor>
    struct Divide final
    {
    public:
        using ValueType = GetValueType<Dividend, Divisor>;
        static constexpr Dividend DividendInstance;
        static constexpr Divisor  DivisorInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return DividendInstance(args...) / DivisorInstance(args...);
        }

        using DerivativeType = Divide<Subtract<Multiply<typename Dividend::DerivativeType, Divisor>, Multiply<Dividend, typename Divisor::DerivativeType>>, Multiply<Divisor, Divisor>>;
    };

    template <typename Outer, typename Inner>
    struct Compose final
    {
    public:
        using ValueType = GetValueType<Outer, Inner>;
        static constexpr Outer OuterInstance;
        static constexpr Inner InnerInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return OuterInstance(InnerInstance(args...));
        }

        using DerivativeType = Multiply<Compose<typename Outer::DerivativeType, Inner>, typename Inner::DerivativeType>;
    };

    template <typename Base, typename Exponent>
    struct PowerCompose final
    {
    public:
        using ValueType = GetValueType<Base, Exponent>;
        static constexpr Base     BaseInstance;
        static constexpr Exponent ExponentInstance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return Pow(BaseInstance(args...), ExponentInstance(args...));
        }

        using DerivativeType = Multiply<PowerCompose<Base, Exponent>, Add<Multiply<typename Base::DerivativeType, Divide<Exponent, Base>>, Multiply<typename Exponent::DerivativeType, Compose<NaturalLogarithm<ValueType>, Base>>>>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_COMPOSITION_FUNCTIONS_HPP
