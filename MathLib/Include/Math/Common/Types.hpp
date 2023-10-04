#ifndef MATHLIB_COMMON_TYPES_HPP
#define MATHLIB_COMMON_TYPES_HPP

#include <cstdint>
#include <cstddef>
#include <limits>

namespace Math
{
    using SizeType = std::size_t;

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    using i8  = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using u8  = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    using f32 = float;
    using f64 = double;
}

#endif //MATHLIB_COMMON_TYPES_HPP
