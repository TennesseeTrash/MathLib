#ifndef MATHLIB_COMMON_ARRAY_HPP
#define MATHLIB_COMMON_ARRAY_HPP

#include "Concepts.hpp"

#include <initializer_list>

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
            static_assert(sizeof...(Ts) == ToUnderlying(Size), "Invalid number of arguments");
            static_assert(sizeof...(Ts) == 0
                      || (IsSame<T, Ts> && ...), "Invalid types");
        }

        [[nodiscard]] constexpr
        Array(const ValueType (&initializer)[ToUnderlying(Size)])
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                (*this)[i] = initializer[ToUnderlying(i)];
            }
        }

        template <typename Func>
            requires IsInvocable<Func, T&>
        [[maybe_unused]] constexpr
        Func ForEach(Func func) noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                func((*this)[i]);
            }

            return func;
        }

        template <typename Func>
            requires IsInvocable<Func, SizeType, const T&>
        [[maybe_unused]] constexpr
        Func ForEach(Func func) const noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                func(i, (*this)[i]);
            }

            return func;
        }

        constexpr
        void Fill(const T& value) noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                (*this)[i] = value;
            }
        }

        template <ConceptRandomNumberGenerator RNG, template <typename> typename Dist>
            requires ConceptDistribution<Dist<SizeType>, RNG>
        constexpr
        void Shuffle(RNG& rng) noexcept
        {
            Dist<SizeType> dist(0, Size - 1);
            for (SizeType i = 0; i < Size; ++i)
            {
                SizeType j = dist(rng);
                std::swap((*this)[i], (*this)[j]);
            }
        }

        [[nodiscard]] constexpr
        T Min() const noexcept
        {
            if constexpr (Size == 0)
            {
                return T{};
            }

            T result = mArray[0];
            for (SizeType i = 1; i < Size; ++i)
            {
                if ((*this)[i] < result)
                {
                    result = (*this)[i];
                }
            }
            return result;
        }

        [[nodiscard]] constexpr
        T Max() const noexcept
        {
            if constexpr (Size == 0)
            {
                return T{};
            }

            T result = mArray[0];
            for (SizeType i = 1; i < Size; ++i)
            {
                if ((*this)[i] > result)
                {
                    result = (*this)[i];
                }
            }
            return result;
        }

        [[nodiscard]] constexpr       T& operator[] (SizeType i)       { return mArray[ToUnderlying(i)]; }
        [[nodiscard]] constexpr const T& operator[] (SizeType i) const { return mArray[ToUnderlying(i)]; }
    private:
        T mArray[ToUnderlying(Size)] = {};
    };

    template <typename T, StaticSizeType N, typename... Ts>
    [[nodiscard]] constexpr
    Array<T, N> MakeArray(const Ts&... values)
    {
        static_assert(sizeof...(Ts) == ToUnderlying(N), "Invalid number of arguments");
        static_assert((IsConvertible<UnderlyingType<T>, UnderlyingType<Ts>> && ...), "Invalid types");
        return Array<T, N>(Cast<T>(values)...);
    }

    template <typename T, StaticSizeType N>
    [[nodiscard]] constexpr
    Array<T, N> MakeArrayFillAscending(T offset)
    {
        Array<T, N> result;
        for (SizeType i = 0; i < N; ++i)
        {
            result[i] = offset + Cast<T>(i);
        }
        return result;
    }
}

#endif //MATHLIB_COMMON_ARRAY_HPP
