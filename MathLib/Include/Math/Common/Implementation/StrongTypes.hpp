#ifndef MATHLIB_COMMON_IMPL_STRONG_TYPES_HPP
#define MATHLIB_COMMON_IMPL_STRONG_TYPES_HPP

#include "Traits.hpp"

#include <cstdint>
#include <cstddef>
#include <compare>
#include <limits>

namespace Math
{
    template <typename T>
    class StrongType final
    {
    public:
        static_assert(!Implementation::IsSpecialization<T, StrongType>::Value, "StrongType may not be nested");
        using ValueType = T;
    private:
        using STVT = StrongType<ValueType>;
        using STSZ = StrongType<std::size_t>;
    public:
        [[nodiscard]] constexpr
        StrongType(T value = T{}) noexcept
            : mValue(value)
        {}

        static const StrongType<ValueType> Min;
        static const StrongType<ValueType> Max;
    public:
        // Note(3011): Some of these operators will not work for certain types.
        // In the future, explicit 'requires' clauses would be nice.
        // e.g. StrongType<float>(4.0f) << 1 will not compile.
        [[nodiscard]]    friend constexpr STVT  operator+   (STVT  a, STVT b)     noexcept { return a.mValue + b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator-   (STVT  a, STVT b)     noexcept { return a.mValue - b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator*   (STVT  a, STVT b)     noexcept { return a.mValue * b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator/   (STVT  a, STVT b)     noexcept { return a.mValue / b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator%   (STVT  a, STVT b)     noexcept { return a.mValue % b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator-   (STVT  a)             noexcept { return -a.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator&   (STVT  a, STVT b)     noexcept { return a.mValue & b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator|   (STVT  a, STVT b)     noexcept { return a.mValue | b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator^   (STVT  a, STVT b)     noexcept { return a.mValue ^ b.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator&   (STVT  a)             noexcept { return ~a.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator<<  (STVT  a, STSZ shift) noexcept { return a.mValue << shift.mValue; }
        [[nodiscard]]    friend constexpr STVT  operator>>  (STVT  a, STSZ shift) noexcept { return a.mValue >> shift.mValue; }
        [[maybe_unused]] friend constexpr STVT  operator++  (STVT& a)             noexcept { return ++a.mValue; }
        [[maybe_unused]] friend constexpr STVT  operator--  (STVT& a)             noexcept { return --a.mValue; }
        [[maybe_unused]] friend constexpr STVT  operator++  (STVT& a, int)        noexcept { return a.mValue++; }
        [[maybe_unused]] friend constexpr STVT  operator--  (STVT& a, int)        noexcept { return a.mValue--; }
        [[maybe_unused]] friend constexpr STVT& operator+=  (STVT& a, STVT b)     noexcept { a.mValue += b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator-=  (STVT& a, STVT b)     noexcept { a.mValue -= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator*=  (STVT& a, STVT b)     noexcept { a.mValue *= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator/=  (STVT& a, STVT b)     noexcept { a.mValue /= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator%=  (STVT& a, STVT b)     noexcept { a.mValue %= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator&=  (STVT& a, STVT b)     noexcept { a.mValue &= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator|=  (STVT& a, STVT b)     noexcept { a.mValue |= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator^=  (STVT& a, STVT b)     noexcept { a.mValue ^= b.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator<<= (STVT& a, STSZ shift) noexcept { a.mValue <<= shift.mValue; return a; }
        [[maybe_unused]] friend constexpr STVT& operator>>= (STVT& a, STSZ shift) noexcept { a.mValue >>= shift.mValue; return a; }

        // Note(3011): Default this when the bogus warning in Clang is fixed.
        // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
        [[nodiscard]] friend constexpr
        bool operator==(StrongType<T> a, StrongType<T> b) noexcept { return a.mValue == b.mValue; }
        [[nodiscard]] friend constexpr
        auto operator<=>(StrongType<T> a, StrongType<T> b) noexcept { return a.mValue <=> b.mValue; }

        template <typename U>
        friend constexpr U ToUnderlying(StrongType<U> value) noexcept;

        template <typename U>
        friend class StrongType;
    private:
        ValueType mValue;
    };

    template <typename T>
    constexpr StrongType<T> StrongType<T>::Min = std::numeric_limits<T>::min();
    template <typename T>
    constexpr StrongType<T> StrongType<T>::Max = std::numeric_limits<T>::max();

    template <typename T>
    struct StaticStrongType final
    {
    public:
        static_assert(!Implementation::IsSpecialization<T, StaticStrongType>::Value, "StaticStrongType may not be nested");
        static_assert(!Implementation::IsSpecialization<T, StrongType>::Value, "StaticStrongType may not be specialized with StrongType");
        using ValueType = T;
        ValueType Value;
    public:
        [[nodiscard]] constexpr
        StaticStrongType(T value) noexcept
            : Value(value)
        {}

        [[nodiscard]] constexpr
        operator StrongType<T>() const noexcept
        {
            return StrongType<T>(Value);
        }

        static const StaticStrongType<T> Min;
        static const StaticStrongType<T> Max;

        template <typename U>
        friend constexpr U ToUnderlying(StaticStrongType<U> value) noexcept;
    };

    template <typename T>
    constexpr StaticStrongType<T> StaticStrongType<T>::Min = std::numeric_limits<T>::min();
    template <typename T>
    constexpr StaticStrongType<T> StaticStrongType<T>::Max = std::numeric_limits<T>::max();

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
}

#endif //MATHLIB_COMMON_IMPL_STRONG_TYPES_HPP
