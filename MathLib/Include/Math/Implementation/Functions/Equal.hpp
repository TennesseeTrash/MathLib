#ifndef MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP
#define MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP

#include "../Base/Concepts.hpp"
#include "../../Constants.hpp"

namespace Math
{
    template <Concept::FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, T val2, T epsilon = Constant::EqualEpsilon<T>) noexcept
    {
        if constexpr (Concept::FloatingPointType<T>)
        {
            return Abs(val1 - val2) < epsilon;
        }
        else
        {
            return val1 == val2;
        }
    }

    template <Concept::FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, StrongType<T> val2, StrongType<T> epsilon = Constant::EqualEpsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <Concept::FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(StrongType<T> val1, T val2, StrongType<T> epsilon = Constant::EqualEpsilon<StrongType<T>>) noexcept
    {
        return Equal(ToUnderlying(val1), val2, ToUnderlying(epsilon));
    }

    template <Concept::FundamentalType T>
    [[nodiscard]] constexpr
    bool Equal(T val1, StrongType<T> val2, StrongType<T> epsilon = Constant::EqualEpsilon<StrongType<T>>) noexcept
    {
        return Equal(val1, ToUnderlying(val2), ToUnderlying(epsilon));
    }

    template <Concept::MathType T>
    [[nodiscard]] constexpr
    bool Equal(const T& u, const T& v, typename T::ScalarType epsilon = Constant::EqualEpsilon<typename T::ScalarType>) noexcept
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

    template <Concept::Quaternion Quat>
    [[nodiscard]] constexpr
    bool Equal(const Quat& p, const Quat& q) noexcept
    {
        return Equal(p.Vector(), q.Vector()) && Equal(p.Scalar(), q.Scalar());
    }
}

#endif //MATHLIB_IMPLEMENTATION_FUNCTIONS_EQUAL_HPP
