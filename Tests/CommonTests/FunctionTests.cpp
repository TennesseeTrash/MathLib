#include <catch2/catch_test_macros.hpp>

#include <Math/Functions.hpp>
#include <Math/Common/Function.hpp>
#include <Math/Common/Array.hpp>

namespace
{
    class LinFuncImpl
    {
    public:
        using ValueType = Math::f32;

        template <Math::StaticSizeType Dim>
        static constexpr bool HasDimension = Math::Implementation::TrueFor<Dim, 1>::Value;

        template <Math::StaticSizeType Order>
        static constexpr bool HasDerivative = true;

        template <Math::StaticSizeType Order>
        static constexpr bool HasPartials = true;

        constexpr
        LinFuncImpl(ValueType slope, ValueType intercept)
            : mSlope(slope)
            , mIntercept(intercept)
        {}

        constexpr
        ValueType Value(ValueType x) const
        {
            return mSlope * x + mIntercept;
        }

        template <Math::StaticSizeType Order>
        constexpr
        ValueType DerivativeValue([[maybe_unused]] ValueType x) const
        {
            if constexpr (Order == Math::SizeType(1))
            {
                return mSlope;
            }
            else
            {
                return ValueType(0);
            }
        }

        template <Math::StaticSizeType Order>
        constexpr
        Math::Array<ValueType, 1> PartialsValue([[maybe_unused]] ValueType x) const
        {
            if constexpr (Order == Math::SizeType(1))
            {
                return Math::Array<ValueType, 1>{ mSlope };
            }
            else
            {
                return Math::Array<ValueType, 1>{ ValueType(0) };
            }
        }
    private:
        ValueType mSlope;
        ValueType mIntercept;
    };

    using Linear = Math::Function<LinFuncImpl>;
}

TEST_CASE("Test Function", "[Math][Common][Function]")
{

    SECTION("Function initializes returns correct values")
    {
        Linear linFunc(2.0f, 1.0f);

        REQUIRE(Math::Equal(linFunc(0.0f), 1.0f));
        REQUIRE(Math::Equal(linFunc(1.0f), 3.0f));
        REQUIRE(Math::Equal(linFunc(2.0f), 5.0f));
    }

    SECTION("Function returns correct derivative values")
    {
        Math::Derivative<Linear> linFunc(2.0f, 1.0f);

        REQUIRE(Math::Equal(linFunc(0.0f), 2.0f));
        REQUIRE(Math::Equal(linFunc(1.0f), 2.0f));
        REQUIRE(Math::Equal(linFunc(2.0f), 2.0f));
    }
}
