#ifndef MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_HPP
#define MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_HPP

#include <cstdint>
#include <cstddef>
#include <compare>
#include <limits>

// TODO(3011):
//  - It might prove beneficial to make StrongType into a struct with
//    the member value being public. This would make it possible to
//    get rid of StaticStrongType.

namespace Math
{
    template <typename T>
    class StrongType final
    {
    public:
        //static_assert(!Implementation::IsSpecialization<T, StrongType>::Value, "StrongType may not be nested");
        using ValueType = T;

        [[nodiscard]] constexpr
        StrongType(T value = T{}) noexcept
            : mValue(value)
        {}

        static constexpr StrongType<ValueType> Min() { return StrongType(std::numeric_limits<ValueType>::min()); }
        static constexpr StrongType<ValueType> Max() { return StrongType(std::numeric_limits<ValueType>::max()); }

        // Note(3011): Some of these operators will not work for certain types.
        // In the future, explicit 'requires' clauses would be nice.
        // e.g. StrongType<float>(4.0f) << 1 will not compile.
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator+   (StrongType<ValueType>  a)                          noexcept { return +a.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator-   (StrongType<ValueType>  a)                          noexcept { return -a.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator+   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue + b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator-   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue - b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator*   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue * b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator/   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue / b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator%   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue % b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator~   (StrongType<ValueType>  a)                          noexcept { return ~a.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator&   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue & b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator|   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue | b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator^   (StrongType<ValueType>  a, StrongType<ValueType> b) noexcept { return a.mValue ^ b.mValue; }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator<<  (StrongType<ValueType>  a, StrongType<ValueType> s) noexcept { return ValueType(a.mValue << s.mValue); }
        [[nodiscard]]    friend constexpr StrongType<ValueType>  operator>>  (StrongType<ValueType>  a, StrongType<ValueType> s) noexcept { return ValueType(a.mValue >> s.mValue); }

        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator++  (StrongType<ValueType>& a)                          noexcept { return ++a.mValue; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator--  (StrongType<ValueType>& a)                          noexcept { return --a.mValue; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator++  (StrongType<ValueType>& a, int)                     noexcept { return a.mValue++; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>  operator--  (StrongType<ValueType>& a, int)                     noexcept { return a.mValue--; }

        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator+=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue += b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator-=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue -= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator*=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue *= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator/=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue /= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator%=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue %= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator&=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue &= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator|=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue |= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator^=  (StrongType<ValueType>& a, StrongType<ValueType> b) noexcept { a.mValue ^= b.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator<<= (StrongType<ValueType>& a, StrongType<ValueType> s) noexcept { a.mValue <<= s.mValue; return a; }
        [[maybe_unused]] friend constexpr StrongType<ValueType>& operator>>= (StrongType<ValueType>& a, StrongType<ValueType> s) noexcept { a.mValue >>= s.mValue; return a; }

        // Note(3011): Default this when the bogus warning in Clang is fixed.
        // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
        [[nodiscard]] friend constexpr
        bool operator==(StrongType<T> a, StrongType<T> b) noexcept { return a.mValue == b.mValue; }
        [[nodiscard]] friend constexpr
        auto operator<=>(StrongType<T> a, StrongType<T> b) noexcept { return a.mValue <=> b.mValue; }

        template <typename U>
        friend constexpr U ToUnderlying(StrongType<U> value) noexcept;
    private:
        ValueType mValue;
    };

    template <typename T>
    struct StaticStrongType final
    {
        //static_assert(!Implementation::IsSpecialization<T, StaticStrongType>::Value, "StaticStrongType may not be nested");
        //static_assert(!Implementation::IsSpecialization<T, StrongType>::Value, "StaticStrongType may not be specialized with StrongType");
        using ValueType = T;
        ValueType Value;

        [[nodiscard]] constexpr
        StaticStrongType(T value) noexcept
            : Value(value)
        {}

        [[nodiscard]] constexpr
        StaticStrongType(StrongType<T> value) noexcept
            : Value(ToUnderlying(value))
        {}

        [[nodiscard]] constexpr
        operator StrongType<T>() const noexcept
        {
            return StrongType<T>(Value);
        }

        static constexpr StaticStrongType<T> Min() { return StaticStrongType(std::numeric_limits<ValueType>::min()); }
        static constexpr StaticStrongType<T> Max() { return StaticStrongType(std::numeric_limits<ValueType>::max()); }

        template <typename U>
        friend constexpr U ToUnderlying(StaticStrongType<U> value) noexcept;
    };

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(StrongType<T> value) noexcept
    {
        return value.mValue;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(StaticStrongType<T> value) noexcept
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

    using StaticSizeType = StaticStrongType<std::size_t>;
    using StaticSignedSizeType = StaticStrongType<std::int64_t>;

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

    using i8s  = StaticStrongType<std::int8_t>;
    using i16s = StaticStrongType<std::int16_t>;
    using i32s = StaticStrongType<std::int32_t>;
    using i64s = StaticStrongType<std::int64_t>;

    using u8s  = StaticStrongType<std::uint8_t>;
    using u16s = StaticStrongType<std::uint16_t>;
    using u32s = StaticStrongType<std::uint32_t>;
    using u64s = StaticStrongType<std::uint64_t>;

    using f32s = StaticStrongType<float>;
    using f64s = StaticStrongType<double>;
}

#endif //MATHLIB_COMMON_IMPLEMENTATION_STRONG_TYPES_HPP
