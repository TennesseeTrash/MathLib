#ifndef MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP
#define MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP

#include "ElementaryFunctions.hpp"
#include "CompositionFunctions.hpp"
#include "../../../Constants.hpp"
#include "../../../Common/Packs.hpp"

namespace Math::Function
{
    namespace Implementation
    {
        template <typename T, StaticSizeType Order>
        struct Derivative final
        {
            using Type = typename Derivative<typename Derivative<T, 1>::Type, Cast<SizeType>(Order) - 1>::Type;
        };

        template <typename T>
        struct Derivative<T, 0> final
        {
            using Type = T;
        };

        template <typename T, MakeStaticStrongType<T>... TCoefficients>
        struct Derivative<Polynomial<T, TCoefficients...>, 1> final
        {
        private:
            template <typename CoefficientsPack>
            struct ConvertToPolynomial;

            template <typename ValuePackValueType, ValuePackValueType... ValuePackCoefficients>
            struct ConvertToPolynomial<ValuePack<ValuePackValueType, ValuePackCoefficients...>>
            {
                using Type = Polynomial<T, ValuePackCoefficients...>;
            };

            using ValueType = GetValueType<Polynomial<T, TCoefficients...>>;
            using ShiftedCoefficients = ValuePack<MakeStaticStrongType<ValueType>, TCoefficients...>;
            using Multipliers = typename ValuePack<MakeStaticStrongType<ValueType>>::template MakeDescending<sizeof...(TCoefficients)>;
            using DerivedCoefficients = ZipWith<decltype([](ValueType a, ValueType b) { return a * b; }), ShiftedCoefficients, Multipliers>;
            using DerivedPolynomial = typename ConvertToPolynomial<RemoveLast<DerivedCoefficients>>::Type;
            using Zero = Polynomial<T, Cast<ValueType>(0)>;
        public:
            using Type = ConditionalType<sizeof...(TCoefficients) == 1, Zero, DerivedPolynomial>;
        };

        template <typename T, MakeStaticStrongType<T> TExponent, MakeStaticStrongType<T> TMultiplier>
        struct Derivative<Power<T, TExponent, TMultiplier>, 1> final
        {
        private:
            using ValueType = GetValueType<Power<T, TExponent, TMultiplier>>;
        public:
            using Type = Multiply<Constant<ValueType, Cast<ValueType>(TExponent) * Cast<ValueType>(TMultiplier)>, Power<T, Cast<ValueType>(TExponent) - Cast<ValueType>(1)>>;
        };

        template <typename T, MakeStaticStrongType<T> TBase, MakeStaticStrongType<T> TExponentMultiplier>
        struct Derivative<Exponential<T, TBase, TExponentMultiplier>, 1> final
        {
        private:
            // TODO(3011): Currently does not compile due to non-constexpr Log, implement or wait until C++26
            using ValueType = GetValueType<Exponential<T, TBase>>;
            using BaseE = Multiply<Constant<ValueType, TExponentMultiplier>, Exponential<ValueType, TBase, TExponentMultiplier>>;
            using GeneralCase = Multiply<BaseE, Constant<ValueType, Log(TBase)>>;
        public:
            using Type = ConditionalType<Equal(Cast<ValueType>(TBase), Math::Constant::E<ValueType>), BaseE, GeneralCase>;
        };

        template <typename T>
        struct Derivative<NaturalLogarithm<T>, 1> final
        {
        private:
            using ValueType = GetValueType<NaturalLogarithm<T>>;
        public:
            using Type = Divide<Constant<ValueType, Cast<ValueType>(1)>, Linear<ValueType, Cast<ValueType>(1), Cast<ValueType>(0)>>;
        };

        template <typename T, MakeStaticStrongType<T> TBase>
        struct Derivative<Logarithm<T, TBase>, 1> final
        {
        private:
            // TODO(3011): Currently does not compile due to non-constexpr Log, implement or wait until C++26
            using ValueType = GetValueType<Logarithm<T, TBase>>;
        public:
            using Type = Divide<Constant<ValueType, Cast<ValueType>(1)>, Multiply<Linear<ValueType>, Constant<ValueType, Log(TBase)>>>;
        };

        template <typename Func>
        struct Derivative<Minus<Func>, 1> final
        {
            using Type = Minus<typename Derivative<Func, 1>::Type>;
        };

        template <typename... Funcs>
        struct Derivative<Add<Funcs...>, 1> final
        {
            using Type = Add<typename Derivative<Funcs, 1>::Type...>;
        };

        template <typename Subtrahend, typename Subtractor>
        struct Derivative<Subtract<Subtrahend, Subtractor>, 1> final
        {
            using Type = Subtract<typename Derivative<Subtrahend, 1>::Type, typename Derivative<Subtractor, 1>::Type>;
        };

        template <typename Func1, typename Func2>
        struct Derivative<Multiply<Func1, Func2>, 1> final
        {
            using Type = Add<Multiply<typename Derivative<Func1, 1>::Type, Func2>, Multiply<Func1, typename Derivative<Func2, 1>::Type>>;
        };

        template <typename Dividend, typename Divisor>
        struct Derivative<Divide<Dividend, Divisor>, 1> final
        {
        private:
            using ValueType = GetValueType<Divide<Dividend, Divisor>>;
            using DividendFunc = Add<Multiply<typename Derivative<Dividend, 1>::Type, Divisor>, Multiply<Dividend, Minus<typename Derivative<Divisor, 1>::Type>>>;
            using DivisorFunc = PowerCompose<Divisor, Constant<ValueType, Cast<ValueType>(2)>>;
        public:
            using Type = Divide<DividendFunc, DivisorFunc>;
        };

        template <typename Outer, typename Inner>
        struct Derivative<Compose<Outer, Inner>, 1> final
        {
            using Type = Multiply<Compose<typename Derivative<Outer, 1>::Type, Inner>, typename Derivative<Inner, 1>::Type>;
        };

        template <typename Base, typename Exponent>
        struct Derivative<PowerCompose<Base, Exponent>, 1> final
        {
        private:
            using ValueType = GetValueType<PowerCompose<Base, Exponent>>;
            using BaseDerivative = typename Derivative<Base, 1>::Type;
            using ExponentDerivative = typename Derivative<Exponent, 1>::Type;
            using Multiplier = Add<Multiply<BaseDerivative, Divide<Exponent, Base>>, Multiply<ExponentDerivative, Compose<NaturalLogarithm<ValueType>, Base>>>;
        public:
            using Type = Multiply<PowerCompose<Base, Exponent>, Multiplier>;
        };
    }

    template <typename T, StaticSizeType Order = 1>
    using Derivative = typename Implementation::Derivative<T, Order>::Type;
}

#endif //MATHLIB_IMPL_FUNCTIONS_FUNCTION_DERIVATIVES_HPP
