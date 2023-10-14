#ifndef MATHLIB_COMMON_TYPES_HPP
#define MATHLIB_COMMON_TYPES_HPP

#include "Traits.hpp"

#include <cstdint>
#include <cstddef>
#include <limits>

namespace Math
{
    enum class Handedness
    {
        Left,
        Right
    };

    template <typename T>
    class StrongType final
    {
    public:
        static_assert(!IsSpecialization<T, StrongType>, "StrongType may not be nested");
        using ValueType = T;
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
        [[nodiscard]] friend constexpr
        auto operator<=>(StrongType<T> a, StrongType<T> b) = default;

        [[nodiscard]] friend constexpr
        T ToUnderlying(StrongType<T> value) noexcept { return value.mValue; }
    private:
        T mValue;
    };

    namespace Implementation
    {
        template <typename T>
        struct UnderlyingType
        {
            using Type = T;
        };

        template <typename T>
        struct UnderlyingType<StrongType<T>>
        {
            using Type = T;
        };
    }

    template <typename T>
    using UnderlyingType = typename Implementation::UnderlyingType<T>::Type;

    template <typename T>
        requires (!IsSpecialization<T, StrongType>)
    [[nodiscard]] constexpr
    T ToUnderlying(T value) noexcept
    {
        return value;
    }

    template <typename To, typename From>
    [[nodiscard]] constexpr
    To Convert(From value) noexcept
    {
        return static_cast<UnderlyingType<To>>(ToUnderlying(value));
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

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    using f32 = StrongType<float>;
    using f64 = StrongType<double>;

    class StaticSizeType
    {
    public:
        std::size_t Value;

        [[nodiscard]] constexpr
        StaticSizeType(std::size_t value) noexcept
            : Value(value)
        {}

        [[nodiscard]] constexpr
        operator SizeType() const noexcept
        {
            return SizeType(Value);
        }
    };

    namespace Implementation
    {
        template <std::size_t>
        struct SignedIntegerSelector
        {
            using Type = void;
        };

        template <> struct SignedIntegerSelector<1> { using Type = i8;  };
        template <> struct SignedIntegerSelector<2> { using Type = i16; };
        template <> struct SignedIntegerSelector<4> { using Type = i32; };
        template <> struct SignedIntegerSelector<8> { using Type = i64; };

        template <std::size_t>
        struct UnsignedIntegerSelector
        {
            using Type = void;
        };

        template <> struct UnsignedIntegerSelector<1> { using Type = u8;  };
        template <> struct UnsignedIntegerSelector<2> { using Type = u16; };
        template <> struct UnsignedIntegerSelector<4> { using Type = u32; };
        template <> struct UnsignedIntegerSelector<8> { using Type = u64; };

        template <std::size_t>
        struct FloatingPointSelector
        {
            using Type = void;
        };

        template <> struct FloatingPointSelector<4> { using Type = f32; };
        template <> struct FloatingPointSelector<8> { using Type = f64; };
    }

    template <std::size_t Size>
    using SignedIntegerSelector = typename Implementation::SignedIntegerSelector<Size>::Type;

    template <std::size_t Size>
    using UnsignedIntegerSelector = typename Implementation::UnsignedIntegerSelector<Size>::Type;

    template <std::size_t Size>
    using FloatingPointSelector = typename Implementation::FloatingPointSelector<Size>::Type;
}

#endif //MATHLIB_COMMON_TYPES_HPP
