#include <catch2/catch_test_macros.hpp>
#include <Math/Utils/ContainerTools.hpp>
#include <Math/Vector.hpp>

TEST_CASE("Test Math library types in containers", "[ContainerTools][Math]")
{
    SECTION("Test creating an unordered_map of vectors")
    {
        Math::UnorderedVecMap<Math::Vector2i, int> map;

        map[{15, 41}] = 1;
        map[{ 1,  2}] = 2;
        map[{ 3,  4}] = 3;
        map[{ 5,  6}] = 4;
        map[{ 7,  8}] = 5;

        REQUIRE(map[{15, 41}] == 1);
        REQUIRE(map[{ 1,  2}] == 2);
        REQUIRE(map[{ 3,  4}] == 3);
        REQUIRE(map[{ 5,  6}] == 4);
        REQUIRE(map[{ 7,  8}] == 5);
    }
}
