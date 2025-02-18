#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::f32;

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
        // TODO(3011): Don't enforce result ordering.
        auto solution = Math::QuadraticRoots(f32(2.0f), f32(-4.0f), f32(-6.0f));
        REQUIRE(solution.Count == Math::SizeType(2));
        REQUIRE(Math::Equal(solution.Roots[1], f32(-1.0f)));
        REQUIRE(Math::Equal(solution.Roots[0], f32(3.0f)));
    }
}
