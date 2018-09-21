#include "vect.h"
#include "catch.hpp"

Vect<int> leedle;

void create() {
    for(int i = 0; i < 5; i++) {
        int j =(i*10)+5;
        leedle.push(j);
    }
}

TEST_CASE("Custom Vector Cases") {

    create();

    SECTION("Vector has a beginning") {
        REQUIRE(leedle.first() == 5);
        REQUIRE(leedle[0] == 5);
        REQUIRE(leedle.elementAt(0) == 5);
    }
    SECTION("Vector has an end") {
        REQUIRE(leedle[4] == 45);
        REQUIRE(leedle.elementAt(4) == 45);
        REQUIRE(leedle.last() == 45);
    }

}
