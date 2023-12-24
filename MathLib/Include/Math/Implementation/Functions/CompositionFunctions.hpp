#ifndef MATHLIB_IMPL_FUNCTIONS_COMPOSITION_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_COMPOSITION_FUNCTIONS_HPP

namespace Math::Function
{
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
    };

    template <typename... Funcs>
    struct Add;

    template <typename Func1, typename Func2>
    struct Add<Func1, Func2> final
    {
    public:
        using ValueType = GetValueType<Func1, Func2>;
        static constexpr Func1 Func1Instance;
        static constexpr Func2 Func2Instance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return Func1Instance(args...) + Func2Instance(args...);
        }
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
    };

    template <typename Func1, typename Func2>
    struct Multiply final
    {
    public:
        using ValueType = GetValueType<Func1, Func2>;
        static constexpr Func1 Func1Instance;
        static constexpr Func2 Func2Instance;

        template <typename... Args>
        [[nodiscard]] constexpr
        ValueType operator()(Args... args) const
        {
            return Func1Instance(args...) * Func2Instance(args...);
        }
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
    };
}

#endif //MATHLIB_IMPL_FUNCTIONS_COMPOSITION_FUNCTIONS_HPP
