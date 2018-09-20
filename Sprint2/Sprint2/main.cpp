#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vect.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

void runner();

int main(int argc, char* argv[]) {

    if(strcmp(argv[1], "-t") == 0) {
        Catch::Session().run();
    } else if(strcmp(argv[1], "-r") == 0) {
        runner();
    }

    return (0);
}

void runner() {

}
