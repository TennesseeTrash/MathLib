#ifndef MATHLIB_IMPLEMENTATION_RANDOM_XOSHIRO_HPP
#define MATHLIB_IMPLEMENTATION_RANDOM_XOSHIRO_HPP

// Note(3011):
// Big thanks to Sebastiano Vigna and David Blackman for their work on
// PRNGs. Their work can be found here: http://prng.di.unimi.it/

// Note(3011):
// The behaviour of Jump and LongJump implementations may seem a bit weird.
// They return the current state of the PRGN in a new instance, and advance
// the internal state. The rationale behind this is that it allows for easy
// chaining when passing copies into other threads. This also makes it
// possible to easily advance the state of the PRNG by just calling the
// Jump functions and discarding the result.

#include "../Base/Types.hpp"
#include "../Base/Array.hpp"
#include "../Functions/IntUtils.hpp"
#include "Splitmix.hpp"

namespace Math
{
    class Xoshiro128StarStar final
    {
    public:
        using ValueType = u32;

        [[nodiscard]] constexpr
        Xoshiro128StarStar(u32 seed = 0) noexcept
            : mState()
        {
            Implementation::Splitmix32 splitMix(seed);
            for (SizeType i = 0; i < 4; ++i)
            {
                mState[i] = splitMix();
            }
        }

        [[nodiscard]] constexpr
        u32 operator() () noexcept
        {
            const u32 result = RotateLeft(mState[1] * 5, 7u) * 9;
            const u32 t = mState[1] << 9;

            mState[2] ^= mState[0];
            mState[3] ^= mState[1];
            mState[1] ^= mState[2];
            mState[0] ^= mState[3];

            mState[2] ^= t;

            mState[3] = RotateLeft(mState[3], 11u);

            return result;
        }

        [[nodiscard]] constexpr
        Xoshiro128StarStar Jump() noexcept
        {
            Xoshiro128StarStar result = *this;
            Xoshiro128StarStar temp = *this;
            mState = {};
            for (SizeType i = 0; i < sJump.Size; ++i)
            {
                for (SizeType b = 0; b < SizeType(32); ++b)
                {
                    if (ToUnderlying(sJump[i] & (u32(1) << b)))
                    {
                        mState[0] ^= temp.mState[0];
                        mState[1] ^= temp.mState[1];
                        mState[2] ^= temp.mState[2];
                        mState[3] ^= temp.mState[3];
                    }
                    static_cast<void>(temp());
                }
            }
            return result;
        }

        [[nodiscard]] constexpr
        Xoshiro128StarStar LongJump() noexcept
        {
            Xoshiro128StarStar result = *this;
            Xoshiro128StarStar temp = *this;
            mState = {};
            for (SizeType i = 0; i < sLongJump.Size; ++i)
            {
                for (SizeType b = 0; b < SizeType(32); ++b)
                {
                    if (ToUnderlying(sLongJump[i] & (u32(1) << b)))
                    {
                        mState[0] ^= temp.mState[0];
                        mState[1] ^= temp.mState[1];
                        mState[2] ^= temp.mState[2];
                        mState[3] ^= temp.mState[3];
                    }
                    static_cast<void>(temp());
                }
            }
            return result;
        }
    private:
        Array<u32, 4> mState;

        static constexpr Array<u32, 4> sJump = Array<u32, 4>(
            u32(0x8764000B),
            u32(0xF542D2D3),
            u32(0x6FA035C3),
            u32(0x77F2DB5B));
        static constexpr Array<u32, 4> sLongJump = Array<u32, 4>(
            u32(0xB523952E),
            u32(0x0B6F099F),
            u32(0xCCF5A0EF),
            u32(0x1C580662));
    };

    class Xoshiro256StarStar final
    {
    public:
        using ValueType = u64;

        [[nodiscard]] constexpr
        Xoshiro256StarStar(u64 seed = 0) noexcept
            : mState()
        {
            Implementation::Splitmix64 splitMix(seed);
            for (SizeType i = 0; i < 4; ++i)
            {
                mState[i] = splitMix();
            }
        }

        [[nodiscard]] constexpr
        Xoshiro256StarStar(const Array<u64, 4>& state)
            : mState(state)
        {}

        [[nodiscard]] constexpr
        u64 operator() () noexcept
        {
            // xoshiro256**
            const u64 result = RotateLeft(mState[1] * 5, 7u) * 9;
            const u64 t = mState[1] << 17;

            mState[2] ^= mState[0];
            mState[3] ^= mState[1];
            mState[1] ^= mState[2];
            mState[0] ^= mState[3];

            mState[2] ^= t;

            mState[3] = RotateLeft(mState[3], 45u);

            return result;
        }

        [[nodiscard]] constexpr
        Xoshiro256StarStar Jump() noexcept
        {
            Xoshiro256StarStar result = *this;
            Xoshiro256StarStar temp = *this;
            mState = {};
            for (SizeType i = 0; i < sJump.Size; ++i)
            {
                for (SizeType b = 0; b < SizeType(64); ++b)
                {
                    if (ToUnderlying(sJump[i] & (u64(1) << b)))
                    {
                        mState[0] ^= temp.mState[0];
                        mState[1] ^= temp.mState[1];
                        mState[2] ^= temp.mState[2];
                        mState[3] ^= temp.mState[3];
                    }
                    static_cast<void>(temp());
                }
            }
            return result;
        }

        [[nodiscard]] constexpr
        Xoshiro256StarStar LongJump() noexcept
        {
            Xoshiro256StarStar result = *this;
            Xoshiro256StarStar temp = *this;
            mState = {};
            for (SizeType i = 0; i < sLongJump.Size; ++i)
            {
                for (SizeType b = 0; b < SizeType(64); ++b)
                {
                    if (ToUnderlying(sLongJump[i] & (u64(1) << b)))
                    {
                        mState[0] ^= temp.mState[0];
                        mState[1] ^= temp.mState[1];
                        mState[2] ^= temp.mState[2];
                        mState[3] ^= temp.mState[3];
                    }
                    static_cast<void>(temp());
                }
            }
            return result;
        }
    private:
        Array<u64, 4> mState;

        static constexpr Array<u64, 4> sJump = Array<u64, 4>(
            u64(0x180EC6D33CFD0ABA),
            u64(0xD5A61266F0C9392C),
            u64(0xA9582618E03FC9AA),
            u64(0x39ABDC4529b1661C));
        static constexpr Array<u64, 4> sLongJump = Array<u64, 4>(
            u64(0x76E15D3EFEFDCBBF),
            u64(0xC5004E441C522FB3),
            u64(0x77710069854EE241),
            u64(0x39109BB02ACBE635));
    };
}

#endif //MATHLIB_IMPLEMENTATION_RANDOM_XOSHIRO_HPP
