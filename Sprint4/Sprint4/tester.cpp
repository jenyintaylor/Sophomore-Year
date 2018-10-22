#include "catch.hpp"
#include "linkedlist.h"
#include "adjlist.h"
#include "stack.h"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Linked List Tester") {
    LinkedList<string> tester;

    SECTION("Linked List can tell that its empty and won't absolutely die") {
        bool check = tester.isEmpty();
        REQUIRE(check == true);
        tester.popBack();
        tester.popFront();
        tester.clear();
        REQUIRE(tester.size() == 0);


    }


    SECTION("Push functions work") {
        for(int i = 0; i < 15; i++) {
            tester.push("cat");
        }
        REQUIRE(tester.size() == 15);
        tester.pushFront("not cat");
        REQUIRE(tester[0] == "not cat");
        REQUIRE(tester.size() == 16);
        tester.push("totally still cat");
        REQUIRE(tester.size() == 17);
        tester.printBackward();
        cout << tester[16] << endl;
        //REQUIRE(tester[16] == "totally still cat");

    }
}
