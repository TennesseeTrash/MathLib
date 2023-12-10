#ifndef MATHLIB_IMPL_FUNCTIONS_ELEMENTARY_FUNCTIONS_HPP
#define MATHLIB_IMPL_FUNCTIONS_ELEMENTARY_FUNCTIONS_HPP

#include "../../Common/Types.hpp"
#include "BasicFunctions.hpp"

namespace Math::Function
{
    template <typename T, MakeStaticStrongType<T> TValue>
    struct Constant
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Value = TValue;

        [[nodiscard]] constexpr
        ValueType operator() ([[maybe_unused]] ValueType x) const noexcept
        {
            return Value;
        }
    };

    template <typename T, MakeStaticStrongType<T> TSlope = Cast<T>(1), MakeStaticStrongType<T> TIntercept = Cast<T>(0)>
    struct Linear
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType Slope = TSlope;
        static constexpr ValueType Intercept = TIntercept;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            ValueType result = Cast<ValueType>(0);
            if constexpr (!Equal(Intercept, Cast<ValueType>(0)))
            {
                result += Intercept;
            }
            if constexpr (!Equal(Slope, Cast<ValueType>(0)))
            {
                result += x * Slope;
            }
            return result;
        }
    };

    template <typename T, MakeStaticStrongType<T> TSquare = Cast<T>(1), MakeStaticStrongType<T> TLinear = Cast<T>(0), MakeStaticStrongType<T> TConstant = Cast<T>(0)>
    struct Quadratic
    {
    public:
        using ValueType = MakeStrongType<T>;
        static constexpr ValueType                  Square = TSquare;
        static constexpr Linear<ValueType, TLinear, TConstant> LinearFunction;

        [[nodiscard]] constexpr
        ValueType operator() (ValueType x) const noexcept
        {
            ValueType result = LinearFunction(x);
            if constexpr (!Equal(Square, Cast<ValueType>(0)))
            {
                result += Square * Squared(x);
            }
            return result;
        }
    };

    template <typename T, MakeStaticStrongType<T> TExponent, MakeStaticStrongType<T> TMultiplier = Cast<T>(1)>
    struct Power
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

    template <typename T, MakeStaticStrongType<T> TBase = Math::Constants::E<T>, MakeStaticStrongType<T> TExponentMultiplier = Cast<T>(1)>
    struct Exponential
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
    struct NaturalLogarithm
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
    struct Logarithm
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
