#ifndef MATHLIB_IMPLEMENTATION_NOISE_SIMPLEX_HPP
#define MATHLIB_IMPLEMENTATION_NOISE_SIMPLEX_HPP

#include "../Base/Array.hpp"
#include "../../Random.hpp"
#include "../../Vector.hpp"

namespace Math::Noise
{
    template <Concept::FloatingPointType Float>
    class Simplex final
    {
    public:
        using ValueType = Float;

        [[nodiscard]] constexpr explicit
        Simplex(u64 seed = 0) noexcept
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
    };
}

#endif //MATHLIB_IMPLEMENTATION_NOISE_SIMPLEX_HPP
