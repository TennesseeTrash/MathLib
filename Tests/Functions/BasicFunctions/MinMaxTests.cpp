#include <catch2/catch_test_macros.hpp>
#include <Math/Functions.hpp>

using Math::Min;
using Math::Max;
using Math::Equal;

TEST_CASE("Basic Min tests", "[Math][Functions]")
{
    SECTION("Basic int values with Min")
    {
        REQUIRE(Min(1) == 1);
        REQUIRE(Min(1, 2) == 1);
        REQUIRE(Min(2, 1, 3) == 1);
        REQUIRE(Min(2, 3, 1, 4) == 1);
        REQUIRE(Min(2, 3, 4, 1, 5) == 1);
    }

    SECTION("Basic float values with Min")
    {
        REQUIRE(Equal(Min(1.0f), 1.0f));
        REQUIRE(Equal(Min(1.0f, 2.0f), 1.0f));
        REQUIRE(Equal(Min(2.0f, 1.0f, 3.0f), 1.0f));
        REQUIRE(Equal(Min(2.0f, 3.0f, 1.0f, 4.0f), 1.0f));
        REQUIRE(Equal(Min(2.0f, 3.0f, 4.0f, 1.0f, 5.0f), 1.0f));
    }
}

TEST_CASE("Basic Max tests", "[Math][Functions]")
{
    SECTION("Basic int values with Max")
    {
        REQUIRE(Max(1) == 1);
        REQUIRE(Max(1, 2) == 2);
        REQUIRE(Max(2, 1, 3) == 3);
        REQUIRE(Max(2, 3, 1, 4) == 4);
        REQUIRE(Max(2, 3, 4, 1, 5) == 5);
    }

    SECTION("Basic float values with Max")
    {
        REQUIRE(Equal(Max(1.0f), 1.0f));
        REQUIRE(Equal(Max(1.0f, 2.0f), 2.0f));
        REQUIRE(Equal(Max(2.0f, 1.0f, 3.0f), 3.0f));
        REQUIRE(Equal(Max(2.0f, 3.0f, 1.0f, 4.0f), 4.0f));
        REQUIRE(Equal(Max(2.0f, 3.0f, 4.0f, 1.0f, 5.0f), 5.0f));
    }
}
