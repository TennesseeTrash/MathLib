#ifndef MATHLIB_COMMON_TYPES_HPP
#define MATHLIB_COMMON_TYPES_HPP

#include <cstdint>
#include <cstddef>
#include <limits>

namespace Math
{
    using SizeType = std::size_t;

    using i8  = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    using u8  = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    using f32 = float;
    using f64 = double;
}

#endif //MATHLIB_COMMON_TYPES_HPP
