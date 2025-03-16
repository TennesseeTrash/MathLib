#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::f32;
namespace C = Math::Constant;

TEST_CASE("Test Polynomial Solvers", "[Math][Functions]")
{
    SECTION("Quadratic with no roots")
    {
        auto solution = Math::QuadraticRoots(f32(3.0f), f32(4.0f), f32(2.0f));
        REQUIRE(solution.Count == Math::SizeType(0));
        REQUIRE(Math::IsNan(solution.Roots[0]));
        REQUIRE(Math::IsNan(solution.Roots[1]));
    }

    SECTION("Quadratic with one root")
    {
        auto solution = Math::QuadraticRoots(f32(1.0f), f32(6.0f), f32(9.0f));
        REQUIRE(solution.Count == Math::SizeType(1));
        REQUIRE(Math::Equal(solution.Roots[0], f32(-3.0f)));
        REQUIRE(Math::IsNan(solution.Roots[1]));
    }

    SECTION("Quadratic with two roots")
    {
        auto solution = Math::QuadraticRoots(f32(2.0f), f32(-4.0f), f32(-6.0f));
        REQUIRE(solution.Count == Math::SizeType(2));
        REQUIRE(Math::Equal(solution.Roots[0], f32(-1.0f)));
        REQUIRE(Math::Equal(solution.Roots[1], f32(3.0f)));
    }

    SECTION("Cubic with one root")
    {
        auto solution = Math::CubicRoots(f32(3.0), f32(3.0), f32(3.0), f32(3.0));
        REQUIRE(solution.Count == Math::SizeType(1));
        REQUIRE(Math::Equal(solution.Roots[0], f32(-1.0f)));
        REQUIRE(Math::IsNan(solution.Roots[1]));
        REQUIRE(Math::IsNan(solution.Roots[2]));
    }

    SECTION("Cubic with two roots")
    {
        auto solution = Math::CubicRoots(f32(1.0f), f32(3.0f), f32(-9.0f), f32(-27.0f));
        REQUIRE(solution.Count == Math::SizeType(2));
        REQUIRE(Math::Equal(solution.Roots[0], f32(-3.0f)));
        REQUIRE(Math::Equal(solution.Roots[1], f32(3.0f)));
        REQUIRE(Math::IsNan(solution.Roots[2]));
    }

    SECTION("Cubic with three roots")
    {
        auto solution = Math::CubicRoots(f32(2.0f), f32(-2.0f), f32(-4.0f), f32(4.0f));
        REQUIRE(solution.Count == Math::SizeType(3));
        REQUIRE(Math::Equal(solution.Roots[0], -C::Sqrt2<f32>));
        REQUIRE(Math::Equal(solution.Roots[1], f32(1.0f)));
        REQUIRE(Math::Equal(solution.Roots[2], C::Sqrt2<f32>));
    }
}
