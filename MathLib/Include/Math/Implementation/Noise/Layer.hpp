#ifndef MATHLIB_IMPLEMENTATION_NOISE_LAYER_HPP
#define MATHLIB_IMPLEMENTATION_NOISE_LAYER_HPP

#include "../Base/Array.hpp"
#include "../../Vector.hpp"

namespace Math::Noise
{
    template <Concept::FloatingPointType Float, template <typename> typename BaseNoise>
    class Layer final
    {
    public:
        using ValueType = Float;

        [[nodiscard]] constexpr explicit
        Layer(u64 seed = 0) noexcept
            : mBaseNoise(seed)
        {}

        [[nodiscard]] constexpr
        Float operator()(const Vector2T<Float>& in) const noexcept
        {
            return Float(0);
        }

        [[nodiscard]] constexpr
        Float operator()(const Vector3T<Float>& in) const noexcept
        {
            return Float(0);
        }

        [[nodiscard]] constexpr
        Float operator()(const Vector4T<Float>& in) const noexcept
        {
            return Float(0);
        }
    private:
        BaseNoise<Float> mBaseNoise;
    };
}

#endif //MATHLIB_IMPLEMENTATION_NOISE_LAYER_HPP
