#ifndef MATHLIB_IMPLEMENTATION_BASE_UTILITIES_HPP
#define MATHLIB_IMPLEMENTATION_BASE_UTILITIES_HPP

#include "Concepts.hpp"

namespace Math
{
    template <typename T>
    constexpr
    void Swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
}

#endif //MATHLIB_IMPLEMENTATION_BASE_UTILITIES_HPP
