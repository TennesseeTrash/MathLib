#ifndef MATHLIB_IMPL_FUNCTIONS_ELEMENTARY_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_ELEMENTARY_FUNCTIONS_HPP

#include "../../../Common/Types.hpp"
#include "../../../Common/Array.hpp"
#include "../BasicFunctions.hpp"

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
    };
}

#endif //MATHLIB_IMPL_FUNCTIONS_ELEMENTARY_FUNCTIONS_HPP
