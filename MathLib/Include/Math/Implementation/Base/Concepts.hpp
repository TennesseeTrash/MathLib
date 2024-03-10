#ifndef MATHLIB_IMPLEMENTATION_BASE_CONCEPTS_HPP
#define MATHLIB_IMPLEMENTATION_BASE_CONCEPTS_HPP

#include "StrongTypes.hpp"

#include <type_traits>
#include <concepts>

namespace Math::Concept
{
    //////////////////////////////////////////////////////////////////////////
    // Implementation details
    //////////////////////////////////////////////////////////////////////////

    namespace Implementation
    {
        auto Prvalue(auto&& arg)
        {
            return arg;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    // Basic Traits
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename U>
    concept IsSame = std::is_same_v<T, U>;

    template <typename T, typename U>
    concept IsConvertible = std::is_convertible_v<T, U>;

    template <typename T, typename U>
    concept IsSameBaseType = std::is_same_v<std::remove_cvref_t<U>, std::remove_cvref_t<T>>;

    template <typename T, typename U>
    concept IsSameTypeRef = std::is_same_v<U&, T>;

    template <typename T>
    concept IsEmpty = std::is_empty_v<T>;

    namespace Implementation
    {
        template <typename Specialization, template <typename...> typename Base>
        struct IsSpecialization
        {
            static constexpr bool Value = false;
        };

        template <template<typename...> typename Specialization, typename... Args>
        struct IsSpecialization<Specialization<Args...>, Specialization>
        {
            static constexpr bool Value = true;
        };
    }

    template <typename Specialization, template<typename...> typename Base>
    concept IsSpecialization = Implementation::IsSpecialization<Specialization, Base>::Value;

    template <typename T>
    concept HasValueType = requires
    {
        typename T::ValueType;
    };

    template <typename Func, typename... Args>
    concept Invocable = std::is_invocable_v<Func, Args...>;

    template <typename Ret, typename Func, typename... Args>
    concept InvocableWithReturn = std::is_invocable_r_v<Ret, Func, Args...>;

    template <typename T>
    concept FundamentalType = std::is_fundamental_v<T>;

    template <typename T>
    concept IntegralType = std::is_integral_v<T>
                        || std::is_integral_v<typename T::ValueType>;

    template <typename T>
    concept SignedIntegralType = IntegralType<T>
                              &&(std::is_signed_v<T>
                              || std::is_signed_v<typename T::ValueType>);

    template <typename T>
    concept UnsignedIntegralType = IntegralType<T>
                                &&(std::is_unsigned_v<T>
                                || std::is_unsigned_v<typename T::ValueType>);

    template <typename T>
    concept FloatingPointType = std::is_floating_point_v<T>
                             || std::is_floating_point_v<typename T::ValueType>;

    //////////////////////////////////////////////////////////////////////////
    // Arithmetics concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename Ta, typename Tb>
    concept Addition = requires (Ta a, Tb b)
    {
        { a + b } -> std::same_as<Ta>;
        { b + a } -> std::same_as<Ta>;

        { a += b } -> IsSameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Subtraction = requires (Ta a, Tb b)
    {
        { a - b } -> std::same_as<Ta>;
        { b - a } -> std::same_as<Ta>;

        { a -= b } -> IsSameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Multiplication = requires (Ta a, Tb b)
    {
        { a * b } -> std::same_as<Ta>;
        { b * a } -> std::same_as<Ta>;

        { a *= b } -> IsSameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Division = requires (Ta a, Tb b)
    {
        { a / b } -> std::same_as<Ta>;
        { b / a } -> std::same_as<Ta>;

        { a /= b } -> IsSameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept BinaryArithmetic = requires (Ta a, Tb b)
    {
        requires Addition<Ta, Tb>;
        requires Subtraction<Ta, Tb>;
        requires Multiplication<Ta, Tb>;
        requires Division<Ta, Tb>;
    };

    template <typename T>
    concept ArithmeticType = requires
    {
        requires BinaryArithmetic<T, T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Helper type concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept StrongType = requires (T a)
    {
        requires FundamentalType<typename T::ValueType>;
        { ToUnderlying(a) } -> IsSame<typename T::ValueType>;

        { T::Min()  } -> IsSame<T>;
        { T::Max()  } -> IsSame<T>;
    };

    template <typename T>
    concept StrongIntegerType = requires
    {
        requires StrongType<T>;
        requires IntegralType<typename T::ValueType>;
    };

    template <typename T>
    concept StrongFloatType = requires
    {
        requires StrongType<T>;
        requires FloatingPointType<typename T::ValueType>;
    };

    template <typename T>
    concept Array = requires (T a)
    {
        typename T::ValueType;
        { T::Size } -> std::convertible_to<SizeType>;

        requires requires (SizeType i)
        {
            { a[i] } -> IsSameBaseType<typename T::ValueType>;
        };
    };

    //////////////////////////////////////////////////////////////////////////
    // Random concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept RandomNumberGenerator = requires(T rng)
    {
        requires StrongType<typename T::ValueType>;
        requires UnsignedIntegralType<typename T::ValueType>;

        requires requires (typename T::ValueType val)
        {
            { T(val) } -> IsSame<T>;
        };

        { rng()          } -> IsSame<typename T::ValueType>;
        { rng.Jump()     } -> IsSame<T>;
        { rng.LongJump() } -> IsSame<T>;
    };

    template <typename T, typename RNG>
    concept Distribution = requires (T dist)
    {
        requires StrongType<typename T::ValueType>;
        requires requires (typename T::ValueType val)
        {
            { T(val, val) } -> IsSame<T>;
        };

        requires RandomNumberGenerator<RNG>;
        requires requires (RNG rng)
        {
            { dist(rng) } -> IsSame<typename T::ValueType>;
        };
    };

    //////////////////////////////////////////////////////////////////////////
    // Scalar concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept Scalar = requires (T s)
    {
        requires ArithmeticType<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Vector concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept BasicVector = requires (T u)
    {
        typename T::ScalarType;
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires Scalar<typename T::ScalarType>;

        requires requires (SizeType i)
        {
            { u[i] } -> IsSameBaseType<typename T::ScalarType>;
        };

        { u.LenSqr() } -> IsSameBaseType<typename T::ScalarType>;
        { u.Length() } -> IsSameBaseType<typename T::ScalarType>;

        { u.Max() } -> IsSameBaseType<typename T::ScalarType>;
        { u.Min() } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept VectorN = requires (T u, T v)
    {
        requires BasicVector<T>;
        requires ArithmeticType<T>;
        requires BinaryArithmetic<T, typename T::ScalarType>;
    };

    template <typename T>
    concept Vector2 = requires (T u)
    {
        requires VectorN<T>;
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s) } -> IsSame<T>;
        };

        requires T::Dimension == 2;
    };

    template <typename T>
    concept Vector3 = requires (T u)
    {
        requires VectorN<T>;
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.y) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.z) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s) } -> IsSame<T>;
        };

        requires T::Dimension == 3;
    };

    template <typename T>
    concept Vector4 = requires (T u)
    {
        requires VectorN<T>;
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.y) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.z) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.w) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s, s) } -> IsSame<T>;
        };

        requires T::Dimension == 4;
    };

    template <typename T>
    concept Vector = requires
    {
        requires Vector2<T>
              || Vector3<T>
              || Vector4<T>
              || VectorN<T>;
    };

    template <typename T>
    concept IntegerVector = requires
    {
        requires Vector<T>;
        requires IntegralType<typename T::ScalarType>;
    };

    template <typename T>
    concept FloatVector = requires
    {
        requires Vector<T>;
        requires FloatingPointType<typename T::ScalarType>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Point concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept BasicPoint = requires (T p)
    {
        typename T::ScalarType;
        typename T::VectorType;
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires Scalar<typename T::ScalarType>;

        requires BasicVector<typename T::VectorType>;
        requires T::Dimension == T::VectorType::Dimension;

        requires requires (SizeType i)
        {
            { p[i] } -> IsSameBaseType<typename T::ScalarType>;
        };

        { p.Max() } -> IsSameBaseType<typename T::ScalarType>;
        { p.Min() } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept PointN = requires (T p)
    {
        requires BasicPoint<T>;

        requires requires (T q)
        {
            { p - q } -> IsSameBaseType<typename T::VectorType>;
        };

        requires Addition<T, typename T::VectorType>;
        requires Subtraction<T, typename T::VectorType>;
    };

    template <typename T>
    concept Point2 = requires (T p)
    {
        requires PointN<T>;
        { Implementation::Prvalue(p.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(p.x) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v)
        {
            { T(v) } -> IsSame<T>;
        };

        requires T::Dimension == 2;
    };

    template <typename T>
    concept Point3 = requires (T p)
    {
        requires PointN<T>;
        { Implementation::Prvalue(p.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(p.y) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(p.z) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v)
        {
            { T(v) } -> IsSame<T>;
        };

        requires T::Dimension == 3;
    };

    template <typename T>
    concept Point = requires
    {
        requires Point2<T>
              || Point3<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Matrix concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept BasicMatrix = requires (T m)
    {
        typename T::ScalarType;
        typename T::VectorType;
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires Scalar<typename T::ScalarType>;
        requires BasicVector<typename T::VectorType>;
        requires T::Dimension == T::VectorType::Dimension;

        requires requires (SizeType i)
        {
            { m[i][i] } -> IsSameBaseType<typename T::ScalarType>;
        };

        { m.Max() } -> IsSameBaseType<typename T::ScalarType>;
        { m.Min() } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept MatrixN = requires (T m)
    {
        requires BasicMatrix<T>;
        requires BinaryArithmetic<T, typename T::ScalarType>;
        requires Addition<T, T>;
        requires Subtraction<T, T>;
        requires Multiplication<T, T>;
    };

    template <typename T>
    concept Matrix2 = requires (T m)
    {
        requires MatrixN<T>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s,
                s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v)
        {
            { T(v, v) } -> IsSame<T>;
        };

        requires T::Dimension == 2;
    };

    template <typename T>
    concept Matrix3 = requires (T m)
    {
        requires MatrixN<T>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s,
                s, s, s,
                s, s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v)
        {
            { T(v, v, v) } -> IsSame<T>;
        };

        requires T::Dimension == 3;
    };

    template <typename T>
    concept Matrix4 = requires (T m)
    {
        requires MatrixN<T>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s, s,
                s, s, s, s,
                s, s, s, s,
                s, s, s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v)
        {
            { T(v, v, v, v) } -> IsSame<T>;
        };

        requires T::Dimension == 4;
    };

    template <typename T>
    concept Matrix = requires
    {
        requires Matrix2<T>
              || Matrix3<T>
              || Matrix4<T>
              || MatrixN<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Transform concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept BasicTransform = requires (T t)
    {
        typename T::ScalarType;
        typename T::VectorType;
        typename T::MatrixType;
        typename T::RowVectorType;
        typename T::TransformMatrixType;
        { T::Dimension } -> IsSameBaseType<SizeType>;
        requires BasicVector<decltype(T::BottomRow)>;

        requires Scalar<typename T::ScalarType>;
        requires BasicVector<typename T::VectorType>;
        requires BasicMatrix<typename T::MatrixType>;
        requires BasicVector<typename T::RowVectorType>;
        requires BasicMatrix<typename T::TransformMatrixType>;
        requires T::Dimension == T::VectorType::Dimension;
        requires T::Dimension == T::MatrixType::Dimension;
        requires T::Dimension + 1 == T::RowVectorType::Dimension;
        requires T::Dimension + 1 == T::TransformMatrixType::Dimension;

        requires requires (SizeType i)
        {
            { t[i][i] } -> IsSameBaseType<typename T::ScalarType>;
        };
    };

    template <typename T>
    concept TransformN = requires (T t)
    {
        requires BasicTransform<T>;
        requires Multiplication<T, T>;
    };

    template <typename T>
    concept Transform2 = requires (T t)
    {
        requires TransformN<T>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s,
                s, s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v, typename T::MatrixType m)
        {
            { T(v, v) } -> IsSame<T>;
            { T(m)    } -> IsSame<T>;
            { T{m, v} } -> IsSame<T>;
        };

        requires requires (typename T::RowVectorType r)
        {
            { T(r, r) } -> IsSame<T>;
        };

        requires T::Dimension == 2;
    };

    template <typename T>
    concept Transform3 = requires (T t)
    {
        requires TransformN<T>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s, s, s,
                s, s, s, s,
                s, s, s, s) } -> IsSame<T>;
        };

        requires requires (typename T::VectorType v, typename T::MatrixType m)
        {
            { T(v, v, v) } -> IsSame<T>;
            { T(m)       } -> IsSame<T>;
            { T{m, v}    } -> IsSame<T>;
        };

        requires requires (typename T::RowVectorType r)
        {
            { T(r, r, r) } -> IsSame<T>;
        };

        requires T::Dimension == 3;
    };

    template <typename T>
    concept Transform = requires
    {
        requires Transform2<T>
              || Transform3<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Quaternion concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept BasicQuaternion = requires (T q)
    {
        typename T::ScalarType;
        typename T::VectorType;
        typename T::MatrixType;
        typename T::TransformType;

        requires Scalar<typename T::ScalarType>;
        requires BasicVector<typename T::VectorType>;
        requires BasicMatrix<typename T::MatrixType>;
        requires BasicTransform<typename T::TransformType>;

        requires T::VectorType::Dimension == 3;
        requires T::MatrixType::Dimension == 3;
        requires T::TransformType::Dimension == 3;

        { q.Vector() } -> IsSameBaseType<typename T::VectorType>;
        { q.Scalar() } -> IsSameBaseType<typename T::ScalarType>;

        { q.NormSqr() } -> IsSameBaseType<typename T::ScalarType>;
        { q.Norm()    } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept Quaternion = requires (T q)
    {
        requires BasicQuaternion<T>;

        requires requires (T p)
        {
            { q + p } -> IsSameBaseType<T>;
            { q - p } -> IsSameBaseType<T>;
            { q * p } -> IsSameBaseType<T>;
        };
    };

    //////////////////////////////////////////////////////////////////////////
    // Utility concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept MathType = requires
    {
        requires BasicVector<T>
              || BasicPoint<T>
              || BasicMatrix<T>
              || BasicTransform<T>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_BASE_CONCEPTS_HPP
