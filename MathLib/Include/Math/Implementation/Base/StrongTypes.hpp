#ifndef MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP
#define MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP

#include <cstdint>
#include <cstddef>
#include <compare>
#include <limits>

// TODO(3011): Not again ...
#include <cmath>

namespace Math
{
    namespace Implementation
    {
        template <typename T>
        struct StrongIntegerType final
        {
        public:
            using ValueType = T;
            ValueType Value;
        private:
            using ThisType = StrongIntegerType<ValueType>;
        public:

            [[nodiscard]] constexpr
            StrongIntegerType(T value = T{}) noexcept
                : Value(value)
            {}

            static constexpr ThisType Min() { return ThisType(std::numeric_limits<ValueType>::min()); }
            static constexpr ThisType Max() { return ThisType(std::numeric_limits<ValueType>::max()); }

            [[nodiscard]]    friend constexpr ThisType  operator+   (ThisType  a)             noexcept { return +a.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator-   (ThisType  a)             noexcept { return -a.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator+   (ThisType  a, ThisType b) noexcept { return a.Value + b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator-   (ThisType  a, ThisType b) noexcept { return a.Value - b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator*   (ThisType  a, ThisType b) noexcept { return a.Value * b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator/   (ThisType  a, ThisType b) noexcept { return a.Value / b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator%   (ThisType  a, ThisType b) noexcept { return a.Value % b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator~   (ThisType  a)             noexcept { return ~a.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator&   (ThisType  a, ThisType b) noexcept { return a.Value & b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator|   (ThisType  a, ThisType b) noexcept { return a.Value | b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator^   (ThisType  a, ThisType b) noexcept { return a.Value ^ b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator<<  (ThisType  a, ThisType s) noexcept { return ValueType(a.Value << s.Value); }
            [[nodiscard]]    friend constexpr ThisType  operator>>  (ThisType  a, ThisType s) noexcept { return ValueType(a.Value >> s.Value); }

            [[maybe_unused]] friend constexpr ThisType  operator++  (ThisType& a)            noexcept { return ++a.Value; }
            [[maybe_unused]] friend constexpr ThisType  operator--  (ThisType& a)            noexcept { return --a.Value; }
            [[maybe_unused]] friend constexpr ThisType  operator++  (ThisType& a, int)       noexcept { return a.Value++; }
            [[maybe_unused]] friend constexpr ThisType  operator--  (ThisType& a, int)       noexcept { return a.Value--; }

            [[maybe_unused]] friend constexpr ThisType& operator+=  (ThisType& a, ThisType b) noexcept { a.Value += b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator-=  (ThisType& a, ThisType b) noexcept { a.Value -= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator*=  (ThisType& a, ThisType b) noexcept { a.Value *= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator/=  (ThisType& a, ThisType b) noexcept { a.Value /= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator%=  (ThisType& a, ThisType b) noexcept { a.Value %= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator&=  (ThisType& a, ThisType b) noexcept { a.Value &= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator|=  (ThisType& a, ThisType b) noexcept { a.Value |= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator^=  (ThisType& a, ThisType b) noexcept { a.Value ^= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator<<= (ThisType& a, ThisType s) noexcept { a.Value <<= s.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator>>= (ThisType& a, ThisType s) noexcept { a.Value >>= s.Value; return a; }

            // Note(3011): Default this when the bogus warning in Clang is fixed.
            // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
            [[nodiscard]] friend constexpr
            bool operator==(ThisType a, ThisType b) noexcept { return a.Value == b.Value; }
            [[nodiscard]] friend constexpr
            auto operator<=>(ThisType a, ThisType b) noexcept { return a.Value <=> b.Value; }
        };

        template <typename T>
        struct StrongFloatType final
        {
        public:
            using ValueType = T;
            ValueType Value;
        private:
            using ThisType = StrongFloatType<ValueType>;
        public:

            [[nodiscard]] constexpr
            StrongFloatType(T value = T{}) noexcept
                : Value(value)
            {}

            static constexpr ThisType Min()      { return ThisType(std::numeric_limits<ValueType>::min()); }
            static constexpr ThisType Max()      { return ThisType(std::numeric_limits<ValueType>::max()); }
            static constexpr ThisType Epsilon()  { return ThisType(std::numeric_limits<ValueType>::epsilon()); }
            static constexpr ThisType Infinity() { return ThisType(std::numeric_limits<ValueType>::infinity()); }
            static constexpr ThisType NaN()      { return ThisType(std::numeric_limits<ValueType>::quiet_NaN()); }

            ThisType Previous() const noexcept { return std::nextafter(Value, -ThisType::Infinity().Value); }
            ThisType Next()     const noexcept { return std::nextafter(Value,  ThisType::Infinity().Value); }

            [[nodiscard]]    friend constexpr ThisType  operator+   (ThisType  a)             noexcept { return +a.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator-   (ThisType  a)             noexcept { return -a.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator+   (ThisType  a, ThisType b) noexcept { return a.Value + b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator-   (ThisType  a, ThisType b) noexcept { return a.Value - b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator*   (ThisType  a, ThisType b) noexcept { return a.Value * b.Value; }
            [[nodiscard]]    friend constexpr ThisType  operator/   (ThisType  a, ThisType b) noexcept { return a.Value / b.Value; }

            [[maybe_unused]] friend constexpr ThisType  operator++  (ThisType& a)             noexcept { return ++a.Value; }
            [[maybe_unused]] friend constexpr ThisType  operator--  (ThisType& a)             noexcept { return --a.Value; }
            [[maybe_unused]] friend constexpr ThisType  operator++  (ThisType& a, int)        noexcept { return a.Value++; }
            [[maybe_unused]] friend constexpr ThisType  operator--  (ThisType& a, int)        noexcept { return a.Value--; }

            [[maybe_unused]] friend constexpr ThisType& operator+=  (ThisType& a, ThisType b) noexcept { a.Value += b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator-=  (ThisType& a, ThisType b) noexcept { a.Value -= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator*=  (ThisType& a, ThisType b) noexcept { a.Value *= b.Value; return a; }
            [[maybe_unused]] friend constexpr ThisType& operator/=  (ThisType& a, ThisType b) noexcept { a.Value /= b.Value; return a; }

            // Note(3011): Default this when the bogus warning in Clang is fixed.
            // Relevant issue - https://github.com/llvm/llvm-project/issues/43670
            [[nodiscard]] friend constexpr
            bool operator==(ThisType a, ThisType b) noexcept { return a.Value == b.Value; }
            [[nodiscard]] friend constexpr
            auto operator<=>(ThisType a, ThisType b) noexcept { return a.Value <=> b.Value; }
        };
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(Implementation::StrongIntegerType<T> value) noexcept
    {
        return value.Value;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(Implementation::StrongFloatType<T> value) noexcept
    {
        return value.Value;
    }

    template <typename T>
    [[nodiscard]] constexpr
    T ToUnderlying(T value) noexcept
    {
        return value;
    }

    inline namespace Types
    {
        using SizeType = Implementation::StrongIntegerType<std::size_t>;
        using SignedSizeType = Implementation::StrongIntegerType<std::int64_t>;

        using i8  = Implementation::StrongIntegerType<std::int8_t>;
        using i16 = Implementation::StrongIntegerType<std::int16_t>;
        using i32 = Implementation::StrongIntegerType<std::int32_t>;
        using i64 = Implementation::StrongIntegerType<std::int64_t>;

        using u8  = Implementation::StrongIntegerType<std::uint8_t>;
        using u16 = Implementation::StrongIntegerType<std::uint16_t>;
        using u32 = Implementation::StrongIntegerType<std::uint32_t>;
        using u64 = Implementation::StrongIntegerType<std::uint64_t>;

        using f32 = Implementation::StrongFloatType<float>;
        using f64 = Implementation::StrongFloatType<double>;
    }
}

#endif //MATHLIB_IMPLEMENTATION_BASE_STRONG_TYPE_HPP
