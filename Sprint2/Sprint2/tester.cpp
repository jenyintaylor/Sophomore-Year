#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vect.h"

Vect<int> leedle;

void create() {
    for(int i = 0; i < 5; i++) {
        leedle[i] = ((i*10)+5);
    }
}

TEST_CASE("Vector has a beginning") {
    REQUIRE(leedle[0] == 5);
}
TEST_CASE("Vector has an end") {
    REQUIRE(leedle[4] == 45);
}