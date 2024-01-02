#ifndef MATHLIB_IMPL_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP

#include "../../../Common/Types.hpp"
#include "../../../Common/Array.hpp"
#include "../../../Common/Packs.hpp"
#include "../BasicFunctions.hpp"
#include "CompositionFunctions.hpp"

namespace Math::Function
{
    template <typename T, MakeStaticStrongType<T>... TCoefficients>
    struct Polynomial final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr Array<ValueType, sizeof...(TCoefficients)> Coefficients = { Cast<ValueType>(TCoefficients)... };

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            if constexpr (Coefficients.Size == 0)
            {
                return Cast<ValueType>(0);
            }
            ValueType result = Coefficients[0];
            for (SizeType i = 1; i < Coefficients.Size; ++i)
            {
                result = result * x + Coefficients[i];
            }
            return result;
        }

    private:
        template <typename CoefficientsPack>
        struct ConvertToPolynomial;

        template <typename ValuePackValueType, ValuePackValueType... ValuePackCoefficients>
        struct ConvertToPolynomial<ValuePack<ValuePackValueType, ValuePackCoefficients...>>
        {
            using Type = Polynomial<T, ValuePackCoefficients...>;
        };

        using StaticValueType = MakeStaticStrongType<ValueType>;
        using CoefficientsPack = ValuePack<StaticValueType, TCoefficients...>;
        using Multipliers = typename ValuePack<StaticValueType>::template MakeDescending<sizeof...(TCoefficients)>;
        using MultipliedCoefficients = ZipWith<decltype([](ValueType a, ValueType b) { return a * b; }), CoefficientsPack, Multipliers>;
        using DerivedCoefficients = RemoveLast<MultipliedCoefficients>;
        using DerivedPolynomial = typename ConvertToPolynomial<DerivedCoefficients>::Type;
        using Zero = Polynomial<T, Cast<StaticValueType>(0)>;
    public:
        using DerivativeType = ConditionalType<sizeof...(TCoefficients) == 1, Zero, DerivedPolynomial>;
    };

    template <typename T, MakeStaticStrongType<T> TConstant>
    using Constant = Polynomial<T, TConstant>;

    template <typename T, MakeStaticStrongType<T> TSlope = Cast<T>(1), MakeStaticStrongType<T> TIntercept = Cast<T>(0)>
    using Linear = Polynomial<T, TSlope, TIntercept>;

    template <typename T, MakeStaticStrongType<T> TSquare = Cast<T>(1), MakeStaticStrongType<T> TLinear = Cast<T>(0), MakeStaticStrongType<T> TConstant = Cast<T>(0)>
    using Quadratic = Polynomial<T, TSquare, TLinear, TConstant>;

    template <typename T, MakeStaticStrongType<T> TExponent, MakeStaticStrongType<T> TMultiplier = Cast<T>(1)>
    struct Power final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Exponent = TExponent;
        static constexpr ValueType Multiplier = TMultiplier;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Pow(x, Exponent) * Multiplier;
        }

        using DerivativeType = Multiply<Constant<ValueType, Exponent * Multiplier>, Power<ValueType, Exponent - Cast<ValueType>(1)>>;
    };

    template <typename T, MakeStaticStrongType<T> TBase = Math::Constant::E<T>, MakeStaticStrongType<T> TExponentMultiplier = Cast<T>(1)>
    struct Exponential final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Base = TBase;
        static constexpr ValueType ExponentMultiplier = TExponentMultiplier;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Pow(Base, ExponentMultiplier * x);
        }

        using DerivativeType = Multiply<Constant<ValueType, ExponentMultiplier>, Exponential<ValueType, Base, ExponentMultiplier>>;
    };

    template <typename T>
    struct NaturalLogarithm final
    {
    public:
        using ValueType = MakeStrongType<T>;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Log(x);
        }

        using DerivativeType = Divide<Constant<ValueType, Cast<ValueType>(1)>, Linear<ValueType, Cast<ValueType>(1), Cast<ValueType>(0)>>;
    };

    template <typename T, MakeStaticStrongType<T> TBase>
    struct Logarithm final
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Base = TBase;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Log(x) / Log(Base);
        }

        // TODO: Implement Log
        //using DerivativeType = Divide<Constant<ValueType, Cast<ValueType>(1)>, Multiply<Linear<ValueType>, Constant<ValueType, Log(Base)>>>;
        using DerivativeType = Constant<ValueType, Cast<ValueType>(1)>;
    };
}

#endif //MATHLIB_IMPL_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP
