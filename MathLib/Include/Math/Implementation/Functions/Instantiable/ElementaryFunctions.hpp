#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP

#include "../../../Base.hpp"
#include "../BasicFunctions.hpp"
#include "CompositionFunctions.hpp"

namespace Math::Function
{
    template <Concept::StrongType T, T... TCoefficients>
    struct Polynomial final
    {
    public:
        using ValueType = T;

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
        static constexpr Array<ValueType, sizeof...(TCoefficients)> Coefficients = { Cast<ValueType>(TCoefficients)... };

        template <typename CoefficientsPack>
        struct ConvertToPolynomial;

        template <typename ValuePackValueType, ValuePackValueType... ValuePackCoefficients>
        struct ConvertToPolynomial<ValuePack<ValuePackValueType, ValuePackCoefficients...>>
        {
            using Type = Polynomial<T, ValuePackCoefficients...>;
        };

        using CoefficientsPack = ValuePack<ValueType, TCoefficients...>;
        using Multipliers = typename ValuePack<ValueType>::template MakeDescending<sizeof...(TCoefficients)>;
        using MultipliedCoefficients = ZipWith<decltype([](ValueType a, ValueType b) { return a * b; }), CoefficientsPack, Multipliers>;
        using DerivedCoefficients = RemoveLast<MultipliedCoefficients>;
        using DerivedPolynomial = typename ConvertToPolynomial<DerivedCoefficients>::Type;
        using Zero = Polynomial<T, Cast<ValueType>(0)>;
    public:
        using DerivativeType = ConditionalType<sizeof...(TCoefficients) == 1, Zero, DerivedPolynomial>;
    };

    template <Concept::StrongType T, T Constant>
    using Constant = Polynomial<T, Constant>;

    template <Concept::StrongType T, T Slope = Cast<T>(1), T Intercept = Cast<T>(0)>
    using Linear = Polynomial<T, Slope, Intercept>;

    template <Concept::StrongType T, T Square = Cast<T>(1), T Linear = Cast<T>(0), T Constant = Cast<T>(0)>
    using Quadratic = Polynomial<T, Square, Linear, Constant>;

    template <Concept::StrongType T, T Exponent, T Multiplier = Cast<T>(1)>
    struct Power final
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Pow(x, Exponent) * Multiplier;
        }

        using DerivativeType = Multiply<Constant<ValueType, Exponent * Multiplier>, Power<ValueType, Exponent - Cast<ValueType>(1)>>;
    };

    template <Concept::StrongType T, T Base = Math::Constant::E<T>, T ExponentMultiplier = Cast<T>(1)>
    struct Exponential final
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Pow(Base, ExponentMultiplier * x);
        }

        using DerivativeType = Multiply<Constant<ValueType, ExponentMultiplier>, Exponential<ValueType, Base, ExponentMultiplier>>;
    };

    template <Concept::StrongType T>
    struct NaturalLogarithm final
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Log(x);
        }

        using DerivativeType = Divide<Constant<ValueType, Cast<ValueType>(1)>, Linear<ValueType, Cast<ValueType>(1), Cast<ValueType>(0)>>;
    };

    template <Concept::StrongType T, T Base>
    struct Logarithm final
    {
    public:
        using ValueType = T;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            return Log(x) / Log(Base);
        }

        // TODO: Implement Log (or waint until C++26)
        //using DerivativeType = Divide<Constant<ValueType, Cast<ValueType>(1)>, Multiply<Linear<ValueType>, Constant<ValueType, Log(Base)>>>;
        using DerivativeType = Constant<ValueType, Cast<ValueType>(1)>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_INSTANTIABLE_ELEMENTARY_FUNCTIONS_HPP
