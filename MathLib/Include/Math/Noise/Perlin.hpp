#ifndef MATHLIB_NOISE_PERLIN_HPP
#define MATHLIB_NOISE_PERLIN_HPP

#include "../Common/Concepts.hpp"
#include "../Common/Array.hpp"
#include "../Functions.hpp"
#include "../Random.hpp"

// TODO(3011): This is not a good interface. It makes it difficult to
// get derivatives with minimal overhead. The interface and implementation
// could use a split. This could also make it possible for the user to further
// customize the calculation. The "pretty interface" would just overload
// the () operator and call the underlying implementation that the user could
// tweak.

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Perlin Noise
    //////////////////////////////////////////////////////////////////////////

    template <FloatingPointType Float, typename Interpolation = decltype([](Float v) -> Float { return Smootherstep(v, Cast<Float>(0), Cast<Float>(1)); })>
    class PerlinNoise final
    {
    public:
        using ValueType = Float;

        [[nodiscard]] constexpr explicit
        PerlinNoise(u64 seed = 0) noexcept
            : mPermutation(ToUnderlying(seed) ? MakeArray<u8, 256>([](SizeType i, u8& v){ v = Cast<u8>(i); }) : sDefaultPermutation)
        {
            if (ToUnderlying(seed))
            {
                Random64 rng(seed);
                mPermutation.Shuffle<Random64, UniformIntegerDistribution>(rng);
            }
        }

        [[nodiscard]] constexpr
        Float operator()(Float x, Float y) const noexcept
        {
            using Int = SignedIntegerSelector<sizeof(Float)>;

            u8 xi = Cast<u8>(Abs(Floor<Int>(x)) & 255);
            u8 yi = Cast<u8>(Abs(Floor<Int>(y)) & 255);

            Float xf = Frac(x);
            Float yf = Frac(y);

            Float u = Interpolation{}(xf);
            Float v = Interpolation{}(yf);

            Float v1 = Grad(Hash2(xi, yi, 0, 0), xf,     yf    );
            Float v2 = Grad(Hash2(xi, yi, 1, 0), xf - 1, yf    );
            Float v3 = Grad(Hash2(xi, yi, 0, 1), xf,     yf - 1);
            Float v4 = Grad(Hash2(xi, yi, 1, 1), xf - 1, yf - 1);

            return (Lerp(v, Lerp(u, v1, v2),
                            Lerp(u, v3, v4)) + 2) / 4;
        }

        [[nodiscard]] constexpr
        Float operator()(Float x, Float y, Float z) const noexcept
        {
            using Int = SignedIntegerSelector<sizeof(Float)>;

            u8 xi = Cast<u8>(Abs(Floor<Int>(x)) & 255);
            u8 yi = Cast<u8>(Abs(Floor<Int>(y)) & 255);
            u8 zi = Cast<u8>(Abs(Floor<Int>(z)) & 255);

            Float xf = Frac(x);
            Float yf = Frac(y);
            Float zf = Frac(z);

            Float u = Interpolation{}(xf);
            Float v = Interpolation{}(yf);
            Float w = Interpolation{}(zf);

            Float v1 = Grad(Hash3(xi, yi, zi, 0, 0, 0), xf,     yf,     zf    );
            Float v2 = Grad(Hash3(xi, yi, zi, 1, 0, 0), xf - 1, yf,     zf    );
            Float v3 = Grad(Hash3(xi, yi, zi, 0, 1, 0), xf,     yf - 1, zf    );
            Float v4 = Grad(Hash3(xi, yi, zi, 1, 1, 0), xf - 1, yf - 1, zf    );
            Float v5 = Grad(Hash3(xi, yi, zi, 0, 0, 1), xf,     yf,     zf - 1);
            Float v6 = Grad(Hash3(xi, yi, zi, 1, 0, 1), xf - 1, yf,     zf - 1);
            Float v7 = Grad(Hash3(xi, yi, zi, 0, 1, 1), xf,     yf - 1, zf - 1);
            Float v8 = Grad(Hash3(xi, yi, zi, 1, 1, 1), xf - 1, yf - 1, zf - 1);

            return (Lerp(w, Lerp(v, Lerp(u, v1, v2),
                                    Lerp(u, v3, v4)),
                            Lerp(v, Lerp(u, v5, v6),
                                    Lerp(u, v7, v8))) + 1) / 2;
        }

        [[nodiscard]] constexpr
        Float operator()(Float x, Float y, Float z, Float w) const noexcept
        {
            using Int = SignedIntegerSelector<sizeof(Float)>;

            u8 xi = Cast<u8>(Abs(Floor<Int>(x)) & 255);
            u8 yi = Cast<u8>(Abs(Floor<Int>(y)) & 255);
            u8 zi = Cast<u8>(Abs(Floor<Int>(z)) & 255);
            u8 wi = Cast<u8>(Abs(Floor<Int>(w)) & 255);

            Float xf = Frac(x);
            Float yf = Frac(y);
            Float zf = Frac(z);
            Float wf = Frac(w);

            Float u = Interpolation{}(xf);
            Float v = Interpolation{}(yf);
            Float s = Interpolation{}(zf);
            Float t = Interpolation{}(wf);

            Float v1  = Grad(Hash4(xi, yi, zi, wi, 0, 0, 0, 0), xf,     yf,     zf,     wf    );
            Float v2  = Grad(Hash4(xi, yi, zi, wi, 1, 0, 0, 0), xf - 1, yf,     zf,     wf    );
            Float v3  = Grad(Hash4(xi, yi, zi, wi, 0, 1, 0, 0), xf,     yf - 1, zf,     wf    );
            Float v4  = Grad(Hash4(xi, yi, zi, wi, 1, 1, 0, 0), xf - 1, yf - 1, zf,     wf    );
            Float v5  = Grad(Hash4(xi, yi, zi, wi, 0, 0, 1, 0), xf,     yf,     zf - 1, wf    );
            Float v6  = Grad(Hash4(xi, yi, zi, wi, 1, 0, 1, 0), xf - 1, yf,     zf - 1, wf    );
            Float v7  = Grad(Hash4(xi, yi, zi, wi, 0, 1, 1, 0), xf,     yf - 1, zf - 1, wf    );
            Float v8  = Grad(Hash4(xi, yi, zi, wi, 1, 1, 1, 0), xf - 1, yf - 1, zf - 1, wf    );
            Float v9  = Grad(Hash4(xi, yi, zi, wi, 0, 0, 0, 1), xf,     yf,     zf,     wf - 1);
            Float v10 = Grad(Hash4(xi, yi, zi, wi, 1, 0, 0, 1), xf - 1, yf,     zf,     wf - 1);
            Float v11 = Grad(Hash4(xi, yi, zi, wi, 0, 1, 0, 1), xf,     yf - 1, zf,     wf - 1);
            Float v12 = Grad(Hash4(xi, yi, zi, wi, 1, 1, 0, 1), xf - 1, yf - 1, zf,     wf - 1);
            Float v13 = Grad(Hash4(xi, yi, zi, wi, 0, 0, 1, 1), xf,     yf,     zf - 1, wf - 1);
            Float v14 = Grad(Hash4(xi, yi, zi, wi, 1, 0, 1, 1), xf - 1, yf,     zf - 1, wf - 1);
            Float v15 = Grad(Hash4(xi, yi, zi, wi, 0, 1, 1, 1), xf,     yf - 1, zf - 1, wf - 1);
            Float v16 = Grad(Hash4(xi, yi, zi, wi, 1, 1, 1, 1), xf - 1, yf - 1, zf - 1, wf - 1);

            return (Lerp(t, Lerp(s, Lerp(v, Lerp(u,  v1,  v2),
                                            Lerp(u,  v3,  v4)),
                                    Lerp(v, Lerp(u,  v5,  v6),
                                            Lerp(u,  v7,  v8))),
                            Lerp(s, Lerp(v, Lerp(u,  v9, v10),
                                            Lerp(u, v11, v12)),
                                    Lerp(v, Lerp(u, v13, v14),
                                            Lerp(u, v15, v16)))) + 1) / 2;
        }

        template <ConceptVector Vec>
        [[nodiscard]] constexpr
        Float operator()(const Vec& vec) const noexcept
        {
            if constexpr (ConceptVector2<Vec>)
            {
                return (*this)(vec.x, vec.y);
            }
            else if constexpr (ConceptVector3<Vec>)
            {
                return (*this)(vec.x, vec.y, vec.z);
            }
            else if constexpr (ConceptVector4<Vec>)
            {
                return (*this)(vec.x, vec.y, vec.z, vec.w);
            }
        }
    private:
        [[nodiscard]] constexpr
        u8 Hash2(u8 x, u8 y, u8 i = 0, u8 j = 0) const noexcept
        {
            u16 hash = 0;
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(x) + Cast<u16>(i)) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(y) + Cast<u16>(j) + hash) & 255]);
            return Cast<u8>(hash);
        }

        [[nodiscard]] constexpr
        u8 Hash3(u8 x, u8 y, u8 z, u8 i = 0, u8 j = 0, u8 k = 0) const noexcept
        {
            u16 hash = 0;
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(x) + Cast<u16>(i)) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(y) + Cast<u16>(j) + hash) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(z) + Cast<u16>(k) + hash) & 255]);
            return Cast<u8>(hash);
        }

        [[nodiscard]] constexpr
        u8 Hash4(u8 x, u8 y, u8 z, u8 w, u8 i = 0, u8 j = 0, u8 k = 0, u8 l = 0) const noexcept
        {
            u16 hash = 0;
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(x) + Cast<u16>(i)) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(y) + Cast<u16>(j) + hash) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(z) + Cast<u16>(k) + hash) & 255]);
            hash = Cast<u16>(mPermutation[Cast<SizeType>(Cast<u16>(w) + Cast<u16>(l) + hash) & 255]);
            return Cast<u8>(hash);
        }

        [[nodiscard]] constexpr
        Float Grad(u8 hash, Float x, Float y) const noexcept
        {
            hash &= 7;
            Float u = (hash < 4) ? x : y;
            Float v = (hash < 4) ? y : x;
            return (ToUnderlying(hash & 1) ? -u : u)
                 + (ToUnderlying(hash & 2) ? Cast<Float>(-2) * v : Cast<Float>(2) * v);
        }

        [[nodiscard]] constexpr
        Float Grad(u8 hash, Float x, Float y, Float z) const noexcept
        {
            hash &= 15;
            Float u = (hash < 8) ? x : y;
            Float v = (hash < 4) ? y : (hash == 12 || hash == 14) ? x : z;
            return (!ToUnderlying(hash & 1) ? u : -u)
                 + (!ToUnderlying(hash & 2) ? v : -v);
        }

        [[nodiscard]] constexpr
        Float Grad(u8 hash, Float x, Float y, Float z, Float w) const noexcept
        {
            hash &= 31;
            Float t = (hash < 24) ? x : y;
            Float u = (hash < 16) ? y : z;
            Float v = (hash < 8) ? z : w;
            return (!ToUnderlying(hash & 1) ? t : -t)
                 + (!ToUnderlying(hash & 2) ? u : -u)
                 + (!ToUnderlying(hash & 4) ? v : -v);
        }

        Array<u8, 256> mPermutation;

        static constexpr Array<u8, 256> sDefaultPermutation = MakeArray<u8, 256>(
            151, 160, 137, 91,  90,  15,  131, 13,  201, 95,  96,  53,  194, 233, 7,   225,
            140, 36,  103, 30,  69,  142, 8,   99,  37,  240, 21,  10,  23,  190, 6,   148,
            247, 120, 234, 75,  0,   26,  197, 62,  94,  252, 219, 203, 117, 35,  11,  32,
            57,  177, 33,  88,  237, 149, 56,  87,  174, 20,  125, 136, 171, 168, 68,  175,
            74,  165, 71,  134, 139, 48,  27,  166, 77,  146, 158, 231, 83,  111, 229, 122,
            60,  211, 133, 230, 220, 105, 92,  41,  55,  46,  245, 40,  244, 102, 143, 54,
            65,  25,  63,  161, 1,   216, 80,  73,  209, 76, 132,  187, 208, 89,  18,  169,
            200, 196, 135, 130, 116, 188, 159, 86,  164, 100, 109, 198, 173, 186, 3,   64,
            52,  217, 226, 250, 124, 123, 5,   202, 38,  147, 118, 126, 255, 82,  85,  212,
            207, 206, 59,  227, 47,  16,  58,  17,  182, 189, 28,  42,  223, 183, 170, 213,
            119, 248, 152, 2,   44,  154, 163, 70,  221, 153, 101, 155, 167, 43,  172, 9,
            129, 22,  39,  253, 19,  98,  108, 110, 79,  113, 224, 232, 178, 185, 112, 104,
            218, 246, 97,  228, 251, 34,  242, 193, 238, 210, 144, 12,  191, 179, 162, 241,
            81,  51,  145, 235, 249, 14,  239, 107, 49,  192, 214, 31,  181, 199, 106, 157,
            184, 84,  204, 176, 115, 121, 50,  45,  127, 4,   150, 254, 138, 236, 205, 93,
            222, 114, 67,  29,  24,  72,  243, 141, 128, 195, 78,  66,  215, 61,  156, 180
        );
    };
}

#endif //MATHLIB_NOISE_PERLIN_HPP
