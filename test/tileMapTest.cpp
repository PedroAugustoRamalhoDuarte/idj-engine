#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../include/TileMap.h"

TEST_CASE("TileMap::load", "[TileMap]") {
    auto gameObject = new GameObject();
    auto tileMap = TileMap(*gameObject);

    tileMap.load("../assets/map/tileMap.txt");
    REQUIRE(tileMap.getWidth() == 25);
    REQUIRE(tileMap.getHeight() == 25);
    REQUIRE(tileMap.getDepth() == 2);
}

TEST_CASE("TileMap::at", "[TileMap]") {
    auto gameObject = new GameObject();
    auto tileMap = TileMap(*gameObject);

    tileMap.load("../assets/map/tileMap.txt");
    REQUIRE(tileMap.at(0, 0, 1) == -1);
}