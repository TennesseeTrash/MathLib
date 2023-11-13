#ifndef MATHLIB_COMMON_FUNCTION_HPP
#define MATHLIB_COMMON_FUNCTION_HPP

// Note(3011):
// This will be an implementation of the unified interface of mathematical
// functions in this library. The idea is to have all common operations
// on a function defined by a single interface. This interface is what
// will be available to the end user.
//
// Of course, the "internal" implementations will also be visible, and if the
// users choose, they can use them directly. However, most "advanced" uses of
// these functions will be predicated on using specifically this interface.
//
// Currently, the goal is to get a basic interface up and running, performance
// tuning and potential rewrites related to that may come later. However, the
// main goal is to avoid any dynamic allocations inside the library itself,
// as much as possible. (Of course, it may turn out that dynamic allocations
// ironically make the calculations faster, but that's an issue for later.)
//
// Current plans for the interface:
//    - class Function<ConceptFunctionImplementation Func>
//       - T operator(...) <-- Calls through to get the actual value
//       - bool HasDimension<StaticSizeType /* Dim */>()    }\
//       - bool HasDerivative<StaticSizeType /* Order */>() }--- These might be just static constexpr bools
//       - bool HasPartials<StaticSizeType /* Order */>()   }/
//       - T DerivativeValue<StaticSizeType /* Order */>(...) <-- Calls through to get the total derivative value
//       - Array<T, sizeof...(Args)> PartialsValues<StaticSizeType /* Order */>(Args...) <-- Calls through to get the partial derivatives
//
//    - class Derivative<Function>
//       - bool HasDimension<StaticSizeType /* Dim */>() }--- These might just be static constexpr bools
//       - bool HasOrder<StaticSizeType /* Order */>()   }/
//       - T operator(...) <-- Calls through to get the total derivative value
//
//    - class Partials<Function>
//       - bool HasDimension<StaticSizeType /* Dim */>() }--- These might just be static constexpr bools
//       - bool HasOrder<StaticSizeType /* Order */>()   }/
//       - Array<T, sizeof...(Args)> operator()(Args...) <-- Calls through to get the partial derivatives
//
//    Side Note: It might be smart to have Derivative and Partials butcher out the underlying function
//         (#1)  implementation and use that directly, instead of going through the Function interface.
//               That way it makes more sense for them to just have a copy.
//
//    Side Note: Would nesting Derivative and Partials into the Function class be a good idea?
//         (#2)  - Probably, but then it would be e.g. `Perlin::Derivative` instead of `Derivative<Perlin>`
//
//    Side Note: Some functions have a performance benefit when calculating the derivative/partials and the
//         (#3)  value at the same time, because some intermediate values can be reused. How to handle this?
//               (In some cases, the performance overhead of calculating the derivative/partials
//                separately could have the same performance penalty as calculating the value twice.)
//
//    Side Note: How will nesting of functions work? Will it be possible to nest functions inside each other?
//         (#4)     - It definitely should be possible, the question is how hard it will be to implement.
//                  - The most worrisome part is that the some the builders (e.g. Add<Func1, Func2>) will need
//                    to be implemented as the underlying function, instead of the Function wrapper,
//                    but they will need to take the Function wrappers arguments.
//
// Potentially useful internals:
//    - class ConditinalHeapAlloc
//       - Takes care of deciding whether to use dynamic allocation or not
//         based on the size of the function. Should take a MaxStackAllocSize
//         (template) parameter.
//    - struct TrueFor<Values...> or struct FalseFor<Values...>
//             (else false)                 (else true)

#include "Traits.hpp"
#include "Types.hpp"

#include <utility>

namespace Math
{
    template <typename FunctionImpl>
    class Function final
    {
    public:
        using ValueType = GetValueType<FunctionImpl>;

        template <StaticSizeType Dim>
        static constexpr bool HasDimension = FunctionImpl::template HasDimension<Dim>;

        template <StaticSizeType Order>
        static constexpr bool HasDerivative = FunctionImpl::template HasDerivative<Order>;

        template <StaticSizeType Order>
        static constexpr bool HasPartials = FunctionImpl::template HasPartials<Order>;

        template <typename... Args>
        Function(Args&&... args)
            : mFunc(std::forward<Args>(args)...)
        {}

        template <typename... Args>
        auto operator()(Args&&... args) const
        {
            return mFunc.Value(std::forward<Args>(args)...);
        }

        template <StaticSizeType Order = 1, typename... Args>
        auto Derivative(Args&&... args) const
        {
            static_assert(HasDerivative<Order>, "This function does not have a derivative of this order");
            return mFunc.template DerivativeValue<Order>(std::forward<Args>(args)...);
        }

        template <StaticSizeType Order = 1, typename... Args>
        auto Partials(Args&&... args) const
        {
            static_assert(HasPartials<Order>, "This function does not have partial derivatives of this order");
            return mFunc.template PartialsValue<Order>(std::forward<Args>(args)...);
        }
    private:
        FunctionImpl mFunc;

        template <typename FunctionParam, StaticSizeType Order>
            requires IsSpecialization<FunctionParam, Function>
        friend class Derivative;

        template <typename FunctionParam, StaticSizeType Order>
            requires IsSpecialization<FunctionParam, Function>
        friend class Partials;
    };

    template <typename FunctionParam, StaticSizeType Order = 1>
        requires IsSpecialization<FunctionParam, Function>
    class Derivative final
    {
    private:
        using FunctionImpl = TemplateArgument<FunctionParam, Function>;
        static_assert(FunctionImpl::template HasDerivative<Order>, "This function does not have a derivative of this order");
    public:
        using ValueType = GetValueType<FunctionImpl>;

        template <StaticSizeType Dim>
        static constexpr bool HasDimension = FunctionImpl::template HasDimension<Dim>;

        template <typename... Args>
            requires (sizeof...(Args) != 1 && ((!IsSpecialization<Args, Function>) && ...))
        [[nodiscard]] constexpr
        Derivative(Args&&... args)
            : mFunc(std::forward<Args>(args)...)
        {}

        [[nodiscard]] constexpr
        Derivative(const Function<FunctionImpl>& func)
            : mFunc(func.mFunc)
        {}

        template <typename... Args>
        [[nodiscard]] constexpr
        auto operator()(Args&&... args) const
        {
            return mFunc.template DerivativeValue<Order>(std::forward<Args>(args)...);
        }
    private:
        FunctionImpl mFunc;
    };

    template <typename FunctionParam, StaticSizeType Order = 1>
        requires IsSpecialization<FunctionParam, Function>
    class Partials final
    {
    private:
        using FunctionImpl = TemplateArgument<FunctionParam, Function>;
        static_assert(FunctionImpl::template HasPartials<Order>, "This function does not have partial derivatives of this order");
    public:
        using ValueType = GetValueType<FunctionImpl>;

        template <StaticSizeType Dim>
        static constexpr bool HasDimension = FunctionImpl::template HasDimension<Dim>;

        template <typename... Args>
            requires (sizeof...(Args) != 1 && ((!IsSpecialization<Args, Function>) && ...))
        [[nodiscard]] constexpr
        Partials(Args&&... args)
            : mFunc(std::forward<Args>(args)...)
        {}

        [[nodiscard]] constexpr
        Partials(const Function<FunctionImpl>& func)
            : mFunc(func.mFunc)
        {}

        template <typename... Args>
        [[nodiscard]] constexpr
        auto operator()(Args&&... args) const
        {
            return mFunc.template PartialsValue<Order>(std::forward<Args>(args)...);
        }
    private:
        FunctionImpl mFunc;
    };
}

#endif //MATHLIB_COMMON_FUNCTION_HPP
