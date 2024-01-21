#ifndef MATHLIB_IMPLEMENTATION_QUATERNION_HPP
#define MATHLIB_IMPLEMENTATION_QUATERNION_HPP

#include "Base/Concepts.hpp"
#include "Vector.hpp"
#include "Transform.hpp"

namespace Math
{
    template <Concept::StrongType T>
    class QuaternionT final
    {
    public:
        using ScalarType = T;
        using VectorType = Vector3T<T>;
        using MatrixType = Matrix3T<T>;
        using TransformType = Transform3T<T>;

        [[nodiscard]] constexpr
        QuaternionT() noexcept = default;

        [[nodiscard]] constexpr explicit
        QuaternionT(const VectorType& vector, ScalarType scalar) noexcept
            : mVector(vector), mScalar(scalar)
        {}

        [[nodiscard]] constexpr explicit
        QuaternionT(ScalarType x, ScalarType y, ScalarType z, ScalarType w) noexcept
            : mVector(x, y, z), mScalar(w)
        {}

        [[nodiscard]] constexpr       VectorType& Vector()       noexcept { return mVector; }
        [[nodiscard]] constexpr const VectorType& Vector() const noexcept { return mVector; }
        [[nodiscard]] constexpr       ScalarType& Scalar()       noexcept { return mScalar; }
        [[nodiscard]] constexpr const ScalarType& Scalar() const noexcept { return mScalar; }

        [[nodiscard]] constexpr ScalarType NormSqr() const noexcept { return mVector.LenSqr() + Squared(mScalar); }
        [[nodiscard]] constexpr ScalarType Norm   () const noexcept { return Sqrt(NormSqr()); }

        [[nodiscard]] static constexpr QuaternionT Identity() noexcept { return QuaternionT({}, 1); }
    private:
        VectorType mVector;
        ScalarType mScalar;
    };
}

#endif //MATHLIB_IMPLEMENTATION_QUATERNION_HPP
