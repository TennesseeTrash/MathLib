#ifndef MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP
#define MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP

#include <cstdint>
#include <cstddef>
#include <compare>
#include <limits>

namespace Math
{
    template <typename T>
    struct StrongType final
    {
    public:
        using ValueType = T;
        ValueType Value;

        [[nodiscard]] constexpr
        StrongType(T value = T{}) noexcept
            : Value(value)
        {}

        static constexpr StrongType<ValueType> Min() { return StrongType(std::numeric_limits<ValueType>::min()); }
        static constexpr StrongType<ValueType> Max() { return StrongType(std::numeric_limits<ValueType>::max()); }

        // Note(3011): Some of these operators will not work for certain types.
        // In the future, explicit 'requires' clauses would be nice.
        // e.g. StrongType<float>(4.0f) << 1 will not compile.
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator+   (StrongType<ValueType>  a)                          noexcept { return +a.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator-   (StrongType<ValueType>  a)                          noexcept { return -a.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator+   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value + b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator-   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value - b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator*   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value * b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator/   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value / b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator%   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value % b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator~   (StrongType<ValueType>  a)                          noexcept { return ~a.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator&   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value & b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator|   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value | b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator^   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.Value ^ b.Value; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator<<  (StrongType<ValueType>  a, StrongType<ValueType> s) noexcept { return ValueType(a.Value << s.Value); }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator>>  (StrongType<ValueType>  a, StrongType<ValueType> s) noexcept { return ValueType(a.Value >> s.Value); }

        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator++  (StrongType<ValueType>& a)                          noexcept { return ++a.Value; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator--  (StrongType<ValueType>& a)                          noexcept { return --a.Value; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator++  (StrongType<ValueType>& a, int)                     noexcept { return a.Value++; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator--  (StrongType<ValueType>& a, int)                     noexcept { return a.Value--; }

        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator+=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value += b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator-=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value -= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator*=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value *= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator/=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value /= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator%=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value %= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator&=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value &= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator|=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value |= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator^=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.Value ^= b.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator<<= (StrongType<ValueType>& a, StrongType<ValueType> s) noexcept { a.Value <<= s.Value; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator>>= (StrongType<ValueType>& a, StrongType<ValueType> s) noexcept { a.Value >>= s.Value; return a; }

        // Note(3011): Default this when the bogus warning in Clang is fixed.
        // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
        [[nodiscard]] friend constexpr
        bool operator==(StrongType<T> a, StrongType<T> b) noexcept { return a.Value == b.Value; }
        [[nodiscard]] friend constexpr
        auto operator<=>(StrongType<T> a, StrongType<T> b) noexcept { return a.Value <=> b.Value; }
    };

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(StrongType<T> value) noexcept
    {
        return value.Value;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(T value) noexcept
    {
        return value;
    }

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

    using f32 = StrongType<float>;
    using f64 = StrongType<double>;
}

#endif //MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP
