#define CATCH_CONFIG_MAIN

#include "Catch/single_include/catch2/catch.hpp"

#include "matchbench/example.hpp"

TEST_CASE("Test example") {
  REQUIRE( matchbench::example() );
}
