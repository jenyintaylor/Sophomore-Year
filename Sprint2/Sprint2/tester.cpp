//Jeffrey Taylor, 47400760, Sprint2


//inc
#include "vect.h"
#include "catch.hpp"

//global variable
Vect<int> leedle;

//function
void create() {
    for(int i = 0; i < 5; i++) {
        int j =(i*10)+5;
        leedle.push(j);
    }
}

//Vect tests
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
    SECTION("Vector elementAt function works") {
        REQUIRE(leedle.elementAt(0) == leedle[0]);
        REQUIRE(leedle.elementAt(1) == leedle[1]);
        REQUIRE(leedle.elementAt(2) == leedle[2]);
        REQUIRE(leedle.elementAt(3) == leedle[3]);
        REQUIRE(leedle.elementAt(4) == leedle[4]);
    }
    SECTION("Capacity and resize functions work") {
        REQUIRE(leedle.cap() == 10);
        leedle.resize(5);
        REQUIRE(leedle.cap() == 10);
        leedle.resize(15);
        REQUIRE(leedle.cap() == 15);
    }
    SECTION("Total elements function works") {
        REQUIRE(leedle.tot() == 5);
    }

}
