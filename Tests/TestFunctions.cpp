#include <catch2/catch_test_macros.hpp>
#include <Math/Vector.hpp>

TEST_CASE("Test Min/Max functions", "[Math][Functions]")
{
    SECTION("Check Min")
    {
        REQUIRE(Math::Min(1) == 1);
        REQUIRE(Math::Min(1, 2) == 1);
        REQUIRE(Math::Min(2, 1, 3) == 1);
        REQUIRE(Math::Min(2, 3, 1, 4) == 1);
        REQUIRE(Math::Min(2, 3, 4, 1, 5) == 1);
    }

    SECTION("Check Max")
    {
        REQUIRE(Math::Max(1) == 1);
        REQUIRE(Math::Max(1, 2) == 2);
        REQUIRE(Math::Max(2, 1, 3) == 3);
        REQUIRE(Math::Max(2, 3, 1, 4) == 4);
        REQUIRE(Math::Max(2, 3, 4, 1, 5) == 5);
    }
}
