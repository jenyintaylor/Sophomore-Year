#include "catch.hpp"
#include "linkedlist.h"
#include "adjlist.h"
#include "stack.h"
#include <string>

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

    for(int i = 0; i < 15; i++) {
        tester.push("cat");
    }
}
