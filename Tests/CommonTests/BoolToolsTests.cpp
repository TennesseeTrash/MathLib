#include <catch2/catch_test_macros.hpp>

#include <Math/Common/BoolTools.hpp>

TEST_CASE("Test TrueFor", "[Math][Common][BoolTools]")
{
    SECTION("Is true for specified values")
    {
        REQUIRE(Math::TrueFor< 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 7, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor< 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::TrueFor<10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
    }

    SECTION("Is false for unspecified values values")
    {
        REQUIRE_FALSE(Math::TrueFor< 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::TrueFor<11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::TrueFor<12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::TrueFor<89, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
    }
}

TEST_CASE("Test FalseFor", "[Math][Common][BoolTools]")
{
    SECTION("Is false for specified values")
    {
        REQUIRE_FALSE(Math::FalseFor< 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 7, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 8, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor< 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE_FALSE(Math::FalseFor<10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
    }

    SECTION("Is true for unspecified values values")
    {
        REQUIRE(Math::FalseFor< 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::FalseFor<11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::FalseFor<12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
        REQUIRE(Math::FalseFor<89, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>);
    }
}
