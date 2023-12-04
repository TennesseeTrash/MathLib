#ifndef MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP
#define MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP

#include "ElementaryFunctions.hpp"
#include "CompositionFunctions.hpp"

namespace Math::Function
{
    namespace Implementation
    {
        template <typename T, StaticSizeType Order>
        struct Derivative
        {
            using Type = typename Derivative<typename Derivative<T, 1>::Type, Cast<SizeType>(Order) - 1>::Type;
        };

        template <typename T>
        struct Derivative<T, 0>
        {
            using Type = T;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TValue>
        struct Derivative<Constant<T, TValue>, 1>
        {
            using Type = Constant<T, Cast<T>(0)>;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TSlope, ::Math::MakeStaticStrongType<T> TIntercept>
        struct Derivative<Linear<T, TSlope, TIntercept>, 1>
        {
            using Type = Constant<T, TSlope>;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TSquare, ::Math::MakeStaticStrongType<T> TLinear, ::Math::MakeStaticStrongType<T> TConstant>
        struct Derivative<Quadratic<T, TSquare, TLinear, TConstant>, 1>
        {
            using ValueType = ::Math::GetValueType<Quadratic<T, TSquare, TLinear, TConstant>>;
            using Type = Linear<ValueType, Cast<ValueType>(2) * TSquare, TLinear>;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TExponent, MakeStaticStrongType<T> TMultiplier>
        struct Derivative<Power<T, TExponent, TMultiplier>, 1>
        {
            using ValueType = ::Math::GetValueType<Power<T, TExponent, TMultiplier>>;
            using Type = Multiply<Constant<ValueType, Cast<ValueType>(TExponent) * Cast<ValueType>(TMultiplier)>, Power<T, Cast<ValueType>(TExponent) - Cast<ValueType>(1)>>;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TBase, ::Math::MakeStaticStrongType<T> TExponentMultiplier>
        struct Derivative<Exponential<T, TBase, TExponentMultiplier>, 1>
        {
            // TODO(3011): Currently does not compile due to non-constexpr Log, implement or wait until C++26
            using ValueType = ::Math::GetValueType<Exponential<T, TBase>>;
            using BaseE = Multiply<Constant<ValueType, TExponentMultiplier>, Exponential<ValueType, TBase, TExponentMultiplier>>;
            using GeneralCase = Multiply<BaseE, Constant<ValueType, ::Math::Log(TBase)>>;
            using Type = ::Math::ConditionalType<::Math::Equal(Cast<ValueType>(TBase), ::Math::Constants::E<ValueType>), BaseE, GeneralCase>;
        };

        template <typename T>
        struct Derivative<NaturalLogarithm<T>, 1>
        {
            using ValueType = ::Math::GetValueType<NaturalLogarithm<T>>;
            using Type = Divide<Constant<ValueType, Cast<ValueType>(1)>, Linear<ValueType, Cast<ValueType>(1), Cast<ValueType>(0)>>;
        };

        template <typename T, ::Math::MakeStaticStrongType<T> TBase>
        struct Derivative<Logarithm<T, TBase>, 1>
        {
            // TODO(3011): Currently does not compile due to non-constexpr Log, implement or wait until C++26
            using ValueType = ::Math::GetValueType<Logarithm<T, TBase>>;
            using Type = Divide<Constant<ValueType, Cast<ValueType>(1)>, Multiply<Linear<ValueType>, Constant<ValueType, Log(TBase)>>>;
        };

        template <typename Func>
        struct Derivative<Minus<Func>, 1>
        {
            using Type = Minus<typename Derivative<Func, 1>::Type>;
        };

        template <typename... Funcs>
        struct Derivative<Add<Funcs...>, 1>
        {
            using Type = Add<typename Derivative<Funcs, 1>::Type...>;
        };

        template <typename Subtrahend, typename Subtractor>
        struct Derivative<Subtract<Subtrahend, Subtractor>, 1>
        {
            using Type = Subtract<typename Derivative<Subtrahend, 1>::Type, typename Derivative<Subtractor, 1>::Type>;
        };

        template <typename Func1, typename Func2>
        struct Derivative<Multiply<Func1, Func2>, 1>
        {
            using Type = Add<Multiply<typename Derivative<Func1, 1>::Type, Func2>, Multiply<Func1, typename Derivative<Func2, 1>::Type>>;
        };

        template <typename Dividend, typename Divisor>
        struct Derivative<Divide<Dividend, Divisor>, 1>
        {
            using ValueType = ::Math::GetValueType<Divide<Dividend, Divisor>>;
            using DividendFunc = Add<Multiply<typename Derivative<Dividend, 1>::Type, Divisor>, Multiply<Dividend, Minus<typename Derivative<Divisor, 1>::Type>>>;
            using DivisorFunc = PowerCompose<Divisor, Constant<ValueType, Cast<ValueType>(2)>>;
            using Type = Divide<DividendFunc, DivisorFunc>;
        };

        template <typename Outer, typename Inner>
        struct Derivative<Compose<Outer, Inner>, 1>
        {
            using Type = Multiply<Compose<typename Derivative<Outer, 1>::Type, Inner>, typename Derivative<Inner, 1>::Type>;
        };

        template <typename Base, typename Exponent>
        struct Derivative<PowerCompose<Base, Exponent>, 1>
        {
            using ValueType = ::Math::GetValueType<PowerCompose<Base, Exponent>>;
            using BaseDerivative = typename Derivative<Base, 1>::Type;
            using ExponentDerivative = typename Derivative<Exponent, 1>::Type;
            using Multiplier = Add<Multiply<BaseDerivative, Divide<Exponent, Base>>, Multiply<ExponentDerivative, Compose<NaturalLogarithm<ValueType>, Base>>>;
            using Type = Multiply<PowerCompose<Base, Exponent>, Multiplier>;
        };
    }

    template <typename T, StaticSizeType Order = 1>
    using Derivative = typename Implementation::Derivative<T, Order>::Type;
}

#endif //MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP
