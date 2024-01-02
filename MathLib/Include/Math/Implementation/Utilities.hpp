#ifndef MATHLIB_IMPLEMENTATION_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_UTILITIES_HPP

#include "../Common/Concepts.hpp"

namespace Math
{
    template <ConceptMathTypeUtil T>
    [[nodiscard]] constexpr
    typename T::ScalarType Min(const T& u) noexcept
    {
        return u.Min();
    }

    template <ConceptMathTypeUtil T>
    [[nodiscard]] constexpr
    typename T::ScalarType Max(const T& u) noexcept
    {
        return u.Max();
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

#endif //MATHLIB_IMPLEMENTATION_UTILITIES_HPP
