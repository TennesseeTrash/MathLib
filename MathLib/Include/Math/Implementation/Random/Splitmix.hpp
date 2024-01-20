#ifndef MATHLIB_IMPLEMENTATION_RANDOM_SPLITMIX_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_SPLITMIX_HPP

#include "../Base/Types.hpp"

namespace Math::Implementation
{
    class Splitmix32
    {
    public:
        [[nodiscard]] constexpr
        Splitmix32(u32 seed = 0) noexcept
            : mState(seed)
        {}

        [[nodiscard]] constexpr
        u32 operator()() noexcept
        {
            mState += 0x9E3779B9;
            u32 result = mState;
            result = (result ^ (result >> 16)) * 0x21F0AAAD;
            result = (result ^ (result >> 13)) * 0x735A2D97;
            return result ^ (result >> 16);
        }
    private:
        u32 mState;
    };

    class Splitmix64
    {
    public:
        [[nodiscard]] constexpr
        Splitmix64(u64 seed = 0) noexcept
            : mState(seed)
        {}

        [[nodiscard]] constexpr
        u64 operator()() noexcept
        {
            mState += 0x9E3779B97f4A7C15;
            u64 result = mState;
            result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
            result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
            return result ^ (result >> 31);
        }
    private:
        u64 mState;
    };
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_SPLITMIX_HPP
