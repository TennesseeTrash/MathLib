#ifndef MATHLIB_COMMON_TYPE_CONCEPTS_HPP
#define MATHLIB_COMMON_TYPE_CONCEPTS_HPP

#include "Types.hpp"

#include <type_traits>
#include <concepts>

namespace Math
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

        template <typename Specialization, template <typename...> typename... Bases>
        struct IsSpecializationOfAny
        {
            static constexpr bool Value = (IsSpecialization<Specialization, Bases>::Value || ...);
        };
    }

    template <typename Specialization, template<typename...> typename Base>
    concept IsSpecialization = Implementation::IsSpecialization<Specialization, Base>::Value;

    template <typename Specialization, template<typename...> typename... Bases>
    concept IsSpecializationOfAny = Implementation::IsSpecializationOfAny<Specialization, Bases...>::Value;

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
    concept ConceptStrongType = requires (T a)
    {
        typename T::ValueType;
        { ToUnderlying(a) } -> IsSameBaseType<typename T::ValueType>;

        { T::Min()  } -> IsSame<T>;
        { T::Max()  } -> IsSame<T>;
    };

    template <typename T>
    concept ConceptArray = requires (T a)
    {
        typename T::ValueType;
        { T::Size } -> std::convertible_to<SizeType>;

        requires requires (SizeType i)
        {
            { a[i] } -> IsSameBaseType<typename T::ValueType>;
        };
    };

    template <typename T>
    concept ConceptFunction = requires (T f)
    {
        typename T::ValueType;

        requires requires (typename T::ValueType val)
        {
            { f(val) } -> IsSame<T>;
        };
    };

    //////////////////////////////////////////////////////////////////////////
    // Random concepts
    //////////////////////////////////////////////////////////////////////////

    template <typename T>
    concept ConceptRandomNumberGenerator = requires(T rng)
    {
        typename T::ValueType;

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
    concept ConceptDistribution = requires (T dist)
    {
        typename T::ValueType;
        requires ConceptStrongType<typename T::ValueType>;
        requires requires (typename T::ValueType val)
        {
            { T(val, val) } -> IsSame<T>;
        };

        requires ConceptRandomNumberGenerator<RNG>;
        requires requires (RNG rng)
        {
            { dist(rng) } -> IsSame<typename T::ValueType>;
        };
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
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;

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
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;
        { Implementation::Prvalue(u.x) } -> IsSameBaseType<typename T::ScalarType>;

        requires requires (typename T::ScalarType s)
        {
            { T(s, s) } -> IsSame<T>;
        };

        requires T::Dimension == 2;
    };

    template <typename T>
    concept ConceptVector3 = requires (T u)
    {
        requires ConceptVectorN<T>;
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
    concept ConceptVector4 = requires (T u)
    {
        requires ConceptVectorN<T>;
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
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;

        requires ConceptBasicVector<typename T::VectorType>;
        requires T::Dimension == T::VectorType::Dimension;

        requires requires (SizeType i)
        {
            { p[i] } -> IsSameBaseType<typename T::ScalarType>;
        };

        { p.Max() } -> IsSameBaseType<typename T::ScalarType>;
        { p.Min() } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptPointN = requires (T p)
    {
        requires ConceptBasicPoint<T>;

        requires requires (T q)
        {
            { p - q } -> IsSameBaseType<typename T::VectorType>;
        };

        requires Addition<T, typename T::VectorType>;
        requires Subtraction<T, typename T::VectorType>;
    };

    template <typename T>
    concept ConceptPoint2 = requires (T p)
    {
        requires ConceptPointN<T>;
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
    concept ConceptPoint3 = requires (T p)
    {
        requires ConceptPointN<T>;
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
        typename T::VectorType;
        { T::Dimension } -> IsSameBaseType<SizeType>;

        requires ConceptScalar<typename T::ScalarType>;
        requires ConceptBasicVector<typename T::VectorType>;
        requires T::Dimension == T::VectorType::Dimension;

        requires requires (SizeType i)
        {
            { m[i][i] } -> IsSameBaseType<typename T::ScalarType>;
        };

        { m.Max() } -> IsSameBaseType<typename T::ScalarType>;
        { m.Min() } -> IsSameBaseType<typename T::ScalarType>;
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
    concept ConceptMatrix3 = requires (T m)
    {
        requires ConceptMatrixN<T>;

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
    concept ConceptMatrix4 = requires (T m)
    {
        requires ConceptMatrixN<T>;

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
        typename T::VectorType;
        typename T::MatrixType;
        typename T::RowVectorType;
        typename T::TransformMatrixType;
        { T::Dimension } -> IsSameBaseType<SizeType>;
        requires ConceptBasicVector<decltype(T::BottomRow)>;

        requires ConceptScalar<typename T::ScalarType>;
        requires ConceptBasicVector<typename T::VectorType>;
        requires ConceptBasicMatrix<typename T::MatrixType>;
        requires ConceptBasicVector<typename T::RowVectorType>;
        requires ConceptBasicMatrix<typename T::TransformMatrixType>;
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
    concept ConceptTransformN = requires (T t)
    {
        requires ConceptBasicTransform<T>;
        requires Multiplication<T, T>;
    };

    template <typename T>
    concept ConceptTransform2 = requires (T t)
    {
        requires ConceptTransformN<T>;

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
    concept ConceptTransform3 = requires (T t)
    {
        requires ConceptTransformN<T>;

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

        { q.Vector() } -> IsSameBaseType<typename T::VectorType>;
        { q.Scalar() } -> IsSameBaseType<typename T::ScalarType>;

        { q.NormSqr() } -> IsSameBaseType<typename T::ScalarType>;
        { q.Norm() } -> IsSameBaseType<typename T::ScalarType>;
    };

    template <typename T>
    concept ConceptQuaternion = requires (T q)
    {
        requires ConceptBasicQuaternion<T>;

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
    concept ConceptMathTypeUtil = requires
    {
        requires ConceptBasicVector<T>
              || ConceptBasicPoint<T>
              || ConceptBasicMatrix<T>
              || ConceptBasicTransform<T>;
    };
}

#endif //MATHLIB_COMMON_TYPE_CONCEPTS_HPP
