#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "linkedlist.h"
#include "adjlist.h"
#include "stack.h"
#include <iostream>
#include <string>

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
