#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/TreeMap.hpp"

TEST_CASE() {
    TreeMap map;

    SECTION("Insert and get") {
        map.insert("a", "A");
        map.insert("b", "B");
        map.insert("c", "C");

        REQUIRE(map.get("a") == "A");
        REQUIRE(map.get("b") == "B");
        REQUIRE(map.get("c") == "C");
        REQUIRE(map.get("missing") == "");
    }

    SECTION("Overwrite key") {
        map.insert("x", "one");
        map.insert("x", "two");
        REQUIRE(map.get("x") == "two");
    }

    SECTION("Delete") {
        map.insert("k", "v");
        REQUIRE(map.get("k") == "v");
        map.deleteKey("k");
        REQUIRE(map.get("k") == "");
    }
}