#ifndef MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP
#define MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP

#include "Warnings.hpp"

#include <cstdint>
#include <cstddef>
#include <compare>
#include <limits>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Assumptions
    //////////////////////////////////////////////////////////////////////////

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    //////////////////////////////////////////////////////////////////////////
    // Type Utilities
    //////////////////////////////////////////////////////////////////////////

    namespace Implementation
    {
        template <bool Condition, typename TrueType, typename FalseType>
        struct ConditionalType
        {
            using Type = TrueType;
        };

        template <typename TrueType, typename FalseType>
        struct ConditionalType<false, TrueType, FalseType>
        {
            using Type = FalseType;
        };
    }

    template <bool Condition, typename TrueType, typename FalseType>
    using ConditionalType = typename Implementation::ConditionalType<Condition, TrueType, FalseType>::Type;



    namespace Implementation
    {
        template <typename T>
        struct UnderlyingType
        {
            using Type = T;
        };

        template <typename T>
            requires requires { typename T::ValueType; }
        struct UnderlyingType<T>
        {
            using Type = typename T::ValueType;
        };
    }

    template <typename T>
    using UnderlyingType = typename Implementation::UnderlyingType<T>::Type;

    //////////////////////////////////////////////////////////////////////////
    // Basic Types
    //////////////////////////////////////////////////////////////////////////

    enum class Orientation
    {
        Left,
        Right
    };

    //////////////////////////////////////////////////////////////////////////
    // StrongTypes
    //////////////////////////////////////////////////////////////////////////

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

            [[nodiscard]] static constexpr ThisType Min() { return ThisType(std::numeric_limits<ValueType>::min()); }
            [[nodiscard]] static constexpr ThisType Max() { return ThisType(std::numeric_limits<ValueType>::max()); }

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

            constexpr ThisType Previous() const noexcept;
            constexpr ThisType Next()     const noexcept;

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
            bool operator==(ThisType a, ThisType b) noexcept { return MATH_NO_WARN(-Wfloat-equal, a.Value == b.Value); }
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

    template <typename To, typename From>
    [[nodiscard]] constexpr
    To Cast(From value) noexcept
    {
        return To(static_cast<UnderlyingType<To>>(ToUnderlying(value)));
    }

    template <typename T>
    constexpr
    void Swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    //////////////////////////////////////////////////////////////////////////
    // Type Aliases
    //////////////////////////////////////////////////////////////////////////

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

    namespace Implementation
    {
        template <SizeType>
        struct SignedIntegerSelector;
        template <> struct SignedIntegerSelector<1> { using Type = i8;  };
        template <> struct SignedIntegerSelector<2> { using Type = i16; };
        template <> struct SignedIntegerSelector<4> { using Type = i32; };
        template <> struct SignedIntegerSelector<8> { using Type = i64; };

        template <SizeType>
        struct UnsignedIntegerSelector;
        template <> struct UnsignedIntegerSelector<1> { using Type = u8;  };
        template <> struct UnsignedIntegerSelector<2> { using Type = u16; };
        template <> struct UnsignedIntegerSelector<4> { using Type = u32; };
        template <> struct UnsignedIntegerSelector<8> { using Type = u64; };

        template <SizeType>
        struct FloatingPointSelector;
        template <> struct FloatingPointSelector<4> { using Type = f32; };
        template <> struct FloatingPointSelector<8> { using Type = f64; };
    }

    template <SizeType Size>
    using SignedIntegerSelector = typename Implementation::SignedIntegerSelector<Size>::Type;

    template <SizeType Size>
    using UnsignedIntegerSelector = typename Implementation::UnsignedIntegerSelector<Size>::Type;

    template <SizeType Size>
    using FloatingPointSelector = typename Implementation::FloatingPointSelector<Size>::Type;

    //////////////////////////////////////////////////////////////////////////
    // Out of Line definitions for StrongTypes
    //////////////////////////////////////////////////////////////////////////

    namespace Implementation
    {
        template <typename T>
        [[nodiscard]] constexpr
        StrongIntegerType<T> operator<< (const StrongIntegerType<T>& u, const SizeType& v) noexcept
        {
            return u.Value << v.Value;
        }

        template <typename T>
        [[nodiscard]] constexpr
        StrongIntegerType<T> operator>> (const StrongIntegerType<T>& u, const SizeType& v) noexcept
        {
            return u.Value >> v.Value;
        }

        template <typename T>
        [[nodiscard]] constexpr
        StrongIntegerType<T> operator<<= (StrongIntegerType<T>& u, const SizeType& v) noexcept
        {
            return u = u << v;
        }

        template <typename T>
        [[nodiscard]] constexpr
        StrongIntegerType<T> operator>>= (StrongIntegerType<T>& u, const SizeType& v) noexcept
        {
            return u = u >> v;
        }

        // Note(3011): The following definitions produce warnings about comparing
        // floating point values. This is intentional in this case, because
        // we need to compare against exact bit patterns. (In the case of NaNs,
        // it's a whole range of values, but the ALU should be able to deal with it.)
        // So far, whe warnings are not supressed, because the implementation still
        // needs scruitiny.

        template <typename T>
        [[nodiscard]] constexpr
        StrongFloatType<T> StrongFloatType<T>::Previous() const noexcept
        {
            if (Value != Value)
            {
                return StrongFloatType<T>::NaN();
            }

            using UInt = typename UnsignedIntegerSelector<sizeof(T)>::Type;
            constexpr UInt sign = UInt(1) << UInt(sizeof(T) * 8 - 1);
            UInt bits = reinterpret_cast<const UInt &>(Value);
            if (bits == UInt(0))
            {
                bits = sign;
                ++bits;
            }
            else if (Value > T(0))
            {
                --bits;
            }
            else if (Value < T(0))
            {
                ++bits;
            }
            return StrongFloatType<T>(reinterpret_cast<T&>(bits));
        }

        template <typename T>
        [[nodiscard]] constexpr
        StrongFloatType<T> StrongFloatType<T>::Next() const noexcept
        {
            if (MATH_NO_WARN(-Wfloat-equal, Value != Value))
            {
                return StrongFloatType<T>::NaN();
            }

            using UInt = typename UnsignedIntegerSelector<sizeof(T)>::Type;
            constexpr UInt sign = UInt(1) << UInt(sizeof(T) * 8 - 1);
            UInt bits = reinterpret_cast<const UInt &>(Value);
            if (bits == sign)
            {
                bits = UInt(0);
                ++bits;
            }
            else if (Value > T(0))
            {
                ++bits;
            }
            else if (Value < T(0))
            {
                --bits;
            }
            return StrongFloatType<T>(reinterpret_cast<T&>(bits));
        }
    }
}

#endif //MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP
