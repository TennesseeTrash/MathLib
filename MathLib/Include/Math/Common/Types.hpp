#ifndef MATHLIB_COMMON_TYPES_HPP
#define MATHLIB_COMMON_TYPES_HPP

#include "Traits.hpp"

#include <cstdint>
#include <cstddef>
#include <limits>

namespace Math
{
    template <typename T>
    class StrongType final
    {
    private:
        static_assert(!IsSpecialization<T, StrongType>, "StrongType may not be nested");

        T mValue;
    public:
        [[nodiscard]] constexpr
        StrongType(T value = T{}) noexcept
            : mValue(value)
        {}

        // Note(3011): Some of these operators will not work for certain types.
        // This should not be a problem unless you try to use them.
        // e.g. StrongType<float>(4.0f) << 1 will not compile.
        [[nodiscard]]    friend constexpr StrongType<T>  operator+   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue + b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator-   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue - b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator*   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue * b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator/   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue / b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator%   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue % b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator-   (StrongType<T> a)                     noexcept { return -a.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator&   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue & b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator|   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue | b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator^   (StrongType<T> a,  StrongType<T> b)   noexcept { return a.mValue ^ b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator&   (StrongType<T> a)                     noexcept { return ~a.mValue; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator<<  (StrongType<T> a,  std::size_t shift) noexcept { return a.mValue << shift; }
        [[nodiscard]]    friend constexpr StrongType<T>  operator>>  (StrongType<T> a,  std::size_t shift) noexcept { return a.mValue >> shift; }
        [[maybe_unused]] friend constexpr StrongType<T>  operator++  (StrongType<T>& a)                    noexcept { return ++a.mValue; }
        [[maybe_unused]] friend constexpr StrongType<T>  operator--  (StrongType<T>& a)                    noexcept { return --a.mValue; }
        [[maybe_unused]] friend constexpr StrongType<T>  operator++  (StrongType<T>& a, int)               noexcept { return a.mValue++; }
        [[maybe_unused]] friend constexpr StrongType<T>  operator--  (StrongType<T>& a, int)               noexcept { return a.mValue--; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator+=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue += b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator-=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue -= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator*=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue *= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator/=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue /= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator%=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue %= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator&=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue &= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator|=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue |= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator^=  (StrongType<T>& a, StrongType<T> b)   noexcept { a.mValue ^= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator<<= (StrongType<T>& a, std::size_t shift) noexcept { a.mValue <<= shift; return a; }
        [[maybe_unused]] friend constexpr StrongType<T>& operator>>= (StrongType<T>& a, std::size_t shift) noexcept { a.mValue >>= shift; return a; }

        // Note(3011): The warning that appears here is bogus.
        // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
        [[nodiscard]] friend constexpr auto operator<=>(StrongType<T> a, StrongType<T> b) = default;

        friend constexpr
        T ToUnderlying(StrongType<T> value) noexcept { return value.mValue; }

        template <typename To>
            requires IsSpecialization<To, StrongType>
        friend constexpr
        To Convert(StrongType<T> value) noexcept
        {
            return To(static_cast<decltype(ToUnderlying(To()))>(value.mValue));
        }
    };

    using SizeType = StrongType<std::size_t>;
    using SignedSizeType = StrongType<std::int64_t>;

    using i8  = StrongType<std::int8_t>;
    using i16 = StrongType<std::int16_t>;
    using i32 = StrongType<std::int32_t>;
    using i64 = StrongType<std::int64_t>;

    using u8  = StrongType<std::uint8_t>;
    using u16 = StrongType<std::uint16_t>;
    using u32 = StrongType<std::uint32_t>;
    using u64 = StrongType<std::uint64_t>;

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    using f32 = StrongType<float>;
    using f64 = StrongType<double>;
}

#endif //MATHLIB_COMMON_TYPES_HPP
