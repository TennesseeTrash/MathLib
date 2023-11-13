#include <catch2/catch_test_macros.hpp>

#include <Math/Functions.hpp>
#include <Math/Common/Function.hpp>
#include <Math/Common/Array.hpp>
#include <Math/Common/BoolTools.hpp>

namespace
{
    class LinFuncImpl
    {
    public:
        using ValueType = Math::f32;

        template <Math::StaticSizeType Dim>
        [[maybe_unused]]
        static constexpr bool HasDimension = Math::TrueFor<Dim, 1>;

        template <Math::StaticSizeType Order>
        [[maybe_unused]]
        static constexpr bool HasDerivative = true;

        template <Math::StaticSizeType Order>
        [[maybe_unused]]
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

TEST_CASE("Basic Function tests", "[Math][Common][Function]")
{

    SECTION("Function initializes returns correct values")
    {
        Linear f(2.0f, 1.0f);

        REQUIRE(Math::Equal(f(0.0f), 1.0f));
        REQUIRE(Math::Equal(f(1.0f), 3.0f));
        REQUIRE(Math::Equal(f(2.0f), 5.0f));
    }
}

TEST_CASE("Basic Derivative tests", "[Math][Common][Function]")
{
    SECTION("Derivative returns correct values")
    {
        Math::Derivative<Linear> df(2.0f, 1.0f);

        REQUIRE(Math::Equal(df(0.0f), 2.0f));
        REQUIRE(Math::Equal(df(1.0f), 2.0f));
        REQUIRE(Math::Equal(df(2.0f), 2.0f));

        Math::Derivative<Linear, 2> ddf(2.0f, 1.0f);

        REQUIRE(Math::Equal(ddf(0.0f), 0.0f));
        REQUIRE(Math::Equal(ddf(1.0f), 0.0f));
        REQUIRE(Math::Equal(ddf(2.0f), 0.0f));

        Math::Derivative<Linear, 3> dddf(2.0f, 1.0f);

        REQUIRE(Math::Equal(dddf(0.0f), 0.0f));
        REQUIRE(Math::Equal(dddf(1.0f), 0.0f));
        REQUIRE(Math::Equal(dddf(2.0f), 0.0f));
    }

    SECTION("Derivative returns correct values when initialized from existing function")
    {
        Linear f(2.0f, 1.0f);
        Math::Derivative<Linear> df(f);

        REQUIRE(Math::Equal(df(0.0f), 2.0f));
        REQUIRE(Math::Equal(df(1.0f), 2.0f));
        REQUIRE(Math::Equal(df(2.0f), 2.0f));

        Math::Derivative<Linear, 2> ddf(f);

        REQUIRE(Math::Equal(ddf(0.0f), 0.0f));
        REQUIRE(Math::Equal(ddf(1.0f), 0.0f));
        REQUIRE(Math::Equal(ddf(2.0f), 0.0f));
    }
}

TEST_CASE("Basic Partials tests", "[Math][Common][Function]")
{
    SECTION("\"Partial\" derivative returns correct value")
    {
        Math::Partials<Linear> df(2.0f, 1.0f);

        REQUIRE(Math::Equal(df(0.0f)[0], 2.0f));
        REQUIRE(Math::Equal(df(1.0f)[0], 2.0f));
        REQUIRE(Math::Equal(df(2.0f)[0], 2.0f));

        Math::Partials<Linear, 2> ddf(2.0f, 1.0f);

        REQUIRE(Math::Equal(ddf(0.0f)[0], 0.0f));
        REQUIRE(Math::Equal(ddf(1.0f)[0], 0.0f));
        REQUIRE(Math::Equal(ddf(2.0f)[0], 0.0f));
    }

    SECTION("\"Partial\" derivative returns correct value when initialized from existing function")
    {
        Linear f(2.0f, 1.0f);
        Math::Partials<Linear> df(f);

        REQUIRE(Math::Equal(df(0.0f)[0], 2.0f));
        REQUIRE(Math::Equal(df(1.0f)[0], 2.0f));
        REQUIRE(Math::Equal(df(2.0f)[0], 2.0f));

        Math::Partials<Linear, 2> ddf(f);

        REQUIRE(Math::Equal(ddf(0.0f)[0], 0.0f));
        REQUIRE(Math::Equal(ddf(1.0f)[0], 0.0f));
        REQUIRE(Math::Equal(ddf(2.0f)[0], 0.0f));
    }
}
