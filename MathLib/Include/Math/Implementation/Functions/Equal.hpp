#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP

#include "../Base/Concepts.hpp"

namespace Math
{
    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, T val2, T epsilon = Constant::Epsilon<T>) noexcept
    {
        if constexpr (FloatingPointType<T>)
        {
            return Abs(val1 - val2) < epsilon;
        }
        else
        {
            return val1 == val2;
        }
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, StrongType<T> val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, T val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), val2, ToUnderlying(epsilon));
    }

    template <FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, StrongType<T> val2, StrongType<T> epsilon = Constant::Epsilon<StrongType<T>>) noexcept
    {
        return Equal(val1, ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <ConceptMathTypeUtil T>
    [[nodiscard]] constexpr
    bool Equal(const T& u, const T& v, typename T::ScalarType epsilon = Constant::Epsilon<typename T::ScalarType>) noexcept
    {
        for (SizeType i = 0; i < T::Dimension; ++i)
        {
            if (!Equal(u[i], v[i], epsilon))
            {
                return false;
            }
        }

        return true;
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP
