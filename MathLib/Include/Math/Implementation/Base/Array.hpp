#ifndef MATHLIB_IMPLEMENTATION_BASE_ARRAY_HPP
#define MATHLIB_IMPLEMENTATION_BASE_ARRAY_HPP

#include "Types.hpp"
#include "Concepts.hpp"

namespace Math
{
    template <typename T, SizeType N>
    class Array final
    {
    public:
        using ValueType = T;
        static constexpr SizeType Size = N;

        [[nodiscard]] constexpr
        Array() noexcept = default;

        template <typename... Ts>
            requires (sizeof...(Ts) == ToUnderlying(Size)
                  && (Concept::IsConvertible<Ts, T> && ...))
        [[nodiscard]] constexpr
        Array(const Ts&... values)
            : mArray{ values... }
        {
            static_assert(sizeof...(Ts) == ToUnderlying(Size), "Invalid number of arguments");
        }

        [[nodiscard]] constexpr
        T* Data()
        {
            if constexpr (Size == 0)
            {
                return nullptr;
            }

            return mArray;
        }

        [[nodiscard]] constexpr
        const T* Data() const
        {
            if constexpr (Size == 0)
            {
                return nullptr;
            }

            return mArray;
        }

        template <Concept::Invocable<T&> Func>
        [[maybe_unused]] constexpr
        Func ForEach(Func func) noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                func((*this)[i]);
            }

            return func;
        }

        template <Concept::Invocable<const T&> Func>
        [[maybe_unused]] constexpr
        Func ForEach(Func func) const noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                func((*this)[i]);
            }

            return func;
        }

        template <Concept::Invocable<SizeType, T&> Func>
        [[maybe_unused]] constexpr
        Func ForEach(Func func) noexcept
        {
            for (SizeType i = 0; i < Size; ++i)
            {
                func(i, (*this)[i]);
            }

            return func;
        }

        template <Concept::Invocable<SizeType, const T&> Func>
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

        template <Concept::RandomNumberGenerator RNG, template <typename> typename Dist>
            requires Concept::Distribution<Dist<SizeType>, RNG>
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

    namespace Implementation
    {
        template <typename ValueType, typename T>
        struct MakeArrayImpl;

        template <typename ValueType, typename T, T... Values>
        struct MakeArrayImpl<ValueType, ValuePack<T, Values...>>
        {
            using Type = Array<ValueType, sizeof...(Values)>;
            static constexpr Type Value{ Cast<ValueType>(Values)... };
        };
    }

    template <typename ValueType, typename T>
    [[nodiscard]] constexpr
    typename Implementation::MakeArrayImpl<ValueType, T>::Type MakeArray()
    {
        return Implementation::MakeArrayImpl<ValueType, T>::Value;
    }
}

#endif //MATHLIB_IMPLEMENTATION_BASE_ARRAY_HPP
