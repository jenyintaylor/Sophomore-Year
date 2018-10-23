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
    for(int i = 0; i < 15; i++)
        tester.push("cat");
    tester.printForward();
    cout << "--------------------------" << endl;
    tester.printBackward();

    SECTION("Push functions work") {

        REQUIRE(tester.size() == 15);
        tester.pushFront("not cat");
        REQUIRE(tester[0] == "not cat");
        REQUIRE(tester.size() == 16);
        tester.push("totally still cat");
        REQUIRE(tester[16] == "totally still cat");
        REQUIRE(tester.size() == 17);

        tester.pushAt("dog",1); //been looking at this one too long. It's hit or miss
        //will fix during the week



    }
    SECTION("Pop functions work") {
        tester.popBack();
        tester.popFront();
        REQUIRE(tester.size() == 13);
        REQUIRE(tester[0] == "cat");
        tester.push("dog");
        tester.popAt(13);
        REQUIRE(tester[12] == "cat");
        tester.printForward();

    }
    SECTION("Clear works") {
        tester.clear();
        REQUIRE(tester.size() == 0);
        REQUIRE(tester.isEmpty() == true);
    }

}
TEST_CASE("Stack also works") {
    Stack<int> cat;

    SECTION("Stack knows its empty") {
        REQUIRE(cat.isEmpty() == true);
        cat.push(5);
        REQUIRE(cat.isEmpty() == false);
    }
    for(int i = 0; i < 200; i++) {
        cat.push(i*10);
    }
    SECTION("Stack push works") {
        REQUIRE(cat.size() == 200);
    }
    SECTION("Stack pop works") {
        int k = 0;
        for(int i = 0; i < 14; i++)
            k = cat.pop();
        REQUIRE(cat.size() == 186);
        REQUIRE(k == 1860);
    }
    SECTION("Peek works") {
        REQUIRE(cat.peek() == 1990);
    }
    SECTION("Contains works") {
        REQUIRE(cat.contains(1500) == true);
        REQUIRE(cat.contains(3000) == false);
    }
}
TEST_CASE("Adjacency lists") {
    AdjList<int> kek;

    SECTION("Insert for") {
        //kek.insertFor(4, 6);

    }

}
