#ifndef MATHLIB_COMMON_ARRAY_HPP
#define MATHLIB_COMMON_ARRAY_HPP

#include "Types.hpp"

namespace Math
{
    template <typename T, StaticSizeType N>
    class Array final
    {
    public:
        using ValueType = T;
        static constexpr SizeType Size = N;
    public:
        [[nodiscard]] constexpr
        Array() noexcept = default;

        template <typename... Ts>
        [[nodiscard]] constexpr
        Array(const Ts&... values)
            : mArray{ values... }
        {
            static_assert(sizeof...(Ts) == 0 || (std::is_convertible_v<T, Ts> && ...), "Invalid types");
            static_assert(sizeof...(Ts) == ToUnderlying(Size), "Invalid number of arguments");
        }

        constexpr
        void Fill(const T& value) noexcept
        {
            for (SizeType i = 0; i < Size; ++i) { mArray[i] = value; }
        }

        [[nodiscard]] constexpr       T& operator[] (SizeType i)       { return mArray[ToUnderlying(i)]; }
        [[nodiscard]] constexpr const T& operator[] (SizeType i) const { return mArray[ToUnderlying(i)]; }
    private:
        T mArray[ToUnderlying(Size)] = {};
    };
}

#endif //MATHLIB_COMMON_ARRAY_HPP
