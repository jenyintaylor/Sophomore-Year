#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "linkedlist.h"
#include "adjlist.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void actualMain(char *input);

int main(int argc, char* argv[]) {
    if(strcmp(argv[1], "-t") == 0) {
        Catch::Session().run();
    } else if(strcmp(argv[1], "-r") == 0) {
        actualMain(argv[1]); //cannot lie, basically ripped from my Sprint 2
    }
}

//what is in here TBD
void actualMain(char* input) {

}
/*Lab notes:
    They also want to see how many people a certain person is connected to (both directly and indirectly with a max distance of 2)
    Really, follow rules and ask help again later if needed

    -r has three files.  What the graph is, the paths wanted, and the output
    -t is exactly what it already is

    So in the adjacency list, make sure that you have name 1 and name 2 connected to each other

    ---------------------------------------------------------
    6
    Carol | Bob
    Carol | Ellen
    Bob | Dave
    Dave | Ellen
    Dave | Frances
    Ellen | Frances
    ----------------------------------------------------------

    So you start with Carol(see phone, Oct 25).  She is connected to Bob.
    In your list, there is no row for Bob, thus you make it.
    Bob, we already know has a Carol.  [1][1] is thus, Carol.
    Back to row 0.  Next name is Ellen.
    She is not in your list of rows, so add her under Bob. [2][1] is now Carol.  And continue

    Next part is why you have a stack.
    You are given Carol, and you need to find how close she is to Frances.

    Iterative Backtracking:
        Make Stack
        Reset all iterators
        Push your start person (Carol).

        while(!stack.isEmpty())
            So then you peek to see if the top person on the stack is the target name.
            No?
            Next name: push Bob.
                Frances?
                If yes: Save path and pop it off the stack
                If no: search from top

            while(top iterator is not on stack)
                stepIter
            if(top.iterator exists)
                push(top.iterator)

        Eventually you'll reach frances.  That's when you backtrack. Basically, it'll loop through again.

        First time: Carol - Bob - Dave - Ellen - Frances
        Then:       Carol - Bob - Dave - Frances
                    Carol - Ellen - Dave - Frances
                    Carol - Ellen - Frances

                    Then Stack is empty.  You have all your paths.  Save and all that and you're good




*/
