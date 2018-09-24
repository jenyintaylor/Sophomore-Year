//Jeffrey Taylor, 47400760, Sprint2


//inc
#include "vect.h"
#include "catch.hpp"

Vect<int> leedle;

//Vect tests
TEST_CASE("Custom Vector Cases") {



    for(int i = 0; i < 5; i++) {
        int j =(i*10)+5;
        leedle.push(j); //I think this is a sign that this works
    }
//    REQUIRE(leedle.tot() == 5);

//    REQUIRE(leedle.cap() == 10);
    //I played with this for about an hour with the debugger; having the REQUIRE function was changing private values in Vect
    //Also I was getting different numbers of passed tests every few minutes

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
    SECTION("Can remove elements") {
        leedle.pop();
        REQUIRE(leedle.tot() == 4);
        leedle.push(45);
        REQUIRE(leedle.tot() == 5);
        leedle.popAt(4);
        REQUIRE(leedle.tot() == 4);
    }
    SECTION("Size-based functions work") {
        REQUIRE(leedle.cap() == 10);
        leedle.resize(5);
        REQUIRE(leedle.cap() == 10);
        leedle.resize(15);
        REQUIRE(leedle.cap() == 15);
        REQUIRE(leedle.tot() == 5);
    }



}
