#ifndef MATHLIB_COMMON_TYPE_CONCEPTS_HPP
#define MATHLIB_COMMON_TYPE_CONCEPTS_HPP

#include "Types.hpp"

#include <type_traits>
#include <concepts>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // General concepts
    //////////////////////////////////////////////////////////////////////////

    namespace Detail
    {
        auto Prvalue(auto&& arg)
        {
            return arg;
        }
    }

    template <typename T, typename U>
    concept SameBaseType = std::is_same_v<std::remove_cvref_t<U>, std::remove_cvref_t<T>>;

    template <typename T, typename U>
    concept SameTypeRef = std::is_same_v<U&, T>;

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

    template <typename Ta, typename Tb>
    concept Addition = requires (Ta a, Tb b)
    {
        { a + b } -> std::same_as<Ta>;
        { b + a } -> std::same_as<Ta>;

        { a += b } -> SameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Subtraction = requires (Ta a, Tb b)
    {
        { a - b } -> std::same_as<Ta>;
        { b - a } -> std::same_as<Ta>;

        { a -= b } -> SameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Multiplication = requires (Ta a, Tb b)
    {
        { a * b } -> std::same_as<Ta>;
        { b * a } -> std::same_as<Ta>;

        { a *= b } -> SameTypeRef<Ta>;
    };

    template <typename Ta, typename Tb>
    concept Division = requires (Ta a, Tb b)
    {
        { a / b } -> std::same_as<Ta>;
        { b / a } -> std::same_as<Ta>;

        { a /= b } -> SameTypeRef<Ta>;
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
    concept ConceptStrongType = requires (T a)
    {
        typename T::ValueType;
        { ToUnderlying(a) } -> SameBaseType<typename T::ValueType>;

        requires IsSpecialization<T, StrongType>
              || IsSpecialization<T, StaticStrongType>;
    };

    template <typename T>
    concept ConceptArray = requires (T a)
    {
        typename T::ValueType;
        { T::Size } -> std::convertible_to<SizeType>;

        requires requires (SizeType i)
        {
            { a[i] } -> SameBaseType<typename T::ValueType>;
        };
    };

    template <typename T, typename Param = void>
    concept Mapping = requires (T t, Param param)
    {
        requires requires {{ t(param) } -> std::same_as<Param>; }
              || requires {{ T(param) } -> std::same_as<Param>; };
    };

    template <typename T, typename Param = void>
    concept Differentiable = requires (Param param)
    {
        { Derivative<T>(param) } -> std::same_as<Param>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Scalar concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptScalar = requires (T s)
    {
        requires ArithmeticType<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Vector concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptBasicVector = requires (T u)
    {
        typename T::ScalarType;
        { T::Dimension } -> SameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;

        requires requires (SizeType i)
        {
            { u[i] } -> SameBaseType<typename T::ScalarType>;
        };

        { u.LenSqr() } -> SameBaseType<typename T::ScalarType>;
        { u.Length() } -> SameBaseType<typename T::ScalarType>;

        { u.Max() } -> SameBaseType<typename T::ScalarType>;
        { u.Min() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptVectorN = requires (T u, T v)
    {
        requires ConceptBasicVector<T>;
        requires ArithmeticType<T>;
        requires BinaryArithmetic<T, typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptVector2 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptVector3 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.y) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.z) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptVector4 = requires (T u)
    {
        requires ConceptVectorN<T>;
        { Detail::Prvalue(u.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.y) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.z) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(u.w) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 4;
    };

    template <typename T>
    concept ConceptVector = requires
    {
        requires ConceptVector2<T>
              || ConceptVector3<T>
              || ConceptVector4<T>
              || (ConceptVectorN<T> && T::Dimension > 4);
    };

    //////////////////////////////////////////////////////////////////////////
    // Point concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptBasicPoint = requires (T p)
    {
        typename T::ScalarType;
        typename T::VectorType;
        { T::Dimension } -> SameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;

        requires ConceptBasicVector<typename T::VectorType>;
        requires T::Dimension == T::VectorType::Dimension;

        requires requires (SizeType i)
        {
            { p[i] } -> SameBaseType<typename T::ScalarType>;
        };

        { p.Max() } -> SameBaseType<typename T::ScalarType>;
        { p.Min() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptPointN = requires (T p)
    {
        requires ConceptBasicPoint<T>;

        requires requires (T q)
        {
            { p - q } -> SameBaseType<typename T::VectorType>;
        };

        requires Addition<T, typename T::VectorType>;
        requires Subtraction<T, typename T::VectorType>;
    };

    template <typename T>
    concept ConceptPoint2 = requires (T p)
    {
        requires ConceptPointN<T>;
        { Detail::Prvalue(p.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(p.x) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptPoint3 = requires (T p)
    {
        requires ConceptPointN<T>;
        { Detail::Prvalue(p.x) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(p.y) } -> SameBaseType<typename T::ScalarType>;
        { Detail::Prvalue(p.z) } -> SameBaseType<typename T::ScalarType>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptPoint = requires
    {
        requires ConceptPoint2<T>
              || ConceptPoint3<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Matrix concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptBasicMatrix = requires (T m)
    {
        typename T::ScalarType;
        { T::Dimension } -> SameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;

        requires requires (SizeType i)
        {
            { m[i][i] } -> SameBaseType<typename T::ScalarType>;
        };

        { m.Max() } -> SameBaseType<typename T::ScalarType>;
        { m.Min() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptMatrixN = requires (T m)
    {
        requires ConceptBasicMatrix<T>;
        requires BinaryArithmetic<T, typename T::ScalarType>;
        requires Addition<T, T>;
        requires Subtraction<T, T>;
        requires Multiplication<T, T>;
    };

    template <typename T>
    concept ConceptMatrix2 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptMatrix3 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptMatrix4 = requires (T m)
    {
        requires ConceptMatrixN<T>;
        requires T::Dimension == 4;
    };

    template <typename T>
    concept ConceptMatrix = requires
    {
        requires ConceptMatrix2<T>
              || ConceptMatrix3<T>
              || ConceptMatrix4<T>
              || (ConceptMatrixN<T> && T::Dimension > 4);
    };

    //////////////////////////////////////////////////////////////////////////
    // Transform concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptBasicTransform = requires (T t)
    {
        typename T::ScalarType;
        typename T::MatrixType;
        { T::Dimension } -> SameBaseType<SizeType>;
        requires ConceptBasicVector<decltype(T::BottomRow)>;

        requires ConceptScalar<typename T::ScalarType>;
        requires ConceptBasicMatrix<typename T::MatrixType>;
        requires T::Dimension + 1 == T::MatrixType::Dimension;

        requires requires (SizeType i)
        {
            { t[i][i] } -> SameBaseType<typename T::ScalarType>;
        };

        { t.ToMatrix() } -> SameBaseType<typename T::MatrixType>;
    };

    template <typename T>
    concept ConceptTransformN = requires (T t)
    {
        requires ConceptBasicTransform<T>;
        requires Multiplication<T, T>;
    };

    template <typename T>
    concept ConceptTransform2 = requires (T t)
    {
        requires ConceptTransformN<T>;
        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptTransform3 = requires (T t)
    {
        requires ConceptTransformN<T>;
        requires T::Dimension == 3;
    };

    template <typename T>
    concept ConceptTransform = requires
    {
        requires ConceptTransform2<T>
              || ConceptTransform3<T>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Quaternion concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptBasicQuaternion = requires (T q)
    {
        typename T::ScalarType;
        typename T::VectorType;
        typename T::MatrixType;
        typename T::TransformType;

        requires ConceptScalar<typename T::ScalarType>;
        requires ConceptBasicVector<typename T::VectorType>;
        requires ConceptBasicMatrix<typename T::MatrixType>;
        requires ConceptBasicTransform<typename T::TransformType>;

        requires T::VectorType::Dimension == 3;
        requires T::MatrixType::Dimension == 3;
        requires T::TransformType::Dimension == 3;

        { q.Vector() } -> SameBaseType<typename T::VectorType>;
        { q.Scalar() } -> SameBaseType<typename T::ScalarType>;

        { q.NormSqr() } -> SameBaseType<typename T::ScalarType>;
        { q.Norm() } -> SameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptQuaternion = requires (T q)
    {
        requires ConceptBasicQuaternion<T>;

        requires requires (T p)
        {
            { q + p } -> SameBaseType<T>;
            { q - p } -> SameBaseType<T>;
            { q * p } -> SameBaseType<T>;
        };
    };

    //////////////////////////////////////////////////////////////////////////
    // Utility concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptMathTypeUtil = requires
    {
        requires ConceptBasicVector<T>
              || ConceptBasicPoint<T>
              || ConceptBasicMatrix<T>
              || ConceptBasicTransform<T>;
    };
}

#endif //MATHLIB_COMMON_TYPE_CONCEPTS_HPP
